#ifndef GAME_H
#define GAME_H

#include "bitboard.h"

class ChessGame {

enum PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

private:
    // Constants for colors
    static constexpr int WHITE = 1;
    static constexpr int BLACK = 0;

    // Bitboards for pieces by color and type
    bitboard whitePawns;
    bitboard whiteRooks;
    bitboard whiteKnights;
    bitboard whiteBishops;
    bitboard whiteQueens;
    bitboard whiteKing;

    bitboard blackPawns;
    bitboard blackRooks;
    bitboard blackKnights;
    bitboard blackBishops;
    bitboard blackQueens;
    bitboard blackKing;

    bitboard occupiedSquares;  // All occupied squares on the board
    bool whiteTurn;            // Boolean flag to track which player's turn it is

    // Helper function to retrieve the appropriate bitboard
    bitboard& getBitboard(PieceType piece, int color) {
        if (color == WHITE) { // White
            switch (piece) {
                case PAWN:   return whitePawns;
                case ROOK:   return whiteRooks;
                case KNIGHT: return whiteKnights;
                case BISHOP: return whiteBishops;
                case QUEEN:  return whiteQueens;
                case KING:   return whiteKing;
            }
        } else if (color == BLACK) { // Black
            switch (piece) {
                case PAWN:   return blackPawns;
                case ROOK:   return blackRooks;
                case KNIGHT: return blackKnights;
                case BISHOP: return blackBishops;
                case QUEEN:  return blackQueens;
                case KING:   return blackKing;
            }
        }
        throw std::invalid_argument("Invalid PieceType or color");
    }

public:
    ChessGame();
    void initializeGame();
    bool makeMove(int fromSquare, int toSquare, PieceType piece, int color);
    bool isCheckmate();
    bool isStalemate();
    void printBoard();
};

#endif
