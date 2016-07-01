﻿#ifndef TEST3_HPP
#define	TEST3_HPP
#include "include.hpp"
#include <string.h>
#include <cstdarg>
#include <iostream>
#include <map>
#include <bitset>
namespace x3
{
	namespace design_model
	{
    // namespace test_count_ref
    // {
    // 	class base
    // 	{
    // 	public:
    // 		base():m_ref_count(0),m_shareable(true)
    // 		{}
    // 		base(const base& r):m_ref_count(0),m_shareable(true)
    // 		{}
    // 		base& operator=(const base& r)
    // 		{
    // 			return *this;
    // 		}
    // 		virtual ~base()=0;
    // 		//{}
    // 		void add_ref()
    // 		{
    // 			++m_ref_count;
    // 			cout<<"add:"<<m_ref_count<<endl;
    // 		}
    // 		void remove_ref()
    // 		{
    // 			if(--m_ref_count==0) delete this;
    // 			cout<<"remove:"<<m_ref_count<<endl;
    // 		}
    // 		void mark_unshareable()
    // 		{
    // 			m_shareable=false;
    // 			cout<<"mark_unshareable"<<endl;
    // 		}
    // 		bool is_shareable()const
    // 		{
    // 			cout<<"is_shareable"<<endl;
    // 			return m_shareable;
    // 		}
    // 		bool is_shared()const
    // 		{
    // 			cout<<"is_shared"<<endl;
    // 			return m_ref_count>1;
    // 		}
    // 	private:
    // 		int m_ref_count;
    // 		bool m_shareable;
    // 	};
    // 	base::~base(){}
    // 	template<typename T>
    // 	class ptr
    // 	{
    // 	public:
    // 		ptr(T* p=nullptr):m_pointee(p)
    // 		{
    // 			init();
    // 		}
    // 		ptr(const ptr& r):m_pointee(r.m_pointee)
    // 		{
    // 			init();
    // 		}
    // 		~ptr()
    // 		{
    // 			if(m_pointee)
    // 				m_pointee->remove_ref();
    // 		}
    // 		ptr& operator=(const ptr& r)
    // 		{
    // 			if(m_pointee!=r.m_pointee)
    // 			{
    // 				if(m_pointee)
    // 				{
    // 					m_pointee->remove_ref();
    // 				}
    // 				m_pointee=r.m_pointee;
    // 				init();
    // 			}
    // 			return *this;
    // 		}
    // 		T* operator->()const
    // 		{
    // 			return m_pointee;
    // 		}
    // 		T& operator*()const
    // 		{
    // 			return *m_pointee;
    // 		}
    // 	private:
    // 		T* m_pointee;
    // 		void init()
    // 		{
    // 			if(m_pointee==nullptr)
    // 				return;
    // 			if(m_pointee->is_shareable()==false)
    // 				m_pointee=new T(*m_pointee);
    // 			m_pointee->add_ref();
    // 		}
    // 	};
    // 	class string
    // 	{
    // 	public:
    // 		class proxy
    // 		{
    // 		proxy(string& str,int index):m_string(str),m_char_index(index)
    // 		{

    // 		}
    // 		proxy& operator=(const proxy& r)
    // 		{
    // 			if(m_string.m_value->is_shared())
    // 			{
    // 				m_string.m_value=new string_data(m_string.m_value->data);
    // 			}
    // 			//m_string.m_value->mark_unshareable();
    // 			m_string.m_value->data[m_char_index]=r.m_string.m_value->data[r.m_char_index];
    // 			return *this;
    // 		}
    // 		proxy& operator=(char c)
    // 		{
				// if(m_string.m_value->is_shared())
    // 			{
    // 				m_string.m_value=new string_data(m_string.m_value->data);
    // 			}
    // 			//m_string.m_value->mark_unshareable();
    // 			m_string.m_value->data[m_char_index]=c;
    // 			return *this;
    // 		}
    // 		operator char()const
    // 		{
    // 			return m_string.m_value->data[m_char_index];
    // 		}
    // 	private:
    // 		string& m_string;
    // 		int m_char_index;
    // 		};
    // 		string(const char* v):m_value(new string_data(v))
    // 		{
    // 			cout<<"string constructor"<<endl;
    // 		}
    // 		const proxy operator[](int index)const
    // 		{
    // 			cout<<"string operator[]const"<<endl;
    // 			//return m_value->data[index];
    // 			return proxy(const_cast<string&>(*this),index);
    // 		}
    // 		proxy operator[](int index)
    // 		{
    // 			cout<<"string operator[]"<<endl;
    // 			// if(m_value->is_shared())
    // 			// {
    // 			// 	m_value=new string_data(m_value->data);
    // 			// }
    // 			// m_value->mark_unshareable();
    // 			// return m_value->data[index];
    // 			return proxy(*this,index);
    // 		}
    // 		// ostream operator<<(ostream& os)const
    // 		// {
    // 		// 	return os<<m_value->data<<endl;
    // 		// }
    // 		friend inline ostream & operator << (ostream & os, string &t1)
    // 		{  
		  //        cout << t1.m_value->data<< endl;  
		  //        return os; 
		  //   }
		  //   friend class proxy;
    // 	private:
    // 		struct  string_data:public base
    // 		{
    // 			char *data;
    // 			string_data(const char* v)
    // 			{
    // 				data=new char[strlen(v)+1];
    // 				strcpy(data,v);
    // 				cout<<"string_data constructor"<<endl;
    // 			}
    // 			string_data(const string_data& r)
    // 			{
    // 				data=new char[strlen(r.data)+1];
    // 				strcpy(data,r.data);
    // 				cout<<"string_data copy"<<endl;
    // 			}
    // 			~string_data()
    // 			{
    // 				delete[] data;
    // 				cout<<"~string_data"<<endl;
    // 			}
    // 		};
    // 		ptr<string_data> m_value;
    		
    // 	};
    // 	void test()
    // 	{
    // 		string x("hello");
    // 		cout<<"----------------------"<<endl;
    // 		string y=x;
    // 		cout<<"----------------------"<<endl;
    // 		string z("wo");
    // 		cout<<"----------------------"<<endl;
    // 		z=y;
    // 		cout<<"----------------------"<<endl;
    // 		z[1]='l';
    // 		cout<<"----------------------"<<endl;
    // 		cout<<x<<endl;
    // 		cout<<y<<endl;
    // 		cout<<z<<endl;
    // 	}
    // }
    namespace test_auto_ptr
    {
        template<typename T>
        class auto_ptr
        {
            template<typename U> friend class auto_ptr;
        public:
            explicit auto_ptr(T* p=nullptr):m_pointee(p)
            {}
            template<class U>
            auto_ptr(auto_ptr<U>& r):m_pointee(r.release())
            {}
            ~auto_ptr()
            {
                delete m_pointee;
            }
            template<class U>
            auto_ptr<T>& operator=(auto_ptr<U>& r)
            {
                if(this!=&r)
                    reset(r.release());
                return *this;
            }
            T& operator*()const
            {
                return *m_pointee;
            }
            T* operator->()const
            {
                return m_pointee;
            }
            T* get()const
            {
                return m_pointee;
            }
            T* release()
            {
                T* old=m_pointee;
                m_pointee=nullptr;
                return old;
            }
            void reset(T* p=nullptr)
            {
                if(m_pointee!=p)
                    delete m_pointee;
                m_pointee=p;
            }

        private:
            T* m_pointee;
            
        };
        class b
        {};
        class d:public b 
        {};     
        void test()
        {
            auto_ptr<int> p(new int(5));
            cout<<*p<<endl;
            auto_ptr<b> pb(new d());

        }
    }
    namespace test_operator_new_and_delete
    {
        class bad{};
        class  base
        {
        public:
             base():m_id(0)
             {
                cout<<"base default constructor,this="<<this<<" id="<<m_id<<endl;
             }
             base(int i):m_id(i)
             {
                cout<<"base constructor,this="<<this<<" id="<<m_id<<endl;
                throw bad();
             }
            ~ base()
            {
                cout<<"base destructor,this="<<this<<" id="<<m_id<<endl;
            }
            void *operator new(size_t size)
            {
                base* p=(base*)malloc(size);
                cout<<"operator new:"<<size<<endl;
                return p;
            }
            void *operator new[](size_t size)
            {
                base* p=(base*)malloc(size);
                cout<<"operator new[]:"<<size<<endl;
                return p;
            }
            void operator delete(void* v,size_t size)
            {
                cout<<"operator delete:"<<size<<endl;
                free(v);
            }
            void operator delete[](void* v,size_t size)
            {
                cout<<"operator delete[]:"<<size<<endl;
                free(v);
            }
            /////////////////////////
            void* operator new(size_t size,void *start)
            {
                return start;
            }
            void* operator new(size_t size,long extra)
            {
                return malloc(size+extra);
            }
            void* operator new(size_t size,long extra,char init)
            {
                return malloc(size+extra);
            }
            // void* operator new(long extra,char init)
            // {}
            
            void operator delete(void*,void*)
            {
                cout<<"operator delete(void*,void*)"<<endl;
            }
            void operator delete(void*,long)
            {
                cout<<"operator delete(void*,long)"<<endl;
            }
            void operator delete(void*,long,char)
            {
                cout<<"operator delete(void*,long,char)"<<endl;
            }
        private:
            int m_id;
            long m_data;
            string m_str;
        };
        void test()
        {
            // cout<<"sizeof string="<<sizeof(string)<<endl;
            // cout<<"sizeof base="<<sizeof(base)<<endl;
            // base* p=new base(7);
            // delete p;

            // base* p_array=new base[5];
            // delete[] p_array;

            // base* p=::new base(7);
            // ::delete p;
            // base* p_array=::new base[5];
            // ::delete[] p_array;
            base start;
            base* p1=new base;
            base* p2=new(&start)base;
            base* p3=new(100)base;
            base* p4=new(100,'a')base;
            //base* p5=new(100)base(1);
            //base* p6=new(100,'a')base(1);
            //base* p7=new(&start)base(1);
            base* p8=new base(1);
        }
    }
    namespace test_function_pointer
    {
        float func(int, int); 
        float func(int a, int b)
        {     
            return (float)(a + b); 
        }
        void test()
        {     
            float (*pf)(int, int);     
            pf = func;    
             printf("%fn", pf(1, 2));   
             cout<<endl;  
             printf("%.16Xn", (uint64_t)(pf));   cout<<endl;   
             printf("%.16Xn", (uint64_t)(func));  cout<<endl;    
             printf("%.16Xn", (uint64_t)(&func)); cout<<endl;     
             printf("%.16Xn", (uint64_t)(&pf));cout<<endl; 
             
        }

    }
    namespace test_string_reference_counting
    {
        void test()
        {
            string test1="12345";
            string test2=test1;
            char* p=&test1[3];
            *p='5';
            cout<<test1<<endl;
            cout<<test2<<endl;
        }
        
    }
    namespace test_object_reference_counting
    {
        class rc_object
        {
        public:
            rc_object():m_ref_count(0),m_shareable(true)
            {
                cout<<"rc_object::rc_object():"<<this<<":"<<m_ref_count<<endl;
                cout<<"rc_object::rc_object():"<<this<<":"<<m_shareable<<endl;
            }
            rc_object(const rc_object& r):m_ref_count(0),m_shareable(true)
            {
                cout<<"rc_object::rc_object(const rc_object& r):"<<this<<":"<<m_ref_count<<endl;
                cout<<"rc_object::rc_object(const rc_object& r):"<<this<<":"<<m_shareable<<endl;
            }
            rc_object& operator=(const rc_object& r)
            {
                cout<<"3:"<<this<<":"<<m_ref_count<<endl;
                cout<<"3:"<<this<<":"<<m_shareable<<endl;
                return *this;
            }
            virtual ~rc_object()
            {
                cout<<"rc_object::~rc_object():"<<this<<":"<<m_ref_count<<endl;
                cout<<"rc_object::~rc_object():"<<this<<":"<<m_shareable<<endl;
            }
            void add_ref()
            {
                ++m_ref_count;
                cout<<"rc_object::add_ref():"<<this<<":"<<m_ref_count<<endl;
                cout<<"rc_object::add_ref():"<<this<<":"<<m_shareable<<endl;
            }
            void remove_ref()
            {
                if(--m_ref_count==0) delete this;
                cout<<"rc_object::remove_ref():"<<this<<":"<<m_ref_count<<endl;
                cout<<"rc_object::remove_ref():"<<this<<":"<<m_shareable<<endl;
            }
            void set_unshareable()
            {
                m_shareable=false;
                cout<<"rc_object::set_unshareable():"<<this<<":"<<m_ref_count<<endl;
                cout<<"rc_object::set_unshareable():"<<this<<":"<<m_shareable<<endl;
            }
            bool get_shareable()const
            {
                return m_shareable;
            }
            bool is_shared()const
            {
                return m_ref_count>1;
            }
        private:
            int m_ref_count;
            bool m_shareable;
        };
        template<typename T>
        class rc_pointer
        {
        public:
            rc_pointer(T* rc_pointer=nullptr):m_pointee(rc_pointer)
            {
                cout<<"rc_pointer::rc_pointer():"<<this<<":"<<endl;
                init();
            }
            rc_pointer(const rc_pointer& r):m_pointee(r.m_pointee)
            {
                cout<<"rc_pointer::rc_pointer(const rc_pointer& r):"<<this<<":"<<endl;
                init();
            }
            ~rc_pointer()
            {

                cout<<"rc_pointer::~rc_pointer():"<<this<<":"<<endl;
                if(m_pointee)
                    m_pointee->remove_ref();
            }
            rc_pointer& operator=(const rc_pointer& r)
            {
                cout<<"rc_pointer::operator=:"<<this<<":"<<endl;
                if(m_pointee!=r.m_pointee)
                {
                    if(m_pointee)
                    {
                        m_pointee->remove_ref();
                    }
                    m_pointee=r.m_pointee;
                    init();
                }
                return *this;
            }
            T* operator->()const
            {
                return m_pointee;
            }
            T& operator*()const
            {
                return *m_pointee;
            }
        private:
            T* m_pointee;
            void init()
            {
                cout<<"rc_pointer::init():"<<this<<":"<<endl;
                if(m_pointee==nullptr)
                    return;
                if(m_pointee->get_shareable()==false)
                    m_pointee=new T(*m_pointee);
                m_pointee->add_ref();
            }
        };
        class string
        {
            class char_proxy
            {
            public:
                char_proxy(string& str,int index):m_string(str),m_char_index(index)
                {
                    cout<<"char_proxy::char_proxy():"<<this<<":"<<endl;
                }
                char_proxy& operator=(const char_proxy& r)
                {
                    cout<<"char_proxy::operator=():"<<this<<":"<<endl;
                    if (m_string.m_value->is_shared()) 
                    {
                        m_string.m_value = new string_data(m_string.m_value->m_data);
                    }
                       
                        m_string.m_value->m_data[m_char_index] =
                        r.m_string.m_value->m_data[r.m_char_index];
                        return *this;
                }
                char_proxy& operator=(char c)
                {
                    cout<<"char_proxy::operator=(char c):"<<this<<":"<<endl;
                    if (m_string.m_value->is_shared()) 
                    {
                        m_string.m_value = new string_data(m_string.m_value->m_data);
                    
                    }
                        m_string.m_value->m_data[m_char_index] = c;
                        return *this;
                }
                operator char()const
                {
                    cout<<"char_proxy::operator char()const:"<<this<<":"<<endl;
                    return m_string.m_value->m_data[m_char_index];
                }
            private:
                string& m_string;
                int m_char_index;
            };
        public:

            string(const char* value=""):m_value(new string_data(value))
            {
                cout<<"string::string():"<<this<<":"<<value<<endl;
            }
            const char_proxy operator[](int index)const
            {
                cout<<"string::operator[]()const:"<<this<<":"<<endl;
                //return m_value->m_data[index];
                return char_proxy(const_cast<string&>(*this),index);
            }
            char_proxy operator[](int index)
            {
                cout<<"string::operator[]():"<<this<<":"<<endl;
                // cout<<"string::operator[]:"<<this<<":"<<endl;
                // if(m_value->is_shared())
                // {
                //     m_value=new string_data(m_value->m_data);
                // }
                // m_value->set_unshareable();
                // return m_value->m_data[index];
                return char_proxy(*this,index);
            }
            void print()
            {
                cout<<m_value->m_data<<endl;

            }
            
            friend class char_proxy;
        private:
            struct  string_data:public rc_object
            {
                char* m_data;
                string_data(const char* data)
                {
                    cout<<"string_data::string_data():"<<this<<":"<<endl;
                    init(data);
                }
                string_data(const string_data& r)
                {
                    cout<<"string_data::string_data(const string_data& r):"<<this<<":"<<endl;
                    init(r.m_data);
                }
                void init(const char* data)
                {
                    cout<<"string_data::init():"<<this<<":"<<endl;
                    m_data=new char[strlen(data)+1];
                    strcpy(m_data,data);
                }
                ~string_data()
                {
                    cout<<"string_data::~string_data():"<<this<<":"<<endl;
                    delete[] m_data;
                }
            };
            rc_pointer<string_data> m_value;
        };
        void test()
        {
            string t="xx";
            cout<<"#############################"<<endl;
            string pt=t;
            //t.print();
            cout<<"-----------------"<<endl;
            //pt.print();
            //cout<<"-----------------"<<endl;
            pt[1]='y';
            //t[1]='y';
            //pt.print();
            cout<<"-----------------"<<endl;
            cout<<pt[1]<<endl;
            cout<<"-----------------"<<endl;
        }
    }
    namespace test_twofold_virtual
    {
        class game_object
        {
        public:
            virtual void collide(game_object& other)=0;
            // virtual void collides(space_ship& other)=0;
            // virtual void collides(space_station& other)=0;
            // virtual void collides(asteroid& other)=0;
        };
       
        class space_station:public game_object
        {
        public:
            void collide(game_object& other)
            {

            }
        };
        class asteroid:public game_object
        {
        public:
            void collide(game_object& other)
            {

            }
        };
        
        class space_ship:public game_object
        {
            typedef void(space_ship::*hit_func)(game_object&);
            typedef std::map<string,hit_func> hit_func_map;
        public:
            virtual void collide(game_object& other)
            {
                cout<<"space_ship virtual void collide(game_object& other)"<<endl;
                //other.collide(*this);
                hit_func h=lookup(other);
                if(h)
                {
                    (this->*h)(other);
                }
            }
            virtual void space_ship_collides(game_object& other)
            {
                cout<<"space_ship virtual void collides(space_ship& other)"<<endl;
                space_ship& o=dynamic_cast<space_ship&>(other);

            }
            virtual void space_station_collides(game_object& other)
            {
                cout<<"space_ship virtual void collides(space_station& other)"<<endl;
            }
            virtual void asteroid_collides(game_object& other)
            {
                cout<<"space_ship virtual void collides(asteroid& other)"<<endl;
            }
            
            static hit_func_map *init_map()
            {
                hit_func_map* h=new hit_func_map;
                (*h)["space_ship"]=&space_ship::space_ship_collides;
                (*h)["space_station"]=&space_ship::space_station_collides;
                (*h)["asteroid"]=&space_ship::asteroid_collides;
                // for(auto& c:(*h))
                // {
                //     cout<<c.first<<":"<<c.second<<endl;
                // }
            }
            
            
            static hit_func lookup(const game_object& what)
            {
                std::shared_ptr<hit_func_map> collision_map(init_map());
                int status;
                const std::type_info  &ti = typeid(what);
                string realname_ful = abi::__cxa_demangle(ti.name(), 0, 0, &status);
                //cout<<realname_ful<<endl;
                std::vector<std::string> ymd;
                boost::split(ymd,realname_ful , boost::is_any_of("::"));
                string realname=ymd[ymd.size()-1];
                //cout<<realname<<endl;
                for(auto& c:(*collision_map))
                {                    
                    if(c.first==realname)
                    {
                        return c.second;
                    }
                }
            }
        };
        void test()
        {
            space_ship s;
            space_station ss;
            game_object& sss=ss;
            s.collide(sss);
        }
    }
    namespace test_template_const
    {
        const int & max(const int &a,const int &b)
        {
            return a>b?a:b;
           //return x;
        }
        const std::string& foo(const std::string& temp)
        {
                return temp;
        }

        
        void test()
        {
            int x;
            x=max(1,2);
            cout<<x<<endl;
            const std::string& ref = foo("abcde");
            std::cout << ref << std::endl;
        }
    }
    namespace test_lifetime
    {
        class T {}; // trivial
        struct B 
        {
            B()
            {
                cout<<"B"<<endl;
            }
            ~B() 
            {
                cout<<"~B"<<endl;
            } // non-trivial
        };
        void x() 
        {
            long long n; // automatic, trivial
            new (&n) double(3.14); // reuse with a different type okay
        } // okay
        //const B b;
        //cout<<"--------------------"<<endl;
        class Base
       {
           public:
             
                virtual void Bar()const { cout << "base bar()" << endl; }
       };
       
       class DerOne: public Base
       {
          public:
          
             virtual void Bar()const { cout << "DerOne Bar()" << endl; }
      };
      
      class DerTwo: public Base
      {
          public:
              
             virtual void Bar()const { cout << "DerTwo Bar()" << endl; }
      };
      Base GetBase()
      {
          return Base();
      }
      
       DerOne GetDerOne()
      {
           return DerOne();
      }
      
      DerTwo GetDerTwo()
      {
           return DerTwo();
      }
        void test()
         {
            B b; // automatic non-trivially destructible
            cout<<"--------1------------"<<endl;
            b.~B(); // end lifetime (not required, since no side-effects)
            cout<<"--------2------------"<<endl;
//            new (&b) T; // wrong type: okay until the destructor is called

            new (const_cast<B*>(&b)) const B; 
            cout<<"--------3------------"<<endl;   

              // const Base& ref1=GetBase();
              // const Base& ref2=GetDerOne();
              // const Base& ref3=GetDerTwo();
          
              const Base& ref1(Base{});
              const Base& ref2(DerOne{});
              const Base& ref3(DerTwo{});
              ref1.Bar();
              ref2.Bar();
              ref3.Bar();
        } // destructor 
    }
    namespace test_coroutine
    {

        void test5()
        {
            boost::coroutines::asymmetric_coroutine<int>::push_type sink( // constructor does NOT enter coroutine-function
                [&](boost::coroutines::asymmetric_coroutine<int>::pull_type& source)
                {
                    for (int i:source) 
                    {
                        std::cout << i <<endl;;
                    }
                });

            std::vector<int> v{1,2,3,4,5};
            cout<<"---------------"<<endl;
            for( int i:v)
            {
                cout<<"======================="<<endl;
                sink(i); // push {i} to coroutine-function
            }
        }
        void test4()
        {
            boost::coroutines::asymmetric_coroutine<int>::pull_type source( // constructor enters coroutine-function
            [&](boost::coroutines::asymmetric_coroutine<int>::push_type& sink)
            {
                for(int i=0;i<6;++i)
                {
                    cout<<i<<endl;
                    sink(i);
                }
                // cout<<
                // sink(1); // push {1} back to main-context
                // sink(2); // push {1} back to main-context
                // sink(3); // push {2} back to main-context
                // sink(4); // push {3} back to main-context
                // sink(5); // push {5} back to main-context
                // sink(6); // push {8} back to main-context
            });
            cout<<"--------------"<<endl;
            while(source)
            {            // test if pull-coroutine is valid
                cout<<":"<<endl;
                int ret=source.get(); // access data value
                source();             // context-switch to coroutine-function
                cout<<"main:"<<ret<<endl;
            }
        }
        void test3()
        {
            struct FinalEOL
            {
                ~FinalEOL()
                {
                    //std::cout << std::endl;
                    cout<<"~~"<<endl;
                }
            };

        const int num=5, width=10;
        boost::coroutines::asymmetric_coroutine<std::string>::push_type writer(
            [&](boost::coroutines::asymmetric_coroutine<std::string>::pull_type& in)
            {
                cout<<"enter pull function"<<endl;
                // finish the last line when we leave by whatever means
                FinalEOL eol;
                // pull values from upstream, lay them out 'num' to a line
                for (;;)
                {
                    for(int i=0;i<num;++i)
                    {
                        // when we exhaust the input, stop
                        if(!in) return;
                        std::cout << std::setw(width) << in.get();
                        // now that we've handled this item, advance to next
                        in();
                    }
                    // after 'num' items, line break
                    std::cout <<" ::"<< std::endl;
                }
            });

        std::vector<std::string> words
        {
            "peas", "porridge", "hot", "peas",
            "porridge", "cold", "peas", "porridge",
            "in", "the", "pot", "nine",
            "days", "old" 
        };

        std::copy(boost::begin(words),boost::end(words),boost::begin(writer));
        }
        void test2()
        {
            boost::coroutines::asymmetric_coroutine<int>::pull_type source(
            [&](boost::coroutines::asymmetric_coroutine<int>::push_type& sink)
            {
                cout<<"reenter push_type"<<endl;
                int first=1,second=1;
                sink(first);
                sink(second);
                for(int i=0;i<8;++i)
                {
                    //cout<<i<<":"<<first<<":"<<second<<endl;
                    int third=first+second;
                    first=second;
                    second=third;
                    sink(third);
                }
            });

            for(auto i:source)
            {
                std::cout << i <<  " ";
            }

        }
        void test1()
        {
            typedef boost::coroutines::symmetric_coroutine< void >  coro_t;
            coro_t::call_type * other1 = 0;
            coro_t::call_type * other2 = 0;

            coro_t::call_type coro1(
                [&]( coro_t::yield_type & yield) {
                    std::cout << "foo1" << std::endl;
                    yield( * other2);
                    std::cout << "foo2" << std::endl;
                    yield( * other2);
                    std::cout << "foo3" << std::endl;
                });
            coro_t::call_type coro2(
                [&]( coro_t::yield_type & yield) {
                    std::cout << "bar1" << std::endl;
                    yield( * other1);
                    std::cout << "bar2" << std::endl;
                    yield( * other1);
                    std::cout << "bar3" << std::endl;
                });

            other1 = & coro1;
            other2 = & coro2;

            coro1();

            std::cout << "Done" << std::endl;
        }
        void test6()
        {
            boost::coroutines::asymmetric_coroutine<boost::tuple<int,int>>::push_type sink(
                [&](boost::coroutines::asymmetric_coroutine<boost::tuple<int,int>>::pull_type& source)
                {
                    // access tuple {7,11}; x==7 y==1
                    int x,y;
                    boost::tie(x,y)=source.get();
                    cout<<x<<":"<<y<<endl;
                });
            cout<<"-------------------"<<endl;
            sink(boost::make_tuple(7,11));
        }
        void test7()
        {
            struct X 
            {
                X()
                {
                    std::cout<<"X()"<<std::endl;
                }

                ~X()
                {
                    std::cout<<"~X()"<<std::endl;
                }
            };

            {
                boost::coroutines::asymmetric_coroutine<void>::push_type sink(
                    [&](boost::coroutines::asymmetric_coroutine<void>::pull_type& source)
                    {
                        X x;
                        for(int i=0;;++i)
                        {
                            std::cout<<"fn(): "<<i<<std::endl;
                            // transfer execution control back to main()
                            source();
                        }
                    });

                sink();
                sink();
                sink();
                sink();
                sink();

                std::cout<<"sink is complete: "<<std::boolalpha<<!sink<<"\n";
            }
        }
        void test8()
        {
            int number=2,exponent=8;
            boost::coroutines::asymmetric_coroutine< int >::pull_type source(
                [&]( boost::coroutines::asymmetric_coroutine< int >::push_type & sink)
                {
                    int counter=0,result=1;
                    while(counter++<exponent)
                    {
                        result=result*number;
                        sink(result);
                        cout<<result<<endl;
                    }
                });
            cout<<"---------------------"<<endl;
            for (auto i:source)
            {
                std::cout << i <<  ":";
            }    
            cout<<"======================"<<endl;
        }
        void test9()
        {
            boost::coroutines::asymmetric_coroutine<int>::push_type sink(
            [&](boost::coroutines::asymmetric_coroutine<int>::pull_type& source)
            {
                while(source)
                {
                    std::cout << source.get() <<  " ";
                    source();
                }
                cout<<":"<<endl;
            });
            cout<<"----------------"<<endl;
            std::vector<int> v{1,2,3,4,5};
            std::copy(boost::begin(v),boost::end(v),boost::begin(sink));
        }
        void test10()
        {
            boost::coroutines::symmetric_coroutine<int>::call_type coro( // constructor does NOT enter coroutine-function
            [&](boost::coroutines::symmetric_coroutine<int>::yield_type& yield)
            {
                for (;;) 
                {
                    std::cout << yield.get() <<  " ";
                    yield(); // jump back to starting context
                }
            });
            cout<<"-------------"<<endl;
            coro(11); // transfer {1} to coroutine-function
            coro(22); // transfer {2} to coroutine-function
            coro(33); // transfer {3} to coroutine-function
            coro(44); // transfer {4} to coroutine-function
            coro(55); // transfer {5} to coroutine-function
        }
        void test()
        {
            struct X 
            {
                X(){
                    std::cout<<"X()"<<std::endl;
                }

                ~X(){
                    std::cout<<"~X()"<<std::endl;
                }
            };

            boost::coroutines::symmetric_coroutine<int>::call_type other_coro([&](boost::coroutines::symmetric_coroutine<int>::yield_type& yield)
            {
                for (;;) 
                {
                    std::cout << yield.get() <<  " ";
                    yield(); // jump back to starting context
                 }
            });

            {
                boost::coroutines::symmetric_coroutine<void>::call_type coro(
                    [&](boost::coroutines::symmetric_coroutine<void>::yield_type& yield)
                    {
                        X x;
                        std::cout<<"fn()"<<std::endl;
                        // transfer execution control to other coroutine
                        int xx=7;
                        yield( other_coro, xx);
                    });

                coro();

                std::cout<<"coro is complete: "<<std::boolalpha<<!coro<<"\n";
            }
        }
    }
    namespace test_traits
    {
        template<typename T> inline T sigma(const T* start,const T* end)
        {
            T total=T();
            while(start!=end)
            {
                total+=*start++;
            }
            return total;
        }
        
        template<typename T>
        class sigma_traits{};
        template<>
        class sigma_traits<char>
        {
        public:
            typedef int return_type;
        };
        template<>
        class sigma_traits<short>
        {public:
            typedef int return_type;
        };
        template<>
        class sigma_traits<int>
        {public:
            typedef long return_type;
        };
        template<>
        class sigma_traits<unsigned int>
        {public:
            typedef unsigned long return_type;
        };
        template<>
        class sigma_traits<float>
        {public:
            typedef double return_type;
        };
        template<typename T> inline typename sigma_traits<T>::return_type sigma2(const T* start,const T* end)
        {
            typedef typename sigma_traits<T>::return_type return_type;
            return_type total=return_type();
            while(start!=end)
            {
                total+=*start++;
            }
            return total;
        }
        void test()
        {
            char c[]="abc";
            size_t l=strlen(c);
            char *p=c;
            char *q=c+l;
            cout<<(int)sigma<char>(p,q)<<endl;
            cout<<sigma2<char>(p,q)<<endl;
        }
    }
    namespace test_vector
    {
        void test()
        {
            cout<<sizeof(string)<<endl;
            cout<<sizeof(wstring)<<endl;
            std::vector<std::wstring> v;
            v.reserve(10);
            v.push_back(L"test");
            try
            {
                std::wstring ws1=v[0];
                wstring ws2=v.at(3);
                wcout<<ws1<<endl;
                cout<<sizeof(ws1)<<endl;
                cout<<sizeof(L"test")<<endl;
                cout<<sizeof(L"测试")<<endl;
                cout<<sizeof("test")<<endl;
                cout<<sizeof("测试")<<endl;
            }
            catch(const std::exception& ex)
            {
                cout<<ex.what()<<endl;
            }
        }
    }
    namespace test_remove_if
    {
        class remove_condition:public std::unary_function<wstring,bool>
        {
        public:
            remove_condition(const wstring& w):m_w(w)
            {
                wcout<<"constructor:"<<w<<endl;
            }
            bool operator()(const wstring& w)const
            {
                wcout<<"operator():"<<w<<endl;
                return w.find(m_w)!=-1;
            }
            wstring m_w;
        };
        void print(const std::list<wstring>& v)
        {
            for(const auto& i:v)
            {
                wcout<<i<<endl;
            }
        }
        void test()
        {
            std::list<std::wstring> v;
            //v.reserve(10);
            v.push_back(L"test1");
            v.push_back(L"test2");
            v.push_back(L"test3");
            v.push_back(L"test4");
            v.push_back(L"aa");
            //print(v);
            //v.erase(remove_if(v.begin(),v.end(),remove_condition(L"test")),v.end());
            //v.erase(remove_if(v.begin(),v.end(),[](wstring m_w){return m_w.find(L"test")!=-1;}),v.end());
            cout<<"---------------------------"<<endl;
            print(v);
            cout<<"---------------------------"<<endl;
            std::list<std::wstring> u;
            //u.reserve(10);
            u.push_back(L"a");
            u.push_back(L"b");
            u.push_back(L"c");
            u.push_back(L"d");
            u.push_back(L"e");
            print(u);
            v.splice(v.begin(),u);
            cout<<"---------------------------"<<endl;
            print(v);
            cout<<"---------------------------"<<endl;
            print(u);
            list<wstring>::const_iterator it=v.begin();
            advance(it,3);
            //u.splice(u.begin(),v,it);
            
            v.splice(v.begin(),u,it,v.end());
            cout<<"---------------------------"<<endl;
            print(v);
            cout<<"---------------------------"<<endl;
            print(u);
        }
    }
    namespace test_set
    {
        class people
        {
        public:

            people(const string& name,const size_t id):m_name(name),m_id(id)
            {
                cout<<"constructor"<<endl;
            }
            const string& get_name()const
            {
                return m_name;
            }
            const size_t get_id()const
            {
                return m_id;
            }
            bool set_name(const string& name)
            {
                m_name=name;
            }
            bool set_id(const size_t id)
            {
                m_id=id;
            }
        private:
            string m_name;
            size_t m_id;
        };
        struct people_comparer:public binary_function<people,people,bool>
        {
            bool operator()(const people& p1,const people& p2)const
            {
                return p1.get_id()<p2.get_id();
            }
        };
        void print(const set<people,people_comparer>& s)
        {
            for(const auto& i:s)
            {
                cout<<i.get_id()<<":"<<i.get_name()<<endl;
            }
            cout<<"-----------------"<<endl;
        }
        void test()
        {
            people people_array[3]=
            {
                people("a",1),
                people("b",2),
                people("c",3)
            };
            set<people,people_comparer> ps(people_array,people_array+3);
            set<people,people_comparer> ps1;
            ps1.insert(people("c",3));
            ps1.insert(people("d",4));
            print(ps);
            print(ps1);
            set<people,people_comparer> dest;
            insert_iterator<set<people,people_comparer>> ii(dest,dest.begin());
            // set_union(ps.begin(),ps.end(),ps1.begin(),ps1.end(),ii,people_comparer());
            // print(dest);
            // set_intersection(ps.begin(),ps.end(),ps1.begin(),ps1.end(),ii,people_comparer());
            // print(dest);
            set_difference(ps.begin(),ps.end(),ps1.begin(),ps1.end(),ii,people_comparer());
            print(dest);
            set<people,people_comparer>::iterator it=dest.find(people("b",2));
            if(it!=dest.end())
            {
                //const_cast<people&>(*it).set_name("bb");
                //static_cast<people>(*it).set_name("bb");
                ((people)(*it)).set_name("bb");
            }
            print(dest);
        }
    }
    namespace test_function_object
    {
        void test()
        {
            std::greater<int> g;
            cout<<boolalpha<<g(10,3)<<endl;
            cout<<greater<int>()(100,300)<<endl;
        }
    }
    namespace test_locale
    {
        void test2()
        {
             using namespace boost::locale;
            using namespace std;

            generator gen;
            // Make system default locale global
            std::locale loc = gen("");
            locale::global(loc); 
            cout.imbue(loc);
            

           string text="Hello World! あにま! Linux2.6 and Windows7 is word and number. שָלוֹם עוֹלָם!";

            cout<<text<<endl;

            boundary::ssegment_index index(boundary::word,text.begin(),text.end());
            boundary::ssegment_index::iterator p,e;

            for(p=index.begin(),e=index.end();p!=e;++p) {
                cout<<"Part ["<<*p<<"] has ";
                if(p->rule() & boundary::word_number)
                    cout<<"number(s) ";
                if(p->rule() & boundary::word_letter)
                    cout<<"letter(s) ";
                if(p->rule() & boundary::word_kana)
                    cout<<"kana character(s) ";
                if(p->rule() & boundary::word_ideo)
                    cout<<"ideographic character(s) ";
                if(p->rule() & boundary::word_none)
                    cout<<"no word characters";
                cout<<endl;
            }

            index.map(boundary::character,text.begin(),text.end());

            for(p=index.begin(),e=index.end();p!=e;++p) {
                cout<<"|" <<*p ;
            }
            cout<<"|\n\n";

            index.map(boundary::line,text.begin(),text.end());

            for(p=index.begin(),e=index.end();p!=e;++p) {
                cout<<"|" <<*p ;
            }
            cout<<"|\n\n";

            index.map(boundary::sentence,text.begin(),text.end());

            for(p=index.begin(),e=index.end();p!=e;++p) {
                cout<<"|" <<*p ;
            }
            cout<<"|\n\n";
            
        }
        void test1()
        {
            using namespace boost::locale;
            using namespace std;
            generator gen;
            locale loc=gen(""); 
            // Create system default locale

            locale::global(loc); 
            // Make it system global
            
            cout.imbue(loc);
            // Set as default locale for output
            
            cout <<format("Today {1,date} at {1,time} we had run our first localization example") % time(0) 
                  <<endl;
           
            cout<<"This is how we show numbers in this locale "<<as::number << 103.34 <<endl; 
            cout<<"This is how we show currency in this locale "<<as::currency << 103.34 <<endl; 
            cout<<"This is typical date in the locale "<<as::date << std::time(0) <<endl;
            cout<<"This is typical time in the locale "<<as::time << std::time(0) <<endl;
            cout<<"This is upper case "<<to_upper("Hello World!")<<endl;
            cout<<"This is lower case "<<to_lower("Hello World!")<<endl;
            cout<<"This is title case "<<to_title("Hello World!")<<endl;
            cout<<"This is fold case "<<fold_case("Hello World!")<<endl;
        }
        void test()
        {
            using namespace boost::locale;

            generator gen;
            std::locale::global(gen(""));
            std::cout.imbue(std::locale());
            // Setup environment

            boost::locale::date_time now;

            date_time start=now;

            // Set the first day of the first month of this year
            start.set(period::month(),now.minimum(period::month()));
            start.set(period::day(),start.minimum(period::day()));

            int current_year = period::year(now);


            // Display current year
            std::cout << format("{1,ftime='%Y'}") % now << std::endl;

            //
            // Run forward untill current year is the date
            //
            for(now=start; period::year(now) == current_year;) {

                // Print heading of month
                if(calendar().is_gregorian()) 
                    std::cout << format("{1,ftime='%B'}") % now <<std::endl;
                else
                    std::cout << format("{1,ftime='%B'} ({1,ftime='%Y-%m-%d',locale=en} - {2,locale=en,ftime='%Y-%m-%d'})")
                        % now 
                        % date_time(now,now.maximum(period::day())*period::day()) << std::endl;

                int first = calendar().first_day_of_week();

                // Print weeks days
                for(int i=0;i<7;i++) {
                    date_time tmp(now,period::day_of_week() * (first + i));
                    std::cout << format("{1,w=8,ftime='%a'} ") % tmp;
                }
                std::cout << std::endl;

                int current_month = now / period::month();
                int skip = now / period::day_of_week_local() - 1;
                for(int i=0;i<skip*9;i++)
                    std::cout << ' ';
                for(;now / period::month() == current_month ;now += period::day()) {
                    std::cout << format("{1,w=8,ftime='%e'} ") % now;     
                    if(now / period::day_of_week_local() == 7)
                        std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
    namespace test_string_size
    {
        class test_string
        {
          struct _Rep_base
          {
            int*       _M_length;
            int*       _M_capacity;
            int*        _M_refcount;
          };
          struct _Alloc_hider
          {
            int* _M_p; // The actual data.
          };
          mutable _Alloc_hider  _M_dataplus;
          _Rep_base t;
        };
        void test()
        {
            cout<<sizeof(string)<<endl;
            string s("adfaf");
            cout<<sizeof(s)<<endl;
            cout<<sizeof(test_string)<<endl;
        }

    }
    namespace test_test
    {
        void test()
        {
            int *a=new int(10);
            int *b=new int(20);
            cout<<"a="<<hex<<a<<endl;
            cout<<"b="<<hex<<b<<endl;
            a=(int*)(b-a);
            cout<<"a="<<hex<<a<<endl;
            b=(int*)(b-(long)a);
            cout<<"b="<<hex<<b<<endl;
            a=(int*)(b+(long)a);
            cout<<"a="<<hex<<a<<endl;
            cout<<*a<<endl;
            cout<<*b<<endl;
        }
    }
    namespace test_asio_post
    {
        boost::mutex cs;
        void func(int i)
        {
            
            boost::mutex::scoped_lock lc(cs);
            cout<<i<<endl;
        }
        void test()
        {   
            boost::asio::io_service io;
            boost::asio::io_service::strand one(io),two(io);
            for(int i=0;i<5;++i)
            {
                //io.post(one.wrap(boost::bind(func,i)));
                one.post(boost::bind(func,i));
                //one.wrap(boost::bind(func,i));
                //one.dispatch(boost::bind(func,i));
            }
            //io.post(one);
            // for(int i=5;i<10;++i)
            // {
            //     io.post(two.wrap(boost::bind(func,i)));
            // }
            boost::thread_group th;
            for(int i=0;i<4;++i)
                th.create_thread([&](){io.run();});
            boost::this_thread::sleep(boost::posix_time::millisec(2000));
            th.join_all();
        }
    }
    namespace test_strand_io
    {
        boost::mutex global_stream_lock;  
  
        void WorkerThread( boost::shared_ptr< boost::asio::io_service > io_service )  
        {  
            global_stream_lock.lock();  
            std::cout << "[" << boost::this_thread::get_id()  
                << "] Thread Start" << std::endl;  
            global_stream_lock.unlock();  
          
            io_service->run();  
          
            global_stream_lock.lock();  
            std::cout << "[" << boost::this_thread::get_id()  
                << "] Thread Finish" << std::endl;  
            global_stream_lock.unlock();  
        }  
          
        void Dispatch( int x )  
        {  
            global_stream_lock.lock();  
            std::cout << "[" <<  boost::this_thread::get_id()  << "] "   
                << __FUNCTION__  << " x = " << x <<  std::endl;  
            global_stream_lock.unlock();  
        }  
          
        void Post( int x )  
        {  
            global_stream_lock.lock();  
            std::cout << "[" <<  boost::this_thread::get_id()  << "] "   
                << __FUNCTION__  << " x = " << x <<  std::endl;  
            global_stream_lock.unlock();  
        }  
          
        void Run3( boost::shared_ptr< boost::asio::io_service > io_service )  
        {  
            for( int x = 0; x < 3; ++x )  
            {  
                io_service->post( boost::bind( &Post, x * 2 + 1 ) ); 
                io_service->dispatch( boost::bind( &Dispatch, x * 2 ) );  
                 
                //boost::this_thread::sleep( boost::posix_time::milliseconds( 1000 ) );  
            }  
        }  
        void test()
        {
            boost::shared_ptr< boost::asio::io_service > io_service(   
                new boost::asio::io_service  
            );  
            boost::shared_ptr< boost::asio::io_service::work > work(  
                new boost::asio::io_service::work( *io_service )  
            );  
          
            global_stream_lock.lock();  
            std::cout << "[" <<  boost::this_thread::get_id()    
                << "] The program will exit when all  work has finished." <<  std::endl;  
            global_stream_lock.unlock();  
          
            boost::thread_group worker_threads;  
            for( int x = 0; x < 5; ++x )  
            {  
                worker_threads.create_thread( boost::bind( &WorkerThread, io_service ) );  
            }  
          
            io_service->post( boost::bind( &Run3, io_service ) );  
          
            work.reset();  
          
            worker_threads.join_all();  
        }
    }
    namespace test_strand_io2
    {

    }
    namespace test_salary
    {
        void test()
        {
            float  base=14000;
            float final=base*0.825-((base*0.825-3500)*0.2-555);
            cout<<final<<endl;
            float x=14000,y;
            float before_tax=x-y*0.105-x*0.07;
            before_tax=11600.60;
            y=(x*0.93-before_tax)/0.105;
            cout<<y<<endl;
            float tax=(before_tax-3500)*0.2-555;
            cout<<tax<<endl;
            float changed=before_tax-tax;
            cout<<changed<<endl;

            

        }
    }
	void test()
	{
		
		//test_count_ref::test();
        //test_auto_ptr::test();
		//test_operator_new_and_delete::test();
        //test_function_pointer::test();
        //test_string_reference_counting::test();
        //test_object_reference_counting::test();
        //test_twofold_virtual::test();
        //test_template_const::test();
        //test_lifetime::test();
        //test_coroutine::test();
        //test_traits::test();
        //test_vector::test();
        //test_remove_if::test();
        //test_set::test();
        //test_function_object::test();
        //test_locale::test();
        //test_string_size::test();
        //test_test::test();
        //test_asio_post::test();
        //test_strand_io::test();
        //test_strand_io::test();
        test_salary::test();
	}
}
}
#endif	/* PAYPAL_HPP */

