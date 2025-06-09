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

void interpret (const char *source, Stack* stack) {
    char op[10];
    char arg[10];

    sscanf (source, "%s%s", op, arg);
    // printf("operação: %s\n", op);
    // printf("argumento: %s\n",  arg);

    if (isEqual(op, "push")) { // Adicionar à pilha
        stack_push(stack, atoi(arg));
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
    } else if (isEqual(op, "exit")) {  // Sair
        exit(0);
    }
}