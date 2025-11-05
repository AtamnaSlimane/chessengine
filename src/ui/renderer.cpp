#include "../../include/ui/renderer.hpp"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <optional>

namespace ui {

Renderer::Renderer()
    : window(sf::VideoMode({800, 800}), "Chess Board", sf::State::Windowed) // ✅ correct call
{
    if (!boardTexture.loadFromFile("assets/sprites/b_queen_svg_NoShadow.png"))
        throw std::runtime_error("Failed to load board texture");

    pieceSprite = std::make_unique<sf::Sprite>(boardTexture);
}

void Renderer::run() {
    const float tileSize = 100.f;

    while (window.isOpen()) {
        // ✅ new event polling API
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();

        // Draw 8x8 chess board
        sf::RectangleShape tile({tileSize, tileSize});
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                bool isLight = (row + col) % 2 == 0;
                tile.setFillColor(isLight ? sf::Color(240, 217, 181)
                                          : sf::Color(181, 136, 99));
                tile.setPosition({col * tileSize, row * tileSize});
                window.draw(tile);
            }
        }

        // Test sprite
        pieceSprite->setPosition({0.f, 0.f});
        window.draw(*pieceSprite);

        window.display();
    }
}

} // namespace ui
