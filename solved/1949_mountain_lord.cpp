#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

/// 14:05
/// 14:38
int N, K;
int map[8][8];
int visited[8][8];
int height;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int path;


void go(int x, int y, int flag, int h, int cnt) {
	int kflag = 0;
	if (path < cnt) {
		path = cnt;
	}
	for (int i = 0; i < 4; i++) {
		int xpos = x + dx[i];
		int ypos = y + dy[i];
		if (xpos < 0 || ypos <0 || xpos >N - 1 || ypos >N - 1 || visited[ypos][xpos] == 1) {
			continue;
		}
		if (map[ypos][xpos] < h) {
			kflag = 1;
			visited[y][x] = 1;
			go(xpos, ypos, flag, map[ypos][xpos], cnt + 1);
			visited[y][x] = 0;
		}
		else {
			if (flag == 1) {
				continue;
			}
			for (int j = 1; j <= K; j++) {
				if (map[ypos][xpos] - j < h) {
					visited[y][x] = 1;
					go(xpos, ypos, 1, map[ypos][xpos] - j, cnt + 1);
					visited[y][x] = 0;
					kflag = 1;
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
		scanf("%d %d", &N, &K);
		height = 0;
		path = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > height) {
					height = map[i][j];
				}
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == height) {
					go(j, i, 0, height, 1);
				}
			}
		}
		printf("#%d %d\n", num, path);
	}
	return 0;
}