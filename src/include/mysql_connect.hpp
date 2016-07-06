#ifndef MYSQL_CONNECT_HPP
#define	MYSQL_CONNECT_HPP
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
class mysql_connect
{
public:
	void test();
};
#endif