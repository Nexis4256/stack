#include "stdafx.h"
#include "stos.h"
#include "my_interface.h"
#include <malloc.h>
#include "my_data.h"
#include<string.h>
#include <iostream>
#include <string>
#include "messages.h"

using namespace std;

#pragma warning(disable : 4996)

const int buff = 1024;

const char *strtab[] =
{
	"0 - init",
	"1 - push",
	"2 - print",
	"3 - save",
	"4 - load",
	"5- clear",
	"6 - pop",
	"7-comparing",
	"8 - koniec"
};

void menu()
{
	int i = 0;
	for (i = 0; i < INTERFACE_LAST; i++)
	{
		cout << strtab[i]<<endl;
	}
}


stack *init(stack *top)
{
	if (top == NULL)
	{
		top = new stack;
		if (top == NULL)
		{
			error(MEMORY_ALLOCATION_PROBLEM);
		}

	}
	return top;
}


void *push()
{

	char inflastname[buff];
	memset(inflastname, 0, buff);
	int year = 0;
	int numberofstudy=0;
	cout << "podaj nazwisko" << endl;
	cin >> inflastname;
	cout << "podaj rok" << endl;
	cin >> year;
	cout << " podaj kierunek 0- INFORMATYKA 1-AUTOMATYKA,2-ROBOTYKA  " << endl;
	cin >> numberofstudy;
	while ((numberofstudy > 2) or (numberofstudy < 0))
	{
				cout << " taki kierunek nie istnieje podaj inny" << endl;
				cin >> numberofstudy;
	}
	return MY_DATA_Init(numberofstudy, inflastname, year);
}


