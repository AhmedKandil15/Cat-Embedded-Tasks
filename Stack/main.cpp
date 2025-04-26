#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STATIC_STACK_SIZE 5

typedef struct {
    int data[STATIC_STACK_SIZE];
    int top;
} StaticStack;

void staticStack_create(StaticStack *s) {
    s->top = -1;
}
bool staticStack_isEmpty(StaticStack *s) {
    return s->top == -1;
}
bool staticStack_isFull(StaticStack *s) {
    return s->top == STATIC_STACK_SIZE - 1;
}
void staticStack_push(StaticStack *s, int value) {
    if (staticStack_isFull(s)) {
        printf("Static Stack overflow! Cannot push %d\n", value);
    }
    s->data[++s->top] = value;
}
int staticStack_pop(StaticStack *s) {
    if (staticStack_isEmpty(s)) {
        printf("Static Stack underflow!\n");
        return -1;
    }
    return s->data[s->top--];
}
int staticStack_top(StaticStack *s) {
    if (staticStack_isEmpty(s)) {
        printf("Static Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
}

/* Dynamic Stack Implementation */
typedef struct {
    int *data;
    int top;
    int capacity;
} DynamicStack;

void dynamicStack_create(DynamicStack *s, int initialCapacity) {
    s->data = (int*)malloc(initialCapacity * sizeof(int));
    if (s->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->capacity = initialCapacity;
}
bool dynamicStack_isEmpty(DynamicStack *s) {
    return s->top == -1;
}
bool dynamicStack_isFull(DynamicStack *s) {
    return s->top == s->capacity - 1;
}
void dynamicStack_resize(DynamicStack *s, int newCapacity) {
    int *newData = (int*)realloc(s->data, newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("Memory reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
    s->data = newData;
    s->capacity = newCapacity;
    printf("Dynamic Stack resized to %d\n", newCapacity);
}
void dynamicStack_push(DynamicStack *s, int value) {
    if (dynamicStack_isFull(s)) {
        dynamicStack_resize(s, s->capacity * 2);
    }
    s->data[++s->top] = value;
}
int dynamicStack_pop(DynamicStack *s) {
    if (dynamicStack_isEmpty(s)) {
        printf("Dynamic Stack underflow!\n");
        return -1;
    }
    return s->data[s->top--];
}

int dynamicStack_top(DynamicStack *s) {
    if (dynamicStack_isEmpty(s)) {
        printf("Dynamic Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
}
void dynamicStack_free(DynamicStack *s) {
    free(s->data);
    s->top = -1;
    s->capacity = 0;
}

int main() {
    printf("Static Stack Display\n");
    StaticStack sStack;
    staticStack_create(&sStack);
    printf("\nPushing to static stack:\n");
    for (int i = 1; i <= STATIC_STACK_SIZE + 2; i++) {
        printf("  Attempting to push %d: ", i);
        staticStack_push(&sStack, i);
        printf("Top is now %d\n", staticStack_top(&sStack));
    }

    printf("\nPopping from static stack:\n");
    while (!staticStack_isEmpty(&sStack)) {
        int val = staticStack_pop(&sStack);
        printf("  Popped %d, ", val);
        if (!staticStack_isEmpty(&sStack)) {
            printf("next top is %d\n", staticStack_top(&sStack));
        } else {
            printf("stack is now empty\n");
        }
    }
    printf("\nTesting underflow:\n");
    staticStack_pop(&sStack);

    printf("\n\n Dynamic Stack Display\n");
    DynamicStack dStack;
    dynamicStack_create(&dStack, 2);
    printf("\nPushing to dynamic stack:\n");
    for (int i = 1; i <= 6; i++) {
        printf("  Pushing %d: ", i);
        dynamicStack_push(&dStack, i);
        printf("Top is %d (Capacity: %d)\n", dynamicStack_top(&dStack), dStack.capacity);
    }

    printf("\nPopping from dynamic stack:\n");
    while (!dynamicStack_isEmpty(&dStack)) {
        int val = dynamicStack_pop(&dStack);
        printf("  Popped %d, ", val);
        if (!dynamicStack_isEmpty(&dStack)) {
            printf("next top is %d (Capacity: %d)\n", dynamicStack_top(&dStack), dStack.capacity);
        } else {
            printf("stack is now empty (Capacity remains %d)\n", dStack.capacity);
        }
    }
    printf("\nTesting underflow:\n");
    dynamicStack_pop(&dStack);
    dynamicStack_free(&dStack);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.