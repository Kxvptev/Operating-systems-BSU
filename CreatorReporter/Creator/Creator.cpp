#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <TlHelp32.h>
#include <wchar.h>
#include <cstdlib>

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
	if (argv < 2)
	{
		cout << "Invalid number of arguments!\n";
		system("pause");
		return 1;
	}
	
	string fileName = "D:/Программирование/Операционные системы/CreatorReporter/Debug/";
	fileName += string(argc[0]);
	int numOfRecords = atoi(argc[1]);

	ofstream binaryFile(fileName, ios::binary);

	if (!binaryFile)
	{
		cout << "Failure with binary file creation!\n";
		system("pause");
		return 2;
	}

	for (int i = 0; i < numOfRecords; i++)
	{
		struct employee e;
		cout << "Enter employee ID:\n";
		cin >> e.num;
		cout << "Enter employee name:\n";
		cin >> e.name;
		cout << "Enter hours worked:\n";
		cin >> e.hours;
		binaryFile.write((char*)&e, sizeof(employee));
	}

#ifdef DEBUG

#endif // DEBUG

	Sleep(100);
	binaryFile.close();

	return 0;
}