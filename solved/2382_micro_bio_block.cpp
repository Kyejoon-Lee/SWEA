#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
int n, k, m;
int spe[101][101];
int di[101][101];
int tempspe[101][101];
int tempdi[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void mapcopy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			spe[i][j] = tempspe[i][j];
			di[i][j] = tempdi[i][j];
		}
	}
}

void travel(int x, int y) {
	tempspe[y][x] = 0;
	tempdi[y][x] = 0;
	int max = 0;
	for (int i = 0; i < 4; i++) {
		int xpos = x + dx[i];
		int ypos = y + dy[i];
		if (xpos <0 || xpos > n - 1 || ypos > n - 1 || ypos < 0) { continue; }
		if (spe[ypos][xpos] == 0) {
			continue;
		}
		int condi = di[ypos][xpos];
		if (i == 0 && condi == 1) {
			if (y == 0) {
				tempspe[y][x] = spe[ypos][xpos] / 2;
				tempdi[y][x] = 2;
			}
			else {
				tempspe[y][x] = tempspe[y][x] + spe[ypos][xpos];
				if (max < spe[ypos][xpos]) {
					max = spe[ypos][xpos];
					tempdi[y][x] = condi;
				}
			}
		}
		if (i == 1 && condi == 2) {
			if (y == n - 1) {
				tempspe[y][x] = spe[ypos][xpos] / 2;
				tempdi[y][x] = 1;
			}
			else {
				tempspe[y][x] = tempspe[y][x] + spe[ypos][xpos];
				if (max < spe[ypos][xpos]) {
					max = spe[ypos][xpos];
					tempdi[y][x] = condi;
				}
			}
		}
		if (i == 2 && condi == 3) {
			if (x == 0) {
				tempspe[y][x] = spe[ypos][xpos] / 2;
				tempdi[y][x] = 4;
			}
			else {
				tempspe[y][x] = tempspe[y][x] + spe[ypos][xpos];
				if (max < spe[ypos][xpos]) {
					max = spe[ypos][xpos];
					tempdi[y][x] = condi;
				}
			}
		}
		if (i == 3 && condi == 4) {
			if (x == n - 1) {
				tempspe[y][x] = spe[ypos][xpos] / 2;
				tempdi[y][x] = 3;
			}
			else {
				tempspe[y][x] = tempspe[y][x] + spe[ypos][xpos];
				if (max < spe[ypos][xpos]) {
					max = spe[ypos][xpos];
					tempdi[y][x] = condi;
				}
			}
		}

	}
}

void order() {
	for (int sum = 1; sum <= m; sum++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				travel(i, j);
			}
		}

		mapcopy();
	}
}

int main() {
	int i, j;
	int set, num;
	int a, b;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		n = 0;
		m = 0;
		k = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				spe[i][j] = 0;
				di[i][j] = 0;
			}
		}
		for (i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			scanf("%d %d", &spe[a][b], &di[a][b]);
		}
		order();
		int survival = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				survival = survival + spe[i][j];
			}
		}
		printf("#%d %d\n", num, survival);
	}
}