#include "Queue.h"
#include <stdio.h>

int main()
{
	Queue Q;
	Position P;
	Work W;
	int i = 0;
	Customer NewCell, LastCell = {0, 0};
	JobRecord Record = {0 , 0};

	Q = CreateQueue(100);

	FILE *fd = NULL;
	//fopen_s(&fd, "C:\\Users\\asus\\Desktop\\1.txt", "w");
	//InitData(fd);
	//fclose(fd);

	fopen_s(&fd, "C:\\Users\\asus\\Desktop\\1.txt", "r");

	while (true)
	{

		if((ReadRecord(fd, &NewCell)) != -1)
		{
			Enqueue(NewCell, Q);
		}
		if (!IsEmpty(Q))
		{
			NewCell = FrontAndDequeu(Q);
		}
		else
		{
			break;
		}


		int k = -1;
		for (int i = 0; i < PeopleNumber; i++)
		{
			if (W.IsFree[i] == Free)
			{
				k = i;
				break;
			}
			if (NewCell.ComeTime >= W.cus[i].ComeTime + W.cus[i].WorkTime)
			{
				k = i;
			}
		}

		if (k >= 0)
		{
			Record.LieSureTime += NewCell.ComeTime - (W.cus[k].ComeTime + W.cus[k].WorkTime);
			W.cus[k] = NewCell;
			W.IsFree[k] = NotFree;
		}
		else
		{
			k = 0;
			for (int i = 0; i < PeopleNumber; i++)
			{
				if (W.cus[k].ComeTime + W.cus[k].WorkTime <= W.cus[i].ComeTime + W.cus[i].WorkTime)
				{
					k = i;
				}
			}

			Record.WaitingTime += (W.cus[i].ComeTime + W.cus[i].WorkTime) - NewCell.ComeTime;
			W.cus[i].WorkTime += NewCell.WorkTime;
		}

	}


	/*while (1)
	{
		if ((ReadRecord(fd, &NewCell)) != EOF)
		{
			for (int j = 0; j < PeopleNumber; j++)
			{
				if (NewCell.ComeTime >= W.cus[j].ComeTime + W.cus[j].WorkTime)
				{
					Record.LieSureTime += (NewCell.ComeTime - (W.cus[j].ComeTime + W.cus[j].WorkTime));
					if (IsEmpty(Q))
					{
						W.cus[j].ComeTime = NewCell.ComeTime;
						W.IsFree[j] = Free;
					}
				}
				else
				{
					Enqueue(NewCell, Q);
				}
			}

			if ((i = FindFree(W.IsFree)) >= 0)
			{
				if (IsEmpty(Q))
				{
					W.cus[i] = NewCell;
					W.IsFree[i] = NotFree;
				}

				while (i >= 0&&!IsEmpty(Q))
				{

					Enqueue(NewCell, Q);
					NewCell = FrontAndDequeu(Q);
					Record.WaitingTime += (W.cus[i].ComeTime + W.cus[i].WorkTime) - NewCell.ComeTime;
					W.cus[i] = NewCell;
					W.IsFree[i] = NotFree;
					i = FindFree(W.IsFree);
				}

			}
			else
			{
				Enqueue(NewCell, Q);
			}

		}
		else if((!IsEmpty(Q)))
		{
			NewCell = FrontAndDequeu(Q);
				int k = 0;
				for (int i = 0; i < PeopleNumber; i++)
				{
					if (W.cus[k].ComeTime + W.cus[k].WorkTime <= W.cus[i].ComeTime + W.cus[i].WorkTime)
					{
						k = i;
					}
				}

				if(NewCell.ComeTime > (W.cus[k].ComeTime + W.cus[k].WorkTime))
					Record.LieSureTime += NewCell.ComeTime - (W.cus[k].ComeTime + W.cus[k].WorkTime);
			
				Record.WaitingTime += (W.cus[k].ComeTime + W.cus[k].WorkTime - NewCell.ComeTime);
				W.cus[k].WorkTime += NewCell.WorkTime;
		}
		else
		{
			break;
		}
	}*/

	printf("业务人员休息：%d, 顾客等待时间：%d", Record.LieSureTime, Record.WaitingTime);
	
}

