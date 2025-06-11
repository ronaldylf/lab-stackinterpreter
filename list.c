#include "list.h"  // Header que define a estrutura da lista e suas funções

// Cria uma nova lista e inicializa seus campos
List* new_list() {
    List* l = calloc(1, sizeof(List)); // Aloca memória e zera os campos
    l->first = NULL; // Inicialmente, a lista está vazia
    return l;
}

// Função auxiliar interna para encontrar um nó na lista com a chave fornecida
static struct node* list_find(struct list* l, char* key) {
    struct node* next = l->first; // Começa do início da lista
    while (next) {
        // Compara a chave atual com a chave buscada
        if (strcmp(next->key, key) == 0) return next; // Nó encontrado
        next = next->next; // Avança para o próximo nó
    }
    return NULL; // Retorna NULL se a chave não for encontrada
}

// Adiciona um novo par (chave, valor) à lista
void list_append(struct list* l, const char* key, int value) {
    struct node* node = calloc(1, sizeof(struct node)); // Aloca memória para novo nó
    strcpy(node->key, key); // Copia a chave para o nó
    node->value = value;    // Atribui o valor
    node->next = l->first;  // Insere o novo nó no início da lista (inserção rápida)
    l->first = node;        // Atualiza o ponteiro do início da lista
}

// Retorna o valor associado a uma chave
int list_get(List* l, char* key) {
    struct node* n = list_find(l, key); // Busca o nó
    if (n != NULL) return n->value;     // Se encontrado, retorna o valor
    return -1; // Caso não encontrado, retorna -1 (valor de erro ou padrão)
}

// Atualiza o valor associado a uma chave existente
void list_set(List* l, char* key, int value) {
    struct node* n = list_find(l, key); // Busca o nó
    if (n != NULL) n->value = value;    // Se encontrado, atualiza o valor
}

// Verifica se uma chave existe na lista
int list_exist(List* l, char* key) {
    return list_find(l, key) != NULL; // Retorna 1 (true) se existe, 0 (false) se não
}
