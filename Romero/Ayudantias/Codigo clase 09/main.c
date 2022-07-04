#include <stdio.h>
#include <string.h>
#include "queue_stack.h"

// Leer README para instrucciones de uso
int main(int argc, char* argv[]) {
  
  if (strcmp(argv[1], "cola") == 0) {
    queue *Q = create_queue();
    print_queue(Q);
    int in;
    char option[10];
    printf("Ingrese opcion: ");
    scanf("%s %d", option, &in);
    while (strcmp(option, "quit") != 0) {
      if (strcmp(option, "push") == 0) {
        push_queue(Q, in);
        printf("Push\n");
      }
      else {
        printf("Pop %d\n", pop_queue(Q));
      }
      print_queue(Q);
      printf("Ingrese opcion: ");
      scanf("%s %d", option, &in);
    }
  }
  else {
    stack *S = create_stack();
    print_stack(S);
    int in;
    char option[10];
    printf("Ingrese opcion: ");
    scanf("%s %d", option, &in);
    while (strcmp(option, "quit") != 0) {
      if (strcmp(option, "push") == 0) {
        push_stack(S, in);
        printf("Push\n");
      }
      else {
       printf("Pop %d\n", pop_stack(S));
      }
      print_stack(S);
      printf("Ingrese opcion: ");
      scanf("%s %d", option, &in);
    }
  }
}
