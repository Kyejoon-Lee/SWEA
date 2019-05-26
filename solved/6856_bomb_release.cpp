#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct {
	int a;
	int b;
}Node;

vector<Node>dq;

int N, M;
int beg[1001][2];
int cnt;
int kflag;

void dfs(int check, int beg1, int beg2) {
	Node temp;
	int a, b;
	int flag = 0;
	while (1) {
		if (check == M) {
			break;
		}
		temp = dq[check];
		a = temp.a;
		b = temp.b;

		if (beg[a][0] == 1) {
			if (beg[b][0] == 1) {
				flag = -1;
				break;;
			}
			else {
				if (beg[b][1] == 1) {
					check++;
					continue;
				}
				else {
					beg[b][1] = 1;
					beg2++;
					check++;
					continue;
				}
			}
		}
		else if (beg[a][1] == 1) {
			if (beg[b][1] == 1) {
				flag = -1;
				break;;
			}
			else {
				if (beg[b][0] == 1) {
					check++;
					continue;
				}
				else {
					beg[b][0] = 1;
					beg1++;
					check++;
					continue;
				}
			}
		}
		else {
			if (beg[b][0] == 1) {
				beg[a][1] = 1;
				beg2++;
				check++;
				continue;
			}
			else if (beg[b][1] == 1) {
				beg[a][0] = 1;
				beg1++;
				check++;
				continue;
			}
			else {
				int tbeg[1001][2];
				for (int i = 0; i < N + 1; i++) {
					for (int j = 0; j < 2; j++) {
						tbeg[i][j] = beg[i][j];
					}
				}
				beg[a][0] = 1;
				beg[b][1] = 1;
				dfs(check + 1, beg1 + 1, beg2 + 1);
				for (int i = 0; i < N + 1; i++) {
					for (int j = 0; j < 2; j++) {
						beg[i][j] = tbeg[i][j];
					}
				}
				beg[a][1] = 1;
				beg[b][0] = 1;
				check++;
				beg1++;
				beg2++;

				continue;
			}
		}
	}

	int tcnt;
	if (flag == -1) {
		if (cnt == 0) {
			cnt = -1;
		}
	}
	else {
		int dif;
		if (beg1 >= beg2) {
			tcnt = beg1;
			dif = beg1 - beg2;
		}
		else {
			tcnt = beg2;
			dif = beg2 - beg1;
		}
		int res = N - beg1 - beg2;
		if (res - dif > 0) {
			tcnt = tcnt + (res - dif) / 2 + (res - dif) % 2;
		}
		if (cnt > 0) {
			if (cnt > tcnt) {
				cnt = tcnt;
			}
		}
		else {
			cnt = tcnt;
		}
	}
}


int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &M);
		int a, b;
		int beg1 = 0;
		int beg2 = 0;
		kflag = 0;
		dq.clear();
		cnt = 0;
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < 2; j++) {
				beg[i][j] = 0;
			}
		}
		Node temp;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
			temp.a = a;
			temp.b = b;
			dq.push_back(temp);
		}

		dfs(0, 0, 0);

		printf("#%d %d\n", num, cnt);

	}
	return 0;
}