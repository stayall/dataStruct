#include<stdio.h>
#ifndef _Job_h

#define PeopleNumber 1
#define NotFree 1
#define Free 0
typedef unsigned time;
typedef unsigned Position;


struct JobRecord;
struct Customer;

void InitData(FILE* fd);
int ReadRecord(FILE* fd, Customer* p);
Position FindFree(int* a);

struct Customer
{
	time ComeTime;
	time WorkTime;
};

struct JobRecord
{
	time WaitingTime;
	time LieSureTime;
};
struct Work
{
	int IsFree[PeopleNumber] = { Free };
	Customer cus[PeopleNumber] = { 0 };
};

#endif // !_BusinessPeople_h
