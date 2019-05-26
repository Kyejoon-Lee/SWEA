#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


int R, C;
char map[21][21];
int visited[21][21][4][16];
int cnt;

void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 16; l++) {
					visited[i][j][k][l] = 0;
				}
			}
		}
	}
}
///up down left right
void go(int x, int y, int di, int pow) {
	int tx = x;
	int ty = y;
	int tdi = di;
	int tpow = pow;
	while (1) {
		if (cnt == 1) {
			return;
		}
		if (visited[ty][tx][tdi][tpow] == 1) {
			return;
		}
		visited[ty][tx][tdi][tpow] = 1;
		if (map[ty][tx] == '@') {
			cnt = 1;
			return;
		}
		else if (map[ty][tx] >= 48 && map[ty][tx] <= 57) {
			tpow = map[ty][tx] - 48;
		}
		else if (map[ty][tx] == '+') {
			tpow++;
			if (tpow > 15) {
				tpow = 0;
			}

		}
		else if (map[ty][tx] == '-') {
			tpow--;
			if (tpow < 0) {
				tpow = 15;
			}


		}
		else if (map[ty][tx] == '<') {
			tdi = 2;
		}
		else if (map[ty][tx] == '>') {
			tdi = 3;
		}
		else if (map[ty][tx] == '^') {
			tdi = 0;
		}
		else if (map[ty][tx] == 'v') {
			tdi = 1;
		}

		else if (map[ty][tx] == '_') {
			if (tpow == 0) {
				tdi = 3;
			}
			else {
				tdi = 2;
			}
		}
		else if (map[ty][tx] == '|') {
			if (tpow == 0) {
				tdi = 1;
			}
			else {
				tdi = 0;
			}
		}
		else if (map[ty][tx] == '?') {
			for (int i = 0; i < 4; i++) {
				tdi = i;
				if (tdi == 0) {
					if (ty == 0) {
						go(tx, 15, tdi, tpow);
					}
					else {
						go(tx, ty - 1, tdi, tpow);
					}
				}
				else if (tdi == 1) {
					if (ty == 15) {
						go(tx, 0, tdi, tpow);
					}
					else {
						go(tx, ty + 1, tdi, tpow);
					}
				}
				else if (tdi == 2) {
					if (tx == 0) {
						go(15, ty, tdi, tpow);
					}
					else {
						go(tx - 1, ty, tdi, tpow);
					}
				}
				else if (tdi == 3) {
					if (tx == 15) {
						go(0, ty, tdi, tpow);
					}
					else {
						go(tx + 1, ty, tdi, tpow);
					}
				}
			}
			return;
		}
		if (tdi == 0) {
			ty--;
		}
		else if (tdi == 1) {
			ty++;
		}
		else if (tdi == 2) {
			tx--;
		}
		else if (tdi == 3) {
			tx++;
		}
		if (tx < 0) {
			tx = C - 1;
		}
		else if (tx > C - 1) {
			tx = 0;
		}
		if (ty < 0) {
			ty = R - 1;
		}
		else if (ty > R - 1) {
			ty = 0;
		}

	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &R, &C);
		cnt = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		init();
		go(0, 0, 3, 0);
		if (cnt == 0) {
			printf("#%d NO\n", num);
		}
		else {
			printf("#%d YES\n", num);
		}
	}
	return 0;
}