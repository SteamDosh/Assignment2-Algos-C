#include <iostream>
#include <cctype>
#include "Functions.h"
using namespace std;

char Menu();

int main()
{
	bool Quit = false;

	do
	{
		char Cmd = Menu();
		switch (Cmd)
		{
		case 'r':
			SelectFile();
			break;
		case 'x':
			BuildHeap(true);
			HeapSort(true);
			break;
		case 'm':
			BuildHeap(false);
			HeapSort(false);
			break;
		case 'd':
			PrintHeap();
			break;
		case 'q':
			Quit = true;
			break;
		default:
			cerr << "Invalid command!\n";
		}
	} while (!Quit);

	return 0;
}

char Menu()
{
	char Cmd;
	cout << endl << "*********************************" << endl;
	cout << "*     Heap Sort                 *" << endl;
	cout << "*     (r)ead data file          *" << endl;
	cout << "*     (m)in heap sort           *" << endl;
	cout << "*     ma(x) heap sort           *" << endl;
	cout << "*     (d)isplay heap            *" << endl;
	cout << "*     (q)uit                    *" << endl;
	cout << "*********************************" << endl;
	cout << "Command: ";
	cin >> Cmd;
	cin.ignore();  // eat up '\n'
	Cmd = tolower(Cmd);
	return Cmd;
}