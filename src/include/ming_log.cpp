
#include "ming_log.hpp"
namespace spd = spdlog;

boost::shared_ptr<singleton_ming_log> singleton_ming_log::ps_ = nullptr;
boost::mutex singleton_ming_log::mu_;
// std::shared_ptr<spd::logger> singleton_ming_log::log_file;
// std::shared_ptr<spd::logger> singleton_ming_log::log_console;
boost::shared_ptr<singleton_ming_log> ming_log = singleton_ming_log::get_instance();
// typedef singleton_ming_log::get_instance()->log_file log_files;
// typedef singleton_ming_log::get_instance()->log_console log_consoles;
// 
// 
