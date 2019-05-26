#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct {
	int x;
	int y;
	int power;
}Node;

int N, W, H;
int res;
deque<int>dq;
deque<Node>ping;
int map[15][12];
int tmap[15][12];
int arr[5];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
void mapcopy() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			tmap[i][j] = map[i][j];
		}
	}
}

void gravity() {
	for (int i = 0; i < W; i++) {
		for (int j = H - 2; j >= 0; j--) {
			if (tmap[j][i] > 0) {
				for (int k = j; k < H - 1; k++) {
					if (tmap[k + 1][i] == 0) {
						tmap[k + 1][i] = tmap[k][i];
						tmap[k][i] = 0;
					}
					else {
						break;
					}
				}
			}
		}
	}
}
void boom() {
	for (int i = 0; i < N; i++) {
		int line = arr[i];
		for (int j = 0; j < H; j++) {
			if (tmap[j][line] > 0) {
				Node temp;
				temp.x = line;
				temp.y = j;
				temp.power = tmap[j][line];
				ping.push_back(temp);
				tmap[j][line] = 0;
				break;
			}
		}
		while (!ping.empty()) {
			Node cur = ping.front();
			ping.pop_front();
			for (int k = 1; k < cur.power; k++) {
				for (int l = 0; l < 4; l++) {
					int xpos = dx[l] * k + cur.x;
					int ypos = dy[l] * k + cur.y;
					if (xpos < 0 || ypos<0 || xpos >W - 1 || ypos>H - 1 || tmap[ypos][xpos] == 0) {
						continue;
					}
					if (tmap[ypos][xpos] == 1) {
						tmap[ypos][xpos] = 0;
					}
					else if (tmap[ypos][xpos] > 1) {
						Node temp;
						temp.x = xpos;
						temp.y = ypos;
						temp.power = tmap[ypos][xpos];
						tmap[ypos][xpos] = 0;
						ping.push_back(temp);
					}
				}
			}
		}
		gravity();

	}
}

void count() {
	int temp = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (tmap[i][j] > 0) {
				temp++;
			}
		}
	}
	if (temp < res) {
		res = temp;
	}
}

void dfs(int cnt) {
	if (cnt == N) {
		mapcopy();
		boom();
		count();
		return;
	}
	for (int i = 0; i < W; i++) {
		if (res == 0) {
			break;
		}
		arr[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d", &N, &W, &H);
		res = 200;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		dq.clear();
		ping.clear();
		dfs(0);
		printf("#%d %d\n", num, res);
	}
	return 0;
}