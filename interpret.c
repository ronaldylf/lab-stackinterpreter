#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "interpret.h"
#include <string.h>
#include "stack.h"


bool isEqual(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

void interpret (const char *source, Stack* stack, List* list) {
    char op[10];
    char arg[10];

    sscanf (source, "%s%s", op, arg);

    if (isEqual(op, "push")) { // Adicionar à pilha
        int value;
        /*armazena um inteiro decimal na variável value
        se não houver nenhum número, pega o valor da variável
        na lista de acordo com a chave
        */
        if (sscanf(arg, "%d", &value) == 0) {
            value = list_get(list, arg);
        }

        stack_push(stack, value);
    } else if (isEqual(op, "add")) { // Somar
        const int a = stack_pop(stack);
        const int b = stack_pop(stack);
        stack_push(stack, a+b);
    } else if (isEqual(op, "sub")) { // Subtrair
        const int a = stack_pop(stack);
        const int b = stack_pop(stack);
        stack_push(stack, b-a);
    } else if (isEqual(op, "div")) { // Dividir
        const int a = stack_pop(stack);
        const int b = stack_pop(stack);
        if (a==0) {
            printf("Não é possível dividir por 0.");
        } else {
            stack_push(stack, b/a);
        }
    } else if (isEqual(op, "print")) { // Printar
        printf("%d\n", stack_pop(stack));
    } else if (isEqual(op, "pop")) {
        int value = stack_pop(stack);
        
        if (list_exist(list, arg)) {
            list_set(list, arg, value);
        } else {
            list_append(list, arg, value);
        }

    } else if (isEqual(op, "exit")) {  // Sair
        exit(0);
    }
}