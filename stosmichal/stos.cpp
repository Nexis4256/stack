#include "stdafx.h"
#include "stos.h"
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "messages.h"
#include "my_interface.h"


using namespace std;

#pragma warning(disable : 4996)


static int n=0;   //SF  ???


stack::stack()
{
	pdata = NULL;
	link = NULL;
}

stack::~stack()
{
	if (pdata != NULL)
	{
		//SF gubi Pan pamiec.
		delete(pdata);
	}
	if (link != NULL)
	{
		//SF ???  
		delete(link);
	}
}


void *stack::take_pdata()
{
	return pdata;
}


void stack::push_elements(void *pdata_new)
{
	if (pdata_new != NULL) {
		pdata = pdata_new;
	}
	else{
		error(Nothing_To_Push);
	}
}

int stack::size()
{
	return n;
}

void stack::push_link(stack* new_link)  //???
{
	link = new_link;
}

void stack::add_n(int a)
{
	n += a;
}

stack* pushmain(stack *top)
{
			if ((top->size()) == 0)
			{
				top->push_elements(push());
				top->add_n(1);
				return top;
			}
			else
			{
				stack *temp = new stack;
				if (temp == NULL)
				{
					error(MEMORY_ALLOCATION_PROBLEM);
				}
				temp->push_elements(push());
				if (temp->take_pdata() != NULL) {
					temp->push_link(top);
					temp->add_n(1);
					return temp;
				}
				else {
					delete temp;
					return top;
				}



			}
		

		return top;
}

void stack::print_all(void(*print_elem)(void* pdata))
{
	if (pdata != NULL)
	{
		if (print_elem != NULL)
		{


			print_elem(pdata);

			stack *actuall = link;

			for (int i = 1;i < n;i++)
			{
				if (actuall == NULL)
				{
					error(Data_Got_Lost);
				}
				cout << endl;
				print_elem(actuall->pdata);
				actuall = actuall->link;
			}
		}
		else
		{
			error(Print_FUNCTION_DOESNT_EXIST);
		}
	}
	else
	{
		error(There_Is_Nothing_To_Print);
	}
}




void stack::save_all(void(*save_elem)(void* pdata,FILE *fp))
{
	if (save_elem!= NULL)
	{
		FILE *fp;
		stack *temp = link;
		fp = fopen("score.bin", "wb+");
		fwrite(&n, sizeof(int), 1, fp);
		save_elem(pdata, fp);
		for (int i = 1;i < n;i++)
		{
			save_elem(temp->take_pdata(),fp);
			temp = temp->link;
		}
		fclose(fp);
	}
	else
	{
		error(Save_Function_DOESNT_EXIST);
	}
}
void stack::load_all(stack* first, void*(*load_elem)(FILE *fp))
{
	if (load_elem != NULL)
	{
		FILE *fp;
		stack *temp = NULL;
		fp = fopen("score.bin", "rb");
		//SF przy odczycie tu powstaje GP. Oznacza to, ze Pan nie odnalazl czasu na elementarne testowanie wlasnej aplikacji.
		//Informuje, ze jesli jeszcze raz dostane projekt w takim stanie, ja anuluje Panu ten projekt i dam znacznie badziej zlozony.
		fread(&n, sizeof(int), 1, fp);
		first->pdata = load_elem(fp);
		for (int i = 1;i < n;i++)
		{
			temp = new stack;
			temp->link = NULL;
			first->pdata = load_elem(fp);
			first->link = NULL;
			first = temp;
			temp = NULL;

		}
		temp = NULL;
		fclose(fp);
	}
	else
	{
		error(Load_Function_DOESNT_EXIST);
	}
}



stack * stack::pop(stack *cosiek,void* & ptr )   // & dla dostepu bezposredniego do wskaznika
{
	if (ptr == NULL)
	{
		if (cosiek->pdata != NULL)
		{
			ptr = cosiek->pdata;
			cosiek->pdata = NULL;
			stack *temp = cosiek->link;
			cosiek->link = NULL;
			n--;
			if (n == 0)
			{
				return cosiek;
			}
			delete(cosiek);
			return temp;
		}
		else
		{
			error(No_Elements_In_Stack);
		}
	}
	return cosiek;
}


bool stack::find(void* boolean, bool(*comparing)(void *, void *))
{
	if (boolean != NULL)
	{


		stack *temp = NULL;
		void *tempvoid = pdata;
		if (comparing(pdata, boolean))
		{
			delete(boolean);
			return true;
		}
		temp = link;
		for (int i = 1;i < n;i++)
		{
			tempvoid = temp->pdata;
			if (comparing(tempvoid, boolean))
			{
				delete(boolean);
				return true;
			}
			temp = temp->link;
		}
		delete(boolean);
		return false;
	}
	else
	{
		error(Comparing_Function_DOESNT_EXIST);
	}
	return NULL;
}