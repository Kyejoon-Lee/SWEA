#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int D, W, K;
int film[14][21];
int tfilm[14][21];
int scount;

void mapcopy() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			tfilm[i][j] = film[i][j];
		}
	}
}

int check() {
	int kflag = 0;
	for (int i = 0; i < W; i++) {
		int ycheck = tfilm[0][i];
		int flag = 1;
		for (int j = 1; j < D; j++) {
			if (ycheck == tfilm[j][i]) {
				flag++;
			}
			else {
				flag = 1;
				ycheck = tfilm[j][i];
			}
			if (flag == K) {
				kflag++;
				break;
			}

		}
		if (kflag != i + 1) {
			return 0;
		}
	}
	return 1;
}


void dfs(int cnt, int pos) {
	if (scount <= cnt || pos > D || cnt > K) {
		return;
	}
	if (cnt <= K) {
		if (check()) {
			if (scount > cnt) {
				scount = cnt;
			}
		}
	}
	for (int i = 0; i < W; i++) {
		tfilm[pos][i] = 1;
	}
	dfs(cnt + 1, pos + 1);
	for (int i = 0; i < W; i++) {
		tfilm[pos][i] = 0;
	}
	dfs(cnt + 1, pos + 1);
	for (int i = 0; i < W; i++) {
		tfilm[pos][i] = film[pos][i];
	}
	dfs(cnt, pos + 1);
}


int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &film[i][j]);
			}
		}
		scount = 14;
		mapcopy();
		if (check()) {
			scount = 0;
		}
		else {
			dfs(0, 0);
		}
		printf("#%d %d\n", num, scount);
	}
	return 0;
}