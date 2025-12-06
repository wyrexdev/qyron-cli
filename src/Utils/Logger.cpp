#include "Utils/Logger.hpp"

void Logger::Write(std::string m, std::string style, bool isEndl) {
    std::cout << (style != "" ? style + m + reset : m) << (isEndl ? '\n' : '\0');
}

int Logger::LoadAnimSystem(std::string m, std::string style, const std::string& cmd)
{
    std::atomic<bool> done(false);
    int result = 0;

    std::thread worker([&]() {
        result = std::system(cmd.c_str());
        done = true;
    });

    const char spinner[] = {'|', '/', '-', '\\'};
    int index = 0;

    while (!done)
    {
        std::cout << "\r"
                  << spinner[index] << "  "
                  << (style != "" ? style + m + reset : m)
                  << std::flush;

        index = (index + 1) % 4;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    worker.join();

    if (WEXITSTATUS(result) == 0)
    {
        std::cout << "\r\033[1;32m✔\033[0m  " 
                  << (style != "" ? style + m + reset : m)
                  << "    " << std::endl;
    }
    else
    {
        std::cout << "\r\033[1;31m✖\033[0m  " 
                  << (style != "" ? style + m + reset : m)
                  << "    " << std::endl;
    }

    return result;
}