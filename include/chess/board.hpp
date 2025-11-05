#pragma once
#include <array>
#include <string>

namespace chess {

enum class PieceType { King, Queen, Rook, Bishop, Knight, Pawn, None };
enum class PieceColor { White, Black, None };

struct Piece {
    PieceType type;
    PieceColor color;
    std::string texturePath;
};

class Board {
public:
    static constexpr int SIZE = 8;
    using BoardArray = std::array<std::array<Piece, SIZE>, SIZE>;

    Board();
    const BoardArray& getBoard() const;

private:
    BoardArray board;
    void initBoard();
};

} // namespace chess
