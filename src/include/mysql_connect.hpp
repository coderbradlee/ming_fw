#ifndef MYSQL_CONNECT_HPP
#define	MYSQL_CONNECT_HPP
#include "include.hpp"
#include "mysql_connection.h"
#include "config.hpp"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
struct mysql_info
 {
 	string ip;
 	string port;
 	string username;
 	string password;
 	string data_base;
 }; 

class mysql_connect
{
public:
	mysql_connect(boost::shared_ptr<mysql_info> in);
	void test();
private:
	boost::shared_ptr<sql::Driver> m_drivers;
	boost::shared_ptr<sql::Connection> m_con;
	boost::shared_ptr<sql::Statement> m_stmt;
	boost::shared_ptr<sql::ResultSet> m_res;
	boost::shared_ptr<sql::PreparedStatement> m_pstmt;
	sql::Driver* m_driver;
	boost::shared_ptr<mysql_info> m_mysql_info;
};
void test();

#endif