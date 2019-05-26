#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}Node;


typedef struct Queue
{
	Node* front;
	Node* rear;
	int count;
}Queue;

void InitQueue(Queue* queue)
{
	queue->front = queue->rear = NULL;
	queue->count = 0;
}

int IsEmpty(Queue* queue)
{
	return queue->count == 0;
}

void Enqueue(Queue* queue, int data)
{
	Node* now = (Node*)malloc(sizeof(Node));
	now->data = data;
	now->next = NULL;

	if (IsEmpty(queue))
	{
		queue->front = now;
	}
	else
	{
		queue->rear->next = now;
	}
	queue->rear = now;
	queue->count++;
}

int Dequeue(Queue* queue)
{
	int re = 0;
	Node* now;
	if (IsEmpty(queue))
	{
		return re;
	}
	now = queue->front;
	re = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
}

void mapcopy(int** arr, int** check, int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = arr[i][j];
		}
	}

}

void breed(int** arr, int** check, int m, int n, int k) {

	int i, j;
	for (int a = 1; a <= k; a++) {

		for (i = 151 - (a / 2) - 1; i < 151 + m + (a / 2) + 1; i++) {
			for (j = 151 - (a / 2) - 1; j < 151 + n + (a / 2) + 1; j++) {
				int max = 0;
				if (arr[i][j] == 0) {
					if (check[i - 1][j] == 0 && arr[i - 1][j] > 0) {
						max = arr[i - 1][j];
					}
					if (check[i + 1][j] == 0 && arr[i + 1][j] > 0) {
						if (max < arr[i + 1][j]) {
							max = arr[i + 1][j];
						}
					}
					if (check[i][j - 1] == 0 && arr[i][j - 1] > 0) {
						if (max < arr[i][j - 1]) {
							max = arr[i][j - 1];
						}
					}
					if (check[i][j + 1] == 0 && arr[i][j + 1] > 0) {
						if (max < arr[i][j + 1]) {
							max = arr[i][j + 1];
						}
					}
					arr[i][j] = max;
					check[i][j] = max + 1;
				}
			}
		}
		for (i = 151 - (a / 2) - 1; i < 151 + m + (a / 2) + 1; i++) {
			for (j = 151 - (a / 2) - 1; j < 151 + n + (a / 2) + 1; j++) {
				check[i][j]--;
			}
		}

	}
}
/*
void frag(int **arr, int **check, int m, int n, int time) {
	Queue * qxpos = (Queue*)malloc(sizeof(Queue));
	Queue * qypos = (Queue*)malloc(sizeof(Queue));
	InitQueue(qxpos);
	InitQueue(qypos);


}*/
int main() {
	int set, num, m, n, time;
	int i, j;

	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d", &m, &n, &time);
		int** arr;
		arr = (int**)malloc(sizeof(int*) * 352);
		for (j = 0; j < 352; j++) {
			arr[j] = (int*)calloc(352, sizeof(int));
		}
		int** check;
		check = (int**)malloc(sizeof(int*) * 352);
		for (j = 0; j < 352; j++) {
			check[j] = (int*)calloc(352, sizeof(int));
		}

		for (i = 151; i < 151 + m; i++) {
			for (j = 151; j < 151 + n; j++) {
				scanf("%d", &arr[i][j]);
				check[i][j] = arr[i][j];
			}
		}

		breed(arr, check, m, n, time);

		int sum = 0;

		for (i = 151 - (time / 2) - 1; i < 151 + m + (time / 2) + 1; i++) {
			for (j = 151 - (time / 2) - 1; j < 151 + n + (time / 2) + 1; j++) {

				if (arr[i][j] > 0 && abs(check[i][j]) <= arr[i][j] && check[i][j] * -1 != arr[i][j]) {
					sum++;
				}
			}

		}

		printf("#%d %d\n", num, sum);
	}
	return 0;
}