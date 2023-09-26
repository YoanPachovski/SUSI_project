#pragma once
#include <string>
#include <sstream>
#include <iomanip>

class Subject
{
public:
	Subject();
	Subject(std::string, int, std::string);
	Subject(const Subject&);
	Subject& operator=(const Subject&);
	void create(std::string, int, std::string);
	void copy(const Subject&);
	std::string getSubjectStatus();
	std::string getSubjectName();
	int getSunjectGrade();
	void setSubjectGrade(int);
	void printSubject();
	std::string saveSubject();
	~Subject();

private:
	std::string status;
	std::string subjectName;
	int subjectGrade;
};
Subject::Subject() :status(NULL), subjectName(NULL), subjectGrade(0)
{}
Subject::Subject(std::string name, int grade, std::string status)
{
	create(name, grade, status);
}
Subject::Subject(const Subject& other)
{
	copy(other);
}
Subject& Subject::operator=(const Subject& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}
void Subject::create(std::string name, int grade, std::string status)
{
	if (grade >= 2 && grade <= 6)
	{
		this->status = status;
		this->subjectName = name;
		this->subjectGrade = grade;
	}
}
void Subject::copy(const Subject& other)
{
	status = other.status;
	subjectName = other.subjectName;
	subjectGrade = other.subjectGrade;
}
std::string Subject::getSubjectStatus()
{
	return status;
}
std::string Subject::getSubjectName()
{
	return subjectName;
}
int Subject::getSunjectGrade()
{
	return subjectGrade;
}
void Subject::setSubjectGrade(int newGrade)
{
	if (newGrade >= 2 && newGrade <= 6)
	{
		subjectGrade = newGrade;
	}
}
void Subject::printSubject()
{
	std::cout << "<SubjectName:" << getSubjectName() << " SubjectGrade:" << getSunjectGrade() << " SubjectStatus:" << getSubjectStatus() << ".>" << std::endl;
}
std::string Subject::saveSubject()
{
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(1) << "<SubjectName:" << getSubjectName() << " SubjectGrade:" << getSunjectGrade() << " SubjectStatus:" << getSubjectStatus() << ".>" << std::endl;
	std::string str = ss.str();
	return str;
}
Subject::~Subject()
{
}
