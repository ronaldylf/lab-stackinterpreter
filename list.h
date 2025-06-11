#include <stdio.h>   // Biblioteca padrão de entrada/saída (necessária em algumas implementações)
#include <stdlib.h>  // Para funções de alocação de memória como malloc/calloc
#include <string.h>  // Para manipulação de strings (strcmp, strcpy, etc.)

// Estrutura de um nó da lista encadeada
struct node {
    char key[15];         // Chave associada ao valor (nome da variável, por exemplo)
    int value;            // Valor armazenado
    struct node* next;    // Ponteiro para o próximo nó da lista
};

// Estrutura da lista encadeada (aponta para o primeiro nó)
struct list {
    struct node* first;   // Início da lista
} typedef List;           // Define "List" como um alias para "struct list"

// Cria e retorna um novo objeto List vazio
List* new_list();

// Função interna (não deve ser usada fora do .c):
// Procura por um nó com a chave fornecida e retorna um ponteiro para ele
static struct node* list_find(struct list* l, char* key);

// Adiciona um novo par (chave, valor) ao início da lista
void list_append(struct list* l, const char* key, int value);

// Retorna o valor associado a uma chave (ou -1 se não existir)
int list_get(List* l, char* key);

// Altera o valor associado a uma chave existente
void list_set(List* l, char* key, int value);

// Verifica se uma determinada chave existe na lista
int list_exist(List* l, char* key);
