#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int N;
int cnt;
deque<int>dq;


bool cmp(int a, int b) {
	return a < b;
}

void move() {
	while (!dq.empty()) {
		int cur = dq.back();
		if (50 / cur < 1) {
			dq.pop_back();
			cnt++;
			continue;
		}
		else if (50 / cur == 1) {
			if (50 % cur == 0) {
				dq.pop_back();
				cnt++;
				continue;
			}
			else {
				dq.pop_back();
				if (!dq.empty()) {
					dq.pop_front();
					cnt++;
				}
				else {
					return;
				}
				continue;
			}
		}
		else {
			if (50 % cur == 0) {
				int qsize = dq.size();
				if (qsize >= (50 / cur)) {
					for (int i = 0; i < (50 / cur) - 1; i++) {
						dq.pop_front();
					}
					cnt++;
				}
				else {
					return;
				}
				dq.pop_back();
				continue;
			}
			else {
				int qsize = dq.size();
				if (qsize - 1 >= (50 / cur)) {
					for (int i = 0; i < 50 / cur; i++) {
						dq.pop_front();
					}
					cnt++;
				}
				else {
					return;
				}
				dq.pop_back();
				continue;
			}
		}
	}
}


int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		dq.clear();
		for (int i = 0; i < N; i++) {
			int a;
			scanf("%d", &a);
			dq.push_back(a);
		}
		cnt = 0;
		sort(dq.begin(), dq.end(), cmp);
		move();
		printf("#%d %d\n", num, cnt);

	}
	return 0;
}