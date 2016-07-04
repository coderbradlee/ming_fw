#ifndef TEST6_HPP
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
                    ming_log->get_log_console()->info()<<"cannot find :"<<usditem<<__FILE__<<":"<<__LINE__;
                }
                else
                {
                    const auto& from_usd_exchange_rate=quotes[usditem];
                    float t=from_usd_exchange_rate;
                    ming_log->get_log_console()->info()<<t<<__FILE__<<":"<<__LINE__;
                }
            }
            catch(std::exception& e)
            {
               ming_log->get_log_console()->info()<<e.what()<<":"<<__FILE__<<":"<<__LINE__;
               ming_log->get_log_file()->info()<<e.what()<<":"<<__FILE__<<":"<<__LINE__;
            }
        }
    }
    namespace test_design_model_factory
    {
        class splitter
        {
        public:
            virtual void split()=0;
            virtual ~splitter(){}
        };
        class file_splitter:public splitter
        {
        public:
            void split()
            {
                ming_log->get_log_console()->info()<<"file_splitter:"<<__FILE__<<":"<<__LINE__;
            }
        };
        class video_splitter:public splitter
        {
        public:
            void split()
            {
                ming_log->get_log_console()->info()<<"video_splitter:"<<__FILE__<<":"<<__LINE__;
            }
        };
        class splitter_factory
        {
        public:
            virtual boost::shared_ptr<splitter> create()=0;
            virtual ~splitter_factory(){}
        };
        class file_splitter_factory:public splitter_factory
        {
        public:
            boost::shared_ptr<splitter> create()
            {
                return boost::shared_ptr<splitter>(new file_splitter());
            }
        };
        class video_splitter_factory:public splitter_factory
        {
        public:
            boost::shared_ptr<splitter> create()
            {
                return boost::shared_ptr<splitter>(new video_splitter());
            }
        };
        class win_form
        {
        public:
            win_form(boost::shared_ptr<splitter_factory> sf):m_sf(sf)
            {

            }
            void click()
            {
                boost::shared_ptr<splitter> s=m_sf->create();
                s->split();
            }
        private:
            boost::shared_ptr<splitter_factory> m_sf;
        };
        void test()
        {
            boost::shared_ptr<splitter_factory> sf(new video_splitter_factory());
            boost::shared_ptr<win_form> wf(new win_form(sf));
            wf->click();
        }
    }
	void test()
	{  
        test_design_model_factory::test();
        //test_curl_client::test();
	}

}
#endif

