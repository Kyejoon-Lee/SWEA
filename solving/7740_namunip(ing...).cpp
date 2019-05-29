#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

typedef struct _node{
	_node* rear;
	_node* next;
	long long power;
	long long age;
	int pos;
}Node;

vector<Node>v;
vector<int>ans;
int N;

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			int p, a;
			char c;
			scanf(" %c", &c);
			if (c == 'P'){
				scanf(" %d", p);
				if (v[p - 1].rear == NULL) {
					ans.push_back(-1);
				}
				else {
					ans.push_back(v[p - 1].rear->pos);
				}
			}
			else {
				scanf(" %d %d", &p, &a);
				Node temp;
				temp.age = (long long)a;
				temp.power = (long long)p;
				temp.next = NULL;
				temp.rear = NULL;
				temp.pos = cnt++;
				v.push_back(temp);
			}
		}
	}
}