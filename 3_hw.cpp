#include<vector>
#include<string>
#include<iostream>
using std::cin;using std::cout;using std::endl;
using std::string;
using std::vector;
struct course{
	int ID;
	string name;
};
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

//course_initial
vector<course> course_initial(){
	string Name[]={"Linux","C++","HTML","HTML5","NodeJS","Shell","Phthon"};
	vector<course> courses;
	int cnt=100;
	course coursebuf;
	for(auto c:Name){
		coursebuf.name = c;
		coursebuf.ID = cnt;
		++cnt;
		courses.push_back(coursebuf);
	} 
	return courses;
}

//OPTION_HELP_COMMENT
int display_help(){
	string help_info="\nEnter the option number follow by: \n";
	help_info += "0  show help information\n";
	help_info += "1  show courses id and name\n";
	help_info += "2  show course count\n";
	help_info += "3  show the longest course information\n";
	help_info += "4  delete the last course\n";
	help_info += "5  quit the program\n";
	cout<<help_info<<endl;
	return SUCCESS;
}
//OPTION_COURSE_ID_NAME
int show_course_info(vector<course> courses){
	if(courses.empty()){
		cout<<"No Courses"<<endl;
		return NO_COURSE;
	}
	cout<<"course ID"<<"\t"<<"course Name"<<endl;
	for(auto i=0;i!=courses.size();++i){
		cout<<courses.at(i).ID<<"\t"<<courses.at(i).name<<endl;
	}		
		return SUCCESS;
}
//OPTION_COUNT
int show_course_count(vector<course> courses){
	if(courses.empty()){
		cout<<"No Courses"<<endl;
		return NO_COURSE;
	}
	vector<course>::size_type num=courses.size();
	cout<<"the courses totally is"<<" "
	    <<num<<endl;
		return SUCCESS;
}
//OPTION_COURSE_LONGEST
int show_course_longest(vector<course> courses){
	if(courses.empty()){
		cout<<"No Courses"<<endl;
		return NO_COURSE;
	}
	decltype(courses.at(0).name.size()) longestCourse=0;
	for(auto it=courses.begin();it!=courses.end();++it){
		if(it->name.size()>longestCourse){
			longestCourse=it->name.size();
		}
	}
	//for(auto it=courses.begin();it!=courses.end();++it){
		cout<<"The longest course is:"<<endl;
		for(auto it2=courses.begin();it2!=courses.end();++it2){
		//for(auto a:courses){
			if(it2->name.size()==longestCourse){
				cout<<it2->name<<endl;
			}
		}
	return SUCCESS;
}
//OPTION_COURSE_DELETE
int course_delete(vector<course> &courses){
	
	if(courses.empty()){
		cout<<"No Courses"<<endl;
	}
	vector<course>::size_type lastCourseIndex=0;
	lastCourseIndex=courses.size()-2;
	courses.pop_back();
	//string lastCourseName=course.at(lastCourseIndex).name;
	cout<<"success delete the last course"<<" "
	    <<courses.at(lastCourseIndex).name<<endl;
	return SUCCESS;
}
int main(){
	vector<course> courses=course_initial();
	int option = 0;
	display_help();
	while(cin>>option){
		if(option==OPTION_HELP_COMMENT){
			display_help();	
		}
		else if(option==OPTION_COURSE_ID_NAME){
			show_course_info(courses);
		}
		else if(option==OPTION_COURSE_COUNT){
			show_course_count(courses);
		}
		else if(option==OPTION_COURSE_LONGEST){
			show_course_longest(courses);
		}
		else if(option==OPTION_COURSE_DELETE){
			int code=course_delete(courses);
			if(code==SUCCESS){
				cout<<"you have deleted the last course"<<endl;
				show_course_info(courses);
			}
		}
		else if(option==OPTION_QUIT){
			break;
		}
		else{
			cout<<"you input a wrong command"<<endl;
			show_course_info(courses);
		}
	}	
	return 0;
}

