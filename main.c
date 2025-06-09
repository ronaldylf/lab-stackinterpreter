#include <stdio.h>

#include "interpret.h"
#include "stack.h"

static void repl()
{
  char line[1024];
  Stack* stack = new_stack(10);
  List* list = new_list();
  for (;;)
  {
    printf("> ");

    if (!fgets(line, sizeof(line), stdin))
    {
      printf("\n");
      break;
    }

    interpret(line, stack, list);
  }
}




int main () {

    repl();
    return 0;
}