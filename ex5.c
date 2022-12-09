#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

  int number;
  struct Node *next;
} Node;

typedef struct Stack {

  Node *top;

  // Quantidade de elementos da pilha
  int amount;
} Stack;


int is_empty(Stack *p) {

  return p->amount == 0;
}


void push(Stack *p, int num) {

  Node *new_element = malloc(sizeof(Node));
  new_element->number = num;
  new_element->next = NULL;

  if (p->amount != 0)
    new_element->next = p->top;

  p->top = new_element;
  p->amount++;
}


Stack *initialize_stack() {

  Stack *p = malloc(sizeof(Stack));

  p->top = NULL;
  p->amount = 0;

  return p;
}


Stack *insert_into_stack() {

  Stack *p = initialize_stack();

  while (1) {

    int num;
    printf("Insira um valor que será colocado na pilha(digite um valor menor ou igual a 0 para encerrar a inserção):\n");
    scanf("%d", &num);

    if (num <= 0) {

      break;
    }
    push(p, num);
  }

  return p;
}


void print_stack(Stack *p) {

  if (is_empty(p)) {

    printf("A pilha está vazia!\n");
    return;
  }

  Node *top = p->top;
  printf("\nAqui é o topo da pilha :)\n");

  while (top) {

    printf("\t%d\n", top->number);
    top = top->next;
  }

  printf("\nAqui é o fim da pilha :)\n");
}


void fill_with_numbers(Stack *original, Stack *even_numbers_stack, Stack *odd_numbers_stack) {

  Node *top = original->top;

  while (top) {
    if (top->number % 2 == 0)
      push(even_numbers_stack, top->number);
    else
      push(odd_numbers_stack, top->number);
    top = top->next;
  }
}


int main() {

  printf("\nCriando a primeira pilha...\n");
  Stack *stack = insert_into_stack();

  printf("Esta é a pilha original: \n");
  print_stack(stack);

  Stack *even_numbers_stack = initialize_stack();
  Stack *odd_numbers_stack = initialize_stack();

  fill_with_numbers(stack, even_numbers_stack, odd_numbers_stack);

  printf("Aqui estão os números pares: \n");
  print_stack(even_numbers_stack);

  printf("Aqui estão os números ímpares: \n");
  print_stack(odd_numbers_stack);

  return 0;
}
