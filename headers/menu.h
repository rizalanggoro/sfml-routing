#ifndef menu_h
#define menu_h

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Menu
{
private:
  int selectedMenuIndex = 0;
  double spacerHeight = 8;
  double textSize = 24;
  vector<string> vectorMenu;
  Font font{};

public:
  Menu()
  {
    font.loadFromFile("assets/fonts/Poppins-Regular.ttf");
  }

  void setSpacerHeight(double height)
  {
    spacerHeight = height;
  }

  void setTextSize(double size)
  {
    textSize = size;
  }

  void addMenu(string title)
  {
    vectorMenu.push_back(title);
  }

  void handleKeyboardEvent(RenderWindow &window, Event &event)
  {
    if (event.type == Event::KeyPressed)
      switch (event.key.code)
      {
      case Keyboard::Up:
        if (selectedMenuIndex > 0)
          selectedMenuIndex--;
        break;

      case Keyboard::Down:
        if (selectedMenuIndex < (vectorMenu.size() - 1))
          selectedMenuIndex++;
        break;

      case Keyboard::Escape:
        window.close();
        break;

      case Keyboard::Return:
        if (selectedMenuIndex == 3)
          window.close();
        break;
      }
  }

  void draw(RenderWindow &window)
  {
    double totalHeight = (textSize * vectorMenu.size()) + (spacerHeight * (vectorMenu.size() - 1));

    double windowHeight = window.getSize().y;
    double windowWidth = window.getSize().x;

    double startPosY = (windowHeight / 2) - (totalHeight / 2);

    for (int a = 0; a < vectorMenu.size(); a++)
    {
      Text text{};
      text.setString(vectorMenu.at(a));
      text.setFillColor(selectedMenuIndex == a ? Color::Black : Color(0, 0, 0, 100));
      text.setCharacterSize(textSize);
      text.setFont(font);

      double posX = (windowWidth / 2) - (text.getLocalBounds().width / 2);

      text.setPosition(Vector2f(posX, startPosY));

      window.draw(text);

      startPosY += (textSize + spacerHeight);
    }
  }
};

#endif