#include <string>
#include <iostream>
#include <thread>
#include <atomic>

class Logger
{
public:
    static inline std::string reset = "\033[0m";
    static inline std::string black = "\033[30m";
    static inline std::string red = "\033[31m";
    static inline std::string green = "\033[32m";
    static inline std::string yellow = "\033[33m";
    static inline std::string blue = "\033[34m";
    static inline std::string magenta = "\033[35m";
    static inline std::string cyan = "\033[36m";
    static inline std::string white = "\033[37m";

    static inline std::string bold = "\033[1m";

    static inline std::string underline = "\033[4m";

    static inline std::string bright_black = "\033[90m";
    static inline std::string bright_red = "\033[91m";
    static inline std::string bright_green = "\033[92m";
    static inline std::string bright_yellow = "\033[93m";
    static inline std::string bright_blue = "\033[94m";
    static inline std::string bright_magenta = "\033[95m";
    static inline std::string bright_cyan = "\033[96m";
    static inline std::string bright_white = "\033[97m";

    static inline std::string bg_red = "\033[41m";
    static inline std::string bg_green = "\033[42m";
    static inline std::string bg_yellow = "\033[43m";
    static inline std::string bg_blue = "\033[44m";
    static inline std::string bg_magenta = "\033[45m";
    static inline std::string bg_cyan = "\033[46m";
    static inline std::string bg_white = "\033[47m";

    static inline std::string bred = "\033[1;31m";
    static inline std::string bgreen = "\033[1;32m";
    static inline std::string byellow = "\033[1;33m";
    static inline std::string bblue = "\033[1;34m";
    static inline std::string bmagenta = "\033[1;35m";
    static inline std::string bcyan = "\033[1;36m";
    static inline std::string bwhite = "\033[1;37m";

    static void Write(std::string m, std::string style = "", bool isEndl = false);
    static int LoadAnimSystem(std::string m, std::string style, const std::string& cmd);
};