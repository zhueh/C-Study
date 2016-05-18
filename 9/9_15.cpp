#include <iostream>
#include <vector>
bool compare(std::vector<int>&, std::vector<int>&);
int main(){
	std::vector<int> vec1, vec2;
	vec1 = { 1, 2, 3, 4 };
	vec2 = { 1, 2, 4 };
	compare(vec1, vec2);
	return 0;
}
bool compare(std::vector<int> &vec1, std::vector<int> &vec2){
	if (vec1 == vec2){ std::cout << "vec1 equal to vec2" << std::endl; return true; }
	else { std::cout << "vec1 not equal to vec2" << std::endl; return false; }
}