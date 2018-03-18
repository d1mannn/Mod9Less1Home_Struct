#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Header.h"
#include <time.h>
#include <Windows.h>
#include "Struct_Ice_hockey.h"
#include "StructProductsInform.h"
#include "StructWorkerInform.h"
#include "StructStudentsScores.h"

int TaskNumb()
{
	setlocale(LC_ALL, "Rus");
	int task;
	printf("������� ����� ������� - ");
	scanf_s("%d", &task);
	return task;
}

void StructFilling(struct iceHockey * team, int * numbOfPlayers)
{	
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	char Name[20];
	for (int i = 0; i < *numbOfPlayers; i++)
	{	
		getchar();
		printf("������� ������� ������ - ");
		gets_s(Name, 20);
		strcpy_s(team[i].LastName, Name);
		printf("������� ������� - ");
		scanf_s("%d", &team[i].Age);
		printf("������� ���������� ��������� ������ - ");
		scanf_s("%d", &team[i].CountOfGame);
		printf("������� ���������� ����������� ���� - ");
		scanf_s("%d", &team[i].Goals);
	}
}

void AverageNumb(struct iceHockey * average, int * numbOfPlayers, int * numb)
{
	for (int i = 0; i < *numbOfPlayers; i++)
	{
		*numb += *numb + average[i].Age;
	}
}

void PrintFullInform(struct iceHockey * team, int *numbOfPlayers)
{	
	setlocale(LC_ALL, "Rus");
	printf("������� ������� ���������, � ������� ����� ������ ���������� - ");
	int age;
	scanf_s("%d", &age);
	for (int i = 0; i < *numbOfPlayers; i++)
	{
		if (team[i].Age < age)
		{
			printf("������� ������ - %s\n", team[i].LastName);
			printf("������� - %d\n", team[i].Age);
			printf("R��������� ��������� ������ -  %d\n", team[i].CountOfGame);
			printf("���������� ����������� ���� - %d\n", team[i].Goals);
		}
	}
}

void StructFilling2(struct products * product, int * quantityOfProducts)
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	char Name[40];
	for (int i = 0; i < *quantityOfProducts; i++)
	{
		getchar();
		printf("������� ������������ %d-�� �������� - ", i + 1);
		gets_s(Name, 20);
		strcpy_s(product[i].nameOfProduct, Name);
		getchar();
		printf("������� �������� ������������� - ");
		gets_s(Name, 20);
		strcpy_s(product[i].maker, Name);
		printf("������� ��� ������� - ");
		scanf_s("%d", &product[i].year);
		printf("������� ���������� ������ - ");
		scanf_s("%d", &product[i].quantity);
		printf("������� ���� ����� ������� - ");
		scanf_s("%d", &product[i].price);
	}
}

void PrintFullInform2(struct products * product, int *numb)
{
	setlocale(LC_ALL, "Rus");
	int sum = 0;
	for (int i = 0; i < *numb; i++)
	{
		printf("%d.\t������������ - %s\n", i + 1, product[i].nameOfProduct);
		printf("\t ������������� - %s\n", product[i].maker);
		printf("\t ��� ������� - %d\n", product[i].year);
		printf("\t ���������� ������ - %d\n", product[i].quantity);
		printf("\t ���� ����� ������� - %d\n", product[i].price);
		printf("\t ��������� ���� ��������� = %d\n", product[i].price * product[i].quantity);
	}
}

void Sum(struct products *product, int * numb, int * sum)
{
	for (int i = 0; i < *numb; i++)
	{
		*sum = *sum + (product[i].price * product[i].quantity);
	}
}

void WorkersInform(struct workers * worker, int * numb)
{
	setlocale(LC_ALL, "Rus");
	char name[20];
	for (int i = 0; i < *numb; i++)
	{	
		getchar();
		printf("������� ������� %d-�� ���������� - ", i + 1);
		gets_s(name, 20);
		strcpy_s(worker[i].LastName, name);
		printf("������� ��� �������� - ");
		scanf_s("%d", &worker[i].YearOfBirth);
		printf("������� ��������� - ");
		getchar();
		gets_s(name, 20);
		strcpy_s(worker[i].Position, name);
		printf("������� ������ �/� - ");
		scanf_s("%d", &worker[i].Salary);
		printf("����������� - ");
		getchar();
		gets_s(name, 20);
		strcpy_s(worker[i].Education, name);
	}
}

void TheYoungestWorker(struct workers * worker, int * numb, int * count)
{
	int max = worker[0].YearOfBirth;
	for (int i = 0; i < *numb; i++)
	{
		if (worker[i].YearOfBirth > max)
		{
			max = worker[i].YearOfBirth;
			*count = i;
		}
	}
}

void PrintFullInform3(struct workers * worker, int * count)
{	
	setlocale(LC_ALL, "Rus");
	printf("����� ������� ��������� - %s\n", worker[*count].LastName);
	printf("��� �������� - %d\n", worker[*count].YearOfBirth);
	printf("��������� - %s\n",worker[*count].Position);
	printf("��� �/� - %d\n", worker[*count].Salary);
	printf("����������� - %s\n", worker[*count].Education);
}

void StudentsInformation(struct students * student, int * numb, int * count)
{
	setlocale(LC_ALL, "Rus");
	char name[20];
	for (int i = 0; i < *numb; i++)
	{
		printf("������� ������� %d-�� �������� - ", i + 1);
		getchar();
		gets_s(name, 20);
		strcpy_s(student[i].LastName, name);
		printf("������� ����� ������ - ");
		scanf_s("%d", &student[i].numbOfGroup);
		printf("��� �������� - ");
		scanf_s("%d", &student[i].yearOfBirth);
		printf("����� �� ����� - ");
		scanf_s("%d", &student[i].MathScore);
		if (student[i].MathScore > 95)
			*count = *count + 1;
		printf("����� �� ������ - ");
		scanf_s("%d", &student[i].PhysicScore);
		printf("����� �� ����������� - ");
		scanf_s("%d", &student[i].ITscore);
	}
}

void PrintStudentsInform(struct students *student, int * numb)
{
	for (int i = 0; i < *numb; i++)
	{
		if (student[i].MathScore > 95)
		{
			printf("������� �������� - %s\n", student[i].LastName);
			printf("����� ������ - %d\n\n", student[i].numbOfGroup);
		}
	}
}