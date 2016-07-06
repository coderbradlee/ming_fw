#include "test7.h"

namespace x7
{
	namespace test_design_model_abstract_factory
    {
        bool IDBconnection::connection()
        {
            ming_log->get_log_console()->info()<<"IDBconnection::connection:"<<__FILE__<<":"<<__LINE__;
        }

        bool IDBcommand::command()
        {
            ming_log->get_log_console()->info()<<"IDBcommand::command:"<<__FILE__<<":"<<__LINE__;
        }

          shared_ptr<IDBconnection_base> IDB_factory::create_connection()
          {
                return shared_ptr<IDBconnection_base>(new IDBconnection());
          }
          shared_ptr<IDBcommand_base> IDB_factory::create_command()
          {
               return shared_ptr<IDBcommand_base>(new IDBcommand());
          }
          void employ::get()
          {
                shared_ptr<IDBconnection_base> c=m_IDB_factory->create_connection();
                c->connection();
                shared_ptr<IDBcommand_base> cc=m_IDB_factory->create_command();
                cc->command();
          }
      
        void test()
        {
            shared_ptr<IDB_base_factory> f(new IDB_factory());
            shared_ptr<employ> e(new employ(f));
            e->get();
        }
    }
    namespace test_mysql
    {
      void test()
      {
        
      }
    }
	void test()
	{  
        //test_design_model_abstract_factory::test();
        test_mysql::test();
	}

}


