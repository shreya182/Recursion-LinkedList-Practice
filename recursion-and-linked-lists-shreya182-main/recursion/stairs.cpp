#include "stairs.hpp"

int ways_to_top(int n) {
	if (n == 0){ // base case 1
		return 1;
	} else if (n < 0){ // base case 2
		return 0;
	} else { // recursive solution
		int num_ways = ways_to_top(n-1) + ways_to_top(n-2) + ways_to_top(n-3);
		return num_ways;
	}
}
