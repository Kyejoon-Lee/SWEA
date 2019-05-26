#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<deque>
#include<ctype.h>
#include<algorithm>

using namespace std;

typedef struct {
	int x;
	int y;
	char jew;
}Node;

deque<Node>dq;
vector<Node>jewelry;
vector<Node>box;
char map[51][51];
int visited[51][51];
int cc[51][51][3];

int H, W;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int maxi = 0;

void LCS() {
	int xsize = jewelry.size();
	int bsize = box.size();
	int cmap[52][52] = { 0 };
	for (int i = 1; i <= xsize; i++) {
		for (int j = 1; j <= bsize; j++) {
			if (toupper(jewelry[i - 1].jew) == box[bsize - j].jew && (jewelry[i - 1].x <= box[bsize - j].x && jewelry[i - 1].y <= box[bsize - j].y)) {
				cmap[i][j] = cmap[i - 1][j - 1] + 1;
			}
			else {
				cmap[i][j] = max(cmap[i - 1][j], cmap[i][j - 1]);
			}
		}
	}
	if (maxi < cmap[xsize][bsize]) {
		maxi = cmap[xsize][bsize];
	}
}

void dfs() {
	while (!dq.empty()) {
		Node cur = dq.back();
		int x = cur.x;
		int y = cur.y;

		if (visited[y][x] == 1) {
			visited[y][x] = 0;
			if (map[y][x] != '.' && map[y][x] != '#') {
				if (islower(map[y][x])) {
					jewelry.pop_back();
				}
				else {
					box.pop_back();
				}
			}
			dq.pop_back();
			continue;
		}

		if (map[y][x] != '.' && map[y][x] != '#') {
			cur.jew = map[y][x];
			if (islower(map[y][x])) {
				jewelry.push_back(cur);
			}
			else {
				box.push_back(cur);
			}
		}


		if (y == H - 1 && x == W - 1) {

			LCS();
			if (map[y][x] != '.' && map[y][x] != '#') {
				if (islower(map[y][x])) {
					jewelry.pop_back();
				}
				else {
					box.pop_back();
				}
			}
			dq.pop_back();
			return;
		}

		for (int i = 0; i < 2; i++) {
			int xpos = x + dx[i];
			int ypos = y + dy[i];
			if (xpos > W - 1 || ypos > H - 1 || map[ypos][xpos] == '#') {
				continue;
			}
			Node temp;
			temp.x = xpos;
			temp.y = ypos;
			dq.push_back(temp);
		}

		visited[y][x] = 1;

	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		maxi = -1;
		scanf("%d %d", &H, &W);
		dq.clear();
		jewelry.clear();
		box.clear();

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf(" %c", &map[i][j]);
				visited[i][j] = 0;
			}
		}


		Node cur;
		cur.x = 0;
		cur.y = 0;
		dq.push_back(cur);
		dfs();

		printf("#%d %d\n", num, maxi);
	}
	return 0;
}