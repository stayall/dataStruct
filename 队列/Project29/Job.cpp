#include "Job.h"
#include <stdlib.h>
#define A 48271L
#define M 2147483647L
#define UnderTime 100L
#define OverTime 500L
#define MaxTime 10000L
#define CustomerNumber 50

static unsigned long Seed = 10;

static int Random(void)
{
	Seed = (A * Seed) % M;
	return Seed / 100000L;
}


void InitData(FILE *fd)
{
	if (fd == NULL)
	{
		return;
	}

	int count = 0, ComeTime = 0, WorkTime = 0, LastMaxTime = 0;

	int tmp = 2000;
	while (true)
	{
		srand(ComeTime);
		ComeTime = rand()%10500 + LastMaxTime;
		WorkTime = rand()%1000 + 1000;
		if (ComeTime <= LastMaxTime + tmp && ComeTime >= LastMaxTime)
		{
			fprintf_s(fd, "%d %d\n", ComeTime, WorkTime);
			count++;
			LastMaxTime = ComeTime;
			
		}
		if (count == CustomerNumber)
			break;
	}

	fclose(fd);
}

//Customer ReadRecord(const char *filename)
//{
//	FILE* fd = NULL;
//	fopen_s(&fd, filename, "r");
//	if (fd == NULL)
//	{
//		return;
//	}
//
//	Customer tmp;
//	fscanf_s(fd, "%d %d\n", tmp.ComeTime, tmp.WorkTime);
//
//	return tmp;
//}

int ReadRecord(FILE *fd, Customer *p)
{
	if (fd == NULL)
	{
		return -1;
	}
	int a =  fscanf_s(fd, "%d %d\n", &p->ComeTime, &p->WorkTime);
	return a;
}

Position FindFree(int* a)
{
	for (int i = 0; i < PeopleNumber; i++)
	{
		if (a[i] == Free)
		{
			return i;
		}
	}

	return -1;
}