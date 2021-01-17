#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	printf("¬ведите размер матрицы: ");
	scanf("%d", &size);
	char** adj = gen_adj_matrix(size);
	pr_adj_matrix(adj, size);
	POG(adj, size);
	_getch();
}
