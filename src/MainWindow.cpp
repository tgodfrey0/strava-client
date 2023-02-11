#include "MainWindow.hpp"
#include "Activities.hpp"
#include "Network.hpp"

#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/viewport.h>

#include <boost/log/trivial.hpp>

#define width 600
#define height 1000

MainWindow::MainWindow()
{
  set_default_size(width, height);
  set_resizable(false);

  m_button = Gtk::Button();

  m_activity_list = Gtk::Box(Gtk::Orientation::VERTICAL);


  BOOST_LOG_TRIVIAL(trace) << "Building MainWindow";

  m_activity_list.set_orientation(Gtk::Orientation::VERTICAL);
  m_activity_list.set_halign(Gtk::Align::CENTER);

  auto sw = Gtk::make_managed<Gtk::ScrolledWindow>();

  auto pmap = Gtk::make_managed<Gtk::Image>("../res/svgs/sharp-regular/repeat.svg");
  auto label = Gtk::make_managed<Gtk::Label>("Cool button");
  label->set_expand(true);

  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*label);

  m_button.set_child(*hbox);

  // Sets the margin around the button.
  m_button.set_margin(10);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &MainWindow::on_button_clicked));


  sw->set_size_request(width, (height * 0.8));
  sw->set_halign(Gtk::Align::CENTER);
  
  sw->set_child(m_activity_list);


  auto outer = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 5);
  outer->append(m_button);
  outer->append(*sw);

  // This packs the button into the Window (a container).
  set_child(*outer);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_button_clicked()
{
  add_to_list(activities::make_activity(
    "auth",
    "1/1/1 00:00:00",
    activities::ActivityType::CYCLE,
    1.23f
  ));
  network::get_activities();
}

void MainWindow::add_to_list(activities::Activity a) {
  BOOST_LOG_TRIVIAL(trace) << "Adding activity " << print_activity(a) << " to the view";

  try {
    auto activity_box = activities::make_widget(a);
    m_activity_list.append(*activity_box);
  } catch (const std::exception &e) {
    BOOST_LOG_TRIVIAL(error) << "Error when adding activity - " << e.what();
  }
}