#include <string>
#include<iostream>
bool rep(std::string &s, const std::string &oldVal, const std::string &newVal);

int main(){
	std::string s = "tho,thru" ;
	rep(s, "tho", "though");
	rep(s, "thru", "through");
	std::cout << s << std::endl;
	return 0;
}
bool rep(std::string &s, const std::string &oldVal, const std::string &newVal){
	for (auto it = s.begin(); it <= s.end() - oldVal.size();){
		if (oldVal == std::string{ it, it + oldVal.size() }){
			it = s.erase(it, it + oldVal.size());
			it = s.insert(it, newVal.begin(), newVal.end());
			it += newVal.size();
		}
		else ++it;
	}
	return 0;
}