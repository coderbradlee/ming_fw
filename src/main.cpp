#include "include.hpp"

#include "test7.h"

int main()
{
	try
	{
		{
			//test_ming_fw();
			//test_spdlog();
			//x7::test();
			//this_thread::sleep_for(chrono::seconds(10));
			//test1();
			mysql_connect m;
			m.test();
		}
		

	}
	catch (std::exception& e)
	{
		//cout << diagnostic_information(e) << endl;
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "unknown error" << endl;
	}
	return 0;
}