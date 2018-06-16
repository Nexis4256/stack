

#pragma once
#include "stdafx.h"
#include "stos.h"

using namespace std;

enum INTERFACE
{
	INTERFACE_INIT,
	INTERFACE_PUSH,
	INTERFACE_PRINT,
	INTERFACE_SAVE,
	INTERFACE_LOAD,
	INTERFACE_CLEAR,
	INTERFACE_POP, 
	INTERFACE_COMPARING,
	INTERFACE_END,
	INTERFACE_LAST
};

void menu();
void *push();
stack *init(stack *top);
stack* pushmain(stack *top);