#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<cstring>

using namespace std;


typedef struct {
	int pos;
	int cnt;
}Node;

deque<Node>dq;

int N, M;
int stair[50001];
int score[50001];
int visited[50001];
int harmony;
void go() {
	Node temp;
	temp.pos = 0;
	temp.cnt = 1;
	dq.push_back(temp);
	while (!dq.empty()) {
		Node cur = dq.back();
		if (cur.cnt == M && cur.pos >= N - 1) {
			harmony = 1;
			return;
		}
		if (visited[cur.cnt] == score[cur.cnt]) {
			visited[cur.cnt] = -1;
			dq.pop_back();
			continue;
		}
		if (cur.cnt >= M) {
			dq.pop_back();
			continue;
		}
		visited[cur.cnt] = score[cur.cnt];
		if (!(cur.pos - 1 < 0)) {
			if ((stair[cur.pos - 1] + 11) % 12 == score[cur.cnt]) {
				Node tt;
				tt.pos = cur.pos - 1;
				tt.cnt = cur.cnt + 1;
				dq.push_back(tt);
			}
		}
		if (!(cur.pos + 1 > N)) {
			if ((stair[cur.pos + 1]) % 12 == score[cur.cnt]) {
				Node tt;
				tt.pos = cur.pos + 1;
				tt.cnt = cur.cnt + 1;
				dq.push_back(tt);
			}
		}
		if (!(cur.pos + 2 > N)) {
			if ((stair[cur.pos + 2] + 1) % 12 == score[cur.cnt]) {
				Node tt;
				tt.pos = cur.pos + 2;
				tt.cnt = cur.cnt + 1;
				dq.push_back(tt);
			}
		}

	}
}

int main() {
	int set, num;
	scanf("%d", &set);

	for (num = 1; num <= set; num++) {
		dq.clear();
		harmony = 0;
		scanf("%d %d", &N, &M);
		char temp[3];
		for (int i = 1; i <= N; i++) {
			scanf("%s", temp);
			if (strlen(temp) > 1) {
				if (temp[0] == 'A') {
					stair[i] = 1;
				}
				else if (temp[0] == 'C') {
					stair[i] = 4;
				}
				else if (temp[0] == 'D') {
					stair[i] = 6;
				}
				else if (temp[0] == 'F') {
					stair[i] = 9;
				}
				else if (temp[0] == 'G') {
					stair[i] = 11;
				}
			}
			else {
				if (temp[0] == 'A') {
					stair[i] = 0;
				}
				else if (temp[0] == 'B') {
					stair[i] = 2;
				}
				else if (temp[0] == 'C') {
					stair[i] = 3;
				}
				else if (temp[0] == 'D') {
					stair[i] = 5;
				}
				else if (temp[0] == 'E') {
					stair[i] = 7;
				}
				else if (temp[0] == 'F') {
					stair[i] = 8;
				}
				else if (temp[0] == 'G') {
					stair[i] = 10;
				}
			}
		}
		for (int i = 1; i <= M; i++) {
			visited[i] = -1;
			scanf("%s", temp);
			if (strlen(temp) > 1) {
				if (temp[0] == 'A') {
					score[i] = 1;
				}
				else if (temp[0] == 'C') {
					score[i] = 4;
				}
				else if (temp[0] == 'D') {
					score[i] = 6;
				}
				else if (temp[0] == 'F') {
					score[i] = 9;
				}
				else if (temp[0] == 'G') {
					score[i] = 11;
				}
			}
			else {
				if (temp[0] == 'A') {
					score[i] = 0;
				}
				else if (temp[0] == 'B') {
					score[i] = 2;
				}
				else if (temp[0] == 'C') {
					score[i] = 3;
				}
				else if (temp[0] == 'D') {
					score[i] = 5;
				}
				else if (temp[0] == 'E') {
					score[i] = 7;
				}
				else if (temp[0] == 'F') {
					score[i] = 8;
				}
				else if (temp[0] == 'G') {
					score[i] = 10;
				}
			}
		}
		go();
		if (harmony == 1) {
			printf("#%d YES\n", num);
		}
		else {
			printf("#%d NO\n", num);
		}
	}
	return 0;
}