#ifndef CP5_EX_7_23_H
#define CP5_EX_7_23_H

class Screen{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' '){}
	char get() const{ return contents[cursor]; }
	Screen move(pos r, pos c);
private:
	pos height = 0, width = 0;
	pos cursor = 0;
	string contents;
	
};

#endif