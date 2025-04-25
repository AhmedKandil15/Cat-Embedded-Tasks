#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void CreateQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void append(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot append %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
    printf("Appended: %d\n", value);
}

int serve(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot serve.\n");
        return -1;
    }
    int value = q->items[q->front++];
    printf("served: %d\n", value);
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    CreateQueue(&q);

    append(&q, 10);
    append(&q, 20);
    append(&q, 30);
    displayQueue(&q);

    serve(&q);
    displayQueue(&q);

    append(&q, 40);
    append(&q, 50);
    append(&q, 60);
    displayQueue(&q);

    return 0;
}// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.