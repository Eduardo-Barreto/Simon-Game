#include "utils/logger.hpp"

using namespace utils;

Logger::Logger(logLevel log_level, String tag) : log_level(log_level), tag(tag)
{
    Serial.begin(115200);
}

void Logger::setLevel(logLevel log_level)
{
    this->log_level = log_level;
}

void Logger::log(logLevel log_level, const String &message, bool break_line)
{
    if (this->log_level > log_level)
    {
        return;
    }

    if (break_line)
    {
        Serial.println(message);
    }
    else
    {
        Serial.print(message);
    }
}

void Logger::debug(const String &message, bool break_line)
{
    if (this->log_level > LOG_LEVEL_DEBUG)
    {
        return;
    }

    log(LOG_LEVEL_DEBUG, "[DEBUG] " + this->tag + ": " + message, break_line);
}

void Logger::info(const String &message, bool break_line)
{
    if (this->log_level > LOG_LEVEL_INFO)
    {
        return;
    }

    log(LOG_LEVEL_INFO, "[INFO] " + this->tag + ": " + message, break_line);
}

void Logger::warning(const String &message, bool break_line)
{
    if (this->log_level > LOG_LEVEL_WARNING)
    {
        return;
    }

    log(LOG_LEVEL_WARNING, "[WARNING] " + this->tag + ": " + message, break_line);
}

void Logger::error(const String &message, bool break_line)
{
    if (this->log_level > LOG_LEVEL_ERROR)
    {
        return;
    }

    log(LOG_LEVEL_ERROR, "[ERROR] " + this->tag + ": " + message, break_line);
}
