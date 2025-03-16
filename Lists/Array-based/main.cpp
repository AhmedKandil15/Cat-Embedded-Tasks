#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

typedef struct {
    int array[CAPACITY];
    int size;
} List;
void CreateList(List *pl) {
    pl->size = 0;
    printf("List created with capacity: %d\n", CAPACITY);
}
int isFull(List *pl) {
    return pl->size == CAPACITY;
}
int isEmpty(List *pl) {
    return pl->size == 0;
}
int ListSize(List *pl){
    return pl->size;
}
void replace(List *pl, int index, int value) {
    pl->array[index] = value;
    printf("Replaced element at index %d with %d\n", index, value);
}
void retrieve(List *pl, int index) {
     pl->array[index];
}
void add(List *pl, int value) {
    if (isFull(pl)) {
        printf("List is full! Cannot add %d\n", value);
        return;
    }
    pl->array[pl->size++] = value;
    printf("Added: %d\n", value);
}
void insert(List *pl, int index, int value) {
    if (index < 0 || index > pl->size) {
        printf("Invalid index!\n");
        return;
    }
    if (isFull(pl)) {
        printf("List is full! Cannot insert %d\n", value);
        return;
    }
    for (int i = pl->size; i > index; i--) {
        pl->array[i] = pl->array[i - 1];
    }
    pl->array[index] = value;
    pl->size++;
    printf("Inserted: %d at index %d\n", value, index);
}
void DeleteList(List *pl, int index) {
    if (index < 0 || index >= pl->size) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < pl->size - 1; i++) {
        pl->array[i] = pl->array[i + 1];
    }
    pl->size--;
    printf("Removed element at index %d\n", index);
}
void Traverse(List *list) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

int main() {
    List pl;
    CreateList(&pl);

    add(&pl, 10);
    add(&pl, 20);
    add(&pl, 30);
    Traverse(&pl);

    insert(&pl, 1, 15);
    Traverse(&pl);

    DeleteList(&pl, 2);
    Traverse(&pl);

    add(&pl, 40);
    add(&pl, 50);
    add(&pl, 60);
    Traverse(&pl);

    return 0;
}