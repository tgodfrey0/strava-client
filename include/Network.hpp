#pragma once

#include "Activities.hpp"

#include <stdint.h>
#include <vector>

#include <curl/curl.h>


namespace network {
  static CURL* handle = curl_easy_init();
  static TokenStore tks;

  struct TokenStore {
    std::string auth;
    std::string reauth;
    std::string id;
    std::string secret;
  };

  std::vector<activities::Activity> get_activities();

  TokenStore authenticate();
}