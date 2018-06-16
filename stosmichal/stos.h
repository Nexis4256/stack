#pragma once


#include<fstream>


using namespace std;
class stack
{
private:
	void *pdata;
	stack *link;
public:
	stack();
	~stack();
	int size();
	void push_elements(void*);
	void push_link(stack*);
	void add_n(int);
	void print_all(void(* )(void* ));          //SF brak implementacji
	void save_all(void(* )(void*,FILE *)); //SF brak implementacji
	void *take_pdata();
	void load_all(stack*, void*(* )(FILE *)); //SF brak implementacji
	stack *pop(stack*, void* &);
	bool find(void*, bool(*)(void*, void*));
};