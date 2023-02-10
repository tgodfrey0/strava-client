#include "MainWindow.hpp"
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include <iostream>

MainWindow::MainWindow()
{
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

  // This packs the button into the Window (a container).
  set_child(m_button);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_button_clicked()
{
  std::cout << "Clicked" << std::endl;
}