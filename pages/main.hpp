#pragma once

#ifndef page_main_hpp
#define page_main_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../utils/poppins.hpp"

using namespace sf;
using namespace std;

class PageMain
{
private:
  string *route;
  Font poppinsRegular{};
  RenderWindow *globalWindow;
  bool toR = true;
  bool toB = true;
  Text text{};

public:
  PageMain(string *route)
  {
    this->route = route;
    Poppins::regular(poppinsRegular);
  }

  void
  handleEvent(Event &event)
  {
    if (event.type == Event::KeyPressed)
    {
      if (event.key.code == Keyboard::Num2)
        (*route) = "about";
      else if (event.key.code == Keyboard::Escape)
        (*globalWindow).close();
    }
  }

  void draw(RenderWindow &window)
  {
    globalWindow = &window;

    text.setString("Ini adalah main page");
    text.setCharacterSize(32);
    text.setFillColor(Color::Red);
    text.setFont(poppinsRegular);

    double tX = text.getLocalBounds().width;
    double tY = text.getLocalBounds().height;

    double wX = window.getSize().x;
    double wY = window.getSize().y;

    Vector2f tPos = text.getPosition();
    double v = 5;

    if (toR)
    {
      if (tPos.x <= (wX - tX))
        tPos.x += v;
      else
        toR = false;
    }
    else
    {
      if (tPos.x >= 0)
        tPos.x -= v;
      else
        toR = true;
    }

    if (toB)
    {
      if (tPos.y <= (wY - tY))
        tPos.y += v;
      else
        toB = false;
    }
    else
    {
      if (tPos.y >= 0)
        tPos.y -= v;
      else
        toB = true;
    }

    text.setPosition(tPos);

    window.draw(text);
  }
};

#endif