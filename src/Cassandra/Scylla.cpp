#include "Cassandra/Scylla.hpp"

Scylla::Scylla()
{
    init();
}

Scylla::Scylla(std::string ip)
{
    this->ip = ip;

    init();
}

Scylla::Scylla(std::string ip, ScyllaAuth auth)
{
    this->ip = ip;
    this->auth = auth;

    init();
}

void Scylla::setIPAddress(std::string ip)
{
    this->ip = ip;

    init();
}

Scylla::~Scylla()
{
    Disconnect();
}

void silent_log_callback(const CassLogMessage* message, void* data) {}

void Scylla::init()
{
    cluster = cass_cluster_new();
    session = cass_session_new();

    cass_log_set_callback(silent_log_callback, nullptr);
    cass_log_set_level(CASS_LOG_DISABLED);
}

void Scylla::Connect() 
{
    cass_cluster_set_contact_points(cluster, ip.c_str());

    if (!auth.username.empty() && !auth.password.empty()) {
        cass_cluster_set_credentials(cluster, auth.username.c_str(), auth.password.c_str());
    }

    CassFuture* connect_future = cass_session_connect(session, cluster);

    if (cass_future_error_code(connect_future) == CASS_OK) {
        std::cout << "[Scylla] Connection established successfully." << std::endl;
        isConnected = true;
    } else {
        const char* msg;
        size_t msg_len;
        cass_future_error_message(connect_future, &msg, &msg_len);
        isConnected = false;
    }

    cass_future_free(connect_future);
}

void Scylla::Disconnect()
{
}

bool Scylla::Execute(const std::string &query)
{
    CassStatement *statement = cass_statement_new(query.c_str(), 0);
    CassFuture *result_future = cass_session_execute(session, statement);

    if (cass_future_error_code(result_future) != CASS_OK)
    {
        const char *msg;
        size_t msg_len;
        cass_future_error_message(result_future, &msg, &msg_len);

        cass_statement_free(statement);
        cass_future_free(result_future);
        return false;
    }

    cass_statement_free(statement);
    cass_future_free(result_future);
    return true;
}

std::vector<Row> Scylla::Query(const std::string &query)
{
    std::vector<Row> rows_out;

    CassStatement *statement = cass_statement_new(query.c_str(), 0);
    CassFuture *result_future = cass_session_execute(session, statement);

    if (cass_future_error_code(result_future) != CASS_OK)
    {
        const char *msg;
        size_t msg_len;
        cass_future_error_message(result_future, &msg, &msg_len);

        cass_statement_free(statement);
        cass_future_free(result_future);
        return rows_out;
    }

    const CassResult *result = cass_future_get_result(result_future);
    CassIterator *rows = cass_iterator_from_result(result);

    while (cass_iterator_next(rows))
    {
        const CassRow *row = cass_iterator_get_row(rows);

        Row r;

        const CassValue *col1 = cass_row_get_column(row, 0);
        cass_value_get_uuid(col1, &r.id);

        const CassValue *col2 = cass_row_get_column(row, 1);
        cass_value_get_string(col2, &r.name, &r.name_len);

        const CassValue *col3 = cass_row_get_column(row, 2);
        cass_value_get_string(col3, &r.pubkey, &r.pubkey_len);

        rows_out.push_back(r);
    }

    cass_iterator_free(rows);
    cass_result_free(result);
    cass_statement_free(statement);
    cass_future_free(result_future);

    return rows_out;
}