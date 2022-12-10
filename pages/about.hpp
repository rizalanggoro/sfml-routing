#ifndef page_about_hpp
#define page_about_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../utils/poppins.hpp"

using namespace sf;
using namespace std;

class PageAbout
{
private:
  string *route;
  Font poppinsRegular{};

public:
  PageAbout(string *route)
  {
    this->route = route;
    Poppins::regular(poppinsRegular);
  }

  void handleEvent(Event &event)
  {
    if (event.type == Event::KeyPressed)
    {
      if (event.key.code == Keyboard::Num1)
        (*route) = "main";
    }
  }

  void draw(RenderWindow &window)
  {
    Text text{};
    text.setString("Ini adalah about page");
    text.setCharacterSize(32);
    text.setFillColor(Color::Red);
    text.setFont(poppinsRegular);
    window.draw(text);
  }
};

#endif