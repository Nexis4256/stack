#pragma once
#include <string.h>
#include <string>
#include <fstream>


using namespace std;

struct MY_STUDENT
{
	char  *lastname;
	int year;
	enum kierunki tab;
};

enum kierunki
{
	INFORMATYKA,
	AUTOMATYKA,
	ROBOTYKA,
	NOUN
};

void print(void* pdata);
void *MY_DATA_Init(int nameofstudys, char  *llastname, int year);
void *load(FILE *);
void save(void *, FILE *);
void *porownanie();
bool maincomparing(void*, void*);