#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
using namespace std;

void dfs(int** arr, int** check, int** visit, int n, int m, int x, int y, int time, int sum) {
	if (time == sum) {
		return;
	}
	check[y][x] = 1;
	int cur = arr[y][x];


	for (int i = 0; i < 4; i++) {
		if (i == 0 && (cur == 3 || cur == 5 || cur == 6)) continue;
		if (i == 1 && (cur == 2 || cur == 6 || cur == 7)) continue;
		if (i == 2 && (cur == 3 || cur == 4 || cur == 7))continue;
		if (i == 3 && (cur == 2 || cur == 4 || cur == 5))continue;

		int xpos = x + dx[i];
		int ypos = y + dy[i];


		if (xpos < 0 || ypos < 0 || xpos >= m || ypos >= n) continue;
		int next = arr[ypos][xpos];
		if (next == 0 || visit[ypos][xpos] == 1)continue;

		if (i == 0 && (next == 3 || next == 4 || next == 7)) continue;
		if (i == 1 && (next == 2 || next == 4 || next == 5)) continue;
		if (i == 2 && (next == 3 || next == 5 || next == 6)) continue;
		if (i == 3 && (next == 2 || next == 6 || next == 7)) continue;

		visit[ypos][xpos] = 1;
		dfs(arr, check, visit, n, m, xpos, ypos, time, sum + 1);
		visit[ypos][xpos] = 0;
	}


}
int main() {
	int set, num, n, m, x, y, time;
	int i, j;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d %d %d", &n, &m, &y, &x, &time);
		int** arr;
		arr = (int**)malloc(sizeof(int*) * n);
		for (i = 0; i < n; i++) {
			arr[i] = (int*)malloc(sizeof(int) * m);
		}
		int** check;
		check = (int**)malloc(sizeof(int*) * n);
		for (i = 0; i < n; i++) {
			check[i] = (int*)calloc(m, sizeof(int));
		}
		int** visit;
		visit = (int**)malloc(sizeof(int*) * n);
		for (i = 0; i < n; i++) {
			visit[i] = (int*)calloc(m, sizeof(int));
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		int possible = 0;
		dfs(arr, check, visit, n, m, x, y, time, 0);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (check[i][j] == 1)
					possible++;
			}
		}
		printf("#%d %d\n", num, possible);

	}
	return 0;
}
