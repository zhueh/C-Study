#ifndef CP5_EX_7_27_H
#define CP5_EX_7_27_H
#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::cout; using std::cin; using std::endl;
using std::vector;
class Window_mgr{
public:
	//窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	inline std::vector<Screen> screens;
};
class Screen{
public:
	friend void Window_mgr::clear(ScreenIndex);
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' '){}
	inline char get() const{ return contents[cursor]; }
	inline char get(pos r, pos c) const{ return contents[r*width + c]; }
	inline Screen &move(pos r, pos c);
	inline Screen &set(char);
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
	Screen &display(std::ostream &os){ do_display(os); return *this; }

private:
	pos height = 0, width = 0;
	pos cursor = 0;
	string contents;
	void do_display(std::ostream &os) const { os << contents; }
};
void Window_::clear(ScreenIndex i){
	if (i >= screens.size()) return;    // judge for out_of_range.
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}
Screen &Screen::move(pos r, pos c){
	cursor = r*width + c;
	return *this;
}
Screen &Screen::set(char c){
	contents[cursor] = c;
	return *this;
}
#endif