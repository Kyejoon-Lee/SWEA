#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

int desert[101] = { 0 };
int dx[] = { -1,-1,1,1 };
int dy[] = { 1,-1,1,-1 };
int di[] = { 0 ,0,0,0, 0 };

void dfs(int** arr, int** check, int x, int y, int conx, int cony, int n, int* sum) {



	if ((conx == x && cony == y) && (di[0] + di[1] + di[2] + di[3] >= 3)) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 1) {
					temp++;
				}

			}
		}
		if (temp != 1 && temp > * sum) {
			*sum = temp;
		}
		return;

	}
	int cur = arr[y][x];
	if (desert[cur] == 1) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		int xpos = x + dx[i];
		int ypos = y + dy[i];
		if (xpos < 0 || ypos < 0 || xpos >= n || ypos >= n) {
			continue;
		}
		if (di[i] == 1) {
			continue;
		}
		int pcheck = 4;
		int next = arr[ypos][xpos];
		for (int j = 0; j < 4; j++) {
			int rxpos = x - dx[j];
			int rypos = y - dy[j];
			if (rxpos < 0 || rypos < 0 || rxpos >= n || rypos >= n) {
				continue;
			}
			if (check[rypos][rxpos] == 1) {
				if (di[j] != 1) {
					if (i != j) {
						pcheck = j;
						di[j] = 1;
						break;
					}
				}
			}

		}
		check[y][x] = 1;
		desert[cur] = 1;
		dfs(arr, check, xpos, ypos, conx, cony, n, sum);
		check[y][x] = 0;
		desert[cur] = 0;
		di[pcheck] = 0;
	}
}

int main() {
	int set, num, n;
	int i, j;

	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &n);
		int** arr;
		arr = (int**)malloc(sizeof(int*) * n);
		for (i = 0; i < n; i++) {
			arr[i] = (int*)malloc(sizeof(int) * n);
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		int** check;
		check = (int**)malloc(sizeof(int*) * n);
		for (i = 0; i < n; i++) {
			check[i] = (int*)calloc(n, sizeof(int));
		}
		int sum = -1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				dfs(arr, check, j, i, j, i, n, &sum);
			}
		}
		printf("#%d %d\n", num, sum);
	}

	return 0;
}