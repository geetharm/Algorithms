/*
 * virtual.cpp
 *
 *  Created on: Sep 20, 2016
 *      Author: Meenakshi
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#define NUMBER_OF_SUBJECTS 6

class Person {

	public:
		char name[100];
		int age;
		virtual void getData() {

		}

		virtual void putData() {

		}

};

class Professor: public Person  {

private:
	int publications = 0;
	int cur_id;

public:
	static int numInstances;
	virtual void getData() {
		cin >> name >> age >> publications;
	}
	virtual void putData() {
		cout << name  <<  "\t" << age << "\t" << publications << "\t" << cur_id << endl;
	}

	Professor() {
		++numInstances;
		cur_id = numInstances;
	}

	~Professor() {
		--numInstances;
	}

};

class Student: public Person  {


private:
	int marks[NUMBER_OF_SUBJECTS] = {0};
	int cur_id = 0;
	int sumOfTheMarks = 0;

public:

	static int numInstances;
	virtual void getData() {

		cin >> name >> age;
		for(int i = 0; i < NUMBER_OF_SUBJECTS; ++i) {
			cin >> marks[i];
			sumOfTheMarks += marks[i];
		}
	}
	virtual void putData() {
		cout << "  " << name << "   " << age << "  "  << sumOfTheMarks << "   " << cur_id << endl;
	}

	Student() {
		++numInstances;
		cur_id = numInstances;
	}

	~Student() {
		--numInstances;
	}
};


int Professor::numInstances = 0;
int Student::numInstances = 0;

int main(){

	int numUsers = 0;
	cin >> numUsers;

	for(int i = 0; i < numUsers; ++i) {

		int user = 0;
		cin >> user;

		Person *person;

		if(user == 1) {
			 person = new Professor();
		} else {
			 person = new Student();
		}

		person->getData();
		person->putData();
	}

	return 0;
}



