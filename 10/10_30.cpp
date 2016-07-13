#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	while (cin){
		istream_iterator<int> in(cin), eof;
		ostream_iterator<int> out(cout, " ");
		vector<int> vec;
		while (in != eof)
		vec.push_back(*in++);
		sort(vec.begin(), vec.end());
		for (auto e : vec){
			out = e;
			cout << endl;
		}
	}
	return 0;
}