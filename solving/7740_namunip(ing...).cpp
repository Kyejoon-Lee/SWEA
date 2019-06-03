#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct _node {
	_node* rear;
	_node* next;
	_node* back;
	_node* above;
	_node* upper;
	_node* bound;
	long long power;
	long long age;
	int pos;
}Node;

Node test[200000];
		
int N;
int spos;
void insert(int n) {
	int tt = spos;
	while (1) {
		if (test[tt].age > test[n].age) {
			if (test[tt].rear == NULL) {
				test[n].next = &test[tt];
				test[tt].rear = &test[n];
				spos = n;
				break;
			}
			else {
				test[n].next = &test[tt];
				test[n].rear = test[tt].rear;
				test[tt].rear->next = &test[n];
				test[tt].rear = &test[n];
				break;
			}
		}
		else if(test[tt].age < test[n].age){
			if (test[tt].next == NULL) {
				test[tt].next = &test[n];
				break;
			}
			tt = test[tt].next->pos;
		}
		else {
			while (1) {
				if (test[tt].power > test[n].power) {
					if (test[tt].above == NULL) {
						test[n].rear = test[tt].rear;
						test[n].next = test[tt].next;
						test[n].back = &test[tt];
						test[tt].above = &test[n];
						test[tt].next = NULL;
						test[tt].rear = NULL;
						break;
					}
					else {
						test[n].back = &test[tt];
						test[n].above = test[tt].above;
						test[tt].above = &test[n];
						break;
					}
				}
				else {
					tt = test[tt].back->pos;
				}
			}
			break;
		}
	}
}

void check(int n) {

}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			long long p, a;
			char c;
			scanf(" %c", &c);
			if (c == 'P') {
				scanf(" %lld", p);
				
			}
			else {
				scanf(" %lld %lld", &p, &a);
				Node temp;
				temp.age = a;
				temp.power = p;
				temp.next = NULL;
				temp.rear = NULL;
				temp.pos = cnt;
				temp.above = NULL;
				temp.back = NULL;
				temp.upper = NULL;
				test[cnt] = temp;
				insert(cnt++);
			}
		}
	}
}