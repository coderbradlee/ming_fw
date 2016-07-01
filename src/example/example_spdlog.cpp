//
// Copyright(c) 2015 Gabi Melman.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//
//
// spdlog usage example
//
#include "example_spdlog.h"

namespace spd = spdlog;
void test_ming_fw()
{
    try
    {
    spd::set_level(spd::level::info);
    spd::get("console")->set_level(spd::level::debug);
    spd::get("console")->info("can be seen");

    size_t q_size = 4096; //queue size must be power of 2
    spdlog::set_async_mode(q_size);
    //spd::set_pattern("[%H:%M:%S %z] [thread %t] %v ***");
    auto rotating_logger = spd::rotating_logger_mt("t", "logs/ming_fw", 1048576 * 15, 300);
        for (int i = 0; i < 10; ++i)
            rotating_logger->info("{} * {} equals {:>10}", i, i, i*i);
        
    spdlog::drop_all();
    }

    catch (const spd::spdlog_ex& ex)
    {
        std::cout << "Log failed: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
}
int test_spdlog()
{
    try
    {
        // Multithreaded color console
        auto console = spd::stdout_logger_mt("console", true);
        console->info("Welcome to spdlog!");
        console->info("An info message example {}..", 1);
        console->info() << "Streams are supported too  " << 1;

        // Formatting examples
        console->info("Easy padding in numbers like {:08d}", 12);
        console->info("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
        console->info("Support for floats {:03.2f}", 1.23456);
        console->info("Positional args are {1} {0}..", "too", "supported");

        console->info("{:<30}", "left aligned");
        console->info("{:>30}", "right aligned");
        console->info("{:^30}", "centered");

        spd::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name) function");

        // Runtime log levels
        spd::set_level(spd::level::info); //Set global log level to info
        console->debug("This message shold not be displayed!");
        console->set_level(spd::level::debug); // Set specific logger's log level
        console->debug("This message shold be displayed..");

        // Create basic file logger (not rotated)
        auto my_logger = spd::basic_logger_mt("basic_logger", "logs/basic.txt");
        my_logger->info("Some log message");


        // Create a file rotating logger with 5mb size max and 3 rotated files
        auto rotating_logger = spd::rotating_logger_mt("some_logger_name", "logs/mylogfile", 1048576 * 5, 3);
        for (int i = 0; i < 10; ++i)
            rotating_logger->info("{} * {} equals {:>10}", i, i, i*i);

        // Create a daily logger - a new file is created every day on 2:30am
        auto daily_logger = spd::daily_logger_mt("daily_logger", "logs/daily", 2, 30);

        // Customize msg format for all messages
        spd::set_pattern("*** [%H:%M:%S %z] [thread %t] %v ***");
        rotating_logger->info("This is another message with custom format");


        // Compile time debug or trace macros.
        // Enabled #ifdef SPDLOG_DEBUG_ON or #ifdef SPDLOG_TRACE_ON
        SPDLOG_TRACE(console, "Enabled only #ifdef SPDLOG_TRACE_ON..{} ,{}", 1, 3.23);
        SPDLOG_DEBUG(console, "Enabled only #ifdef SPDLOG_DEBUG_ON.. {} ,{}", 1, 3.23);

        // Asynchronous logging is very fast..
        // Just call spdlog::set_async_mode(q_size) and all created loggers from now on will be asynchronous..
        async_example();

        // syslog example. linux/osx only..
        syslog_example();


        // Release and close all loggers
        spdlog::drop_all();
    }

    catch (const spd::spdlog_ex& ex)
    {
        std::cout << "Log failed: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


void async_example()
{
    size_t q_size = 4096; //queue size must be power of 2
    spdlog::set_async_mode(q_size);
    auto async_file = spd::daily_logger_st("async_file_logger", "logs/ming_fw");
    for (int i = 0; i < 100; ++i)
        async_file->info("Async message #{}", i);
}

//syslog example (linux/osx only)
void syslog_example()
{
#if defined (__linux__) || defined(__APPLE__)
    std::string ident = "spdlog-example";
    auto syslog_logger = spd::syslog_logger("syslog", ident, LOG_PID);
    syslog_logger->warn("This is warning that will end up in syslog. This is Linux only!");
#endif
}


// Example of user defined class with operator<<
class some_class {};
std::ostream& operator<<(std::ostream& os, const some_class&)
{
    return os << "some_class";
}

void custom_class_example()
{
    some_class c;
    spdlog::get("console")->info("custom class with operator<<: {}..", c);
    spdlog::get("console")->info() << "custom class with operator<<: " << c << "..";
}

