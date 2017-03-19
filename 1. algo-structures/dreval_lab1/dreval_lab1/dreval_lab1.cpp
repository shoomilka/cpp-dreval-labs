// dreval_lab1.cpp : Defines the entry point for the console application.

/*****************************************************************************\
|* 1-27. Дано квадратну матрицю порядку n з цілими елементами. Знайти        *|
|* найменше із значень елементів стовбчика, сума модулів елементів котрого   *|
|* є найбільшою. Якщо таких стовбчиків існує декілька, то взяти перший із    *|
|* них.                                                                      *|
\*****************************************************************************/

#include "stdafx.h"

#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

int n;
int** a;

void iniArray() {
	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
}

void printArray() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\t" << a[i][j];
		}
		cout << endl;
	}
}

void randArray() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//a[i][j] = i + j;
			a[i][j] = rand() % 100;
		}
	}
}

void enterArray() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Vvedit element z " << i << " rjadka ";
			cout << j << " stovpchika:" << endl;
			cin >> a[i][j];
		}
	}
}

void findElement() {
	int max_sum = -1;
	int max_row = -1;
	int tempe;

	for (int i = 0; i < n; i++) {
		tempe = 0;
		for (int j = 0; j < n; j++) {
			tempe += abs(a[j][i]);
		}
		if (tempe > max_sum) {
			tempe = max_sum;
			max_row = i;
		}
	}

	tempe = a[0][max_row];
	int min_col = 0;
	for (int i = 1; i < n; i++) {
		if (tempe > a[i][max_row]) {
			tempe = a[i][max_row];
			min_col = i;
		}
	}

	cout << "Minimalnij element v 'maximalnomu' rjadku a[" << min_col << "][";
	cout << max_row << "] = " << tempe;
}

int main() {
	srand(time(NULL));
	cout << "Privet, Glinka!" << endl;
	cout << "Vvedit n:" << endl;
	cin >> n;
	if (n<-1) {
		n = abs(n);
		iniArray();
		randArray();
	} else if(n>1) {
			iniArray();
			enterArray();
		} else {
			cout << "error!";
			_getch();
			return -1;
		}

	cout << "Ccco-co-congratulations! Os' vin:" << endl;
	printArray();

	findElement();
	
	_getch();
	return 0;
}