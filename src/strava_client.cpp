#include "MainWindow.hpp"
#include "Activities.hpp"

#include <gtkmm/application.h>

#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>

#include <curl/curl.h>

// This will change
void init() {
  curl_global_init(CURL_GLOBAL_ALL);

  boost::log::core::get()->set_filter (
    boost::log::trivial::severity >= boost::log::trivial::trace
  );
}

int main(int argc, char* argv[])
{
  init(); // Sets the log filter level & initialises curl

  auto app = Gtk::Application::create("com.tgodfrey.strava");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<MainWindow>(argc, argv);
}