#include "Activities.hpp"

#include <gtkmm/box.h>
#include <gtkmm/label.h>

#include <algorithm>


activities::Activity activities::make_activity(std::string author, std::string date_time, activities::ActivityType sport, float distance){
  return activities::Activity {
    author,
    date_time,
    sport,
    distance
  };
}

Gtk::Box* activities::make_widget(activities::Activity a){
  auto left = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);

  auto author_text = Gtk::make_managed<Gtk::Label>();
  author_text->set_markup("Author: <b>" + a.author + "</b>");
  left->append(*author_text);

  auto date_time_text = Gtk::make_managed<Gtk::Label>();
  date_time_text->set_markup("Date: <b>" + a.date_time + "</b>");
  left->append(*date_time_text);

  auto right = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);

  auto sport_text = Gtk::make_managed<Gtk::Label>();
  std::string sport_s = activities::print_activity_type(a.sport);
  sport_text->set_markup("Sport: <b>" + sport_s + "</b>");
  right->append(*sport_text);

  auto distance_text = Gtk::make_managed<Gtk::Label>();
  distance_text->set_markup("Date: <b>" + std::to_string(a.distance) + "</b>");
  right->append(*distance_text);

  auto outer = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 20);
  outer->append(*left);
  outer->append(*right);

  return outer;
}

std::vector<Gtk::Box*> activities::make_wigit_all(std::vector<activities::Activity> as){
  std::vector<Gtk::Box*> boxes;

  for(auto iter = as.begin(); iter != as.end(); iter++){
    boxes.push_back(make_widget(*iter));
  }

  return boxes;
}

std::string activities::print_activity_type(activities::ActivityType t){
  if(t == activities::ActivityType::RUN) {
    return "Run";
  } else if(t == activities::ActivityType::CYCLE) {
    return "Cycle";
  } else {
    return "Other";
  }
}

std::string activities::print_activity(activities::Activity a){
  std::string s = a.author;

  return s;
}