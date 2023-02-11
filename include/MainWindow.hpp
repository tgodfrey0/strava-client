#pragma once

#include "Activities.hpp"

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/listbox.h>

class MainWindow : public Gtk::Window
{

public:
  MainWindow();
  virtual ~MainWindow();
  void add_to_list(activities::Activity);

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Box m_activity_list;
  Gtk::Button m_button;
};