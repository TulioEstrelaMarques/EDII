#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
    int data;
    LinkedNode* next;
};

LinkedNode* concatena(LinkedNode* lis1, LinkedNode* lis2) {
    if (lis1 == NULL) return lis2;
    if (lis2 == NULL) return lis1;

    LinkedNode* tmp1 = lis1;
    while (lis1 != NULL) {
        lis1 = lis1->next;
    }
    lis1->next = lis2;

    return tmp1;
}

void printList(LinkedNode* curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main() {
    LinkedNode* first1 = malloc(sizeof(LinkedNode));
    LinkedNode* second1 = malloc(sizeof(LinkedNode));
    LinkedNode* first2 = malloc(sizeof(LinkedNode));
    LinkedNode* second2 = malloc(sizeof(LinkedNode));

    first1->data = 1;
    first1->next = second1;
    second1->data = 2;
    second1->next = NULL;

    first2->data = 3;
    first2->next = second2;
    second2->data = 4;
    second2->next = NULL;

    printf("Lista 1: ");
    printList(first1);
    printf("Lista 2: ");
    printList(first2);

    printList(concatena(first1, first2));

    free(first1);
    free(first2);
    free(second1);
    free(second2);

    return 0;
}
