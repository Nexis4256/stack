#include "stdafx.h"
#include "my_data.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include "messages.h"

using namespace std;

const int buff = 256;
#pragma warning(disable : 4996)

void *MY_DATA_Init(int nameofstudys, char  *llastname, int year)
{
	MY_STUDENT *pdat = new MY_STUDENT;
		
	if (pdat)
	{
	
		switch (nameofstudys)
		{
		case 0:
			pdat->tab = INFORMATYKA;
			break;
		case 1:
			pdat->tab = AUTOMATYKA;
			break;
		case 2:
			pdat->tab = ROBOTYKA;
			break;
		}
		pdat->year = year;
		pdat->lastname = (char*)malloc((strlen(llastname)+1) * sizeof(char));
		strcpy(pdat->lastname, llastname);
	}
	else
	{
		error(MEMORY_ALLOCATION_PROBLEM);
	}
	return (void *)(pdat);
}


void print(void* pdata)
{
	if (pdata != NULL) 
	{
		MY_STUDENT *temp = (MY_STUDENT*)pdata;

		cout << "Nazwisko studenta: " << temp->lastname << ", rocznik studenta: " << temp->year << ", kierunek studenta: ";
		switch (temp->tab)
		{
		case 0:
			cout << "INFORMATYKA";
			break;
		case 1:
			cout << "AUTOMATYKA";
			break;
		case 2:
			cout << "ROBOTYKA";
			break;
		}
	}
	else
	{
		error(There_Is_Nothing_To_Print);
	}
}

void *load(FILE *fp)
{
	MY_STUDENT *temp = new MY_STUDENT;
	if (temp == NULL)
	{
		error(MEMORY_ALLOCATION_PROBLEM);
	}
	int b;
	//string a = "";   //SF Proszę w tym projekcie nie używać klasy STL string - moim celom jest nauczyć Pana pracować z tablicami.
	//Dla tego proszę wykonać to ręcznie, a nie wykorzystac zaslugi developerow klasy string.
	//file >> a >> temp->year >> b;  //SF  to jest odczyt sformatowany, a nie binarny. Proszę przerobic.
	//temp->lastname = new char[a.size()+1];  
	//SF operator new wygeneryje wyjatek bad_alloc, a nie zwroci NULL.
	int sizeoflastname;
	int yearr;
	fread(&sizeoflastname, sizeof(int), 1, fp);
	temp->lastname = new char[sizeoflastname+1];
	if (temp->lastname == NULL)
	{
		error(MEMORY_ALLOCATION_PROBLEM);
	}
	//strcpy(temp->lastname, a.c_str());  //A jaki sens w tym? a - pusty wiersz.
	fread(&temp->lastname, sizeof(char), sizeoflastname, fp);
	fread(&yearr, sizeof(int), 1, fp);
	fread(&b, sizeof(int), 1, fp);
	temp->year = yearr;


	switch (b)    //SF b - niezainicjowane
	{
	case 0:
		temp->tab = INFORMATYKA;
		break;
	case 1:
		temp->tab = AUTOMATYKA;
		break;
	case 2:
		temp->tab = ROBOTYKA;
		break;
	}
	return (void*)temp;
}

void save(void *pdata,FILE *fp)
{
	MY_STUDENT *data = (MY_STUDENT*)pdata;
	int b = data->tab;
	//file << data->lastname <<endl<< data->year<<endl << b; //SF to jest zapis sformatowany, a nie binarny.
	int sizeoflastname = strlen((data->lastname));
	fwrite(&sizeoflastname, sizeof(int), 1, fp);
	fwrite(&data->lastname, sizeof(char), sizeoflastname, fp);
	fwrite(&data->year, sizeof(int), 1, fp);
	fwrite(&b, sizeof(int), 1, fp);
}


void *porownanie()
{
	cout << "Po jakim kryterium chcesz szukac elementu" << endl;
	cout << " 1- nazwisko 2-year, 3-kierunek" << endl;
	char* pom = new char[1];  //SF  ???
	memset(pom, 0, 1);
	MY_STUDENT *temp =(MY_STUDENT*)MY_DATA_Init(NOUN, pom, 0);
	delete []pom;
	int n = 0;
	cin >> n;
	switch (n)
	{
	case 1:
		cin >> temp->lastname;
		break;
	case 2:
		cin >> temp->year;
		break;
	case 3:
		int k = 0;
		cout << "twoje mozliwosci" << endl;
		cout << " 1-INFORMATYKA 2-AUTOMATYKA 3-ROBOTYKA" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			temp->tab = INFORMATYKA;
			break;
		case 2:
			temp->tab = AUTOMATYKA;
			break;
		case 3:
			temp->tab = ROBOTYKA;
			break;
		}
		
		break;
	}

	return (void*)temp;
}

bool maincomparing(void *ptr1, void* ptr2)
{
	MY_STUDENT *temp1 = (MY_STUDENT*)ptr1;
	MY_STUDENT *temp2 = (MY_STUDENT*)ptr2;

	if (temp1->year == temp2->year)
	{
		return true;
	}
	if (temp1->tab == temp2->tab)
	{
		return true;
	}
	if (strlen(temp1->lastname) == strlen(temp2->lastname))
	{
		for (int i = 0;i < strlen(temp1->lastname);i++)
		{
			if (temp1->lastname[i] != temp2->lastname[i])
			{
				return false;
			}
			
		}
		return true;
	}
	return false;
}