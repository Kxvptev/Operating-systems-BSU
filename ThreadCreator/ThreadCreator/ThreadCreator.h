#pragma once
#include <thread>
#include <iostream>
#include <windows.h>
#include <process.h>
#include <fstream>
#include <psapi.h>

class ThreadCreator
{
private:
	int min, max;
	double averageNum;
	int* array;

	void minMaxMethod();
	void averageMethod();

public:
	ThreadCreator();
	~ThreadCreator();
};

