#pragma once
int TaskNumb();
void StructFilling(struct iceHockey * team, int * numbOfPlayers);
void AverageNumb(struct iceHockey * average, int * numbOfPlayers, int * numb);
void PrintFullInform(struct iceHockey * team, int *numbOfPlayers);
void StructFilling2(struct products * product, int * quantityOfProducts);
void Sum(struct products *product, int * numb, int * sum);
void PrintFullInform2(struct products * product, int *numb);
void WorkersInform(struct workers * worker, int * numb);
void TheYoungestWorker(struct workers * worker, int * numb, int * count);
void PrintFullInform3(struct workers * worker, int * count);
void PrintStudentsInform(struct students *student, int * numb);
void StudentsInformation(struct students * student, int * numb, int * count);