#include "list.h"

List* new_list() {
    List* l = calloc(1, sizeof(List));
    l->first = NULL;
    return l;
}

static struct node* list_find(struct list* l, char* key) {
    struct node* next = l->first;
    while(next) {
        if (strcmp(next->key, key) == 0) return next;
        next = next->next;
    }
    return NULL;
}

void list_append(struct list* l, const char* key, int value) {
    struct node* node = calloc(1, sizeof(struct node));
    strcpy(node->key, key);
    node->value = value;
    node->next = l->first;
    l->first = node;
}

int list_get(List* l, char* key) {
    struct node* n = list_find(l, key);
    if (n != NULL) return n->value;
    return -1;
}

void list_set(List* l, char* key, int value) {
    struct node* n = list_find(l, key);
    if (n != NULL) n->value = value;
}

int list_exist(List* l, char* key) {
    return list_find(l, key) != NULL;
}
