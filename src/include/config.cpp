
#include "config.hpp"

boost::shared_ptr<iconfig> iconfig::m_ps = nullptr;
boost::mutex iconfig::m_mu;
#define get_config iconfig::get_instance("config.ini");


