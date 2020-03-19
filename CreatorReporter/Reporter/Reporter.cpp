#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

struct employee
{
	int num; // employee ID
	char name[10]; // employee name
	double hours; // hours worked
};

int main(int argv, char* argc[])
{
	setlocale(LC_ALL, "Russian");

	if (argv < 4)
	{
		wcout << "Invalid number of arguments!\n";
		system("pause");
		return 1;
	}

	string binaryFileName = "D:/Программирование/Операционные системы/CreatorReporter/Debug/" + string(argc[0]);
	string fileName = "D:/Программирование/Операционные системы/CreatorReporter/Debug/" + string(argc[1]);
	double salaryCoef = atof(argc[2]);
	int count = atoi(argc[3]);

	ifstream binaryFile(binaryFileName, ios::binary);
	ofstream report(fileName);

	if (!binaryFile)
	{
		cout << "Cannot open binary file!\n";
		system("pause");
		return 2;
	}

	report << "Report on file: " << argc[0] << '\n';

	for (int i = 0; i < count; i++)
	{
		struct employee e;
		double salary;

		binaryFile.read((char*)&e, sizeof(employee));
		salary = e.hours * salaryCoef; 
		report << "Id: " << e.num << '\n';
		report << "Name: " << e.name << '\n';
		report << "Hours worked: " << e.hours << '\n';
		report << "Salary: " << salary << '\n';
	}

	Sleep(100);

	binaryFile.close();
	report.close();

	return 0;
}