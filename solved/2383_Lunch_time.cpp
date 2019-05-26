#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
using namespace std;

list<int>s1;
list<int>s2;

int room[11][11];
int people[11][2];
int stair[2][3];
int mini = 0;
int n, p, s;

int boom(list<int> q, int len) {
	int time;
	q.sort();
	if (q.size() == 0) {
		time = 0;
	}
	else if (q.size() <= 3) {
		time = q.back() + len;
	}
	else {
		int arrival;
		int end;
		list<int>endtime;
		for (int i = 0; i < 3; i++) {
			arrival = q.front();
			q.pop_front();
			endtime.push_back(arrival + len);
		}
		int size = (int)q.size();
		for (int i = 0; i < size; i++) {
			arrival = q.front();
			q.pop_front();
			end = endtime.front();
			endtime.pop_front();
			if (arrival < end) {
				endtime.push_back(end + len);
			}
			else {
				endtime.push_back(arrival + len);
			}
		}
		time = endtime.back();
	}
	return time;
}

void dfs(int num, int select) {
	if (select == 0) {
		int dist = abs(people[num][0] - stair[0][0]) + abs(people[num][1] - stair[0][1]) + 1;
		s1.push_back(dist);
	}
	else if (select == 1) {
		int dist = abs(people[num][0] - stair[1][0]) + abs(people[num][1] - stair[1][1]) + 1;
		s2.push_back(dist);
	}
	if (num == p - 1) {
		int st1 = boom(s1, stair[0][2]);
		int st2 = boom(s2, stair[1][2]);
		mini = mini < max(st1, st2) ? mini : max(st1, st2);
		return;
	}
	dfs(num + 1, 0);
	s1.pop_back();
	dfs(num + 1, 1);
	s2.pop_back();
}

int main() {
	int i, j, num, set;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &n);
		p = 0;
		s = 0;
		s1.clear();
		s2.clear();
		mini = 999999;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &room[i][j]);
				if (room[i][j] == 1) {
					people[p][0] = j;
					people[p++][1] = i;
				}
				else if (room[i][j] >= 2) {
					stair[s][0] = j;
					stair[s][1] = i;
					stair[s++][2] = room[i][j];
				}
			}
		}
		dfs(0, 0);
		s1.pop_back();
		dfs(0, 1);
		s2.pop_back();
		printf("#%d %d\n", num, mini);
	}
	return 0;
}