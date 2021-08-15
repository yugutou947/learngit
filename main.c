#include <stdio.h>
#include <stdlib.h>
#define  NUM 40
#define  LINE 6

void fillarry(int num, double * arry)
{
	for(int index = 0; index < num; index++)
	{
		arry[index] = rand() / (rand() + 0.1);
	}
}

void showarry(int num, const double * arry)
{
	for(int index = 0; index < num; index++)
	{
		printf("%6.2lf", arry[index]);
		if(index % 6 == 5)
		{
			putchar('\n');
		}
	}
	putchar('\n');
}

int mycompare(const void * p1, const void * p2)
{
	const double * a1 = (const double *)p1;
	const double * a2 = (const double *)p2;
	
	if(*a1 < *a2)
	{
		return -1;
	}
	else if(*a1 == *a2)
	{
		return 0;
	}
	else 
	return 1;
}

int main() 
{
	double arryy[NUM];
	fillarry(NUM, arryy);
	showarry(NUM, arryy);
	qsort(arryy, NUM, sizeof(double), mycompare);
	showarry(NUM, arryy);
	
	return 0;
}
