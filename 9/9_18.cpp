#include <string>
#include <deque>
#include <iostream>
int main(){
	std::string str;
	std::deque<std::string> deq;
	while (std::cin >> str){	
		deq.push_back(str);
	}
	//for (; std::cin >> str; deq.push_back(str));
	for (auto it = deq.begin(); it != deq.end();++it)
	{
		std::cout << *it << " " << std::flush;
	}
	return 0;
}