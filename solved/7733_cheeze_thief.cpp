#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

typedef struct {
	int x;
	int y;
}Node;

vector<Node>v;
vector<Node>input[101];

int map[101][101];
int tmap[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N;
int maxi;
void mapcopy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmap[i][j] = map[i][j];
		}
	}
}

void go(int ypos, int xpos) {
	Node cur;
	cur.y = ypos;
	cur.x = xpos;
	v.push_back(cur);
	while (!v.empty()) {
		cur = v.back();
		v.pop_back();
		if (tmap[cur.y][cur.x] == -1) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];
			if (x< 0 || y<0 || x>N - 1 || y>N - 1 || tmap[y][x] == -1) {
				continue;
			}
			Node temp;
			temp.x = x;
			temp.y = y;
			v.push_back(temp);
		}
		tmap[cur.y][cur.x] = -1;
	}
}



void dfs(int n) {
	int cnt = 0;
	while (!input[n].empty()) {
		Node cur = input[n].back();
		input[n].pop_back();
		map[cur.y][cur.x] = -1;
	}
	mapcopy();
	for (int i = n + 1; i < 101; i++) {
		for (int j = 0; j < input[i].size(); j++) {
			if (tmap[input[i][j].y][input[i][j].x] != -1) {
				go(input[i][j].y, input[i][j].x);
				cnt++;
			}
		}

	}
	
	if (maxi < cnt) {
		maxi = cnt;
	}
}


int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		maxi = 1;
		v.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				Node cur;
				cur.x = j;
				cur.y = i;
				input[map[i][j]].push_back(cur);
			}
		}
		for (int i = 1; i < 101; i++) {
			dfs(i);
		}
		printf("#%d %d\n", num, maxi);
	}
	return 0;
}