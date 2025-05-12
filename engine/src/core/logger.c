#include "logger.h"
#include "asserts.h"

// temporary
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line)
{
    log_output(LOG_LEVEL_FATAL, "Asertion Failure: %s, message: '%s', in file: %s, line: %d\n",
        expression, message, file, line);
}

b8 initialize_logging()
{
    // TODO: create log file.
    return true;
}

void shutdown_logging()
{
    // TODO: cleanup logging/write queued entries.
}

void log_output(log_level level, const char* message, ...)
{
    const char* level_strings[6] = {
        "[FATAL]: ",
        "[ERROR]: ",
        "[WARN]: ",
        "[INFO]: ",
        "[DEBUG]: ",
        "[TRACE]: "
    };
    // b8 is_error = level <= 2;

    char formatted_message[3200], out_message[3200];
    memset(formatted_message, 0, sizeof(formatted_message)); // redundant??

    __builtin_va_list arg_ptr; // to overcome windows being windowing
    va_start(arg_ptr, message);
    vsnprintf(formatted_message, 3200, message, arg_ptr);
    va_end(arg_ptr);

    snprintf(out_message, 3200, "%s%s\n", level_strings[level], formatted_message);

    printf("%s", out_message);
}
