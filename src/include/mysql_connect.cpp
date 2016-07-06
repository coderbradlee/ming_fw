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

	  /* Create a connection */
	  //driver = boost::shared_ptr<sql::Driver>(/*sql::mysql::*/get_driver_instance());
	  sql::Driver* driver = get_driver_instance();
	  con = boost::shared_ptr<sql::Connection>(driver->connect("tcp://"+get_config->m_mysql_ip+":"+boost::lexical_cast<string>(get_config->m_mysql_port), get_config->m_mysql_username, get_config->m_mysql_password));
	  /* Connect to the MySQL test database */
	  con->setSchema(get_config->m_mysql_database);

	  // stmt = con->createStatement();
	  // stmt->execute("DROP TABLE IF EXISTS test");
	  // stmt->execute("CREATE TABLE test(id INT)");
	  // delete stmt;

	  /* '?' is the supported placeholder syntax */
	  // pstmt = con->prepareStatement("INSERT INTO test(id) VALUES (?)");
	  // for (int i = 1; i <= 10; i++) {
	  //   pstmt->setInt(1, i);
	  //   pstmt->executeUpdate();
	  // }
	  // delete pstmt;

	  /* Select in ascending order */
	  //pstmt = con->prepareStatement("SELECT id FROM test ORDER BY id ASC");
	  // res = pstmt->executeQuery();

	  // /* Fetch in reverse = descending order! */
	  // res->afterLast();
	  // while (res->previous())
	  //   cout << "\t... MySQL counts: " << res->getInt("id") << endl;
	  // delete res;

	  // delete pstmt;
	  // delete con;
	  string query="select * from t_currency_daily_exchange_rate where exchange_rate_id='UCFB3WJQ5MSOX5CJDNXD' and createBy='exchange_gw'";
	  pstmt = boost::shared_ptr<sql::PreparedStatement>(con->prepareStatement(query));
	  res = boost::shared_ptr<sql::ResultSet>(pstmt->executeQuery());

	  while (res->next()) 
	  {
			ming_log->get_log_console()->info()<< "\t... MySQL replies: " << res->getString("_message");
			ming_log->get_log_console()->info()<< "\t... say it again, MySQL";
			ming_log->get_log_console()->info()<< "\t....MySQL replies: " << res->getString(1);
		}
	} 
	catch (sql::SQLException &e) 
	{
	  ming_log->get_log_console()->info()<< "# ERR: " << e.what();
	  ming_log->get_log_console()->info()<< " (MySQL error code: " << e.getErrorCode();
	  ming_log->get_log_console()->info()<< ", SQLState: " << e.getSQLState() << " )";
	}

}
