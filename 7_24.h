#ifndef CP5_EX_7_24_H
#define CP5_EX_7_24_H
#include<iostream>
#include<string>
using std::string;
using std::cout; using std::cin; using std::endl;
class Screen{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' '){}
	char get() const{ return contents[cursor]; }
	char get(pos r, pos c) const{ return contents[r*width + c]; }

private:
	pos height = 0, width = 0;
	pos cursor = 0;
	string contents;

};

#endif