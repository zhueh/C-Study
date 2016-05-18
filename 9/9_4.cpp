#include <vector>

bool find(std::vector<int>::const_iterator it1, std::vector<int>::const_iteractor it2, int val){
	for (auto it = it1; it != it2; ++it){
		if (*it == val){ return true; }
	}
	return false;
}