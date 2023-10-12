#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct LinkedList {
    int length;
    struct Node* head;
    struct Node* tail;
};

struct LinkedList* LinkedList_new() {
    struct LinkedList* linked_list = malloc(sizeof(struct LinkedList));
    linked_list->length = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
    return linked_list;
}

struct Node* Node_new(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->next = NULL;
    node->value = value;
    return node;
}

void LinkedList_append(struct LinkedList* list, int value) {
    list->length++;

    struct Node* node = Node_new(value);

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = node;
}

void LinkedList_remove(struct LinkedList* list, int value) {
    if (list->length > 0) {
        list->length--;
    }

    struct Node* target_node = list->head;
    struct Node* previous_node = NULL;

    while (target_node->value != value) {
        previous_node = target_node;
        target_node = target_node->next;
    }

    if (target_node == NULL) {
        return;
    }

    // deleting head
    if (previous_node == NULL) {
        struct Node* head = list->head;
        list->head = list->head->next;
        free(head);
        return;
    }

    struct Node* dangling = target_node;
    previous_node->next = target_node->next;
    free(dangling);
}

void LinkedList_print(struct LinkedList list) {
    struct Node* current_node = list.head;
    while (current_node != NULL) {
        if (current_node->next != NULL) {
            printf("%d -> ", current_node->value);
        } else {
            printf("%d", current_node->value);
        }

        current_node = current_node->next;
    }

    printf("\n");
}

void LinkedList_clear(struct LinkedList* list) {
    while (list->head != NULL) {
        LinkedList_remove(list, list->head->value);
    }
}

int main() {
    struct LinkedList* list = LinkedList_new();

    for (int i = 0; i < 10; i++) {
        LinkedList_append(list, i);
    }

    printf("after append, len - %d\n", list->length);
    LinkedList_print(*list);

    for (int i = 2; i < 7; i++) {
        LinkedList_remove(list, i);
    }

    printf("after remove, len - %d\n", list->length);
    LinkedList_print(*list);

    LinkedList_clear(list);
    printf("after clear, len - %d\n", list->length);
    LinkedList_print(*list);

    free(list);

    return 0;
}
