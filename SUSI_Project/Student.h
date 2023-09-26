#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Subject.h"

class Student
{
public:
	Student();
	Student(std::string, std::string, int, int, int, std::string, std::vector<Subject>);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();
	void create(std::string, std::string, int, int, int, std::string, std::vector<Subject>);
	void copy(const Student&);
	double getAverageGrade();
	void addSubject(std::string name, int grade, std::string status);
	void printStudentSubjects();
	void interruptCourse(std::string);
	void resumeCourse(std::string);
	void graduateCourse(std::string);
	void addSubjectGrade(std::string);
	void advanceCourse();
	void printStudent();
	void printStudentsWithSameSubjects(std::string);
	std::string saveStudent();
	std::string saveSubjects();
	int getFacultyNumber();
	int getCourse();
	int getGroup();
	void setSpeciality(std::string);
	void setGroup(int);
	void setCourse(int);
	std::string getName();
	std::string getSpeciality();
	std::string getStatus();


private:
	std::string name;
	std::string speciality;
	int course;
	int group;
	int facultyNumber;
	std::string status;
	double averageGrade;
	std::vector<Subject>studentSubjects;
};

Student::Student() :name(NULL), speciality(NULL), course(0), group(0), facultyNumber(0), status(NULL), averageGrade(0)
{}
Student::Student(std::string name, std::string speciality, int course, int group, int facultyNumber, std::string status, std::vector<Subject>subjects)
{
	create(name, speciality, course, group, facultyNumber, status, subjects);
	getAverageGrade();
}
Student::Student(const Student&other)
{
	copy(other);
}
Student& Student::operator=(const Student&other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
void Student::create(std::string name, std::string speciality, int course, int group, int facultyNumber, std::string status, std::vector<Subject>subjects)
{
	this->name = name;
	this->speciality = speciality;
	this->course = course;
	this->group = group;
	this->facultyNumber = facultyNumber;
	this->status = status;
	this->studentSubjects = subjects;
}
void Student::copy(const Student&other)
{
	this->name = other.name;
	this->speciality = other.speciality;
	this->course = other.course;
	this->group = other.group;
	this->facultyNumber = other.facultyNumber;
	this->status = other.status;
	this->studentSubjects = other.studentSubjects;
}
double Student::getAverageGrade()
{
	double sum = 0;
	for (int i = 0; i < studentSubjects.size(); i++)
	{
		double grade = studentSubjects[i].getSunjectGrade();
		sum = sum + grade;
	}
	sum = sum / studentSubjects.size();
	return sum;
}
void Student::addSubject(std::string Sunjectname, int Subjectgrade, std::string Subjectstatus)
{
	if (status == "interupted")
	{
		std::cout << "You can't add new subjects" << std::endl;
	}
	else
	{
		Subject c(Sunjectname, Subjectgrade, Subjectstatus);
		studentSubjects.push_back(c);
	}
}
void Student::printStudentSubjects()
{
	for (int i = 0; i < studentSubjects.size(); i++)
	{
		studentSubjects[i].printSubject();
	}
}
void Student::interruptCourse(std::string newStatus = "interupted")
{
	status = newStatus;
}
void Student::resumeCourse(std::string newStatus = "recorded")
{
	status = newStatus;
};
void Student::graduateCourse(std::string newStatus = "graduated")
{
	for (int i = 0; i < studentSubjects.size(); i++)
	{
		if (studentSubjects[i].getSunjectGrade() == 2)
		{
			std::cout << "You cannot graduate!" << std::endl;
			break;
		}
		else
		{
			if (course == 4)
			{
				status = newStatus;
			}
		}
	}
};
void Student::addSubjectGrade(std::string course)
{
	bool isThereSuchSubject = false;
	for (int i = 0; i < studentSubjects.size(); i++)
	{
		if (studentSubjects[i].getSubjectName() == course)
		{
			isThereSuchSubject = true;
			int n;
			std::cout << "Write Subject Grade:" << std::endl;
			std::cin >> n;
			studentSubjects[i].setSubjectGrade(n);
		}
	}
	if (isThereSuchSubject == false)
	{
		std::cout << "There is no such Subject!" << std::endl;
	}
}
void Student::advanceCourse()
{
	if (course < 4)
	{
		course = course + 1;
	}
}
void Student::printStudent()
{
	std::cout << "<StudentName:" << getName() << " StudentSpeciality:" << getSpeciality() << " StudentCourse:" << getCourse() << " StudentGroup:" << getGroup() << " StudentFN:" << getFacultyNumber() << " StudentGrade:" << getAverageGrade() << " StudentStatus:" << getStatus() << ".>" << std::endl;
}
std::string Student::saveStudent()
{
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(1) << "<StudentName:" << getName() << " StudentSpeciality:" << getSpeciality() << " StudentCourse:" << getCourse() << " StudentGroup:" << getGroup() << " StudentFN:" << getFacultyNumber() << " StudentGrade:" << getAverageGrade() << " StudentStatus:" << getStatus() << ".>" << std::endl;
	std::string str = ss.str();
	return str;

}
void Student::printStudentsWithSameSubjects(std::string subName)
{
	for (int i = 0; i < studentSubjects.size(); i++)
	{
		if (studentSubjects[i].getSubjectName() == subName)
		{
			printStudent();
		}
	}
}
std::string Student::saveSubjects()
{
	std::ostringstream ss;
	for (size_t i = 0; i < studentSubjects.size(); i++)
	{
		ss << std::fixed << std::setprecision(1) << studentSubjects[i].saveSubject();
	}
	std::string str = ss.str();
	return str;
}
void Student::setGroup(int newGroup)
{
	if (newGroup >= 1 && newGroup <= 8)
	{
		newGroup = group;
	}
}
void Student::setCourse(int newCourse)
{
	int poormarkscounter = 0;
	bool isPossible = true;
	for (int i = 0; i < studentSubjects.size(); i++)
	{
		if (studentSubjects[i].getSubjectStatus() == "Mandatory")
		{
			if (studentSubjects[i].getSunjectGrade() == 2)
			{
				poormarkscounter++;
				if (poormarkscounter >= 2)
				{
					std::cout << "You cannot advance to the next course" << std::endl;
					isPossible = false;
					break;
				}
			}
		}
	}
	if (isPossible == true)
	{
		if (getCourse() + 1 == newCourse)
		{
			advanceCourse();
		}
		else
		{
			std::cout << "You cannot advance 2 or more courses" << std::endl;
		}
	}
}
void Student::setSpeciality(std::string newSpeciality)
{
	bool isPossible = true;
	for (int i = 0; i < studentSubjects.size(); i++)
	{
		if (studentSubjects[i].getSubjectStatus() == "Mandatory")
		{
			if (studentSubjects[i].getSunjectGrade() == 2)
			{
				std::cout << "You cannot change the courses" << std::endl;
				isPossible = false;
				break;
			}
		}
	}
	if (isPossible == true)
	{
		newSpeciality = speciality;
		std::cout << "Successfully changed the speciality" << std::endl;
	}
}
int Student::getFacultyNumber()
{
	return facultyNumber;
}
int Student::getCourse()
{
	return course;
}
std::string Student::getName()
{
	return name;
}
std::string Student::getSpeciality()
{
	return speciality;
}
std::string Student::getStatus()
{
	return status;
}
int Student::getGroup()
{
	return group;
}
Student::~Student()
{
}
