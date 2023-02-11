#pragma once

#include "Activities.hpp"

#include <stdint.h>
#include <vector>

#include <curl/curl.h>


namespace network {
  static CURL* handle = curl_easy_init();
  static TokenStore tks;

  typedef struct TokenStore {
    std::string auth;
    std::string reauth;
    std::string id;
    std::string secret;
  } TokenStore;

  std::vector<activities::Activity> get_activities();

  TokenStore authenticate();
}