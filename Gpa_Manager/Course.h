//Lab-5
#include<iostream>
#include<iomanip>
using namespace std;

class Course{
public:
	string name;
	int hours;
	char grade;
public:
	Course():name("defaultSarthak"),hours(0),grade('A'){} //default-empty constructor
	Course(string name,int hours,char grade):name(name),hours(hours),grade(grade){} //parameterized comstructor
	
	//getters and setters
	string getName(){
		return name;
	}
	int getHours(){
		return hours;
	}
	char getGrade(){
		return grade;
	}
	
	void setName(string name){
		this->name=name;
	}
	void setHours(int hours){
		this->hours=hours;
	}
	void setGrade(char grade){
		this->grade=grade;
	}
	int returnPoints(){
		switch(grade){			//using a switch case to return values according to the grades entered..
			case 'A':
				return 4;
				break;
			case 'B':
				return 3;
				break;
			case 'C':
				return 2;
				break;
			case 'D':
				return 1;
				break;
			case 'F':
				return 0;
				break;
			default:
				cout<<"Enter proper Grading (A/B/C/D/F)"<<endl;
		}
	}
};
