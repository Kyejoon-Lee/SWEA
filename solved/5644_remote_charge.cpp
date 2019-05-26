#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int map[21][21];
int x;
int n;
int max = 0;

void path(int pos) {
	int i, check = 1;
	int flag = 0;
	for (i = 0; i < n - 1; i++) {
		if (map[pos][i] == map[pos][i + 1]) {
			check++;
			if (flag == 1) {
				if (check == x) {
					check = 0;
					flag = 0;
				}
			}
		}
		else if (map[pos][i] - map[pos][i + 1] == -1) {
			if (check >= x) {
				check = 1;
			}
			else {
				break;
			}
		}
		else if (map[pos][i] - map[pos][i + 1] == 1) {
			if (flag == 1) {
				break;
			}
			check = 1;
			flag = 1;
		}
		else {
			break;
		}
		if (i == n - 2 && flag == 0) {
			max++;
		}
	}
	check = 1;
	flag = 0;
	for (i = 0; i < n - 1; i++) {
		if (map[i][pos] == map[i + 1][pos]) {
			check++;
			if (flag == 1) {
				if (check == x) {
					check = 0;
					flag = 0;
				}
			}
		}
		else if (map[i][pos] - map[i + 1][pos] == -1) {
			if (check >= x) {
				check = 1;
			}
			else {
				break;
			}
		}
		else if (map[i][pos] - map[i + 1][pos] == 1) {
			if (flag == 1) {
				break;
			}
			check = 1;
			flag = 1;
		}
		else {
			break;
		}
		if (i == n - 2 && flag == 0) {
			max++;
		}
	}

}

void dfs() {
	int i;
	for (i = 0; i < n; i++) {
		path(i);
	}
}

int main() {
	int i, j, num, set;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &n, &x);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		max = 0;
		dfs();
		printf("#%d %d\n", num, max);
	}
	return 0;
}