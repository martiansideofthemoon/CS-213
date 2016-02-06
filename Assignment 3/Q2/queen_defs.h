#include <iostream>
using namespace std;
struct Vars {
	int count;
	/** DO NOT CHANGE ANYTHING ABOVE THIS LINE **/
	/** Add any global variables you may want below this line **/
	int dimension;
	/** Define this function which takes in the N to solve for. This is called
	 * before calling countQueens from main **/
	void setup(int N) {
		count = 0;
		int i = 1, k = 1;
		while (++i <= N) k = (k << 1) + 1;
		dimension = k;
	}

};

extern Vars glob_vars;

inline bool solved(int col, int ld, int rd) {
	// Must return true iff queens have been placed on each row.
	return col == glob_vars.dimension;
}

inline int getValidPositions(int col, int ld, int rd) {
	// Must return a bit vector with 1s in positions where it is
	// safe to place a queen
	return ~(col | ld | rd) & glob_vars.dimension;
}

inline bool positionsAvailable(int valid_positions) {
	// Must return true iff there are safe positions to place
	// queens
	return valid_positions > 0;
}

inline int chooseOnePosition(int valid_positions) {
	// Must return an int with exactly one bit set as 1.
	// This bit must be chosen from the positions where
	// validPositions is also 1.
	int x = 1;
	while((valid_positions & x) == 0) x = x << 1;
	return x;
}

inline int removeChosenPosition(int valid_positions, int cur_posn) {
	// Must return a bit pattern with one less 1, and this one is
	// removed from the position where cur_posn is 1.
	return valid_positions & (~cur_posn & glob_vars.dimension);
}

inline int calcNewColDanger(int col, int cur_posn) {
	// Must return a bit pattern with the updated
	// column dangers due to placing a queen on cur_posn
	return col | cur_posn;
}

inline int calcNewLdDanger(int ld, int cur_posn) {
	// Must return a bit pattern with the updated
	// bottom left diagonal dangers due to placing a queen
	// on cur_posn
	return (ld >> 1) | (cur_posn >> 1);
}

inline int calcNewRdDanger(int rd, int cur_posn) {
	// Must return a bit pattern with the updated
	// bottom right diagonal dangers due to placing a queen
	// on cur_posn
	return ((rd << 1) | (cur_posn << 1)) & glob_vars.dimension;
}