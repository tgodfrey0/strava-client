#include "MainWindow.hpp"
#include <gtkmm/application.h>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>

// This will change
void init() {
  boost::log::core::get()->set_filter (
    boost::log::trivial::severity >= boost::log::trivial::trace
  );
}

int main(int argc, char* argv[])
{
  init(); // Sets the log filter level

  auto app = Gtk::Application::create("com.tgodfrey.strava");

  //Shows the window and returns when it is closed.
  return app->make_window_and_run<MainWindow>(argc, argv);
}