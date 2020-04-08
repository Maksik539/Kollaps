#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;

void out_mas(int** world, int n) { //вывод массива
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << world[i][j] << " ";
		}
		cout << endl;
	}
}

bool cell_new_life(int** world, int n,int x,int y) {
	return 1;
}

void day(int** world, int** world_after, int n) { //один день эволюции
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (world[i][j]==0 && cell_new_life(world, n, i, j)) {
				world_after[i][j] = 1;
			}
		}
	}
}

void main() {
	//инициализация
	int n=5; //размер мира
	int** world; //мир
	world = new int*[n];
	int** world_after; //мир после дня эволюции
	world_after = new int* [n];
	for (int i = 0; i < n; i++) {
		world[i] = new int[n];
		world_after[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			world[i][j] = 0;
			world_after[i][j] = 0;
		}
	}
	out_mas(world, n);
	_getch();
}