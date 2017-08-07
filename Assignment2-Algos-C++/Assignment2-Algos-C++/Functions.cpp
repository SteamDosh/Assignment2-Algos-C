#include <iostream>
#include "Functions.h"

const int HEAPLIMIT = 100;
int heapArray[HEAPLIMIT];

void SelectFile()
{
	cout << "\nEnter the name of the file (ie test.txt)" << endl;
	string input;
	cin >> input;

	ReadFile(input);
}

void ReadFile(string aFileName)
{
	ifstream fin(aFileName);

	if (!fin.good())
	{
		cerr << "Could not open data file!\n";
		return;
	}
	int i = 0;
	for (string word; fin >> word; i++)
	{
		if (i >= HEAPLIMIT) 
		{
			cerr << "Array is full! Breaking readin\n";
			break;
		}
		heapArray[i] = stoi(word);
		cout << heapArray[i] << endl;
	}

	fin.close();

}

void MinHeapify(int i, int n)
{
	int j, temp;
	temp = heapArray[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && heapArray[j + 1] < heapArray[j]) j = j + 1;
		if (temp < heapArray[j]) break;
		else if (temp >= heapArray[j])
		{
			heapArray[j / 2] = heapArray[j];
			j = 2 * j;
		}
	}
	heapArray[j / 2] = temp;
	return;
}

void MaxHeapify(int i, int n)
{
	int j, temp;
	temp = heapArray[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && heapArray[j + 1] > heapArray[j]) j = j + 1;
		if (temp > heapArray[j]) break;
		else if (temp <= heapArray[j])
		{
			heapArray[j / 2] = heapArray[j];
			j = 2 * j;
		}
	}
	heapArray[j / 2] = temp;
	return;
}

void HeapSort(bool aOption)
{
	int i, temp;
	for (i = HEAPLIMIT; i >= 2; i--)
	{
		temp = heapArray[i];
		heapArray[i] = heapArray[1];
		heapArray[1] = temp;
		if (aOption)
		{
			MaxHeapify(1, i - 1);
		}
		else
		{
			MinHeapify(1, i - 1);
		}
	}
}

void BuildHeap(bool aOption)
{
	for (int i = HEAPLIMIT / 2; i >= 1; i--)
	{
		if (aOption) 
		{
			MaxHeapify(i, HEAPLIMIT);
		}
		else
		{
			MinHeapify(i, HEAPLIMIT);
		}
	}
}

void PrintHeap()
{
	for (int i = 1; i <= HEAPLIMIT; i++)
	{
		cout << heapArray[i] << endl;
	}
}