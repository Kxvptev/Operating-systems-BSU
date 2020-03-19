#include <iostream>
#include <fstream>
#include <windows.h>
#include <TlHelp32.h>
#include <string>

using namespace std;

int manageProcess(string processName, string params)
{
	const char* path_c = "D:/Программирование/Операционные системы/CreatorReporter/Debug/";
	string path = path_c;
	path += processName;
	STARTUPINFO cif;
	LPSTARTUPINFOA ciflp = (LPSTARTUPINFOA)&cif;
	PROCESS_INFORMATION pid;
	ZeroMemory(&cif, sizeof(cif));
	if (!CreateProcessA((LPCSTR)path.c_str(), const_cast<LPSTR>(params.c_str()), NULL, NULL, FALSE, INHERIT_PARENT_AFFINITY, NULL, NULL, ciflp, &pid))
	{
		CloseHandle(pid.hProcess);
		CloseHandle(pid.hThread);
		return 2;
	}

	DWORD result = WaitForSingleObject(pid.hProcess, INFINITE);

	CloseHandle(pid.hProcess);
	CloseHandle(pid.hThread);

	if (result == WAIT_OBJECT_0)
		return 1;
	else
		return 2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string binaryFileName;
	string numOfRecords;

	cout << "Enter the name of binary file you want to create:\n";
	cin >> binaryFileName;
	cout << "Enter the number of records:\n";
	cin >> numOfRecords;

	string commandCr;
	commandCr = binaryFileName + " " + numOfRecords;

	int resultCr = manageProcess("Creator.exe", commandCr);
	if (resultCr == 2)
	{
		cout << "Something went wrong with Creator.exe!\n";
		return 1;
	}

	string fileName;
	string paymentCharge;

	cout << "Enter the name of report file you want to create:\n";
	cin >> fileName;
	cout << "Enter the payment charge:\n";
	cin >> paymentCharge;

	string commandRep;
	commandRep = binaryFileName + " " + fileName + " " + paymentCharge + " " + numOfRecords;

	int resultRep = manageProcess("Reporter.exe", commandRep);
	if (resultRep == 2)
	{
		cout << "Something went wrong with Reporter.exe!\n";
		return 2;
	}

	fileName = string("D:/Программирование/Операционные системы/CreatorReporter/Debug/") + fileName;

	ifstream outFile(fileName);

	if (!outFile)
	{
		cout << "Cannot open a report file!\n";
		return 3;
	}

	while (!outFile.eof())
	{
		string line;
		getline(outFile, line);
		cout << line << '\n';
	}

	return 0;
}