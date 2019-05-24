#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


typedef struct _Node {
	_Node **next;
	_Node *rear;
	int _peach_cnt;
	int _size;
	int _capacity;
	int _len;
	int _sum;
}Tnode;

void resize(Tnode *cur, int i) {
	cur->next = (_Node**)realloc(cur->next, sizeof(_Node*)*(i * 2));
	cur->_capacity *= 2;
}

void init(Tnode *cur) {
	cur->next = (_Node**)malloc(sizeof(_Node*) * 16);
	for (int i = 0; i < 16; i++) {
		cur->next[i] = NULL;
	}
	cur->rear = NULL;
	cur->_capacity = 16;
	cur->_len = 0;
	cur->_size = 0;
	cur->_peach_cnt = 0;
	cur->_sum = 0;
}
void reinit(Tnode *cur) {
	resize(cur, 8);
	for (int i = 0; i < 16; i++) {
		cur->next[i] = NULL;
	}
	cur->rear = NULL;
	cur->_capacity = 16;
	cur->_len = 0;
	cur->_size = 0;
	cur->_peach_cnt = 0;
	cur->_sum = 0;
}

Tnode *T = (Tnode*)malloc(sizeof(Tnode) * 3000);
int N, M, K;

void memo(Tnode *cur, int cnt) {
	if (cur->rear == NULL) {
		return;
	}
	cur->rear->_sum += cnt;
	memo(cur->rear, cnt);
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (int i = 0; i < 3000; i++) {
		init(&T[i]);
	}
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			T[temp]._peach_cnt++;
			T[temp]._sum++;
		}
		for (int i = 0; i < M; i++) {
			int temp;
			scanf("%d", &temp);
			if (i) {
				if (T[temp]._capacity == T[temp]._size) {
					resize(&T[temp], T[temp]._size);
				}
				T[temp].next[T[temp]._size++] = &T[i];
				T[i].rear = &T[temp];
				memo(&T[i], T[i]._sum);
			}
		}
		printf("#%d %d\n", num, T[0]._sum);
		for (int i = 0; i < N; i++) {
			reinit(&T[i]);
		}
	}
	return 0;
}

