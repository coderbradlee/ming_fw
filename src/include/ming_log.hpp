#ifndef MING_LOG_HPP
#define	MING_LOG_HPP
#include "spdlog/spdlog.h"
namespace spd = spdlog;
class singleton_ming_log :public boost::enable_shared_from_this<singleton_ming_log>, boost::noncopyable
{
public:
	singleton_ming_log()
	{	
		initlog();
	}
	~singleton_ming_log()
	{
		spdlog::drop_all();
	}
	static boost::shared_ptr<singleton_ming_log> get_instance()
	{
		boost::mutex::scoped_lock t(mu_);
		if (ps_ == nullptr)
		{
			ps_ = boost::shared_ptr<singleton_ming_log>(new singleton_ming_log());
		}
		/*if (initsink_ == nullptr)
		{
			initsink_ = initlog();
		}*/
		return ps_;
	}
	
	void initlog()
	{
		try
		{
			// trace = 0,
		 //    debug = 1,
		 //    info = 2,
		 //    notice = 3,
		 //    warn = 4,
		 //    err = 5,
		 //    critical = 6,
		 //    alert = 7,
		 //    emerg = 8,
		 //    off = 9
			if(get_config->m_log_level=="info")
			{
				spd::set_level(spd::level::info);
			}
			else if(get_config->m_log_level=="debug")
			{
				spd::set_level(spd::level::debug);
			}
			else if(get_config->m_log_level=="err")
			{
				spd::set_level(spd::level::err);
			}
			else
			{
				spd::set_level(spd::level::warn);
			}
	        log_console = spd::stdout_logger_mt("console", true);
	        spd::get("console")->set_level(spd::level::debug);
	        //spd::get("console")->info("can be seen");
	        //console->info() << "Streams are supported too  " << 1;
	        size_t q_size = 4096; //queue size must be power of 2
	        spdlog::set_async_mode(q_size);
	        spd::set_pattern("[%l][%Y-%m-%d %H:%M:%S.%e][thread %t]%v");
	        log_file = spd::rotating_logger_mt("t", get_config->m_log_name, 1048576 * get_config->m_log_size, get_config->m_log_numbers);
	            // for (int i = 0; i < 10; ++i)
	            //     rotating_logger->info("{} * {} equals {:>10}", i, i, i*i);
	            
	        
		}
		catch (std::exception& e)
		{
			std::cout << "FAILURE: " << e.what() << std::endl;
		}
	}
	std::shared_ptr<spd::logger> get_log_file()
	{
		return log_file;
	}
	std::shared_ptr<spd::logger> get_log_console()
	{
		return log_console;
	}
private:
	static boost::mutex mu_;
	static boost::shared_ptr<singleton_ming_log> ps_;
	std::shared_ptr<spd::logger> log_file;
	std::shared_ptr<spd::logger> log_console;	
};
boost::shared_ptr<singleton_ming_log> singleton_ming_log::ps_ = nullptr;
boost::mutex singleton_ming_log::mu_;
// std::shared_ptr<spd::logger> singleton_ming_log::log_file;
// std::shared_ptr<spd::logger> singleton_ming_log::log_console;
boost::shared_ptr<singleton_ming_log> ming_log = singleton_ming_log::get_instance();
// typedef singleton_ming_log::get_instance()->log_file log_files;
// typedef singleton_ming_log::get_instance()->log_console log_consoles;