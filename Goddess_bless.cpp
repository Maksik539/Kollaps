#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;

void out_mas(int** world, int n) { //вывод массива
	cout << endl;
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << world[i][j] << " ";
		}
		cout << endl;
	}
}

int num_life(int** world, int n,int x,int y) {
	int num = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x+i<n && y+j<n && x+i>=0 && y+j>=0 && !(i == 0 && j == 0)) {
				if (world[x+i][y+j] == 1) {
					num++;
				}
			}
			if (num > 3) {
				return 0;
			}
		}
	}
	cout << num << endl;
	if (num < 2) {
		return 0;
	}
	else {
		return num;
	}
}

void day(int** world, int** world_after, int n) { //один день эволюции
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (world[i][j] == 0) {
				if (num_life(world, n, i, j) == 3) {
					world_after[i][j] = 1;
				}
			}
			else {
				if (num_life(world, n, i, j) != 0) {
					world_after[i][j] = 1;
				}
			}
			
		}
	}
}

void main() {
	//инициализация
	int n=5; //размер мира
	int** world;  //мир
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
	world[2][1] = 1;
	world[1][2] = 1;
	world[3][2] = 1;
	out_mas(world, n);
	day(world, world_after, n);
	out_mas(world_after, n);
	_getch();
}