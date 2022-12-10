#include <SFML/Graphics.hpp>
#include <iostream>

#include "router/router.hpp"
#include "utils/poppins.hpp"

using namespace std;
using namespace sf;

int main()
{
  RenderWindow window(VideoMode(1280, 720), "SFML | Test 2", Style::Close | Style::Titlebar);
  window.setFramerateLimit(60);

  Router router("about");

  while (window.isOpen())
  {
    Event event;
    while (window.pollEvent(event))
    {
      router.handleEvent(event, router);
      if (event.type == Event::Closed)
        window.close();
    }

    window.clear(Color::White);
    router.draw(window);
    window.display();
  }

  return 0;
}