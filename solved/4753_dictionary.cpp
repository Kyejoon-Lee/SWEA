#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
typedef struct node {
	node* next[26];

	long long cnt;
	int flag;
	long long tsum;
	node() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
		cnt = 0;
		flag = 0;
		tsum = 0;
	}
}Node;

int N, M;
int npos;
long long sum;
Node* Tnode = (Node*)malloc(sizeof(Node) * 900000);

void init(int n) {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 26; i++) {
			Tnode[j].next[i] = NULL;
		}
		Tnode[j].cnt = 0;
		Tnode[j].flag = 0;
		Tnode[j].tsum = 0;
	}
}

void insert(Node* tree, char arr[], int len, int pos, long long temp) {

	if (pos == len) {
		tree->cnt++;
		tree->flag = 1;
		tree->tsum = temp + tree->cnt;
		return;
	}
	if (tree->next[arr[pos] - 'a'] == NULL) {

		tree->next[arr[pos] - 'a'] = &Tnode[npos++];
	}
	tree->cnt++;
	insert(tree->next[arr[pos] - 'a'], arr, len, pos + 1, (tree->cnt) + temp);
}

void find(Node * tree, char cmp[], int len, int pos, long long temp) {
	if (len == pos) {
		if (tree->flag == 1) {
			sum += tree->tsum;
		}
		else {
			sum += temp + tree->cnt;
		}
		return;
	}
	if (tree->next[cmp[pos] - 'a'] == NULL) {
		sum += temp + tree->cnt;
		return;
	}
	else {
		find(tree->next[cmp[pos] - 'a'], cmp, len, pos + 1, temp + tree->cnt);
	}
}


int main() {
	int set, num;
	init(900000);
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		sum = 0;
		scanf("%d", &N);
		npos = 1;
		for (int i = 0; i < N; i++) {
			char arr[31];
			scanf("%s", arr);
			insert(&Tnode[0], arr, strlen(arr), 0, 0);
		}
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
			char arr[31];
			scanf("%s", arr);
			find(&Tnode[0], arr, strlen(arr), 0, 0);
		}
		printf("#%d %lld\n", num, sum);
		init(npos);
	}
	return 0;
}