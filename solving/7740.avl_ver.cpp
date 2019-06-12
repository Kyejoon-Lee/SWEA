#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

typedef struct _node{
	_node* left;
	_node* right;
	_node* next;
	_node* rear;
	long long power;
	long long age;
	int pos;
	long long mini;
	long long maxi;
	int height;
}Node;

Node leaf[200001];
int arr[200001];
int N;
Node* root;


void insert(Node &n1, Node *n2) {
	if (n1.age == n2->age) {
		if (n1.maxi < n2->power) {
			n1.maxi = n2->power;
		}
		int tpos = n1.pos;
		while (1) {
			if (leaf[tpos].power < n2->power) {
				if (leaf[tpos].next == NULL) {
					leaf[tpos].next = n2;
					n2->rear = &leaf[tpos];
					break;
				}
				tpos = leaf[tpos].next->pos;
				continue;
			}
			else {
				n2->next = &leaf[tpos];
				if (leaf[tpos].rear != NULL) {
					n2->rear = leaf[tpos].rear;
				}
				else {
					n2->rear = NULL;
				}
				leaf[tpos].rear = n2;
				break;
			}
		}
	}
	else if (n1.age > n2->age) {
		printf("!!!!!!!!!\n");
		if (n1.left == NULL) {
			n1.left = n2;
		}
		else {
			insert(*n1.left, n2);
		}
		int hl, hr;
		if (n1.left == NULL) {
			hl = -1;
		}
		else {
			hl = n1.left->height;
		}
		if (n1.right == NULL) {
			hr = -1;
		}
		else {
			hr = n1.right->height;
		}
		if (hl-hr == 2) {
			printf("*****\n");
			if (n1.left->age > n2->age) {
				Node* temp;
				temp = n1.left;
				n1.left = temp->right;
				temp->right = &n1;
				int hl, hr;
				if (n1.left == NULL) {
					hl = -1;
				}
				else {
					hl = n1.left->height;
				}
				if (n1.right == NULL) {
					hr = -1;
				}
				else {
					hr = n1.right->height;
				}
				n1.height = max(hl, hr) + 1;
				int tl;
				if (temp->left == NULL) {
					tl = -1;
				}
				else {
					tl = temp->left->height;
				}
				temp->height = max(tl, n1.height) + 1;
				n1 = *temp;
			}
			else {
				Node* temp;
				temp = n1.left->right;
				n1.left->right = temp->left;

				temp->left = n1.left;
				int hl, hr;
				if (n1.left->left == NULL) {
					hl = -1;
				}
				else {
					hl = n1.left->left->height;
				}
				if (n1.left ->right == NULL) {
					hr = -1;
				}
				else {
					hr = n1.left->right->height;
				}
				n1.left->height = max(hl, hr) + 1;
				int tr;
				if (temp->right == NULL) {
					tr = -1;
				}
				else {
					tr = temp->right->height;
				}
				temp->height = max(tr, n1.left->height) + 1;
				n1.left = temp;
				Node* tt;
				tt = n1.left;
				n1.left = tt->right;
				tt->right = &n1;
	
				if (n1.left == NULL) {
					hl = -1;
				}
				else {
					hl = n1.left->height;
				}
				if (n1.right == NULL) {
					hr = -1;
				}
				else {
					hr = n1.right->height;
				}
				n1.height = max(hl, hr) + 1;
				int tl;
				if (tt->left == NULL) {
					tl = -1;
				}
				else {
					tl = tt->left->height;
				}
				tt->height = max(tl, n1.height) + 1;
				n1 = *tt;
			}
		}
	}
	else {
		if (n1.right == NULL) {
			n1.right = n2;
			printf("%lld\n", n1.right->age);
		}
		else {

			printf("%lld\n", n1.right->age);
			insert(*n1.right, n2);
		}
		int hl, hr;
		if (n1.left == NULL) {
			hl = -1;
		}
		else {
			hl = n1.left->height;
		}
		if (n1.right == NULL) {
			hr = -1;
		}
		else {
			hr = n1.right->height;
		}
		if (hr-hl == 2) {
			if (n1.right->age < n2->age) {
			printf("______\n");
			Node temp;
			temp = *n1.right;
			n1.right = temp.left;

			temp.left = &n1;
			printf(")()()()%lld\n", temp.left->age);
			int hl, hr;
			if (n1.left == NULL) {
				hl = -1;
			}
			else {
				hl = n1.left->height;
			}
			if (n1.right == NULL) {
				hr = -1;
			}
			else {
				hr = n1.right->height;
			}
			n1.height = max(hl, hr) + 1;
			int tr;
			if (temp.right == NULL) {
				tr = -1;
			}
			else {
				tr = temp.right->height;
			}
			temp.height = max(tr, n1.height) + 1;
			n1 = temp;
			printf("-/-/-/%lld\n", n1.left->age);
			}
			else {
				printf("~~~~~#\n");
				Node* tt;
				tt = n1.right->left;
				n1.right->left = tt->right;
				tt->right = n1.right;
				int hl, hr;
				if (n1.right->left == NULL) {
					hl = -1;
				}
				else {
					hl = n1.right->left->height;
				}
				if (n1.right->right == NULL) {
					hr = -1;
				}
				else {
					hr = n1.right->right->height;
				}
				n1.right->height = max(hl, hr) + 1;
				int tl;
				if (tt->left == NULL) {
					tl = -1;
				}
				else {
					tl = tt->left->height;
				}
				tt->height = max(tl, n1.right->height) + 1;
				n1.right = tt;

				Node* temp;
				temp = n1.right;
				n1.right = temp->left;

				temp->left = &n1;

				if (n1.left == NULL) {
					hl = -1;
				}
				else {
					hl = n1.left->height;
				}
				if (n1.right == NULL) {
					hr = -1;
				}
				else {
					hr = n1.right->height;
				}
				n1.height = max(hl, hr) + 1;
				int tr;
				if (temp->right == NULL) {
					tr = -1;
				}
				else {
					tr = temp->right->height;
				}
				temp->height = max(tr, n1.height) + 1;
				n1 = *temp;
			}
		}
	}
	int hl, hr;
	if (n1.left == NULL) {
		hl = -1;
	}
	else {
		hl = n1.left->height;
	}
	if (n1.right == NULL) {
		hr = -1;
	}
	else {
		hr = n1.right->height;
	}
	n1.height = max(hl,hr) + 1;
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		int cnt = 1;
		root = NULL;
		for (int i = 0; i < N; i++) {
			long long p, a;
			char c;
			scanf(" %c", &c);
			if (c == 'P') {
				int t;
				scanf("%d", &t);
				///check(t);
			}
			else {
				scanf(" %lld %lld", &p, &a);
				Node temp;
				temp.age = a;
				temp.power = p;
				temp.next = NULL;
				temp.rear = NULL;
				temp.left = NULL;
				temp.right = NULL;
				temp.pos = cnt;
				temp.mini = p;
				temp.maxi = p;
				temp.height = 0;
				leaf[cnt] = temp;
				if (cnt == 1) {
					root = &leaf[cnt];
				}
				insert(*root, &leaf[cnt++]);
			}
		}
		printf("!!%lld\n", root->left->age);
		printf("#%d", num);
	}
	return 0;
}