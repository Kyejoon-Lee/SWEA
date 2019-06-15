#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

typedef struct _node {
	_node* left;
	_node* right;
	_node* next;
	_node* above;
	long long age;
	long long power;
	int pos;
	long long maxi;
	long long mini;
	int height;

}Node;

int N;
Node map[200001];
Node* root;
deque<Node*>dq1;
deque<Node*>dq2;
deque<int>ans;

int theight(Node* a) {
	int t;
	if (a == NULL) {
		return -1;

	}
	else {
		t = a->height;
		return t;
	}
}
Node* srl(Node*& a) {
	Node* temp;
	temp = a->left;
	a->left = temp->right;
	temp->right = a;
	a->height = max(theight(a->left), theight(a->right)) + 1;
	temp->height = max(theight(temp->left), a->height) + 1;
	return temp;
}

Node* srr(Node*& a) {
	Node* temp;
	temp = a->right;
	a->right = temp->left;
	temp->left = a;
	a->height = max(theight(a->left), theight(a->right)) + 1;
	temp->height = max(theight(temp->right), a->height) + 1;
	return temp;
}

Node* drl(Node*& a) {
	a->left = srr(a->left);
	return srl(a);
}

Node* drr(Node*& a) {
	a->right = srl(a->right);
	return srr(a);
}

void insert(Node*& r, int tpos) {
	if (r->age == map[tpos].age) {
		if (r->maxi < map[tpos].power) {
			r->maxi = map[tpos].power;
			map[r->above->pos].next = &map[tpos];
			map[tpos].above = r->above;
			r->above = &map[tpos];
			map[tpos].next = r;
			return;
		}
		while (1) {
			if (r->power > map[tpos].power) {
				map[tpos].maxi = r->maxi;
				map[r->above->pos].next = &map[tpos];
				map[tpos].above = r->above;
				map[tpos].next = r;
				r->above = &map[tpos];
				return;
			}
			else {
				r = r->next;
			}
		}
	}
	else if (r->age > map[tpos].age) {

		if (r->left == NULL) {
			r->left = &map[tpos];
		}
		else {
			insert(r->left, tpos);
		}
		if (theight(r->left) - theight(r->right) == 2) {
			if (map[tpos].age < r->left->age) {
				r = srl(r);
			}
			else {
				r = drl(r);
			}
		}
	}
	else {
		if (r->right == NULL) {
			r->right = &map[tpos];
		}
		else {
			insert(r->right, tpos);
		}

		if (theight(r->right) - theight(r->left) == 2) {
			if (map[tpos].age > r->right->age) {
				r = srr(r);
			}
			else {
				r = drr(r);
			}
		}
	}
	r->height = max(theight(r->right), theight(r->left)) + 1;
}

void travel(long long num) {
	dq1.clear();
	dq2.clear();
	Node* cur = root;
	while (cur !=NULL || !dq1.empty()) {
		
		while (cur != NULL && cur->age >= num) {
			dq1.push_back(cur);
			cur = cur->left;
		}
		if (!dq1.empty()) {
			cur = dq1.back();
			dq1.pop_back();
		}
		if (!dq2.empty()) {
			if (dq2.back()->maxi <= cur->mini) {
				dq2.pop_back();
			}
			else {
				dq2.push_back(cur);
			}
			if (dq2.empty()) {
				ans.push_back(cur->pos);
				return;
			}
		}
		else {
			if (num <= cur->age) {
				dq2.push_back(cur);
			}
		}
		cur = cur->right;
	}
	ans.push_back(-1);
}

void check(int p) {
	if (map[p].next->power > map[p].power) {
		ans.push_back(map[p].next->pos);
	}
	else {
		travel(map[p].age);
	}
}

int main() {
	int set;
	scanf("%d", &set);
	for (int num = 1; num <= set; num++) {
		scanf("%d", &N);
		ans.clear();
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			char t;
			scanf(" %c",&t);
			if (t == 'D') {
				long long p, a;
				scanf("%lld %lld", &p, &a);
				map[cnt].left = NULL;
				map[cnt].right = NULL;
				map[cnt].next = &map[cnt];
				map[cnt].above = &map[cnt];
				map[cnt].age = a;
				map[cnt].power = p;
				map[cnt].pos = cnt;
				map[cnt].maxi = p;
				map[cnt].mini = p;
				map[cnt].height = 0;
				if (cnt == 1) {
					root = &map[cnt];
				}
				else {
					insert(root, cnt);
				}
				cnt++;
			}

			else {
				int p;
				scanf("%d", &p);
				check(p);
			}
		}
		printf("#%d", num);
		while (!ans.empty()) {
			if (ans.front() == -1) {
				printf(" NE");
				ans.pop_front();
			}
			else {
				printf(" %d", ans.front());
				ans.pop_front();
			}
		}
		printf("\n");
	}
	return 0;
}