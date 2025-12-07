#include <hiredis/hiredis.h>

#include <iostream>

class HiRedisClient {
public:
    HiRedisClient(const std::string& host, int port);
    ~HiRedisClient();

    redisReply* command(const char* fmt, ...);

private:
    redisContext* ctx = nullptr;
    std::string host;
    int port;

    void connect();
};
