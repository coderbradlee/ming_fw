#include "ming_log.hpp"
boost::shared_ptr<singleton_ming_log> singleton_ming_log::ps_ = nullptr;
boost::mutex singleton_ming_log::mu_;
