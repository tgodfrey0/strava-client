#pragma once

#include <gtkmm/box.h>

#include <string>
#include <stdint.h>
#include <vector>

namespace activities {
  enum ActivityType {
    RUN,
    CYCLE,
    OTHER
  };

  struct Activity {
    std::string author;
    std::string date_time;
    ActivityType sport;
    float distance;
  };

  Activity make_activity(std::string, std::string, ActivityType, float);

  Gtk::Box* make_widget(Activity);
  std::vector<Gtk::Box*> make_wigit_all(std::vector<Activity>);

  std::string print_activity_type(ActivityType);
  std::string print_activity(Activity);
}