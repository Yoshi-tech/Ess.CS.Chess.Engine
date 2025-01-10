#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>
#include <string>
using namespace std;

// Ranks
constexpr bitboard RANK_1 = 0x00000000000000FF;
constexpr bitboard RANK_2 = 0x000000000000FF00;
constexpr bitboard RANK_3 = 0x0000000000FF0000;
constexpr bitboard RANK_4 = 0x00000000FF000000;
constexpr bitboard RANK_5 = 0x000000FF00000000;
constexpr bitboard RANK_6 = 0x0000FF0000000000;
constexpr bitboard RANK_7 = 0x00FF000000000000;
constexpr bitboard RANK_8 = 0xFF00000000000000;

// Files
constexpr bitboard FILE_A = 0x0101010101010101;
constexpr bitboard FILE_B = 0x0202020202020202;
constexpr bitboard FILE_C = 0x0404040404040404;
constexpr bitboard FILE_D = 0x0808080808080808;
constexpr bitboard FILE_E = 0x1010101010101010;
constexpr bitboard FILE_F = 0x2020202020202020;
constexpr bitboard FILE_G = 0x4040404040404040;
constexpr bitboard FILE_H = 0x8080808080808080;

namespace boardUtils{
	using bitboard = uint64_t; // type alias

	bitboard setBit(bitboard b, int square){
		return b | 1ULL << square;
	}

	bitboard clearBit(bitboard b, int square){
		return b & ~(1ULL << square);
	}

	bitboard toggleBit(bitboard b, int square){
		return b ^ (1ULL << square);
	}

	bool isBitSet(bitboard b, int square){
		return (b & (1ULL << square)) != 0;
	}

	bitboard resetBoard(bitboard b){
		return 0ULL;
	}

	// shift operations
	bitboard north(bitboard b) {
        return (b << 8) & ~FILE_A;  // Shift up, and mask A-file to prevent wrapping
    }

    bitboard south(bitboard b) {
        return (b >> 8) & ~FILE_A;  // Shift down, and mask A-file to prevent wrapping
    }

    bitboard east(bitboard b) {
        return (b << 1) & ~FILE_H;  // Shift right, and mask H-file to prevent wrapping
    }

    bitboard west(bitboard b) {
        return (b >> 1) & ~FILE_A;  // Shift left, and mask A-file to prevent wrapping
    }

	bitboard northEast(bitboard b) {
	    return (b << 9) & ~(FILE_A);  // Shift diagonally up-right, and mask A-file to prevent wrapping
	}

	bitboard northWest(bitboard b) {
	    return (b << 7) & ~(FILE_H);  // Shift diagonally up-left, and mask H-file to prevent wrapping
	}

	bitboard southEast(bitboard b) {
	    return (b >> 7) & ~(FILE_A);  // Shift diagonally down-right, and mask A-file to prevent wrapping
	}

	bitboard southWest(bitboard b) {
	    return (b >> 9) & ~(FILE_H);  // Shift diagonally down-left, and mask H-file to prevent wrapping
	}

}



