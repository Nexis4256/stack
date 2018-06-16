
#include "stdafx.h"
#include "messages.h"
#include <iostream>

using namespace std;


void error(enum Error helper)
{
	bool critical=true;
	switch (helper)
	{ 
	case 1:
		cout << "Critical Error  Memory Allocation Problem" << endl; 
		critical = false;
		break;
	case 2: 
		cout << "Critical Error File Opening Problem" << endl; 
		critical = false;
		break;
	case 3:
		cout << "Warning Allert  Print Function Doesn't Exist" << endl; 
		break;
	case 4: 
		cout << "Warning Allert  Save Function  Doesn't Exist" << endl;
		break;
	case 5:	
		cout << "Warning Allert Load Function Doesn't Exist" << endl; 
		break;
	case 6: 
		cout << "Error Comparing Function Doesn't Exist" << endl; 
		break;
	case 7:
		cout << "Critical Error The Data Got lost" << endl; 
		critical = false; 
		break;
	case 8:	
		cout << "Warning Allert New element is NULL, There is nothing to Push" << endl; 
		break;
	case 9:	
		cout << "Warning Allert There are no elements in Stack" << endl; 
		break;
	case 10:
		cout << "Warning Allert There is nothing to print" << endl;
		break;
	}
	if (critical==false) 
	{
		exit(1);
	}
}