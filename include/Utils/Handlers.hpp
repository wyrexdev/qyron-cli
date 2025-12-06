#pragma once

#include <cassandra.h>
#include <string>

struct ScyllaAuth
{
    std::string username;
    std::string password;
};

struct Row
{
    CassUuid id;
    const char *name;
    size_t name_len;
    const char *pubkey;
    size_t pubkey_len;
};