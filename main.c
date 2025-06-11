#include <stdio.h>       // Biblioteca padrão para entrada e saída

#include "interpret.h"   // Header com a função interpret()
#include "stack.h"       // Header com a estrutura de pilha

// Função REPL (Read-Eval-Print Loop)
// Lê comandos do usuário, interpreta e executa continuamente
static void repl()
{
  char line[1024];                  // Buffer para armazenar a linha digitada
  Stack* stack = new_stack(10);     // Cria uma nova pilha com capacidade inicial 10
  List* list = new_list();          // Cria uma nova lista de variáveis

  for (;;)
  {
    printf("> ");                   // Prompt do usuário

    // Lê uma linha do teclado; se falhar (EOF), encerra o loop
    if (!fgets(line, sizeof(line), stdin))
    {
      printf("\n");                 // Imprime nova linha antes de sair
      break;
    }

    // Interpreta e executa a linha de comando lida
    interpret(line, stack, list);
  }
}

// Função principal do programa
int main () {
    repl();         // Inicia o loop de leitura e execução de comandos
    return 0;       // Retorna 0 indicando execução bem-sucedida
}
