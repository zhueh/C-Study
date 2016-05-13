#ifndef CP5_EX_7_27_H
#define CP5_EX_7_27_H
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
	Screen &move(pos r, pos c);
	Screen &set(char);
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
	Screen &display(std::ostream &os){ do_display(os); return *this; }

private:
	pos height = 0, width = 0;
	pos cursor = 0;
	string contents;
	void do_display(std::ostream &os) const { os << contents; }
};
Screen &Screen::move(pos r, pos c){
	cursor = r*width + c;
	return *this;
}
Screen &Screen::set(char c){
	contents[cursor] = c;
	return *this;
}
#endif