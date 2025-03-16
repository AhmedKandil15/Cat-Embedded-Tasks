#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int entry;
    struct Node *next;
} Node;
typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList *CreateList() {
    LinkedList *pl = (LinkedList *)malloc(sizeof(LinkedList));
    if (!pl) {
        printf("Memory allocation failed for the pl!\n");
        exit(1);
    }
    pl->head = NULL;
    pl->size = 0;
    printf("List created.\n");
    return pl;
}

int ListEmpty(LinkedList *pl) {
    return (pl->size == 0);
}
int ListSize(LinkedList *pl) {
    return pl->size;
}
int ListFull(LinkedList *pl){
    return 0;
}

void DestroyList(LinkedList *pl) {
    Node *current = pl->head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(pl);
    printf("List destroyed and memory freed.\n");
}

void InsertList(LinkedList *pl, int index, int value) {
    if (index < 0 || index > pl->size) {
        printf("Invalid index for insertion!\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed for the new node!\n");
        return;
    }
    newNode->entry = value;
    if (index == 0) {
        newNode->next = pl->head;
        pl->head = newNode;
    }
    else {
        Node *current = pl->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    pl->size++;
    printf("Inserted: %d at index %d\n", value, index);
}

void DeleteList(LinkedList *pl, int index) {
    Node *temp;
    if (index == 0) {
        temp = pl->head;
        pl->head = pl->head->next;
    }
    else {
        Node *current = pl->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    pl->size--;
    printf("Deleted element at index %d\n", index);
}

int RetrieveList(LinkedList *pl, int index) {
    Node *current = pl->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->entry;
}

void TraverseList(LinkedList *pl) {
    if (ListEmpty(pl)) {
        printf("List is empty!\n");
        return;
    }
    Node *current = pl->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->entry);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList *pl = CreateList();

    InsertList(pl, 0, 10);
    InsertList(pl, 1, 20);
    InsertList(pl, 2, 30);
    TraverseList(pl);

    InsertList(pl, 1, 15);
    TraverseList(pl);

    DeleteList(pl, 2);
    TraverseList(pl);

    int value = RetrieveList(pl, 1);
    if (value != -1) {
        printf("Retrieved value at index 1: %d\n", value);
    }

    printf("List size: %d\n", ListSize(pl));
    printf("Is pl empty? %s\n", ListEmpty(pl) ? "Yes" : "No");

    DestroyList(pl);
    return 0;
}// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.