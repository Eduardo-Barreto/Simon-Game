#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <Arduino.h>

enum logLevel
{
    LOG_LEVEL_DEBUG = 1,
    LOG_LEVEL_INFO = 2,
    LOG_LEVEL_WARNING = 3,
    LOG_LEVEL_ERROR = 4
};

namespace utils
{
    class Logger
    {
    public:
        /**
         * @brief Construct a new Logger object
         *
         * @param log_level Minimum level of logs to be printed
         * @param tag Tag to be printed before the log message
         */
        Logger(logLevel log_level, const String tag);

        /**
         * @brief Set the log level
         *
         * @param log_level
         */
        void setLevel(logLevel log_level);

        /**
         * @brief Generic log function
         *
         * @param log_level Log level
         * @param message Message to be printed
         * @param break_line Add \n to the end of the message
         */
        void log(logLevel log_level, const String &message, bool break_line);

        /**
         * @brief Prints a debug log
         *
         * @param message Message to be printed
         */
        void debug(const String &message, bool break_line = true);

        /**
         * @brief Prints an info log
         *
         * @param message Message to be printed
         */
        void info(const String &message, bool break_line = true);

        /**
         * @brief Prints a warning log
         *
         * @param message Message to be printed
         */
        void warning(const String &message, bool break_line = true);

        /**
         * @brief Prints an error log
         *
         * @param message Message to be printed
         */
        void error(const String &message, bool break_line = true);

    private:
        logLevel log_level;
        const String tag;
    };
};

#endif // __LOGGER_HPP__