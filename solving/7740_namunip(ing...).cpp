#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

typedef struct _node {
	_node* rear;
	_node* next;
	_node* back;
	_node* above;
	long long power;
	long long age;
	int pos;
	long long mini;
	long long maxi;
}Node;

Node test[200001];
int arr[200000];
deque<Node>dq;
int N;
int spos;
int apos;
void insert(int n) {
	int tt = spos;
	while (1) {
		if (test[tt].age > test[n].age) {
			if (test[tt].rear == NULL) {
			printf("!!\n");
				test[n].next = &test[tt];
				test[tt].rear = &test[n];
				spos = n;
				test[n].mini = test[n].power;
				test[n].maxi = test[n].power;
				break;
			}
			else {
				test[n].next = &test[tt];
				test[n].rear = test[tt].rear;
				test[tt].rear->next = &test[n];
				test[tt].rear = &test[n];
				test[n].mini = test[n].power;
				test[n].maxi = test[n].power;
				break;
			}
		}
		else if(test[tt].age < test[n].age){
			if (test[tt].next == NULL) {
				test[tt].next = &test[n];
				test[n].rear = &test[tt];
				test[n].mini = test[n].power;
				test[n].maxi = test[n].power;
				break;
			}
			printf("~~\n");
			tt = test[tt].next->pos;
		}
		else {
			if (test[tt].maxi < test[n].power) {
				test[tt].maxi = test[n].power;
			}
			while (1) {
				if (test[tt].power > test[n].power) {
					if (test[tt].above == NULL) {
						test[n].rear = test[tt].rear;
						test[n].next = test[tt].next;
						test[n].back = &test[tt];
						test[tt].above = &test[n];
						test[tt].next = NULL;
						test[tt].rear = NULL;
						test[n].mini = test[n].power;
						test[n].maxi = test[tt].maxi;
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
					if (test[tt].back == NULL) {
					printf("@@%d %d\n", n, tt);
						test[n].above = &test[tt];
						test[tt].back = &test[n];
						break;
					}
					tt = test[tt].back->pos;
				}
			}
			break;
		}
	}
}

void check(int n) {

	if (test[n].back != NULL) {
		arr[apos++] = test[n].back->pos;
	}
	else {
		int pos;
		if (test[n].next != NULL) {
			pos = test[n].next->pos;
		}
		else {
			arr[apos++] = -1;
			return;
		}
		dq.clear();
		dq.push_back(test[n]);
		while (1){
			Node cmp1 = dq.back();
		printf("%lld %lld\n",cmp1.maxi, test[pos].mini);
			if (cmp1.maxi <= test[pos].mini) {
				dq.pop_back();
				if (dq.empty()) {
					arr[apos++] = pos;
					return;
				}
				else {
					if (test[pos].next != NULL) {
						pos = test[pos].next->pos;
					}
					else {
						arr[apos++] = -1;
						return;
					}
				}
			}
			else {
				dq.push_back(test[pos]);
				if (test[pos].next != NULL) {
					pos = test[pos].next->pos;
				}
				else {
					arr[apos++] = -1;
					return;
				}
			}
				/*
				if (test[n].next == NULL) {
				arr[apos] = -1;
				return;
			
			}
			*/
		}
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		int cnt = 1;
		apos = 0;
		spos = 0;
		for (int i = 0; i < N; i++) {
			long long p, a;
			char c;
			scanf(" %c", &c);
			if (c == 'P') {
				int t;
				scanf("%d", &t);
				check(t);
			}
			else {
				scanf(" %lld %lld", &p, &a);
				Node temp;
				temp.age = a;
				temp.power = p;
				temp.next = NULL;
				temp.rear = NULL;
				temp.above = NULL;
				temp.back = NULL;
				temp.pos = cnt;
				temp.mini = p;
				temp.maxi = p;
				test[cnt] = temp;
				if (cnt == 1) {
					spos = cnt;
					cnt++;
				}
				else {
					insert(cnt++);
				}
			}
		}
		printf("#%d", num);
		for (int i = 0; i < apos; i++) {
			if (arr[i] != -1) {
				printf(" %d", arr[i]);
			}
			else {
				printf(" NE");
			}
		}
		printf("\n");
	}
	return 0;
}