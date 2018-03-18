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
				/*�������
					�������
					���������� ���
					���������� ����������� ����	
					���������� ������� ������� ���������� � ������� �������� � ����������, ������� ������� ������ 25 ���*/
				struct iceHockey *team;
				int numb, averageAge = 0;
				printf("������� ���-�� ���������� - ");
				scanf_s("%d", &numb);
				team = (iceHockey*)calloc(numb, sizeof(iceHockey));
				if (team == NULL)
				{
					printf("ERRROR\n");
					EXIT_FAILURE;
				}
				StructFilling(team, &numb);
				AverageNumb(team, &numb, &averageAge);
				printf("������� ������� ���� ������� - %d\n", averageAge);
				PrintFullInform(team, &numb);
				free(team);
			} break;

			case 2:
			{
				//���������� ����� ��������� ���� �������, ���������� � ������� ���� � ������� �������� �� ���� �������
				struct products *product;
				int numb, sum = 0;
				printf("������� ���-�� ������������ ��������� - ");
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
				printf("\n����� ��������� ���� ������� = %d\n", sum);
			} break;

			case 3:
			{
				//���������� ����� ��������� ���� �������, ���������� � ������� ���� � ������� �������� �� ���� �������
				struct products *product;
				int numb, sum = 0;
				printf("������� ���-�� ������������ ��������� - ");
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
				printf("\n����� ��������� ���� ������� = %d\n", sum);
			} break;

			case 4:
			{
				//���������� ������ �������� ��������� � ���������� �������� � ���.
				struct workers *worker;
				int numb, count = 0;
				printf("������� ���-�� ����������� - ");
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
				//���������� ������� ���������, ������� ����� ���������� �� �95�, � ���������� �� ����������.
				struct students * student;
				int numb, count = 0;
				printf("������� ���-�� ��������� - ");
				scanf_s("%d", &numb);
				student = (students*)calloc(numb, sizeof(students));
				if (student == NULL)
				{
					printf("ERRROR\n");
					EXIT_FAILURE;
				}
				StudentsInformation(student, &numb, &count);
				printf("\n------------------------\n");
				printf("���-�� ���������, ��� ���� �� ����� > 95 - %d\n��������� ���������� � ���:\n", count);
				PrintStudentsInform(student, &numb);
			} break;
		}
	} while (task > 0);
}