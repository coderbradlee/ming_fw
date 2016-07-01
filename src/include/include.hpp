#ifndef INCLUDE_HPP
#define	INCLUDE_HPP

#include <curl/curl.h>
#include <string.h>
#include <cstdarg>
#include <iostream>
#include <map>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <boost/regex.hpp>
#include <boost/bind.hpp>
#include <list>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/lexical_cast.hpp>
#include <condition_variable>
#include <assert.h>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
//#include <activemq/core/ActiveMQConnection.h> // put "mman.h" after "activemq/core/ActiveMQConnection.h"solve define conflict of MAP_TYPE 
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>
#include <boost/timer/timer.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>  
#include <boost/archive/iterators/binary_from_base64.hpp>  
#include <boost/archive/iterators/transform_width.hpp>
//Added for the default_resource example
#include <fstream>
//#include <boost/asio/yield.hpp>
#include <boost/asio/coroutine.hpp>

//#include "mysql/mysql_api.hpp"
#include <boost/date_time/gregorian/gregorian.hpp>   
#include <boost/any.hpp>
#include <regex>
#include <unordered_map>
#include <thread>
#include <functional>
#include <memory>
#include <boost/enable_shared_from_this.hpp>  
#include <boost/shared_ptr.hpp>  
#include <boost/bind.hpp>  
#include <boost/function.hpp>  
#include <boost/asio.hpp>
//#include <boost/asio/spawn.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/signals2/deconstruct.hpp>
#include <boost/asio/signal_set.hpp>
#include <csignal>
#define BOOST_DATE_TIME_SOURCE  
#define BOOST_SPIRIT_THREADSAFE 
using namespace boost::asio;
using namespace std;
using namespace boost::property_tree;
using namespace boost::posix_time;
#include <limits.h>
#include <sstream>
#include <boost/assign/list_of.hpp>
#include <boost/lexical_cast.hpp>

// #include "json_spirit/json_spirit_reader.h"
// #include "json_spirit/json_spirit_value.h" 
// #include "json_spirit/json_spirit_writer.h" 
// #include "json_spirit/json_spirit_reader_template.h"
// #include "json_spirit/json_spirit_writer_template.h"
// #define JSON_SPIRIT_VALUE_ENABLED
#define BOOST_SPIRIT_THREADSAFE 
#include "json_map.hpp"
#include "json_fifo_map.hpp"
#include <boost/random.hpp>
#include <boost/nondet_random.hpp>
#include <boost/coroutine/all.hpp>
#include <boost/locale.hpp>
#include <iostream>
#include <cassert>
#include <ctime>
//////////reduce compile time
// #include <boost/asio/impl/src.hpp>
// #define BOOST_ASIO_SEPARATE_COMPILATION
#endif

