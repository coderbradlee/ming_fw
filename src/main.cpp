#include "config.hpp"

#include "test5.hpp"
#include "example_spdlog.h"
int main()
{
	try
	{
		{
			test_spdlog();
			//x5::test();
			//this_thread::sleep_for(chrono::seconds(10));
			//test1();
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