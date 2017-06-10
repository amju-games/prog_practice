#include <algorithm>
#include <iostream>

const int NUM_ELEMENTS = 10;

// Find f in array. Return index or -1 if not found.
int bin_search(int array[], int f)
{
	int min = 0;
	int max = NUM_ELEMENTS;

	while (min <= max)
	{
		int half = (min + max) / 2;
		if (f == array[half])
		{
			return half;
		}
		else if (f < array[half])
		{
			// search lower half
			max = half - 1;
		}
		else
		{
			min = half + 1;
		}
	}
	return -1;
}

void print(int array[])
{
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		std::cout << array[i] << "\n";
	}
}

int main()
{
	int array[NUM_ELEMENTS];
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		array[i] = rand(); // TODO C++11 standard random num generator
	}

	std::cout << "Here is the array before sorting:\n";
	print(array);

	std::sort(array, array + NUM_ELEMENTS, [](int a, int b) { return a < b; });

	std::cout << "\nHere is the array after sorting:\n";
	print(array);

	int find = 42; // the number to Find

	std::cout << "Looking for " << find << "...\n";
	int index = bin_search(array, find);
	if (index == -1)
	{
		std::cout << "Not found.\n";
	}
	else
	{
		std::cout << "Found at index " << index << "\n";
	}
}

