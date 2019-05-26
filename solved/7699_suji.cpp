#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int R, C;
char map[21][21];
int alpha[26];
int visited[21][21];
int cnt;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void init() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visited[i][j] = 0;
		}
	}
}

void dfs(int xpos, int ypos, int temp) {
	if (alpha[map[ypos][xpos] - 'A'] == 1) {
		if (cnt < temp) {
			cnt = temp;
		}
		return;
	}
	else {
		alpha[map[ypos][xpos] - 'A'] = 1;
		visited[ypos][xpos] = 1;
		for (int i = 0; i < 4; i++) {
			int x = xpos + dx[i];
			int y = ypos + dy[i];
			if (x < 0 || y < 0 || x >= C || y >= R || visited[y][x] == 1) {
				continue;
			}
			dfs(x, y, temp + 1);
		}
		alpha[map[ypos][xpos] - 'A'] = 0;
		visited[ypos][xpos] = 0;
	}
	if (cnt < temp) {
		cnt = temp;
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &R, &C);
		cnt = 0;
		init();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		dfs(0, 0, 0);
		if (cnt == 0) {
			cnt = 1;
		}
		printf("#%d %d\n", num, cnt);
	}
	return 0;
}