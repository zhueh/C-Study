#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc,char **argv){
	if (argc != 4) return -1;
	ifstream ifs(argv[1]);
	ofstream ofs_odd(argv[2]), ofs_even(argv[3]);
	printf3(ifs, ofs_odd, ofs_even);
	return 0;
}
void printf3(istream& is, ostream& os, ostream& os2){
	istream_iterator<int> in(is),eof;
	ostream_iterator<int> out(os, " "), out2(os2, "\n");
	/*vector<int> vec;
	while (in != eof){
		vec.push_back(*in++);
	}
	remove_copy_if(vec.begin(), vec.end(), back_inserter(out), [](int i){return i % 2; });
	remove_copy_if(vec.begin(), vec.end(), back_inserter(out), [](int i){return !(i % 2); });*/
	for_each(in, eof, [&out, &out2](const int i){
		*(i & 0x1 ? out : out2)++ = i;
	});
}