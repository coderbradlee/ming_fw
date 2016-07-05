#ifndef CURL_CLIENT_HPP
#define	CURL_CLIENT_HPP
#include "include.hpp"
#include <curl/curl.h>
#include <string.h>
#include <cstdarg>
#include <iostream>
#include <map>
#include <cstdio>

class curl_client:boost::noncopyable
{
public:
	curl_client(const std::string& url);
	virtual ~curl_client();
	
	void request(const std::string& method, 
		const std::string& path, 
		const std::string& param, 
		const std::string& content);
	
	string get_data();
	long int get_status();
	long int get_length();
protected:

	static size_t request_callback(
		char *buffer, 
		size_t size, 
		size_t nmemb, 
		void* thisPtr);
	size_t request_write_data(const char *buffer, size_t size, size_t nmemb);

	void curl(
		const std::string& uri, 
		const std::string& method = "GET",
		const std::string& param = "", 
		const std::string& content = "");
	
	void set_url(const std::string& url) const;
	bool on_request();
	static int close_socket_callback(void *clientp, curl_socket_t item);
	void process_content();
	
public:
	std::string m_data;
protected:	
	CURL* m_curl;
	std::string m_url;
	static CURLSH* share_handle;	
	long int m_request_status;
	// boost::asio::streambuf m_content_buffer;
	// std::istream m_content;
};


#endif	/* curl_client_HPP */

