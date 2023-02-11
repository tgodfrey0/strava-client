#include "Activities.hpp"

#include <gtkmm/box.h>
#include <gtkmm/label.h>


Activity make_activity(std::string author, std::string date_time, ActivityType sport, float distance){
  return Activity {
    author,
    date_time,
    sport,
    distance
  };
}

Gtk::Box* make_widget(Activity a){
  auto left = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);
  auto author_text = Gtk::make_managed<Gtk::Label>("Author: " + a.author);
  left->append(*author_text);
  auto date_time_text = Gtk::make_managed<Gtk::Label>("Date: " + a.date_time);
  left->append(*date_time_text);

  auto right = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);
//  auto sport_text = Gtk::make_managed<Gtk::Label>("Sport: " + print_activity_type(a.sport));
  auto sport_text = Gtk::make_managed<Gtk::Label>("Sport: Run");
  right->append(*sport_text);
  auto distance_text = Gtk::make_managed<Gtk::Label>("Date: " + std::to_string(a.distance));
  right->append(*distance_text);

  auto outer = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL);
  outer->append(*left);
  outer->append(*right);

  return outer;
}

std::string print_activity_type(ActivityType t){
  if(t == ActivityType::RUN) {
    return "Run";
  } else if(t == ActivityType::CYCLE) {
    return "Cycle";
  } else {
    return "Other";
  }
}

std::string print_activity(Activity a){
  std::string s = a.author;

  return s;
}