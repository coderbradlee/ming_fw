#include "include.hpp"

#include "test5.hpp"

int main()
{
	try
	{
		{
			//test_ming_fw();
			//test_spdlog();
			x5::test();
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