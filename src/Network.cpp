#include "Network.hpp"

#include <boost/log/trivial.hpp>

#include <curl/curl.h>

#include <fstream>

//CURL* network::handle = curl_easy_init();
network::TokenStore network::tks = network::authenticate();

std::vector<activities::Activity> network::get_activities(){
  std::string requestString;
  requestString.append("https://www.strava.com/api/v3/athlete/activities?authorization_token=");
  requestString.append(tks.auth);

  std::vector<activities::Activity> as;

  if(handle) {
    curl_easy_setopt(handle, CURLOPT_URL, requestString);
    CURLcode res = curl_easy_perform(handle);

    if(res != CURLE_OK) {
      BOOST_LOG_TRIVIAL(error) << "Error during CURL request - " << curl_easy_strerror(res);
    }

  } else {
    BOOST_LOG_TRIVIAL(fatal) << "Error initialising CURL";
  }

  return as;

}

network::TokenStore network::authenticate(){
  std::ifstream token_file;
  network::TokenStore ts;

  token_file.open("../.user_tokens");

  getline(token_file, ts.reauth);
  getline(token_file, ts.auth);

  token_file.close();
  token_file.open("../.app_tokens");

  getline(token_file, ts.id);
  getline(token_file, ts.secret);

  return ts;
}

