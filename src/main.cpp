#include <iostream>

#include "Utils/Logger.hpp"
#include "Utils/System.hpp"

#include "Redis/HiRedisClient.hpp"

int main()
{
    int redisResult = Logger::LoadAnimSystem("Checking Redis Server...", Logger::bold + Logger::bmagenta, "redis-server --test-memory 1 > /dev/null 2>&1");

    if (WEXITSTATUS(redisResult) == 127)
    {
        Logger::Write((Logger::bold + Logger::cyan) + "[Redis] -" + Logger::reset + (Logger::red + Logger::bold) + " redis-server is not found!" + Logger::reset, "", true);
        Logger::Write((Logger::bold + Logger::cyan) + "[Redis] -" + Logger::reset + (Logger::red + Logger::bold) + " You should install Redis! You can look Redis WebSite for installation." + Logger::reset, "", true);
    }
    else
    {
        const std::string redisServerResult = System::execCmd("redis-server > /dev/null 2>&1 &");

        if (redisServerResult.find("Failed listening on port"))
        {
            std::cout << redisServerResult << "asd \n";
        }
        else
        {
            HiRedisClient *redis = new HiRedisClient("127.0.0.1", 6379);

            Logger::Write(redisServerResult, Logger::magenta + Logger::bold);

            int choise;

            std::string logo =
                "══════════════════════════════════════════════════\n"
                "   ▄▄▄▄   ▄▄▄    ▄▄▄ ▄▄▄▄▄▄      ▄▄▄▄    ▄▄▄   ▄▄ \n"
                "  ██▀▀██   ██▄  ▄██  ██▀▀▀▀██   ██▀▀██   ███   ██ \n"
                " ██    ██   ██▄▄██   ██    ██  ██    ██  ██▀█  ██ \n"
                " ██    ██    ▀██▀    ███████   ██    ██  ██ ██ ██ \n"
                "  ██▄▄██▀     ██     ██  ▀██▄  ██    ██  ██  █▄██ \n"
                "   ▀▀▀██      ██     ██    ██   ██▄▄██   ██   ███ \n"
                "       ▀      ▀▀     ▀▀    ▀▀▀   ▀▀▀▀    ▀▀   ▀▀▀ \n"
                "──────────────────────────────────────────────────\n";

            Logger::Write(logo, Logger::magenta + Logger::bold);

            Logger::Write("╔══════════════════════ MENU ════════════════════╗", Logger::magenta + Logger::bold, true);
            Logger::Write("║                                                ║", Logger::magenta + Logger::bold, true);
            Logger::Write("║ " + (Logger::cyan + Logger::bold) + "1- View VPN Clients" + Logger::reset + "                            " + (Logger::magenta + Logger::bold) + "║", Logger::magenta + Logger::bold, true);
            Logger::Write("║ " + (Logger::cyan + Logger::bold) + "2- Create an Client" + Logger::reset + "                            " + (Logger::magenta + Logger::bold) + "║", Logger::magenta + Logger::bold, true);
            Logger::Write("║ " + (Logger::cyan + Logger::bold) + "3- Delete an Client" + Logger::reset + "                            " + (Logger::magenta + Logger::bold) + "║", Logger::magenta + Logger::bold, true);
            Logger::Write("║                                                ║", Logger::magenta + Logger::bold, true);
            Logger::Write("╚════════════════════════════════════════════════╝", Logger::magenta + Logger::bold, true);
            Logger::Write("Please Enter Your Choice: ", Logger::blue, false);

            std::cin >> choise;

            while (true)
            {
            }
        }
    }

    return 1;
}