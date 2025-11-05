#include "../../include/chess/board.hpp"

using namespace chess;

Board::Board() {
    initBoard();
}

const Board::BoardArray& Board::getBoard() const {
    return board;
}

void Board::initBoard() {
    // Empty
    for (auto& row : board)
        for (auto& cell : row)
            cell = {PieceType::None, PieceColor::None, ""};

    // Helper lambda
    auto makePiece = [&](PieceType type, PieceColor color, const std::string& name) {
        std::string prefix = (color == PieceColor::White) ? "w" : "b";
        return Piece{type, color, "assets/sprites/" + prefix + "_" + name + "_svg_NoShadow.png"};
    };

    // Setup major pieces
    board[0] = { makePiece(PieceType::Rook,   PieceColor::Black, "rook"),
                 makePiece(PieceType::Knight, PieceColor::Black, "knight"),
                 makePiece(PieceType::Bishop, PieceColor::Black, "bishop"),
                 makePiece(PieceType::Queen,  PieceColor::Black, "queen"),
                 makePiece(PieceType::King,   PieceColor::Black, "king"),
                 makePiece(PieceType::Bishop, PieceColor::Black, "bishop"),
                 makePiece(PieceType::Knight, PieceColor::Black, "knight"),
                 makePiece(PieceType::Rook,   PieceColor::Black, "rook") };

    for (int i = 0; i < SIZE; ++i)
        board[1][i] = makePiece(PieceType::Pawn, PieceColor::Black, "pawn");

    for (int i = 0; i < SIZE; ++i)
        board[6][i] = makePiece(PieceType::Pawn, PieceColor::White, "pawn");

    board[7] = { makePiece(PieceType::Rook,   PieceColor::White, "rook"),
                 makePiece(PieceType::Knight, PieceColor::White, "knight"),
                 makePiece(PieceType::Bishop, PieceColor::White, "bishop"),
                 makePiece(PieceType::Queen,  PieceColor::White, "queen"),
                 makePiece(PieceType::King,   PieceColor::White, "king"),
                 makePiece(PieceType::Bishop, PieceColor::White, "bishop"),
                 makePiece(PieceType::Knight, PieceColor::White, "knight"),
                 makePiece(PieceType::Rook,   PieceColor::White, "rook") };
}
