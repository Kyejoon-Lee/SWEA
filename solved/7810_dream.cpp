#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

deque<int>dq;
int N;

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		dq.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int a;
			scanf("%d", &a);
			dq.push_back(a);
		}
		sort(dq.begin(), dq.end());
		int size = dq.size();
		int cnt = 0;
		int H = 0;
		int i = 1;
		while (1) {
			if (size - cnt < i) {
				break;
			}
			if (dq.front() <= H) {
				dq.pop_front();
				cnt++;
				continue;
			}
			if (i <= size - cnt) {
				H = i;
				i++;
			}

		}
		printf("#%d %d\n", num, H);
	}
	return 0;
}