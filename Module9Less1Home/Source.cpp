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

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int task;
	do
	{
		task = TaskNumb();
		switch (task)
		{
			case 1:
			{
				/*Фамилия
					Возраст
					Количество игр
					Количество заброшенных шайб	
					Определить средний возраст хоккеистов и вывести сведения о хоккеистах, возраст которых меньше 25 лет*/
				struct iceHockey *team;
				int numb, averageAge = 0;
				printf("Введите кол-во хоккеистов - ");
				scanf_s("%d", &numb);
				team = (iceHockey*)calloc(numb, sizeof(iceHockey));
				if (team == NULL)
				{
					printf("ERRROR\n");
					EXIT_FAILURE;
				}
				StructFilling(team, &numb);
				AverageNumb(team, &numb, &averageAge);
				printf("Средний возраст всех игроков - %d\n", averageAge);
				PrintFullInform(team, &numb);
				free(team);
			} break;

			case 2:
			{
				//Определить общую стоимость всех товаров, выпущенных в текущем году и вывести сведения об этих товарах
				struct products *product;
				int numb, sum = 0;
				printf("Введите кол-во наименований продукции - ");
				scanf_s("%d", &numb);
				product = (products*)calloc(numb, sizeof(products));
				if (product == NULL)
				{
					printf("ERRROR\n");
					EXIT_FAILURE;
				}
				StructFilling2(product, &numb);
				Sum(product, &numb, &sum);
				PrintFullInform2(product, &numb);
				printf("\nОбщая стоимость всех товаров = %d\n", sum);
			} break;

			case 3:
			{
				//Определить общую стоимость всех товаров, выпущенных в текущем году и вывести сведения об этих товарах
				struct products *product;
				int numb, sum = 0;
				printf("Введите кол-во наименований продукции - ");
				scanf_s("%d", &numb);
				product = (products*)calloc(numb, sizeof(products));
				if (product == NULL)
				{
					printf("ERRROR\n");
					EXIT_FAILURE;
				}
				StructFilling2(product, &numb);
				Sum(product, &numb, &sum);
				PrintFullInform2(product, &numb);
				printf("\nОбщая стоимость всех товаров = %d\n", sum);
			} break;

			case 4:
			{
				//Определить самого младшего работника и напечатать сведения о нем.
				struct workers *worker;
				int numb, count = 0;
				printf("Введите кол-во сотрудников - ");
				scanf_s("%d", &numb);
				worker = (workers*)calloc(numb, sizeof(workers));
				if (worker == NULL)
				{
					printf("ERRROR\n");
					EXIT_FAILURE;
				}
				WorkersInform(worker, &numb);
				TheYoungestWorker(worker, &numb, &count);
				PrintFullInform3(worker, &count);
			} break;

			case 5:
			{
				//Напечатать фамилии студентов, которые сдали математику на «95», и определить их количество.
				struct students * student;
				int numb, count = 0;
				printf("Введите кол-во студентов - ");
				scanf_s("%d", &numb);
				student = (students*)calloc(numb, sizeof(students));
				if (student == NULL)
				{
					printf("ERRROR\n");
					EXIT_FAILURE;
				}
				StudentsInformation(student, &numb, &count);
				printf("\n------------------------\n");
				printf("Кол-во студентов, чей балл по матем > 95 - %d\nПодробная информация о них:\n", count);
				PrintStudentsInform(student, &numb);
			} break;
		}
	} while (task > 0);
}