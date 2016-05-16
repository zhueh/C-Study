#include<iostream>
#include <string>
using namespace std;
istream& iotest(istream& is){
	string s;
	while (is >> s){
		cout << s << endl;
	}
		cin.clear();
		return is;
	
}
int main(){
	istream& is = iotest(cin);
	cout << is.rdstate() << endl;
	return 0;
}