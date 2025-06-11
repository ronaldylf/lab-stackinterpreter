#include "stack.h"   // Header com a definição da estrutura Stack e suas funções
#include <stdio.h>   // Para printf
#include <stdlib.h>  // Para calloc

// Estrutura da pilha
struct stack {
    int top;        // Índice do topo da pilha (próxima posição livre)
    int* values;    // Vetor que armazena os valores da pilha
};

// Cria uma nova pilha com capacidade definida por 'size'
Stack* new_stack(int size) {
    Stack* s = calloc(1, sizeof(Stack));        // Aloca memória para a estrutura
    s->values = calloc(size, sizeof(int));      // Aloca memória para os valores
    s->top = 0;                                 // Inicializa o topo como 0 (pilha vazia)
    return s;                                   // CORREÇÃO: a função precisa retornar a pilha criada
}

// Empilha um valor no topo da pilha
void stack_push(Stack* s, int value) {
    s->values[s->top++] = value;  // Insere o valor na posição atual e incrementa o topo
}

// Desempilha e retorna o valor do topo da pilha
int stack_pop(Stack* s) {
    return s->values[--s->top];  // Decrementa o topo e retorna o valor correspondente
}

// Imprime o conteúdo atual da pilha
void stack_print(Stack* s) {
    printf("------Stack---------------\n");
    for (int i = 0; i < s->top; i++) {
        printf("%d\n", s->values[i]);  // Imprime cada valor da base até o topo
    }
    printf("------Stack---------------\n");
}
