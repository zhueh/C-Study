#ifndef _2_HW_H
#define _2_HW_H
#include<vector>
#include<string>
#include<iostream>
//error code
#define SUCCESS		0
#define NO_COURSE 	-1

//option
#define OPTION_HELP_COMMENT 	0
#define OPTION_COURSE_ID_NAME 	1
#define OPTION_COURSE_COUNT 	2
#define OPTION_COURSE_LONGEST 	3
#define OPTION_COURSE_DELETE 	4
#define OPTION_QUIT		5

class Course
{
public:
	friend std::istream &read(std::istream&,Course&);
	friend std::ostream &print(std::ostream&,const Course&);
	Course() = default;
	Course(std::string &na) :Course.name(na){}
	Course(std::istream& is){ read(is,*this) }
	Course(const Course &cor){ *this = cor; }
	std::vector<Course> course_initial();
	
private:
	int ID;
	std::string name;
	static int currentid;
};


class CourseManager{
public:
	CourseManager() = default;
	CourseManager(Course *cor){ this->Courses.push_back(cor); }
	CourseManager(const std::vector<Course> &cor){ *this = cor; }
	//获取课程数量函数
	int show_course_count(std::vector<Course> &courses);
	//添加课程函数
	int add(const std::string&);
	//添加课程函数重载
	int add(const std::vector<Course>&);
	//删除课程
	int course_delete(int);
	int course_delete(const std::string&);
	int show_course_info(std::vector<Course> courses);
	int show_course_info(const std::string&);
	int show_course_info(int);
	//int fprint(std::ofstream,const std::vector<Course>&);
private:
	std::vector<Course> Courses;
};


class CmdManager{
public:
	CmdManager()=default;
	int display_help();
	void cmdProcess(std::ostream&);
private:
	CourseManager manager; //持有一个manager具体业务实现类
};


//返回和设置信息
std::vector<Course> Course::course_initial(){
	std::string Name[] = { "Linux", "C++", "HTML", "HTML5", "NodeJS", "Shell", "Phthon" };
	std::vector<Course> courses;
	Course coursebuf;
	for (auto c : Name){
		coursebuf.name = c;
		coursebuf.ID = currentid;
		++currentid;
		courses.push_back(coursebuf);
	}
	return courses;
}
std::istream &read(std::istream &is, Course &cor){
	is >> cor.ID >> cor.name;
	return is;
}
std::ostream &print(std::ostream &os,const Course &cor){
	os << cor.ID <<" " << cor.name;
	return os;
}
//打印信息函数
int CmdManager::display_help(){
	std::string help_info = "\nEnter the option number follow by: \n";
	help_info += "0  show help information\n";
	help_info += "1  show courses id and name\n";
	help_info += "2  show course count\n";
	help_info += "3  show the longest course information\n";
	help_info += "4  delete the last course\n";
	help_info += "5  quit the program\n";
	std::cout << help_info << std::endl;
	return SUCCESS;
}
int CourseManager::show_course_count(std::vector<Course> &courses){
	if (courses.empty()){
		std::cout << "No Courses" << std::endl;
		return NO_COURSE;
	}
	std::vector<Course>::size_type num = courses.size();
	std::cout << "the courses totally is" << " "
		<< num << std::endl;
	return SUCCESS;
}
int CourseManager::add(const std::string &CourseName){
	Course Coursebuf;
	Coursebuf.name = CourseName;
	Coursebuf.ID = this->size()+100;
	(*this).push_back(Coursebuf);
	return SUCCESS;
}
int CourseManager::add(const std::vector<Course>& Courses){
	(*this).push_back(Courses);
	return SUCCESS;
}
int CourseManager::course_delete(){

	if (this->empty()){
		std::cout << "No Courses" << std::endl;
	}
	std::vector<course>::size_type lastCourseIndex = 0;
	lastCourseIndex = this->size() - 2;
	this->pop_back();
	//string lastCourseName=course.at(lastCourseIndex).name;
	std::cout << "success delete the last course" << " "
		<< this->at(lastCourseIndex).name << std::endl;
	return SUCCESS;
}
int CourseManager::course_delete(int courseID){
	int cnt=0;
	for(auto &c:(*this)){
		
		if(c.ID==courseID){
			std::vector<Course>::iteractor it = this->begin() + cnt;
			this->erase(it);
		}
		++cnt;
	}
}
int CourseManager::course_delete(const std::string& courseName){
	int cnt=0;
	for(auto &c:(*this)){

		if (c.name == courseName){
			std::vector<Course>::iteractor it = this->begin() + cnt;
			this->erase(it);
		}
		++cnt;
	}
}
int CourseManager::show_course_info(std::vector<Course> courses){
	if (courses.empty()){
		std::cout << "No Courses" << std::endl;
		return NO_COURSE;
	}
	std::cout << "course ID" << "\t" << "course Name" << std::endl;
	for (auto i = 0; i != courses.size(); ++i){
		std::cout << courses.at(i).ID << "\t" << courses.at(i).name << std::endl;
	}
	return SUCCESS;
}
int CourseManager::show_course_info(const std::string &courseName){
	int cnt=0;
	for(auto &c:(*this)){

		if (c.name == courseName){
			std::vector<Course>::iteractor it = this->begin() + cnt;
			std::cout << (*it).ID << " " << (*it).name << std::flush;
		}
		++cnt;
	}
}
int CourseManager::show_course_info(int courseID){
	int cnt=0;
	for (auto &c : (*this)){

		if (c.ID == courseID){
			std::vector<Course>::iteractor it = this->begin() + cnt;
			std::cout << (*it).ID << " " << (*it).name << std::flush;
		}
		++cnt;
	}
}
void CmdManager::cmdProcess(const std::istream &is){
	while(is>>option){
		if(option==OPTION_HELP_COMMENT){
			display_help();	
		}
		else if (option == OPTION_COURSE_ID_NAME){
			show_course_info(courses);
		}
		else if (option == OPTION_COURSE_COUNT){
			show_course_count(courses);
		}
		else if (option == OPTION_COURSE_LONGEST){
			show_course_longest(courses);
		}
		else if (option == OPTION_COURSE_DELETE){
			int code = course_delete(courses);
			if (code == SUCCESS){
				std::cout << "you have deleted the last course" << std::endl;
				show_course_info(courses);
			}
		}
		else if (option == OPTION_QUIT){
			break;
		}
		else{
			std::cout << "you input a wrong command" << std::endl;
			show_course_info(courses);
		}
	}
}
}
#endif // !2_HW_H
