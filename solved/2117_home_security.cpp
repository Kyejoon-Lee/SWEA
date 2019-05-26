#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
int home[21][21];
int m, n;
int pos;
int pre = 0;
int high = 0;
int check = 0;
void dfs(int x, int y, int cur) {

	int sum = 0;
	for (int i = 0; i < cur; i++) {
		int j = cur - 1 - i;
		if (i == 0 && j == 0) {
			if (home[y][x] == 1) {
				sum = sum + m;
				check++;
			}
			break;
		}
		if (y + i < n && x + j < n) {
			if (home[y + i][x + j] == 1) {
				sum = sum + m;
				check++;
			}
		}
		if (i != 0 && y - i >= 0 && x + j < n) {
			if (home[y - i][x + j] == 1) {
				sum = sum + m;
				check++;
			}
		}
		if (j != 0 && i != 0 && y - i >= 0 && x - j >= 0) {
			if (home[y - i][x - j] == 1) {
				sum = sum + m;
				check++;
			}
		}
		if (j != 0 && y + i < n && x - j >= 0) {
			if (home[y + i][x - j] == 1) {
				sum = sum + m;
				check++;
			}
		}

	}
	if (pow(cur, 2) + pow(cur - 1, 2) <= sum + pre) {
		if (high < check) {
			high = check;

		}
	}
	pre = sum + pre;

}

void order(int x, int y) {
	for (int i = 0; i <= n; i++) {

		if (i > 1 && ((i - 1) * 4 * m < (i * i - (i - 2) * (i - 2)))) {
			break;
		}
		dfs(x, y, i + 1);
	}
}

int main() {
	int num, set;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &home[i][j]);
			}
		}
		high = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pre = 0;
				check = 0;
				order(i, j);
			}
		}
		printf("#%d %d\n", num, high);
	}
}