#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "course.h"

using namespace std;

// functions given to you:
void displaySchedule(vector<Course> &schedule);

// plugs into the average...
int returnTotalQualityPoints(vector<Course> &schedule);
int returnTotalHours(vector<Course> &schedule);
float returnGPA(vector<Course> &schedule);

// student created functions:
// YOU MUST CREATE THESE.
void addClass(vector<Course> &schedule);
void removeClass(vector<Course> &schedule);

int main()
{
    vector<Course> schedule;
    ifstream infile;
    string filename;

    // file opening
    cout << "Enter a file name: ";
    cin >> filename;

    infile.open(filename);

    // validation loop
    while(!infile.is_open())
    {
        cout << endl << "Invalid file. Please try again." << endl;
        cout << "Enter a file name: ";
        cin >> filename;

        infile.open(filename);
    }

    cout << endl << "File reading..." << endl;

    // ******************************************
    //  file reading here
    string nm;
    int hr;
    char gr;
    Course c1;
	while(getline(infile,nm)){  //using first string of the file as loop condition. its true until EndOfFile
		infile>>hr;
		infile>>gr;
		infile.ignore();
		c1.setName(nm);
		c1.setHours(hr);
		c1.setGrade(gr);
		
		schedule.push_back(c1); //pushing the object to our vector
	}

	// ******************************************


    infile.close();

    cout << "Reading complete. File closed." << endl << endl;

    // menuing
    cout << "Welcome to the GPA manager." << endl;

    string option;

    while(1)
    {
        cout << endl << "0. Exit" << endl;
        cout << "1. View Schedule" << endl;
        cout << "2. Add Class" << endl;
        cout << "3. Remove Class" << endl;
        cout << "4. Display GPA" << endl;
        cout << "Enter menu option: ";
        cin >> option;

        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // display schedule
        else if(option == "1")
        {
            displaySchedule(schedule);
        }

        // ******************************************
        else if(option=="2"){			//adding option nfor adding and removing class.
        	addClass(schedule);
		}
		
		else if(option=="3"){
			removeClass(schedule);
		}


        // ******************************************

        // display gpa
        else if(option == "4")
        {
            cout << "Your GPA with this schedule is: " << returnGPA(schedule) << endl;
        }

        // wrong menu option
        else
        {
            cout << "Invalid menu option. Try again." << endl;
        }
    }

    return 0;
}



// ******************************************
// ******************************************
// functions given to you

void displaySchedule(vector<Course> &schedule)
{
    for(int i = 0; i < schedule.size(); i++)
    {
        cout << "Course: " << schedule[i].getName() << endl;
        cout << "Hours: " << schedule[i].getHours() << "\tGrade: " << schedule[i].getGrade() << endl << endl;
    }

    cout << "Total schedule hours: " << returnTotalHours(schedule) << endl;

}

int returnTotalQualityPoints(vector<Course> &schedule)
{
    int points = 0;

    for(int i = 0; i < schedule.size(); i++)
    {
        points += (schedule[i].returnPoints() * schedule[i].getHours());
    }

    return points;
}

int returnTotalHours(vector<Course> &schedule)
{
    int hours = 0;

    for(int i = 0; i < schedule.size(); i++)
    {
        hours += schedule[i].getHours();
    }

    return hours;
}

float returnGPA(vector<Course> &schedule)
{
    return float(returnTotalQualityPoints(schedule)) / float(returnTotalHours(schedule));
}

// ******************************************

void addClass(vector<Course> &schedule) {
	 if(returnTotalHours(schedule)>19){				//Error checking for our limit
		cout<<"Hour limit is 19 already, cannot add more class."<<endl;
		return;
	}
	
    string name;
    char grade;
    int hours;

    cout << "Enter the course name: ";
    cin >> name;
    
    cout << "Enter the course grade: ";
    cin>>grade;
    //Error checking :Making grades caseSensitive 
    if(grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='F'){
    	    while(grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='F'){
    	    	cout<<"Invalid grade.Please try again."<<endl;
    	    	cout<<"Enter your Course grade(A,B,C,D,F): ";
    	    	cin>>grade;

			}
    }
    
    cout << "Enter the credit hours: ";
    cin >> hours;
    //Error checking for number of hours that can be assigned.
    if(hours<0 || hours>4){
    	while(hours<0 || hours>4){
    		cout<<"Invalid number for hours.Please Retry"<<endl;
    		cout<<"Enter the credit hours(1-4): ";
    		cin>>hours;
		}
	}

    Course c1(name, hours, grade);
    schedule.push_back(c1);

    cout << "Course added to the schedule." << endl;
}

void removeClass(vector<Course> &schedule){
    if (schedule.empty()) {
        cout << "Schedule is empty. Nothing to remove." << endl;
        return ;   									//Just return; returns to the main's loop.
    }

//displaying the name of the courses	
for(int i = 0; i < schedule.size(); i++)
    {
        cout << i+1 <<" : "<< schedule[i].getName() << endl;

    }
	
    cout << "Which course do you want to remove? (1-" << schedule.size() << "): ";
    int index;
    cin >> index;

    if (index >= 0 && index < schedule.size()) {     //indexing the number we wanna remove
        schedule.erase(schedule.begin() + index);
        cout << "Course removed from the schedule." << endl;
    } else {
        cout << "Invalid index. No course removed." << endl;
    }
}
// ******************************************
