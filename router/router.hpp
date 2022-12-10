#pragma once

#ifndef router_hpp
#define router_hpp

#include <iostream>

#include "../pages/main.hpp"
#include "../pages/about.hpp"

using namespace std;

class Router
{
private:
  string route = "/";
  PageMain pageMain{&route};
  PageAbout pageAbout{&route};

public:
  Router(string initialRoute) { route = initialRoute; }

  void handleEvent(Event &event, Router &router)
  {
    if (route == "main")
      pageMain.handleEvent(event);
    else if (route == "about")
      pageAbout.handleEvent(event);
  }

  void
  draw(RenderWindow &window)
  {
    if (route == "main")
      pageMain.draw(window);
    else if (route == "about")
      pageAbout.draw(window);
  }
};

#endif