#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int num[10000];
	int front;
	int rear;
}node;


void push(node* queue, int value);
void pop(node* queue);
void size(node* queue);
void empty(node* queue);
void front(node* queue);
void back(node* queue);

int main() {
	node queue;
	queue.front = 0;
	queue.rear = 0;
	int a;
	char* str = (char *)malloc(sizeof(int)* 20);
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%s", str);
		int value;
		if (!strcmp(str, "back"))
			back(&queue);
		else if (!strcmp(str, "push")) {
			scanf("%d", &value);
			push(&queue, value);
		}
		else if (!strcmp(str, "pop"))
			pop(&queue);
		else if (!strcmp(str, "empty"))
			empty(&queue);
		else if (!strcmp(str, "size"))
			size(&queue);
		else if (!strcmp(str, "front"))
			front(&queue);

	}
	free(str);
}

void push(node* queue, int value) {
	queue->num[queue->rear] = value;
	queue->rear++;
}
void pop(node* queue) {
	if (queue->front == queue->rear)
		printf("-1\n");
	else {
		printf("%d\n", queue->num[queue->front]);
		queue->front++;
	}
}
void size(node* queue) {
	printf("%d\n", queue->rear - queue->front);
}
void empty(node* queue) {
	if (queue->front == queue->rear)
		printf("1\n");
	else
		printf("0\n");
}
void front(node* queue) {
	if (queue->front == queue->rear)
		printf("-1\n");
	else
		printf("%d\n", queue->num[queue->front]);
}
void back(node* queue) {
	if (queue->front == queue->rear)
		printf("-1\n");
	else
		printf("%d\n", queue->num[queue->rear - 1]);
}