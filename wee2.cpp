#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

class Student
{
private:
	string name;
	int age;
	int stdNo;
	int average4Score;
public:
	void description() {
		cout << name << "," << age << "," << stdNo << "," << average4Score << endl;
	};
	Student(int average4Score, int age, string name, int stdNo);
};

Student::Student(int average4Scorei, int agei, string namei, int stdNoi) {
	average4Score = average4Scorei;
	age = agei;
	name = namei;
	stdNo = stdNoi;
}

int main(int argc, char const *argv[])
{
	string studentstr;
	cin >> studentstr;
	char *stdchar = new char[studentstr.length()];
	strcpy(stdchar, studentstr.c_str());


	char *start = strtok(stdchar, ",");

	string name(start);

	start = strtok(NULL, ",");
	int agei = atoi(start);

	start = strtok(NULL, ",");
	int stdNoi = atoi(start);

	start = strtok(NULL, ",");
	int s1i = atoi(start);

	start = strtok(NULL, ",");
	int s2i = atoi(start);

	start = strtok(NULL, ",");
	int s3i = atoi(start);

	start = strtok(NULL, ",");
	int s4i = atoi(start);

	int avarages = (s1i + s2i + s3i + s4i) / 4;


	Student s(avarages, agei, name, stdNoi);
	s.description();
	delete [] stdchar;
	return 0;
}

