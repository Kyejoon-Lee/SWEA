#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
/// 13:30;
int N;
int map[100][100];
/// up down left right
int d1[] = { 1,3,0,2 };
int d2[] = { 3,0,1,2 };
int d3[] = { 2,0,3,1 };
int d4[] = { 1,2,3,0 };
int d5[] = { 1,0,3,2 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int visited[100][100][4];
int cnt = 0;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = -1;
			}
		}
	}
}

void go(int x, int y, int di) {
	int tx = x;
	int ty = y;
	int tdi = di;
	int point = 0;
	while (1) {
		tx += dx[tdi];
		ty += dy[tdi];
		if (tx < 0) {
			tx = 0;
			tdi = 3;
			point++;
		}
		else if (ty < 0) {
			ty = 0;
			tdi = 1;
			point++;
		}
		else if (tx > N - 1) {
			tx = N - 1;
			tdi = 2;
			point++;
		}
		else if (ty > N - 1) {
			ty = N - 1;
			tdi = 0;
			point++;
		}
		if (map[ty][tx] == -1 || (x == tx && y == ty)) {
			visited[y][x][di] = point;
			if (point > cnt) {
				cnt = point;
			}
			return;
		}
		int flag = 0;
		if (map[ty][tx] == 0) {
			continue;
		}
		else if (map[ty][tx] == 1) {
			point++;
			tdi = d1[tdi];
		}
		else if (map[ty][tx] == 2) {
			point++;
			tdi = d2[tdi];
		}
		else if (map[ty][tx] == 3) {
			point++;
			tdi = d3[tdi];
		}
		else if (map[ty][tx] == 4) {
			point++;
			tdi = d4[tdi];
		}
		else if (map[ty][tx] == 5) {
			point++;
			tdi = d5[tdi];
		}
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if ((i != ty || j != tx) && map[i][j] == map[ty][tx]) {
						tx = j;
						ty = i;
						flag = 1;
						break;
					}
				}
				if (flag == 1) {
					break;
				}
			}
		}
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		cnt = 0;
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0) {
					continue;
				}
				for (int k = 0; k < 4; k++) {
					if (k == 0) {
						if (i == 0 || visited[i - 1][j][0] == -1)
							go(j, i, 0);
						else
							visited[i][j][0] = visited[i - 1][j][0];
					}
					else if (k == 1) {
						if (i == 0 || visited[i - 1][j][1] == -1)
							go(j, i, 1);
						else
							visited[i][j][1] = visited[i - 1][j][1];
					}
					else if (k == 2) {
						if (j == 0 || visited[i][j - 1][2] == -1)
							go(j, i, 2);
						else
							visited[i][j][2] = visited[i][j - 1][2];
					}
					else if (k == 3) {
						if (j == 0 || visited[i][j - 1][3] == -1)
							go(j, i, 3);
						else
							visited[i][j][3] = visited[i][j - 1][3];
					}
				}
			}
		}
		printf("#%d %d\n", num, cnt);
	}
	return 0;
}
/// 14:15; 45min;