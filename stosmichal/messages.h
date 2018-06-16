#pragma once


enum Error
{
	MEMORY_ALLOCATION_PROBLEM = 1,
	File_Opening_Problem = 2,
	Print_FUNCTION_DOESNT_EXIST = 3,
	Save_Function_DOESNT_EXIST = 4,
	Load_Function_DOESNT_EXIST = 5,
	Comparing_Function_DOESNT_EXIST = 6,
	Data_Got_Lost = 7,
	Nothing_To_Push = 8,
	No_Elements_In_Stack = 9,
	There_Is_Nothing_To_Print = 10

};


void error(enum Error helper);