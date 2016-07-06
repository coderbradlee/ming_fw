#ifndef TEST7_H
#define	TEST7_H
#include "include.hpp"
#include <string.h>
#include <cstdarg>
#include <iostream>
#include <map>
#include <bitset>
namespace x7
{   using boost::shared_ptr;
	namespace test_design_model_abstract_factory
    {
        class IDBconnection_base
        {
        public:
            virtual bool connection()=0;
            virtual ~IDBconnection_base(){}
        };
        
        class IDBcommand_base
        {
        public:
            virtual bool command()=0;
            virtual ~IDBcommand_base(){}
        };
       
        class IDBconnection:public IDBconnection_base
        {
        public:
            bool connection();
            ~IDBconnection(){}
        };

        class IDBcommand:public IDBcommand_base
        {
        public:
            virtual bool command();
            virtual ~IDBcommand(){}
        };
        class IDB_base_factory
        {
        public:
            virtual shared_ptr<IDBconnection_base> create_connection()=0;
            virtual shared_ptr<IDBcommand_base> create_command()=0;
            virtual ~IDB_base_factory(){}
        };
        class IDB_factory:public IDB_base_factory
        {
        public:
            virtual shared_ptr<IDBconnection_base> create_connection();
            virtual shared_ptr<IDBcommand_base> create_command();            
        };
        class employ
        {
        public:
            employ(shared_ptr<IDB_base_factory> IDB_factory):m_IDB_factory(IDB_factory){}
            void get();
        private:
            shared_ptr<IDB_base_factory> m_IDB_factory;
        };
    }
    namespace test_mysql
    {
      void test();
    }
    void test();
}
#endif

