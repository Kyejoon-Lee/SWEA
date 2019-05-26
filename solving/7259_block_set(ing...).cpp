#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct {
	int x;
	int y;
	char color;
	int a;
	int b;
	int mode;
}Node;

deque<Node>target;
deque<Node>trace;

int N, M;
char map[501][501];
char visited[501][501];
int cnt;
int bx[] = { 0,1,0,-1 };
int by[] = { 1,0,-1,0 };
int wx[] = { 0,1,0,-1 };
int wy[] = { -1,-1,1,1 };

void go() {
	while (1) {
		if (target.empty()) {
			cnt = 1;
			return;
		}
		int sflag = 0;
		Node cur = target.front();
		/*
		printf("##%d %d\n", cur.x, cur.y);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%c ", visited[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		int x = cur.x;
		int y = cur.y;
		if (visited[y][x] == 'c') {
			target.pop_front();
			visited[y][x] = 'd';
			continue;
		}
		else if (visited[y][x] == 'B') {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					int flag = 0;
					for (int k = 0; k < 2; k++) {
						if (x + bx[j * 2 + k]<0 || x + bx[j * 2 + k]>M - 1 || y + by[i * 2 + k]<0 || y + by[i * 2 + k]>N - 1
							|| !(visited[y + by[i * 2 + k]][x + bx[j * 2 + k]] == 'W' || visited[y + by[i * 2 + k]][x + bx[j * 2 + k]] == '.')) {
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						continue;
					}
					else if (flag == 0) {
						sflag = 1;
						Node temp;
						temp.x = x;
						temp.y = y;
						temp.a = i;
						temp.b = j;
						temp.color = 'B';
						trace.push_back(temp);
					}
				}
			}
		}
		else if (visited[y][x] == 'W') {
			/*
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					int flag = 0;
					for (int k = 0; k < 2; k++) {
						if (x + wy[j * 2 + k]<0 || x + wy[j * 2 + k]>M - 1 || y + wx[i * 2 + k]<0 || y + wx[i * 2 + k]>N - 1
							|| !(visited[y + wx[i * 2 + 1]][x + wy[j * 2 + 1]] == 'W' || visited[y + wx[i * 2 + 1]][x + wy[j * 2 + 1]] == '.')
							|| !(visited[y + wx[i * 2]][x + wy[j * 2]] == 'B' || visited[y + wx[i * 2]][x + wy[j * 2]] == '.')) {
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						continue;
					}
					else if (flag == 0) {
						sflag = 1;
						Node temp;
						temp.x = x;
						temp.y = y;
						temp.a = i;
						temp.b = j;
						temp.mode = 2;
						temp.color = 'W';
						trace.push_back(temp);
					}
				}
			}
			*/
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					int flag = 0;
					for (int k = 0; k < 2; k++) {
						if (x + wx[j * 2 + k]<0 || x + wx[j * 2 + k]>M - 1 || y + wy[i * 2 + k]<0 || y + wy[i * 2 + k]>N - 1
							|| !(visited[y + wy[i * 2 + 1]][x + wx[j * 2 + 1]] == 'W' || visited[y + wy[i * 2 + 1]][x + wx[j * 2 + 1]] == '.')
							|| !(visited[y + wy[i * 2]][x + wx[j * 2]] == 'B' || visited[y + wy[i * 2]][x + wx[j * 2]] == '.')) {
							flag = 1;
							break;
						}
					}
					if (flag == 1) {
						continue;
					}
					else if (flag == 0) {
						sflag = 1;
						Node temp;
						temp.x = x;
						temp.y = y;
						temp.a = i;
						temp.b = j;
						temp.mode = 1;
						temp.color = 'W';
						trace.push_back(temp);
					}
				}
			}
		}
		if (sflag == 1) {
			target.pop_front();
		}
		break;
	}
}

void dfs() {
	go();
	while (!trace.empty()) {
		Node cur = trace.back();
		/*
		printf("%d %d\n", cur.x, cur.y);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%c ", visited[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		if (cnt == 1) {
			return;
		}
		if (visited[cur.y][cur.x] == 'c' || visited[cur.y][cur.x] == 'd') {
			if (cur.color == 'B') {
				Node tt;
				for (int k = 1; k >= 0; k--) {
					if (visited[cur.y + by[cur.a * 2 + k]][cur.x + bx[cur.b * 2 + k]] == 'd') {
						tt.color = 'W';
						tt.x = cur.x + bx[cur.b * 2 + k];
						tt.y = cur.y + by[cur.a * 2 + k];
						target.push_front(tt);
					}
					visited[cur.y + by[cur.a * 2 + k]][cur.x + bx[cur.b * 2 + k]] = map[cur.y + by[cur.a * 2 + k]][cur.x + bx[cur.b * 2 + k]];
				}
				tt.color = 'B';
				tt.x = cur.x;
				tt.y = cur.y;
				target.push_front(tt);
				visited[cur.y][cur.x] = 'B';
			}
			else if (cur.color == 'W') {
				Node tt;
				if (cur.mode == 1) {
					if (visited[cur.y + wy[cur.a * 2 + 1]][cur.x + wx[cur.b * 2 + 1]] == 'd') {
						tt.color = 'W';
						tt.x = cur.x + wx[cur.b * 2 + 1];
						tt.y = cur.y + wy[cur.a * 2 + 1];
						target.push_front(tt);
					}
					if (visited[cur.y + wy[cur.a * 2]][cur.x + wx[cur.b * 2]] == 'd') {
						tt.color = 'B';
						tt.x = cur.x + wx[cur.b * 2];
						tt.y = cur.y + wy[cur.a * 2];
						target.push_front(tt);
					}
					visited[cur.y + wy[cur.a * 2]][cur.x + wx[cur.b * 2]] = map[cur.y + wy[cur.a * 2]][cur.x + wx[cur.b * 2]];
					visited[cur.y + wy[cur.a * 2 + 1]][cur.x + wx[cur.b * 2 + 1]] = map[cur.y + wy[cur.a * 2 + 1]][cur.x + wx[cur.b * 2 + 1]];
				}
				/*
				else if (cur.mode == 2) {
					if (visited[cur.y + wx[cur.a * 2 + 1]][cur.x + wy[cur.b * 2 + 1]] == 'd') {
						tt.color = 'W';
						tt.x = cur.x + wy[cur.b * 2 + 1];
						tt.y = cur.y + wx[cur.a * 2 + 1];
						target.push_front(tt);
					}
					if (visited[cur.y + wx[cur.a * 2]][cur.x + wy[cur.b * 2]] == 'd') {
						tt.color = 'B';
						tt.x = cur.x + wy[cur.b * 2];
						tt.y = cur.y + wx[cur.a * 2];
						target.push_front(tt);
					}
						visited[cur.y + wx[cur.a * 2]][cur.x + wy[cur.b * 2]] = map[cur.y + wx[cur.a * 2]][cur.x + wy[cur.b * 2]];
						visited[cur.y + wx[cur.a * 2 + 1]][cur.x + wy[cur.b * 2 + 1]] = map[cur.y + wx[cur.a * 2 + 1]][cur.x + wy[cur.b * 2 + 1]];
				}
				*/
				tt.color = 'W';
				tt.x = cur.x;
				tt.y = cur.y;
				target.push_front(tt);
				visited[cur.y][cur.x] = 'W';
			}

			trace.pop_back();
			continue;
		}
		else {
			if (visited[cur.y][cur.x] == 'B') {
				visited[cur.y][cur.x] = 'c';
				for (int k = 0; k < 2; k++) {
					visited[cur.y + by[cur.a * 2 + k]][cur.x + bx[cur.b * 2 + k]] = 'c';
				}
			}
			else if (visited[cur.y][cur.x] == 'W') {
				visited[cur.y][cur.x] = 'c';
				if (cur.mode == 1) {
					for (int k = 0; k < 2; k++) {
						visited[cur.y + wy[cur.a * 2 + k]][cur.x + wx[cur.b * 2 + k]] = 'c';
					}
				}
				else if (cur.mode == 2) {
					for (int k = 0; k < 2; k++) {
						visited[cur.y + wx[cur.a * 2 + k]][cur.x + wy[cur.b * 2 + k]] = 'c';
					}
				}
			}
			go();
		}
	}
}


int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		trace.clear();
		target.clear();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &map[i][j]);
				visited[i][j] = map[i][j];
				if (map[i][j] == 'W') {
					Node cur;
					cur.x = j;
					cur.y = i;
					cur.color = 'W';
					target.push_back(cur);
				}
				else if (map[i][j] == 'B') {
					Node cur;
					cur.x = j;
					cur.y = i;
					cur.color = 'B';
					target.push_back(cur);
				}
			}
		}
		cnt = 0;
		dfs();
		if (cnt == 1) {
			printf("#%d YES\n", num);
		}
		else if (cnt == 0) {
			printf("#%d NO\n", num);
		}
	}
	return 0;
}