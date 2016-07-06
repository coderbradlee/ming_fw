#include "mysql_connect.hpp"

void mysql_connect::test()
{
	try 
	{
	  boost::shared_ptr<sql::Driver> drivers;
	  boost::shared_ptr<sql::Connection> con;
	  boost::shared_ptr<sql::Statement> stmt;
	  boost::shared_ptr<sql::ResultSet> res;
	  boost::shared_ptr<sql::PreparedStatement> pstmt;

	  sql::Driver* driver = get_driver_instance();
	  con = boost::shared_ptr<sql::Connection>(driver->connect("tcp://"+get_config->m_mysql_ip+":"+boost::lexical_cast<string>(get_config->m_mysql_port), get_config->m_mysql_username, get_config->m_mysql_password));
	  /* Connect to the MySQL test database */
	  con->setSchema(get_config->m_mysql_database);

	  /* '?' is the supported placeholder syntax */
	  pstmt = boost::shared_ptr<sql::PreparedStatement>(con->prepareStatement("insert into t_currency_daily_exchange_rate values(rand_string(20),'TFTBLZNSNBNAZAZGC2RW','2016','03','11',(?),'2016-03-11','2016-03-11 14:51:05','','','','','',0,1);"));
	  for (int i = 1; i <= 1; i++) 
	  {
	    //pstmt->setInt(1, i);
	    pstmt->setDouble(1, 0.772558);
	    pstmt->executeUpdate();
	  }
	 

	  
	  string query="select * from t_currency_daily_exchange_rate where exchange_rate_id='TFTBLZNSNBNAZAZGC2RW' and createBy='exchange_gw and exchange_date='2016-03-11'";
	  pstmt = boost::shared_ptr<sql::PreparedStatement>(con->prepareStatement(query));
	  res = boost::shared_ptr<sql::ResultSet>(pstmt->executeQuery());

	  while (res->next()) 
	  {
			//ming_log->get_log_console()->info()<< res->getString(1)<<":" << res->getString("exchange_ratio");
		  ming_log->get_log_console()->info()<< res->getString(6)<<":" << res->getString("exchange_ratio");	
	  }
	} 
	catch (sql::SQLException &e) 
	{
	  ming_log->get_log_console()->info()<< "# ERR: " << e.what();
	  ming_log->get_log_console()->info()<< " (MySQL error code: " << e.getErrorCode();
	  ming_log->get_log_console()->info()<< ", SQLState: " << e.getSQLState();
	}

}
