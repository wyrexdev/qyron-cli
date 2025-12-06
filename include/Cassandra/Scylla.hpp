#pragma once

#include "Utils/Handlers.hpp"

#include <iostream>
#include <vector>

#include <cassandra.h>

class Scylla
{
public:
    Scylla();
    Scylla(std::string ip);
    Scylla(std::string ip, ScyllaAuth auth);

    ~Scylla();

    void setIPAddress(std::string ip);

    void Connect();
    void Disconnect();

    std::vector<Row> Query(const std::string& query);
    bool Execute(const std::string& query);

private:
    void init();    

    CassCluster *cluster;
    CassSession *session;

    std::string ip;

    ScyllaAuth auth = {
        username : "",
        password : ""
    };

    bool isConnected = false;
};