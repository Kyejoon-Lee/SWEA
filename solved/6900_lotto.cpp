#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct {
	char lotnum[9];
	int reward;
}Node;

deque<Node>l1;
deque<Node>l2;

int N, M, cnt;

void check() {
	for (int i = 0; i < N; i++) {
		Node temp = l1.front();
		l1.pop_front();

		for (int j = 0; j < M; j++) {
			Node node = l2.front();
			l2.pop_front();
			int flag = 0;
			for (int k = 0; k < 8; k++) {
				if (temp.lotnum[k] == '*' || node.lotnum[k] == '*') {
					continue;
				}
				else if (temp.lotnum[k] == node.lotnum[k]) {
					continue;
				}
				else {
					flag = 1;
					l2.push_back(node);
					break;
				}
			}
			if (flag == 0) {
				cnt += temp.reward;
			}
		}
	}
}

int main() {
	int num, set;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &M);
		l1.clear();
		cnt = 0;
		l2.clear();
		for (int i = 0; i < N; i++) {
			Node temp;
			scanf("%s", temp.lotnum);
			scanf("%d", &temp.reward);
			l1.push_back(temp);
		}
		for (int i = 0; i < M; i++) {
			Node temp;
			scanf("%s", temp.lotnum);
			l2.push_back(temp);
		}
		check();
		printf("#%d %d\n", num, cnt);
	}
	return 0;
}