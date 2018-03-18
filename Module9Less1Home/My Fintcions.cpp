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
	printf("Введите номер задания - ");
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
		printf("Введите фамилию игрока - ");
		gets_s(Name, 20);
		strcpy_s(team[i].LastName, Name);
		printf("Введите возраст - ");
		scanf_s("%d", &team[i].Age);
		printf("Введите количество сыгранных матчей - ");
		scanf_s("%d", &team[i].CountOfGame);
		printf("Введите количество заброшенных шайб - ");
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
	printf("Введите возраст хоккеиста, о которых нужна полная информация - ");
	int age;
	scanf_s("%d", &age);
	for (int i = 0; i < *numbOfPlayers; i++)
	{
		if (team[i].Age < age)
		{
			printf("Фамилия игрока - %s\n", team[i].LastName);
			printf("Возраст - %d\n", team[i].Age);
			printf("Rоличество сыгранных матчей -  %d\n", team[i].CountOfGame);
			printf("Количество заброшенных шайб - %d\n", team[i].Goals);
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
		printf("Введите наименование %d-го продукта - ", i + 1);
		gets_s(Name, 20);
		strcpy_s(product[i].nameOfProduct, Name);
		getchar();
		printf("Введите название производителя - ");
		gets_s(Name, 20);
		strcpy_s(product[i].maker, Name);
		printf("Введите год выпуска - ");
		scanf_s("%d", &product[i].year);
		printf("Введите количество товара - ");
		scanf_s("%d", &product[i].quantity);
		printf("Введите цену одной единицы - ");
		scanf_s("%d", &product[i].price);
	}
}

void PrintFullInform2(struct products * product, int *numb)
{
	setlocale(LC_ALL, "Rus");
	int sum = 0;
	for (int i = 0; i < *numb; i++)
	{
		printf("%d.\tНаименование - %s\n", i + 1, product[i].nameOfProduct);
		printf("\t Производитель - %s\n", product[i].maker);
		printf("\t Год выпуска - %d\n", product[i].year);
		printf("\t Количество товара - %d\n", product[i].quantity);
		printf("\t Цена одной единицы - %d\n", product[i].price);
		printf("\t Стоимость всей продукции = %d\n", product[i].price * product[i].quantity);
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
		printf("Введите фамилию %d-го сотрудника - ", i + 1);
		gets_s(name, 20);
		strcpy_s(worker[i].LastName, name);
		printf("Введите год рождения - ");
		scanf_s("%d", &worker[i].YearOfBirth);
		printf("Введите должность - ");
		getchar();
		gets_s(name, 20);
		strcpy_s(worker[i].Position, name);
		printf("Введите размер з/п - ");
		scanf_s("%d", &worker[i].Salary);
		printf("Образование - ");
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
	printf("Самый младший сотрудник - %s\n", worker[*count].LastName);
	printf("Год рождения - %d\n", worker[*count].YearOfBirth);
	printf("Должность - %s\n",worker[*count].Position);
	printf("Его з/п - %d\n", worker[*count].Salary);
	printf("Образование - %s\n", worker[*count].Education);
}

void StudentsInformation(struct students * student, int * numb, int * count)
{
	setlocale(LC_ALL, "Rus");
	char name[20];
	for (int i = 0; i < *numb; i++)
	{
		printf("Введите фамилию %d-го студента - ", i + 1);
		getchar();
		gets_s(name, 20);
		strcpy_s(student[i].LastName, name);
		printf("Введите номер группы - ");
		scanf_s("%d", &student[i].numbOfGroup);
		printf("Год рождения - ");
		scanf_s("%d", &student[i].yearOfBirth);
		printf("Баллы по матем - ");
		scanf_s("%d", &student[i].MathScore);
		if (student[i].MathScore > 95)
			*count = *count + 1;
		printf("Баллы по физике - ");
		scanf_s("%d", &student[i].PhysicScore);
		printf("Баллы по информатике - ");
		scanf_s("%d", &student[i].ITscore);
	}
}

void PrintStudentsInform(struct students *student, int * numb)
{
	for (int i = 0; i < *numb; i++)
	{
		if (student[i].MathScore > 95)
		{
			printf("Фамилия студента - %s\n", student[i].LastName);
			printf("Номер группы - %d\n\n", student[i].numbOfGroup);
		}
	}
}