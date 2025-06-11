#ifndef stack_h
#define stack_h

// Define a estrutura 'Stack' como um tipo opaco.
// A implementação dos campos está no arquivo .c (encapsulamento).
typedef struct stack Stack;

// Cria uma nova pilha com capacidade inicial definida por 'size'
// Retorna um ponteiro para a estrutura Stack alocada
Stack* new_stack(int size);

// Adiciona (empilha) um valor inteiro no topo da pilha
void stack_push(Stack* s, int value);

// Remove (desempilha) e retorna o valor do topo da pilha
int stack_pop(Stack* s);

// Imprime o conteúdo atual da pilha no terminal
void stack_print(Stack* s);

#endif
