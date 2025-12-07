#include "Redis/HiRedisClient.hpp"

HiRedisClient::HiRedisClient(const std::string &host, int port) : host(host), port(port)
{
    connect();
}

HiRedisClient::~HiRedisClient()
{
    if (ctx)
        redisFree(ctx);
}

redisReply *HiRedisClient::command(const char *fmt, ...)
{
    if (!ctx)
        connect();

    va_list args;
    va_start(args, fmt);
    redisReply *reply = (redisReply *)redisvCommand(ctx, fmt, args);
    va_end(args);

    if (!reply)
    {
        std::cerr << "Redis failed, reconnecting..." << std::endl;
        connect();
        va_start(args, fmt);
        reply = (redisReply *)redisvCommand(ctx, fmt, args);
        va_end(args);
    }

    return reply;
}

void HiRedisClient::connect()
{
    if (ctx)
        redisFree(ctx);

    ctx = redisConnect(host.c_str(), port);
    if (ctx == nullptr || ctx->err)
    {
        std::cerr << "Redis connect error: " << ctx->errstr << std::endl;
        ctx = nullptr;
    }
}