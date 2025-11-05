#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

namespace ui {

class Renderer {
public:
    Renderer();
    void run();

private:
    sf::RenderWindow window;
    sf::Texture boardTexture;
    std::unique_ptr<sf::Sprite> pieceSprite;
};

} // namespace ui
