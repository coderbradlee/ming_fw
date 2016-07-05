
#include "curl_client.hpp"

	curl_client::curl_client(const std::string& url) : m_url(url),m_request_status(0)
	{
		//register callback
		//register_callback();
		curl_global_init(CURL_GLOBAL_ALL);
		m_curl = curl_easy_init();
		curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1);
		curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this);
		
#ifdef DEBUG
		curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1);
#endif
		//curl(m_download_url, "GET", filename, true);

		if (!share_handle)
		{
			share_handle = curl_share_init();
			curl_share_setopt(share_handle, CURLSHOPT_SHARE, CURL_LOCK_DATA_DNS);
		}
		curl_easy_setopt(m_curl, CURLOPT_SHARE, share_handle);
		curl_easy_setopt(m_curl, CURLOPT_DNS_CACHE_TIMEOUT, 600 * 5);
		curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, 200 );
		curl_easy_setopt(m_curl, CURLOPT_CONNECTTIMEOUT,300);
	}
	curl_client::~curl_client()
	{
		curl_easy_cleanup(m_curl);
		curl_global_cleanup();
	}
	void curl_client::request(const std::string& method, 
		const std::string& path, 
		const std::string& param, 
		const std::string& content)
	{
		/////////////////////////////////////
		ming_log->get_log_console()->info()<<"request:"<<method<<":"<<path<<":"<<param<<":"<<content;
		
        ming_log->get_log_file()->info()<<"request:"<<method<<":"<<path<<":"<<param<<":"<<content;
		/////////////////////////////////////////////////////
		//t_currency_exchange_rate 
		curl(path, method, param, content);
	}
	string curl_client::get_data()
	{
		return m_data;
	}
	long int curl_client::get_status()
	{
		return m_request_status;
	}
	long int curl_client::get_length()
	{
		return m_data.length();
	}

	size_t curl_client::request_callback(
		char *buffer, 
		size_t size, 
		size_t nmemb, 
		void* thisPtr)
	{
		if (thisPtr)
		{
			//cout << __LINE__ << endl;
			return ((curl_client*)thisPtr)->request_write_data(buffer, size, nmemb);
		}

		else
		{
			//cout << __LINE__ << endl;
			return 0;
		}

	}
	size_t curl_client::request_write_data(const char *buffer, size_t size, size_t nmemb)
	{
		int result = 0;
		if (buffer != 0)
		{
			//cout << __LINE__ << endl;
			//m_data.clear();
			m_data.append(buffer, size * nmemb);
			// response->content.read(&buffer[0], length);
            // content.write(&buffer[0], length);
            //m_content.read(buffer,size * nmemb)
			// cout<<"m_data:"<<m_data.size()<<endl;
			// cout<<"max_size:"<<m_data.max_size() <<endl;
			// cout<<"capacity:"<<m_data.capacity()<<endl;
			result = size * nmemb;
			// boost::asio::streambuf write_buffer;

		}
		return result;
	}

	void curl_client::curl(
		const std::string& uri, 
		const std::string& method,
		const std::string& param, 
		const std::string& content)
	{
		set_url(m_url + uri + "?" + param);
		//cout << __LINE__ << ":" << uri << endl;

#ifdef DEBUG
		curl_easy_setopt(m_curl, CURLOPT_HEADER, 1);
#endif
		curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, request_callback);
		curl_easy_setopt(m_curl, CURLOPT_MAXREDIRS, 50L);
		curl_easy_setopt(m_curl, CURLOPT_TCP_KEEPALIVE, 1L);
		curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, method.c_str());

		//curl_easy_setopt(m_curl, CURLOPT_NOPROGRESS,0L);
		curl_easy_setopt(m_curl, CURLOPT_CLOSESOCKETFUNCTION, close_socket_callback);

		curl_easy_setopt(m_curl, CURLOPT_CLOSESOCKETDATA, this);
		curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, content.c_str());

  		curl_easy_setopt(m_curl, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)content.length());
		if(on_request())
		{
			if(CURLE_OK==curl_easy_getinfo(m_curl, CURLINFO_RESPONSE_CODE,&m_request_status))
			{
				ming_log->get_log_console()->info()<<"get status success";
				//ming_log->get_log_file()->info()<<"get status success";
			}
		}

	}
	void curl_client::set_url(const std::string& url) const
	{
		curl_easy_setopt(m_curl, CURLOPT_URL, url.c_str());
		//ming_log->get_log_console()->info()<<url<<":"<<__FILE__<<":"<<__LINE__;
		//cout<<url<<":"<<__FILE__<<":"<<__LINE__<<endl;
	}
	bool curl_client::on_request()
	{
		m_data.clear();
		return 0 == curl_easy_perform(m_curl);
	}
	int curl_client::close_socket_callback(void *clientp, curl_socket_t item)
	{
		if (clientp)
		{
			//cout << __LINE__ << endl;
			((curl_client*)clientp)->process_content();
		}

	}
	void curl_client::process_content()
	{

		//cout<<*m_data<<":"<<__FILE__<<":"<<__LINE__<<endl;		
	}

CURLSH* curl_client::share_handle = NULL;


