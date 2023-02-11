#include "Network.hpp"

#include <boost/log/trivial.hpp>


void network::get_activities(uint8_t num){
  BOOST_LOG_TRIVIAL(trace) << std::to_string(num);
}