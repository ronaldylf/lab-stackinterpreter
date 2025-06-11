// Verifica se o header já foi incluído anteriormente.
// Isso evita múltiplas inclusões do mesmo arquivo (problema comum em C).
#ifndef interprete_h
#define interprete_h

// Inclui o header da pilha, necessário para usar o tipo Stack e suas operações
#include "stack.h"

// Inclui o header da lista, necessário para usar o tipo List e suas operações
#include "list.h"

// Declaração da função interpret:
// - 'source': string com o comando a ser interpretado (ex: "push 10")
// - 'stack': ponteiro para a pilha onde os dados são manipulados
// - 'list': ponteiro para a lista onde variáveis e valores são armazenados
void interpret (const char *source, Stack* stack, List* list);

// Fim do bloco de proteção contra múltiplas inclusões
#endif
