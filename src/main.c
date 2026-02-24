#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	struct STUDENT st[7]; 
	double avg[7];
	Fill_Struct(st); 
	Print(st);
	Decrease(st, avg);
	Top_Student(st, avg);
	
	return 0;
}
