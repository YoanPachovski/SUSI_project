#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Student.h"
#include "Subject.h"

void save(std::string originalName, std::vector<Student>students)
{
	std::ofstream file;
	file.open(originalName);
	if (file.is_open())
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			file << students[i].saveSubjects();
			file << students[i].saveStudent();
		}
	}
	file.close();
}
void save_As(std::string fname, std::vector<Student>students)
{
	std::ofstream file;
	file.open(fname);
	if (file.is_open())
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			file << students[i].saveSubjects();
			file << students[i].saveStudent();
		}
	}
	file.close();
}
bool open(std::string fname, std::vector<Student>&student)
{
	bool open = false;
	std::vector<Subject>subject;
	std::ifstream inFile;
	inFile.open(fname);
	if (inFile.is_open())
	{
		open = true;
		int counterForStringInsert;
		std::string StudentName;
		std::string StudentSpeciality;
		std::string StudentCourse;
		std::string StudentGroup;
		std::string StudentFN;
		std::string StudentGrade;
		std::string StudentStatus;
		std::string SubjectName;
		std::string SubjectGrade;
		std::string SubjectStatus;
		std::stringstream strStream;
		strStream << inFile.rdbuf();
		std::string str = strStream.str();
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '<')
			{
				i++;
				if (str[i] == 'S')
				{
					i++;
					if (str[i] == 'u')
					{
						i++;
						if (str[i] == 'b')
						{
							while (str[i] != '>')
							{
								i++;
								if (str[i] == 'N')
								{
									i++;
									if (str[i] == 'a')
									{
										counterForStringInsert = 0;
										while (str[i] != ':')
										{
											i++;
										}
										while (i++,str[i] != ' ')
										{
											SubjectName.insert(counterForStringInsert, 1, str[i]);
											counterForStringInsert++;
										}
									}
								}
								if (str[i] == 'G')
								{
									i++;
									if (str[i] == 'r')
									{
										i++;
										if (str[i] == 'a')
										{
											counterForStringInsert = 0;
											while (str[i] != ':')
											{
												i++;
											}
											while (i++, str[i] != ' ')
											{
												SubjectGrade.insert(counterForStringInsert, 1, str[i]);
												counterForStringInsert++;
											}

										}
									}
								}
								if (str[i] == 'S')
								{
									i++;
									if (str[i] == 't')
									{
										i++;
										if (str[i] == 'a')
										{
											counterForStringInsert = 0;
											while (str[i] != ':')
											{
												i++;
											}
											while (i++, str[i] != '.')
											{

												SubjectStatus.insert(counterForStringInsert, 1, str[i]);
												counterForStringInsert++;
											}

										}
									}
								}
							}
							double SubGrade = strtod(SubjectGrade.c_str(), NULL);
							Subject c(SubjectName, SubGrade, SubjectStatus);
							subject.push_back(c);
							SubjectGrade.erase();
							SubjectName.erase();
							SubjectStatus.erase();
						}
					}
					if (str[i] == 't')
					{
						i++;
						if (str[i] == 'u')
						{
							i++;
							if (str[i] == 'd')
							{
								while (str[i] != '>')
								{
									i++;
									if (str[i] == 'N')
									{
										i++;
										if (str[i] == 'a')
										{
											counterForStringInsert = 0;
											while (str[i] != ':')
											{
												i++;
											}
											while (i++,str[i] != ' ')
											{
												StudentName.insert(counterForStringInsert, 1, str[i]);
												counterForStringInsert++;
											}
										}
									}
									if (str[i] == 'S')
									{
										i++;
										if (str[i] == 'p')
										{
											counterForStringInsert = 0;
											while (str[i] != ':')
											{
												i++;
											}
											while (i++, str[i] != ' ')
											{
												StudentSpeciality.insert(counterForStringInsert, 1, str[i]);
												counterForStringInsert++;
											}
										}
										if (str[i] == 't')
										{
											i++;
											if (str[i] == 'a')
											{
												counterForStringInsert = 0;
												while (str[i] != ':')
												{
													i++;
												}
												while (i++, str[i] != '.')
												{

													StudentStatus.insert(counterForStringInsert, 1, str[i]);
													counterForStringInsert++;
												}

											}
										}
									}
									if (str[i] == 'C')
									{
										i++;
										if (str[i] == 'o')
										{
											counterForStringInsert = 0;
											while (str[i] != ':')
											{
												i++;
											}
											while (str[i] != ' ')
											{
												i++;
												StudentCourse.insert(counterForStringInsert, 1, str[i]);
												counterForStringInsert++;
											}
										}
									}
									if (str[i] == 'G')
									{
										i++;
										if (str[i] == 'r')
										{
											i++;
											if (str[i] == 'o')
											{
												counterForStringInsert = 0;
												while (str[i] != ':')
												{
													i++;
												}
												while (str[i] != ' ')
												{
													i++;
													StudentGroup.insert(counterForStringInsert, 1, str[i]);
													counterForStringInsert++;
												}

											}
											if (str[i] == 'a')
											{
												counterForStringInsert = 0;
												while (str[i] != ':')
												{
													i++;
												}
												while (str[i] != ' ')
												{
													i++;
													StudentGrade.insert(counterForStringInsert, 1, str[i]);
													counterForStringInsert++;
												}

											}
										}
									}
									if (str[i] == 'F')
									{
										i++;
										if (str[i] == 'N')
										{
											counterForStringInsert = 0;
											while (str[i] != ':')
											{
												i++;
											}
											while (str[i] != ' ')
											{
												i++;
												StudentFN.insert(counterForStringInsert, 1, str[i]);
												counterForStringInsert++;
											}
										}
									}
								}
							}
						}
						double studCourse = strtod(StudentCourse.c_str(), NULL);
						double studGroup = strtod(StudentGroup.c_str(), NULL);
						double studFN = strtod(StudentFN.c_str(), NULL);
						double studGrade = strtod(StudentGrade.c_str(), NULL);
						Student c(StudentName, StudentSpeciality, studCourse, studGroup, studFN, StudentStatus, subject);
						student.push_back(c);
						StudentName.erase();
						StudentSpeciality.erase();
						StudentCourse.erase();
						StudentGrade.erase();
						StudentGrade.erase();
						StudentStatus.erase();
						StudentFN.erase();
						subject.clear();
					}
				}
			}
		}
	}
	inFile.close();
	return open;
}
