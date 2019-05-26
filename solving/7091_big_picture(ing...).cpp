#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

char cmp[2000][2000];
char pattern[2000][2000];
long long hash_map[2000][2000];
long long thash[2000][2000];
int H, W, N, M;

int poscheck(int x, int y) {
	if (pattern[y][x] == 'o') {
		return 1;
	}
	else {
		return 0;
	}
}

void hash_mapping() {
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < W; j++) {
			temp += poscheck(j, i);
		}
		for (int j = 0; j <= M - W; j++) {
			thash[i][j] = temp;
			if (j != M - W) {
				temp -= poscheck(j, i);
				temp += poscheck(j + W, i);
			}
		}

	}
	for (int i = 0; i <= N - H; i++) {
		for (int j = 0; j <= M - W; j++) {
			if (hash_map[i][j] == -1) {
				hash_map[i][j] = 0;
			}
			for (int k = 0; k < H; k++) {
				hash_map[i][j] += thash[i + k][j];
			}
		}
	}
}

bool check(int x, int y) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (pattern[y + i][x + j] != cmp[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void init() {
	for (int i = 0; i <= N - H; i++) {
		for (int j = 0; j <= M - W; j++) {
			hash_map[i][j] = -1;
		}
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d %d", &H, &W, &N, &M);
		init();
		long long hash_num = 0;
		long long ans = 0;
		long long tnum = 1;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf(" %c", &cmp[i][j]);
				if (cmp[i][j] == 'o') {
					hash_num++;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &pattern[i][j]);
			}
		}
		hash_mapping();

		for (int i = 0; i <= N - H; i++) {
			for (int j = 0; j <= M - W; j++) {
				if (hash_map[i][j] == hash_num) {
					if (check(j, i)) {
						ans++;
					}
				}
			}
		}
		printf("#%d %lld\n", num, ans);
	}
	return 0;
}