#include "ThreadCreator.h"

void ThreadCreator::minMaxMethod()
{
	max = array[0];
	min = array[0];

	for (int i = 0; i < 5; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
		}

		//Sleep(7);

		if (array[i] < min)
		{
			min = array[i];
		}

		//Sleep(7);
	}

	std::cout << "Min: " << min << '\n';
	std::cout << "Max: " << max << '\n';
}

void ThreadCreator::averageMethod()
{
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		sum += array[i];
		//Sleep(12);
	}

	averageNum = sum / 5;

	std::cout << "Average: " << averageNum << '\n';
}

ThreadCreator::ThreadCreator()
{
	array = new int[5];
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Enter the " << i + 1 << " element of the array: ";
		std::cin >> array[i];
		std::cout << '\n';
	}

	std::thread minMax(&ThreadCreator::minMaxMethod, this);
	minMax.join();
	std::thread average(&ThreadCreator::averageMethod, this);
	average.join();
}

ThreadCreator::~ThreadCreator()
{
	delete array;
}
