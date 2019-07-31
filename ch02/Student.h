/******************************************************************************
* File:             Student.h
*
* Author:           talen  
* Created:          07/31/19 
* Description:      struct Student
*                   - operator <
*                   - ostream <<
*****************************************************************************/

#ifndef STUDENT_HEAD
#define STUDENT_HEAD
#include<iostream>
#include<string>

struct Student{
	string name;
	int score;

	bool operator<(const Student &otherStudent){
		return score <otherStudent.score;
	}
	friend ostream& operator<<(ostream &os,const Student &student){

		os<<"Student: "<<student.name<<" "<<student.score<<std::endl;
		return os;
	}
};




#endif /* ifndef STUDENT_HEAD
 */
