#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<deque>
#include<cmath>
using namespace std;

typedef struct _node {
	int x;
	int y;
	int di;
	int power;
}Node;
int map[4002][4002] = { 0 };
int n;
int sum = 0;
deque<Node>d1;

void mapping(int t) {
	int size = d1.size();
	if (size == 0) {
		return;
	}
	for (int i = 0; i < size; i++) {
		Node n = d1.front();
		d1.pop_front();
		if (map[n.y][n.x] != 0 && t + map[n.y][n.x] == 1) {
			sum = sum + n.power;
			map[n.y][n.x] = 0;
			continue;
		}
		else {
			map[n.y][n.x] = 0;
		}
		if (n.di == 0) {
			n.y = n.y - 1;
		}
		else if (n.di == 1) {
			n.y = n.y + 1;
		}
		else if (n.di == 2) {
			n.x = n.x - 1;
		}
		else if (n.di == 3) {
			n.x = n.x + 1;
		}
		if (n.x < 0 || n.y < 0 || n.x>4001 || n.y>4001) {
			continue;
		}
		if (map[n.y][n.x] == t || map[n.y][n.x] == -t) {
			sum = sum + n.power;
			map[n.y][n.x] = -t;
			continue;
		}
		map[n.y][n.x] = t;
		d1.push_back(n);
	}
	mapping(t + 1);
}

int main() {
	int i, set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &n);
		sum = 0;
		d1.clear();
		for (i = 0; i < n; i++) {
			int x, y, di, power;
			Node N;
			scanf("%d %d %d %d", &x, &y, &di, &power);
			x = 2 * x + 2000;
			y = 2000 - 2 * y;
			N.x = x;
			N.y = y;
			N.di = di;
			N.power = power;
			d1.push_back(N);
		}
		mapping(1);
		printf("#%d %d\n", num, sum);
	}
	return 0;
}