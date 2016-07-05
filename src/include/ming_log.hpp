#ifndef SPD_MING_LOG_HPP
#define	SPD_MING_LOG_HPP
#include "include.hpp"
#include "spdlog/spdlog.h"
namespace spd = spdlog;
class singleton_ming_log :public boost::enable_shared_from_this<singleton_ming_log>, boost::noncopyable
{
public:
	singleton_ming_log();
	~singleton_ming_log();
	
	static boost::shared_ptr<singleton_ming_log> get_instance();
	
	void initlog();
	
	std::shared_ptr<spd::logger> get_log_file();
	std::shared_ptr<spd::logger> get_log_console();
	
private:
	static boost::mutex mu_;
	static boost::shared_ptr<singleton_ming_log> ps_;
	std::shared_ptr<spd::logger> log_file;
	std::shared_ptr<spd::logger> log_console;	
};
// boost::shared_ptr<singleton_ming_log> singleton_ming_log::ps_ = nullptr;
// boost::mutex singleton_ming_log::mu_;
// std::shared_ptr<spd::logger> singleton_ming_log::log_file;
// std::shared_ptr<spd::logger> singleton_ming_log::log_console;
//#define boost::shared_ptr<singleton_ming_log> ming_log = singleton_ming_log::get_instance();
#define ming_log singleton_ming_log::get_instance()
//using ming_log=singleton_ming_log::get_instance();
// typedef singleton_ming_log::get_instance()->log_file log_files;
// typedef singleton_ming_log::get_instance()->log_console log_consoles;
// 
// 

#endif