#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;

void out_mas(int** World, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << World[i][j] << " ";
		}
		cout << endl;
	}
}

void main() {
	//инициализация
	int n=5; //размер мира
	int** World; //мир
	World = new int*[n];
	for (int i = 0; i < n; i++) 
		World[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			World[i][j] = 0;
		}
	}
	out_mas(World, n);
	_getch();
}