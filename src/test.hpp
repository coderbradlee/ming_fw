#ifndef TEST_HPP
#define	TEST_HPP
#include "include.hpp"
#include <string.h>
#include <cstdarg>
#include <iostream>
#include <map>
#include <bitset>
namespace x
{
	void rotate(std::vector<std::vector<string>>& vec)
	{
		for (int layer = 0; layer < 6 / 2; ++layer)
		{
			int first = layer;
			int last = 6 - 1 - layer;
			for (int i = first; i < last; ++i)
			{
				/*int offset = i - first;
				string top = vec[first][i];
				vec[first][i] = vec[last - offset][first];
				vec[last - offset][first] = vec[last][last - offset];
				vec[last][last - offset] = vec[i][last];
				vec[i][last] = top;*/
				string top = vec[first][i];
				vec[first][i] = vec[last - i][first];
				vec[last - i][first] = vec[last][last - i];
				vec[last][last - i] = vec[i][last];
				vec[i][last] = top;
			}
		}
	}
	void print(std::vector<std::vector<string>> vec)
	{
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				cout << vec[i][j] << " ";
			}
			cout << endl;
		}
	}
	void test()
	{
		std::vector<std::vector<string>> vec(6);
		for (int i = 0; i < 6; ++i)
			vec[i].resize(6);
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
				vec[i][j] = boost::lexical_cast<string>(i)+boost::lexical_cast<string>(j);
		}
		print(vec);
		rotate(vec);
		cout << "==================================" << endl;
		print(vec);
	}

	class tree
	{	
	public:
		tree(int data) :data(data), left(nullptr), right(nullptr)
		{}
		int data;
		boost::shared_ptr<tree> left;
		boost::shared_ptr<tree> right;
	};
	bool covers(boost::shared_ptr<tree> root, boost::shared_ptr<tree> p)
	{
		if (root == nullptr) return false;
		if (root == p) return true;
		return covers(root->left, p) || covers(root->right, p);
	}
	boost::shared_ptr<tree> common_ancestor_helper(boost::shared_ptr<tree> root, boost::shared_ptr<tree> p, boost::shared_ptr<tree> q)
	{
		if (root == nullptr) return nullptr;
		if (root == p || root == q) return root;
		bool p_in_left = covers(root->left, p);
		bool q_in_left = covers(root->left, q);

		if (p_in_left != q_in_left) return root;
		else
		{
			boost::shared_ptr<tree> child = p_in_left ? root->left : root->right;
			return common_ancestor_helper(child, p, q);
		}
	}
	boost::shared_ptr<tree> common_ancestor(boost::shared_ptr<tree> root, boost::shared_ptr<tree> p, boost::shared_ptr<tree> q)
	{
		if (!covers(root, p) || !covers(root, q))
			return nullptr;
		return common_ancestor_helper(root, p, q);
	}
	void mid_travel(boost::shared_ptr<tree> root)
	{
		if (root == nullptr)
		{
			cout << "root is nullptr" << endl;
		}
		else
		{
			mid_travel(root->left);
			cout << root->data << endl;
			mid_travel(root->right);
		}
	}
	void test_tree()
	{
		//�������Ϊ��123654
		boost::shared_ptr<tree> node1 = boost::shared_ptr<tree>(new tree(1));
		boost::shared_ptr<tree> node3 = boost::shared_ptr<tree>(new tree(3));
		boost::shared_ptr<tree> node4 = boost::shared_ptr<tree>(new tree(4));
		
		boost::shared_ptr<tree> node2 = boost::shared_ptr<tree>(new tree(2));
		node2->left = node1;
		node2->right = node3;
		boost::shared_ptr<tree> node6 = boost::shared_ptr<tree>(new tree(6));
		node6->left = node2;
		boost::shared_ptr<tree> node5 = boost::shared_ptr<tree>(new tree(5));
		node6->right = node5;
		node5->right = node4;

		mid_travel(node6);
		boost::shared_ptr<tree> test1=common_ancestor(node6, node1, node3);
		cout << test1->data << endl;
		boost::shared_ptr<tree> test2=common_ancestor(node6, node3, node4);
		cout << test2->data << endl;
		boost::shared_ptr<tree> test3 = common_ancestor(node6, node4, node5);
		cout << test3->data << endl;
		boost::shared_ptr<tree> test4 = common_ancestor(node6, node2, node3);
		cout << test4->data << endl;
	}
	int length(int x)
	{
		int ret = 0;
		while(x > 0)
		{
			ret++;
			x=x >> 1;
			//cout << __LINE__ << ":"<<x << endl;
		}
		return ret;
	}
	void merge_bit(int n, int m, int j, int i)
	{
		int space = j - i + 1;
		int len = length(m);
		/*int min = len <space ? len : space;
		cout << "len:" << len << endl;
		cout << "min:" << min << endl;*/
		int mask = 0;
		for (int i = 0; i < space; ++i)
			mask += (i +1)* 2;
		n &= ~mask;
		cout << "n:" << hex << n << endl;
		int temp = m << (j-len+1);
		cout << "temp:" << hex << temp << endl;
		cout << hex << n + temp << endl;
	}
	int update_bit(int n, int m, int i, int j)
	{
		int all = ~0;
		int left = all << (j + 1);
		int right = ((1 << i) - 1);
		int mask = left | right;
		int clear = n&mask;
		int shift = m << i;
		return clear | shift;
	}
	void test_merge_bit()
	{
		//01101100 010 3 1 ������100
		//merge_bit(108, 2, 3, 1);
		merge_bit(0x400, 0x13, 6, 2);
		cout << hex << update_bit(0x400, 0x13, 2, 6) << endl;
	}
	void test_bit_set()
	{
		auto str1 = "0011";
		auto str2 = "0110";
		bitset<10> one(str1);
		bitset<10> two(str2);
		auto three = one&two;
		cout << three << endl;
		three <<= 4;
		cout << three << endl;
	}

	void test_nlohmann_fifo_map()
	{
		using json = nlohmann_fifo_map::json;
		 json j =
	    {
	        {"pi", 3.141},
	        {"happy", true},
	        {"name", "Niels"},
	        {"nothing", nullptr},
	        {
	            "answer", {
	                {"everything", 42}
	            }
	        },
	        {"list", {1, 0, 2}},
	        {
	            "object", {
	                {"currency", "USD"},
	                {"value", 42.99}
	            }
	        }
	    };

	    // add new values
	    j["new"]["key"]["value"] = {"another", "list"};

	    // count elements
	    j["size"] = j.size();

	    // pretty print with indent of 4 spaces
	    std::cout << j << '\n';
	}
}
namespace brad
{ 
	//geekband homework1
	class Date
	{
		public:
		Date(int year,int month,int day):m_year(year),m_month(month),m_day(day)
		{
		
		}
		int get_year() const
		{
			return m_year;
		}
		int get_month() const
		{
			return m_month;
		}
		int get_day() const
		{
			return m_day;
		}
		void print() const
		{
			cout<<m_year<<"-"<<setw(2)<< setfill ('0')<<m_month<<"-"<<setw(2)<< setfill ('0')<<m_day<<endl;
		}
		private:
		int m_year;
		int m_month;
		int m_day;	
	};

	inline bool operator<(const Date& l,const Date& r)
	{
		//return 	(l.get_year()<r.get_year())||(l.get_month()<r.get_month())||(l.get_day()<r.get_day());
		if(l.get_year()>r.get_year())
		{
			return false;
		}
		else if(l.get_year()<r.get_year())
		{
			return true;
		}
		else if(l.get_month()>r.get_month())
		{
			return false;
		}
		else if(l.get_month()<r.get_month())
		{
			return true;
		}
		else if(l.get_day()>=r.get_day())
		{
			return false;
		}
		else
		{	
			return true;
		}

	}
	inline bool operator==(const Date& l,const Date& r)
	{
		return (l.get_year()==r.get_year())&&(l.get_month()==r.get_month())&&(l.get_day()==r.get_day());
	}
	inline bool operator>(const Date& l,const Date& r)
	{
		return ~(l<r||l==r);
	}
	int get_random_int(int head, int tail) 
	{  
	    static std::default_random_engine e{std::random_device{}()}; 
	    static std::uniform_int_distribution<int> u;  
	  
	    return u(e, decltype(u)::param_type(head, tail));  
	}
	 class comp
	 {
	 public:
	     bool operator() (const Date &a , const Date  &b) const
	     {
	         return a<b;
	     }
	}; 
	std::vector<Date> CreatePoints()
	{
		std::vector<Date> v;
		for(int i=0;i<10;++i)
		{
			v.push_back(Date(get_random_int(1900,2099),get_random_int(1,12),get_random_int(1,31)));
		}
		return v;
	}
	void Sort(std::vector<Date>& v)
	{
		//std::map<Date,int,comp> m;
		std::map<Date,int> m;
		int i=0;
		for(auto& date:v)
		{
			m.emplace(std::make_pair(date,i++));
		}
		v.clear();

		for(auto& date:m)
		{
			v.push_back(date.first);
		}
	} 
	void test()
	{
		std::vector<brad::Date> v=brad::CreatePoints();
			for(auto& d:v)
			{
				d.print();
			}
			cout<<"--------------------"<<endl;
			brad::Sort(v);
			for(auto& d:v)
			{
				d.print();
			}

	}
}
namespace effective_cplusplus
{
	template<typename T>
	class reference_class
	{
	public:
		reference_class(std::string& name,const T& value):m_name(name),m_value(value){}
		void print()
		{
			cout<<m_name<<":"<<m_value<<endl;
		}
		reference_class& operator=(const reference_class& r)
		{
			m_name=r.m_name;
			m_value=r.m_value;
		}
	private:
		std::string& m_name;
		T m_value;
	};
	void test()
	{
		std::string ps="p";
		std::string ss="s";
		reference_class<int> p(ps,1);
		reference_class<int> s(ss,2);
		reference_class<string> twostring(ss,"2");
		//twostring.print();
		//p=twostring;
		p=s;
		p.print();
	}
}
namespace design_model
{
	namespace proto_type_model
	{
		class proto_type
		{
		protected:
			proto_type()
			{
				cout<<"proto_type"<<endl;
			}
		public:
			virtual proto_type* clone()const=0;
			virtual ~proto_type()
			{
				cout<<"~proto_type"<<endl;
			}
		};
		class concrete1:public proto_type
		{
		public:
			concrete1()
			{
				cout<<"concrete1"<<endl;
			}
			~concrete1()
			{
				cout<<"~concrete1"<<endl;
			}
			concrete1(const concrete1&)
			{
				cout<<"concrete1 copy constructor"<<endl;
			}
			virtual concrete1* clone()const
			{
				return new concrete1(*this);
			}
		};
		class concrete2:public proto_type
		{
		public:
			concrete2()
			{
				cout<<"concrete2"<<endl;
			}
			~concrete2()
			{
				cout<<"~concrete2"<<endl;
			}
			concrete2(const concrete2&)
			{
				cout<<"concrete2 copy constructor"<<endl;
			}
			virtual concrete2* clone()const
			{
				return new concrete2(*this);
			}
		};
		void test()
		{
			proto_type* p1=new concrete1();
			proto_type* p2=p1->clone();
			cout<<"-----------------------"<<endl;
			delete p1;
			delete p2;
		}
	}
	namespace adapter
	{
		namespace way1
		{
		class target
		{
		public:
			target()
			{
				cout<<"target constructor"<<endl;
			}
			virtual ~target()
			{
				cout<<"target destructor"<<endl;
			}
			virtual void request()
			{
				cout<<"target request"<<endl;
			}
		};
		class adaptee
		{
		public:
			adaptee()
			{
				cout<<"adaptee constructor"<<endl;
			}
			~adaptee()
			{
				cout<<"adaptee destructor"<<endl;
			}
			void specific_request()
			{
				cout<<"adaptee specific request"<<endl;
			}
		};
		class adapter:public target,private adaptee
		{
		public:
			adapter()
			{
				cout<<"adapter constructor"<<endl;
			}
			~adapter()
			{
				
				cout<<"adapter destructor"<<endl;
			}
			void request()
			{
				specific_request();
				cout<<"adapter request"<<endl;
			}
		};
	}
	namespace way2
	{
		class target
		{
		public:
			target()
			{
				cout<<"target constructor"<<endl;
			}
			virtual ~target()
			{
				cout<<"target destructor"<<endl;
			}
			virtual void request()
			{
				cout<<"target request"<<endl;
			}
		};
		class adaptee
		{
		public:
			adaptee()
			{
				cout<<"adaptee constructor"<<endl;
			}
			~adaptee()
			{
				cout<<"adaptee destructor"<<endl;
			}
			void specific_request()
			{
				cout<<"adaptee specific request"<<endl;
			}
		};
		class adapter:public target
		{
		public:
			adapter(adaptee* ade):m_ade(ade)
			{
				cout<<"adapter constructor"<<endl;
			}
			~adapter()
			{
				
				cout<<"adapter destructor"<<endl;
			}
			void request()
			{
				m_ade->specific_request();
				cout<<"adapter request"<<endl;
			}
		private:
			adaptee* m_ade;
		};
	}
		void test()
		{
			//way1::adaptee* ade=new adaptee;
			way1::target* adt1=new way1::adapter();
			adt1->request();
			delete adt1;
			cout<<"================================="<<endl;
			way2::adaptee* ade=new way2::adaptee;
			way2::target* adt2=new way2::adapter(ade);
			adt2->request();
			delete adt2;
		}
	}
	namespace observer_space
	{
		class subject;
		class observer
		{
		public:
			virtual ~observer()
			{
				cout<<"~observer"<<endl;
			}
			virtual void update(subject* sub)=0;
			virtual void print_info()=0;
		protected:
			observer()
			{
				//m_state=nullptr;
			}
			string m_state;
		};
		class subject
		{
		public:
			virtual ~subject()
			{
				delete m_observers;
			}
			virtual void attach(observer* obv)
			{
				m_observers->push_back(obv);
			}
			virtual void detach(observer* obv)
			{
				if(obv!=nullptr)
					m_observers->remove(obv);
			}
			virtual void notify()
			{
				for(auto& m:*m_observers)
				{
					m->update(this);
				}
			}
			virtual void set_state(const string& state)=0;
			virtual string get_state()=0;
		protected:
			subject()
			{
				m_observers=new std::list<observer*>;
			}
		private:
			std::list<observer*>* m_observers;
		};

		class concrete_subject:public subject
		{
		public:
			concrete_subject()
			{
				//m_state=nullptr;
			}
			~concrete_subject(){}
			string get_state()
			{
				return m_state;
			}
			void set_state(const string& state)
			{
				m_state=state;
			}
		private:
			string m_state;
		};
		
		class concrete_observer1:public observer
		{
		public:
			virtual subject* get_subject()
			{
				return m_sub;
			}
			concrete_observer1(subject* sub)
			{
				m_sub=sub;
				m_sub->attach(this);
			}
			virtual ~concrete_observer1()
			{
				m_sub->detach(this);
				if(m_sub!=nullptr)
					delete m_sub;
			}
			void update(subject* sub)
			{
				m_state=sub->get_state();
				print_info();
			}
			void print_info()
			{
				cout<<"concrete_observer1:"<<m_sub->get_state()<<endl;
			}
		private:
			subject* m_sub;
		};
		class concrete_observer2:public observer
		{
		public:
			virtual subject* get_subject()
			{
				return m_sub;
			}
			concrete_observer2(subject* sub)
			{
				m_sub=sub;
				m_sub->attach(this);
			}
			virtual ~concrete_observer2()
			{
				m_sub->detach(this);
				if(m_sub!=nullptr)
					delete m_sub;
			}
			void update(subject* sub)
			{
				m_state=sub->get_state();
				print_info();
			}
			void print_info()
			{
				cout<<"concrete_observer2:"<<m_sub->get_state()<<endl;
			}
		private:
			subject* m_sub;
		};
		
		void test()
		{
			concrete_subject* sub=new concrete_subject();
			observer* o1=new concrete_observer1(sub);
			observer* o2=new concrete_observer2(sub);
			sub->set_state("old");
			sub->notify();
			sub->set_state("new");
			sub->notify();
			
			// delete o1;
			// delete o2;
			// delete sub;
		}
	}
	namespace composite
	{
		class component
		{
		public:

			component(){}
			virtual ~component(){}
			virtual void operation()=0;
			virtual void add(const component&){}
			virtual void remove(const component&){}
			virtual component* get_child(int)
			{
				return 0;
			}
		};
		class composite:public component
		{
		public:
			composite(){}
			~composite(){}
			void operation()
			{
				for(auto& m:m_component_vector)
				{
					m->operation();
				}
			}
			void add(component* com)
			{
				m_component_vector.push_back(com);
			}
			void remove(component* com)
			{
				//m_component_vector.erase(com);
			}
			component* get_child(int index)
			{
				return m_component_vector[index];
			}
		private:
			std::vector<component*> m_component_vector;
		};
		class leaf:public component
		{
		public:
			leaf(){}
			~leaf(){}
			void operation()
			{
				cout<<"leaf operation"<<endl;
			}
		};
		void test()
		{
			leaf* l=new leaf();
			l->operation();
			composite* com=new composite();
			com->add(l);
			com->operation();
			component* ll=com->get_child(0);
			ll->operation();
		}
	}
	namespace prototype
	{
		enum image_type
		{
			LSAT,SPOT
		};
		class image
		{
		public:
			virtual void draw()=0;
			static image* find_clone(image_type type)
			{
				for(auto& x:m_proto_type)
				{
					if(x->return_type()==type)
						return x->clone();
				}
			}
		protected:
			virtual image_type return_type()=0;
			virtual image* clone()=0;
			static void add_proto_type(image* image)
			{
				m_proto_type[m_next_slot++]=image;
			}
		private:
			static std::vector<image*> m_proto_type;
			static int m_next_slot; 
		};
		std::vector<image*> image::m_proto_type(8, nullptr);

		int image::m_next_slot=0;
		class land_image:public image
		{
		public:
			image_type return_type()
			{
				return LSAT;
			}
			void draw()
			{
				cout<<"land_image draw"<<m_id<<endl;
			}
			image* clone()
			{
				return new land_image(1);
			}
		protected:
			land_image(int dummy)
			{
				m_id=m_count++;
			}
		private:
			static land_image m_land_image;
			land_image()
			{
				add_proto_type(this);
			}
			int m_id;
			static int m_count;
		};
		land_image land_image::m_land_image;
		int land_image::m_count=1;
		class spot_image:public image
		{
		public:
			image_type return_type()
			{
				return SPOT;
			}
			void draw()
			{
				cout<<"spot image draw"<<m_id<<endl;
			}
			image* clone()
			{
				return new spot_image(1);
			}
		protected:
			spot_image(int dummy)
			{
				m_id=m_count++;
			}
		private:
			spot_image()
			{
				add_proto_type(this);
			}
			static spot_image m_spot_image;
			int m_id;
			static int m_count;
		};
		spot_image spot_image::m_spot_image;
		int spot_image::m_count=1;
		void test()
		{
			const int NUM=8;
			image_type input[NUM]=
			{LSAT,LSAT,LSAT,SPOT,LSAT,SPOT,SPOT,LSAT};
			std::vector<image*> images(NUM, nullptr);
			for(int i=0;i<NUM;++i)
			{
				images[i]=image::find_clone(input[i]);
			}
			for(int i=0;i<NUM;++i)
			{
				images[i]->draw();
			}
			for(int i=0;i<NUM;++i)
			{
				delete images[i];
			}

		}
	}
    namespace test_reset_and_swap
    {
    	class Shape
		{  
		public: 
			Shape():no(0)
			{}
			Shape(int n):no(n)
			{} 
			int get_no()const
			{
				return no;
			}
		private:                
		   int no;
		};              
		class Point
		{
		   int x;
		   int y;
		public:
		   int get_x()const
		   {
		      return x;
		   }
		   int get_y()const
		   {
		      return y;
		   }
		   Point(int x,int y):x(x),y(y)
		   {
		   		cout<<"point constructor"<<endl;
		   }
		   ~Point()
		   {
		   		cout<<x<<":"<<y<<":point destructor"<<endl;
		   }
		};              
		class Rectangle: public Shape
		{
		   int width;
		   int height;
		   std::shared_ptr<Point> leftUp;
		public:
		   Rectangle(int width, int height, int x, int y):width(width),height(height),leftUp(new Point(x,y)),Shape(10)
			{

			}
		   Rectangle(const Rectangle& other)
		   {
		   	width=other.width;
			height=other.height;
			leftUp=std::shared_ptr<Point>((new Point(other.leftUp->get_x(),other.leftUp->get_y())));
		   }
		   Rectangle& operator=(const Rectangle& other)
		   {
				if(this==&other)
					return *this;
				width=other.width;
				height=other.height;
				cout<<"before reset"<<endl;
				leftUp.reset(new Point(other.leftUp->get_x(),other.leftUp->get_y()));
				cout<<"after reset"<<endl;
				return *this;
		   }
		   ~Rectangle()
		   {}         
		   void print()
		   {
		   	cout<<width<<":"<<height<<":"<<leftUp->get_x()<<":"<<leftUp->get_y()<<":"<<get_no()<<endl;
		   }

		};

    	void test()
    	{
    		Rectangle test(1,2,3,4);
			Rectangle test_copy(test);
			Rectangle test_assignment(5,6,7,8);
			test_assignment=test_copy;
			cout<<"============================"<<endl;
			test.print();
			test_copy.print();
			test_assignment.print();
    	}
    }
    namespace test_override
    {
    	class base
    	{
    	private:
    		int x;
    	public:
    		virtual void mf1()=0;
    		virtual void mf1(int x)
    		{
    			cout<<"base::mf1"<<x<<endl;
    		}
    		virtual void mf2()
    		{
    			cout<<"base::mf2"<<endl;
    		}
    		void mf3()
    		{
    			cout<<"base::mf3"<<endl;
    		}
    		void mf3(double x)
    		{
    			cout<<"base::mf3"<<x<<endl;
    		}
    	};
    	void base::mf1()
    	{
    		cout<<"base mf1 pure virtual"<<endl;
    	}
    	class derived:public base
    	{
    	public:
    		// using base::mf1;
    		// using base::mf3;
    		virtual void mf1()
    		{
    			cout<<"derived::mf1"<<endl;
    			base::mf1();
    		}
    		// void mf3()
    		// {
    		// 	cout<<"derived::mf3"<<endl;
    		// }
    		// void mf4()
    		// {
    		// 	cout<<"derived::mf4"<<endl;
    		// }
    	};
    	void test()
    	{
    		derived d;
    		d.mf1();
    		d.mf2();
    		//d.mf1(2);
    		// d.mf2();
    		// d.mf3();
    		//d.mf3(3.1);
    		base* b=new derived();
    		b->mf1();
    		b->base::mf1();
    		b->mf2();
    	}
    }
    namespace non_virtual_interface
    {
    	class base
    	{
    	public:
    		void test_nvi()const
    		{
    			cout<<"base:virtual before"<<endl;
    			private_virtual_func();
    			cout<<"base:virtual after"<<endl;
    		}
    	private:
    		virtual void private_virtual_func()const
    		{
    			cout<<"base:private_virtual_func"<<endl;
    		}
    	};
    	class derived:public base
    	{
    		void private_virtual_func()const
    		{
    			cout<<"derived:private_virtual_func"<<endl;
    		}
    	};
    	void test()
    	{
    		// derived* d=new derived();
    		// d->test_nvi();
    		// delete d;
    		derived d;
    		d.test_nvi();
    	}
    }
    namespace non_virtual_interface2
    {
    	class base;
    	int default_health_calc(const base& gc)
    	{}
    	class base
    	{
    	public:
    		typedef std::function<int (const base&)> health_calc_func;
    		explicit base(health_calc_func hcf=default_health_calc):m_health_func(hcf){}
    		int health_value()const
    		{
    			return m_health_func(*this);
    		}
    	private:
    		
    		health_calc_func m_health_func;
    	};
    	
    	short calc_func(const base&)
    	{
    		cout<<"calc_func"<<endl;
    	}
    	struct  calc_func_object
    	{
    		calc_func_object()
    		{
    			cout<<"calc_func_object constructor"<<endl;
    		}
    		int operator()(const base&)const
    		{
    			cout<<"calc_func_object"<<endl;
    		}
    	};
    	class calc_class_member
    	{
    	public:
    		short health(const base&)const
    		{
    			cout<<"calc_class_member"<<endl;
    		}
    	};
    	class derived:public base
    	{
    	public:
    		derived(health_calc_func hcf=default_health_calc):base(hcf)
    		{
    			cout<<"derived constructor"<<endl;
    		}
    		
    	};
    	void test()
    	{
    		// derived* d=new derived();
    		// d->test_nvi();
    		// delete d;
    		// derived d1(calc_func);
    		// d1.health_value();
    		// calc_func_object cc;
    		// derived d2(cc);
    		//derived d2(calc_func_object());
    		derived d2{calc_func_object()};
    		d2.health_value();
    		// derived *d2=new derived(calc_func_object());
    		// d2->health_value();
    		// calc_class_member c;
    		// // base::health_calc_func cf=std::bind(&calc_class_member::health,&c,std::placeholders::_1);
    		// // derived d3(cf);
    		// derived d3(std::bind(&calc_class_member::health,&c,std::placeholders::_1));
    		// d3.health_value();
    	}
    }
    namespace test_default_param_derived
    {
    	class shape
    	{
    	public:
    		enum shape_color
    		{
    			red,green,blue
    		};

    		//shape();
    		virtual void draw(shape_color color=red)const=0;
    		//~shape();
    		
    	};
    	class rectangle:public shape
    	{
    		virtual void draw(shape_color color=green)const
    		{
    			cout<<"rectangle draw:"<<color<<endl;
    		}
    	};
    	class circle:public shape
    	{
    	public:
    		virtual void draw(shape_color color)const
    		{
    			cout<<"circle draw:"<<color<<endl;
    		}
    	};
    	void test()
    	{
    		shape* ps;
    		shape* pc=new circle();
    		shape* pr=new rectangle();
    		pc->draw(shape::red);
    		pr->draw();
    	}
    }
    namespace test_class_size
    {
    	class base{};
    	class derived:public base
    	{
    		int x;
    	};
    	class have
    	{
    		int x;
    		base b;
    	};
    	void test()
    	{
    		cout<<sizeof(base)<<endl;
    		cout<<sizeof(derived)<<endl;
    		cout<<sizeof(have)<<endl;
    	}
    }
    namespace conversion_function
    {
    	class fraction
    	{
    		public:
    			fraction(int num,int den=1):m_numerator(num),m_denominator(den)
    			{}
    			// operator double()const
    			// {
    			// 	return double(m_numerator)/double(m_denominator);
    			// }
    			fraction operator+(const fraction& f)const
    			{
    				return fraction(m_numerator+f.m_numerator,m_denominator+f.m_denominator);
    			}
    		private:
    			int m_numerator,m_denominator;
    	};
    	void test()
    	{
    		fraction f(3,5);
    		// double d=4+f;
    		// cout<<d<<endl;
    		fraction d2=f+4;
    	}
    }
    namespace test_default_keyword
    {
    	class base
    	{
    	public:
    		explicit base(int x=0){}
    	};
    	class derived:public base
    	{
    	public:
    		derived()=default;
    		derived(int y){}
    	};
    	class widget
    	{
    	public:
    		widget():d(new derived())
    		{}
    	private:
    		derived* d;
    	};
    	void test()
    	{
    		widget w;
    	}
    }
    namespace test_operator_plus
    {
    	class base
    	{
    	public:
    		base(int num=0):m_num(num),m_pointer(&m_num){}
    		base& operator+=(const base& r)
    		{
    			m_num+=r.m_num;
    			return *this;
    		}
    		// friend const base operator+(const base&,int num)const;
    		// friend const base operator+(int num,const base&)const;
    		void print()
    		{
    			cout<<m_num<<":"<<*m_pointer<<endl;
    		}
    	private:
    		int m_num;
    		int* m_pointer;
    	};
    	const base operator+(const base& b,int num)
    	{
    		return base(b)+=num;
    	}
    	const base operator+(int num,const base& b)
    	{
    		return base(num)+=b;
    	}
    	const base operator+(const base& l,const base& r)
    	{
    		return base(l)+=r;
    	}
    	void test()
    	{
    		base b(2);
    		base c;
    		c+=b+3;
    		base d=4+c;
    		b.print();
    		c.print();
    		d.print();
    	}
    }
    namespace test_count_object
    {
    	template<typename being_counted>
    	class counted
    	{
    	public:
    		class too_many_objects{};
    		static int object_count()
    		{
    			return m_num_objects;
    		}
    	protected:
    		counted()
    		{
    			init();
    		}
    		counted(const counted&)
    		{
    			init();
    		}
    		virtual ~counted()
    		{
    			--m_num_objects;
    		}
    	private:
    		static int m_num_objects;
    		static const size_t max_objects=10;
    		void init()
    		{
    			if( m_num_objects>max_objects)
    			{
    				//throw too_many_objects();
    			}	
    			++m_num_objects;
    		}
    	};
    	class printer:private counted<printer>
    	{
    	public:
    		static printer* make_printer()
    		{

    		}
    		static printer* make_printer(const printer& r)
    		{

    		}
    		virtual ~printer()
    		{

    		}
    	private:
    		printer()
    		{}
    		printer(const printer& r)
    		{}
    	};
    	void test()
    	{

    	}

    }
    namespace test_template
    {
		template<typename T>
		class base
		{
		protected:
			void invert(size_t m)
			{
				cout<<"base invert"<<endl;
			}
		};
		template<typename T,size_t n>
		class derived:private base<T>
		{
		private:
			using base<T>::invert;
		public:
			void invert()
			{
				this->invert(n);
			}
		};
		void test()
		{
			derived<int,4> d;
			d.invert();
		}
    }
	void test()
	{
		//design_model::proto_type_model::test();
		//adapter::test();
		//observer_space::test();
		//composite::test();
		//prototype::test();
		//a_test::test();
		//test_reset_and_swap::test();
		//test_override::test();
		//non_virtual_interface2::test();
		// int m;
		// cin>>m;
		// if(cin.exceptions()!=cin.goodbit)
		// {
		// 	cout<<"adfafdf"<<endl;
		// }
		//test_default_param_derived::test();
		//test_class_size::test();
		//conversion_function::test();
		//test_default_keyword::test();
		//test_operator_plus::test();
		// cout<<__cplusplus<<endl;
		// for(int i:{1,2,3,4})
		// {
		// 	cout<<i<<endl;
		// }
		// double x=0;
		// double* p=&x;
		// double& r=x;
		// cout<<sizeof(x)<<endl;
		// cout<<sizeof(*p)<<endl;
		// cout<<sizeof(p)<<endl;
		// cout<<sizeof(r)<<endl;
		// cout<<p<<endl;
		// cout<<*p<<endl;
		// cout<<x<<endl;
		// cout<<r<<endl;
		// cout<<&r<<endl;
		// cout<<&x<<endl;
		//test_count_object::test();
		//test_template::test();
	}
}
#endif	/* PAYPAL_HPP */

