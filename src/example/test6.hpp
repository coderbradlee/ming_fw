﻿#ifndef TEST6_HPP
#define	TEST6_HPP
#include "include.hpp"
#include <string.h>
#include <cstdarg>
#include <iostream>
#include <map>
#include <bitset>
namespace x6
{
	
    namespace test_curl_client
    {
        void test()
        {
            boost::shared_ptr<curl_client> test = 
            boost::shared_ptr<curl_client>(new curl_client(get_config->m_exchange_rate_url));
                test->request("GET", "/api/live", "access_key="+get_config->m_exchange_rate_key, "");
             ming_log->get_log_console()->info()<<test->get_data()<<":"<<__FILE__<<":"<<__LINE__;
             const auto& j = nlohmann_map::json::parse(test->get_data());
            
            if (j.find("quotes") == j.end()) 
            {
               ming_log->get_log_console()->info()<<"get json error from apilayer::"<<__FILE__<<":"<<__LINE__;
                return;
            }
            const auto& quotes = j["quotes"];
            string usditem="USDCNY";
            try
            { 
                if (quotes.find(usditem) == quotes.end()) 
                {
                    //cout<<item.code<<":"<<__FILE__<<":"<<__LINE__<<endl;
                    ming_log->get_log_console()->info()<<item.code<<":"<<__FILE__<<":"<<__LINE__;
                }
            }
            catch(std::exception& e)
            {
               ming_log->get_log_console()->info()<<e.what()<<":"<<__FILE__<<":"<<__LINE__;
               ming_log->get_log_file()->info()<<e.what()<<":"<<__FILE__<<":"<<__LINE__;
            }
        }
    }
	void test()
	{
        
        test_curl_client::test();
	}

}
#endif
