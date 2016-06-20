#include<numeric>
#include<iostream>
#include<vector>
int main(){
	std::vector<int>  vec = { 1, 3, 4, 5, 6, 2 };
	int sum = accumulate(vec.cbegin(), vec.cend(),0);
	std::cout << "sum:" << sum << std::endl;
	return 0;
}