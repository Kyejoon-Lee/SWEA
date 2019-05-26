#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct {
	int x;
	int y;
	int pos;
}Node;

deque<Node>dq;
int N, M;
char map[2001][2001];
int visited[2001][2001];
char result[4001];
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int length;
void dfs() {
	while (!dq.empty()) {
		Node cur = dq.front();
		///printf("%d %d\n", cur.x, cur.y);
		if (cur.x == M - 1 && cur.y == N - 1) {
			length = cur.pos;
			return;
		}
		if (result[cur.pos] < map[cur.y][cur.x]) {
			dq.pop_front();
			continue;
		}
		else {
			for (int i = 0; i < 2; i++) {
				int x = cur.x + dx[i];
				int y = cur.y + dy[i];
				if (x > M - 1 || y > N - 1) {
					continue;
				}
				if (visited[y][x] != 1 && result[cur.pos + 1] >= map[y][x]) {
					result[cur.pos + 1] = map[y][x];
					///printf("%d %c\n", cur.pos + 1, map[y][x]);
					Node temp;
					temp.x = x;
					temp.y = y;
					temp.pos = cur.pos + 1;
					visited[y][x] = 1;
					dq.push_back(temp);
				}
			}
			dq.pop_front();
		}
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &M);
		dq.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %c", &map[i][j]);
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < N + M - 1; i++) {
			result[i] = '~';
		}
		Node cur;
		cur.x = 0;
		cur.y = 0;
		cur.pos = 0;
		dq.push_back(cur);
		result[0] = map[0][0];
		visited[0][0] = 1;
		dfs();
		printf("#%d ", num);
		for (int i = 0; i <= length; i++) {
			printf("%c", result[i]);
		}
		printf("\n");

	}
	return 0;
}