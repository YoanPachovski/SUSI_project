#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Student.h"
#include "Subject.h"
#include "Files.h"

void menu()
{
	std::string writeLine;
	std::vector<Student>students;
	std::vector<Subject>subjects;
	std::cout << "Welcome to SUSI." << std::endl;
	std::cout << "The following commands are supported" << std::endl;
	std::cout << "open <file>	    opens <file>" << std::endl;
	std::cout << "close		        closes currently opened file" << std::endl;
	std::cout << "save			    saves the currently open file" << std::endl;
	std::cout << "saveas <file>	    saves the currently open file in <file>" << std::endl;
	std::cout << "help			    prints this information" << std::endl;
	std::cout << "exit			    exists the program" << std::endl;
	std::cout << "enroll			creates student" << std::endl;
	std::cout << "change			changes students FN,Speciality,Group or Course" << std::endl;
	std::cout << "graduate			graduates the student" << std::endl;
	std::cout << "interrupt 	    interrupts student course" << std::endl;
	std::cout << "resume 			resumes student course" << std::endl;
	std::cout << "print 			prints student info" << std::endl;
	std::cout << "printall 			prints all students from the same course and speciality" << std::endl;
	std::cout << "enrollin 			enrolls student in a subject" << std::endl;
	std::cout << "addgrade          adds grade to subject" << std::endl;
	std::cout << "protocol          prints all students with the same subject" << std::endl;
	std::cout << "report            prints everything about a student" << std::endl;
	while (writeLine != "exit")
	{
		std::cin >> writeLine;
		if (writeLine == "help")
		{
			std::cout << "The following commands are supported" << std::endl;
			std::cout << "open <file>	    opens <file>" << std::endl;
			std::cout << "close		        closes currently opened file" << std::endl;
			std::cout << "save			    saves the currently open file" << std::endl;
			std::cout << "saveas <file>  	saves the currently open file in <file>" << std::endl;
			std::cout << "help			    prints this information" << std::endl;
			std::cout << "exit			    exists the program" << std::endl;
			std::cout << "enroll			creates student" << std::endl;
			std::cout << "change			changes students FN,Speciality,Group or Course" << std::endl;
			std::cout << "graduate			graduates the student" << std::endl;
			std::cout << "interrupt 	    interrupts student course" << std::endl;
			std::cout << "resume 			resumes student course" << std::endl;
			std::cout << "print 			prints student info" << std::endl;
			std::cout << "printall 			prints all students from the same course and speciality" << std::endl;
			std::cout << "enrollin 			enrolls student in a subject" << std::endl;
			std::cout << "addgrade          adds grade to subject" << std::endl;
			std::cout << "protocol          prints all students with the same subject" << std::endl;
			std::cout << "report            prints everything about a student" << std::endl;
		}
		if (writeLine == "open")
		{
			std::cout << "Write File Name:" << std::endl;
			std::string filename;
			std::cin >> filename;
			if (open(filename, students) == true)
			{
				std::cout << "Successsfully opened " << filename << "." << std::endl;
			}
			else
			{
				std::cout << "This " << filename << " File Doesn't exist." << std::endl;
			}
		}
		if (writeLine == "close")
		{
			std::cout << "File closed" << std::endl;
		}
		if (writeLine == "save")
		{
			std::cout << "Name the file you want to save:" << std::endl;
			std::string filename;
			std::cin >> filename;
			save(filename, students);
		}
		if (writeLine == "saveas")
		{
			std::cout << "Name the file you want to save as:" << std::endl;
			std::string filename;
			std::cin >> filename;
			save_As(filename, students);
		}
		if (writeLine == "enroll")
		{
			std::string name;
			std::string speciality;
			int group;
			int Fn;
			std::cout << "Write Name:" << std::endl;
			std::cin >> name;
			std::cout << "Write Speciality:KN,IS or INF" << std::endl;
			std::cin >> speciality;
			std::cout << "Write Group:" << std::endl;
			std::cin >> group;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			Student c(name, speciality, 1, group, Fn, "recorded", subjects);
			students.push_back(c);
			std::cout << "Succesfully created Student" << std::endl;
		}
		if (writeLine == "change")
		{
			bool exist = false;
			int Fn;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					std::string change;
					std::cout << "What do you want to change:speciality,group or course" << std::endl;
					std::cin >> change;
					if (change == "speciality")
					{
						std::string speciality;
						std::cout << "Write Speciality:KN,IS or INF" << std::endl;
						std::cin >> speciality;
						students[i].setSpeciality(speciality);
					}
					if (change == "group")
					{
						int group;
						std::cout << "Write Group:" << std::endl;
						std::cin >> group;
						students[i].setGroup(group);
					}
					if (change == "course")
					{
						int course;
						std::cout << "Write course:" << std::endl;
						std::cin >> course;
						students[i].setCourse(course);
					}
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}
		if (writeLine == "graduate")
		{
			int Fn;
			bool exist = false;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					students[i].graduateCourse();
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}
		if (writeLine == "interrupt")
		{
			int Fn;
			bool exist = false;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					students[i].interruptCourse();
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}
		if (writeLine == "resume")
		{
			int Fn;
			bool exist = false;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					students[i].resumeCourse();
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}
		if (writeLine == "print")
		{
			int Fn;
			bool exist = false;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					students[i].printStudent();
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}
		if (writeLine == "printall")
		{
			std::string speciality;
			std::cout << "Write speciality:KN,IS or INF" << std::endl;
			std::cin >> speciality;
			int course;
			std::cout << "Write course:" << std::endl;
			std::cin >> course;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getSpeciality() == speciality)
				{
					if (students[i].getCourse() == course)
					{
						students[i].printStudent();
					}
				}
			}
		}
		if (writeLine == "enrollin")
		{
			int Fn;
			bool exist = false;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			std::string subName;
			std::cout << "Write SubjectName:" << std::endl;
			std::cin >> subName;
			std::string subStatus;
			std::cout << "Write SubjectStatus:Mandatory or NonMandatory" << std::endl;
			std::cin >> subStatus;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					students[i].addSubject(subName, 2, subStatus);
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}
		if (writeLine == "addgrade")
		{
			int Fn;
			bool exist = false;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			std::string subName;
			std::cout << "Write SubjectName:" << std::endl;
			std::cin >> subName;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					students[i].addSubjectGrade(subName);
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}
		if (writeLine == "protocol")
		{
			std::string subName;
			std::cout << "Write SubjectName:" << std::endl;
			std::cin >> subName;
			for (int i = 0; i < students.size(); i++)
			{
				students[i].printStudentsWithSameSubjects(subName);
			}
		}
		if (writeLine == "report")
		{
			int Fn;
			bool exist = false;
			std::cout << "Write FN:" << std::endl;
			std::cin >> Fn;
			for (int i = 0; i < students.size(); i++)
			{
				if (students[i].getFacultyNumber() == Fn)
				{
					exist = true;
					students[i].printStudentSubjects();
					students[i].printStudent();
				}
			}
			if (exist == false)
			{
				std::cout << "Student with this FN doesnt exist" << std::endl;
			}
		}

	}
}
