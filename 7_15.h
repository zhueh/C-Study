#ifndef CP5_EX_7_15_H
#define CP5_EX_7_15_H
#include<string>
#include<iostream>
using std::string;
istream &read(istream&, Person&);
ostream &print(ostream&, Person&);
class Person{
public:
	Person() = default;
	Person(const string& sn, const string& sa) :name(sn), address(sa){};
	Person(istream&);
private:
	string name;
	string address;
	const string& getName() const{ return name; };
	const string& getAddress() const{ retrun address; };
};
Person::Person(istream &is){
	read(is, *this);
}
istream &read(istream &is, Person &item){
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream& os, const Person& item){
	os << item.name << " " << item.address;
	return os;
}
#endif