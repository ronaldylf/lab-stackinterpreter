#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char key[15];
    int value;
    struct node* next;
};

struct list {
    struct node* first;
} typedef List;


List* new_list();
static struct node* list_find(struct list* l, char* key);
void list_append(struct list* l, const char* key, int value);
int list_get(List* l, char* key);
void list_set(List* l, char* key, int value);
int list_exist(List* l, char* key);