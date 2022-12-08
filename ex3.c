#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {

	int data;
	struct stack* next;
};


void initialize_stack(struct stack** s) {

  *s = NULL;
}


bool is_empty(struct stack* s) {

	if (s == NULL) {
		return true;
    }

	return false;
}


void push(struct stack** s, int x) {

	struct stack* p = (struct stack*) calloc(1, sizeof(*p));

	if (p == NULL) {
		fprintf(stderr, "Falha na Alocação de Memória.\n");
		return;
	}

	p->data = x;
	p->next = *s;
	*s = p;
}


int pop(struct stack** s) {

	int x;
	struct stack* temp;

	x = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;
	free(temp);

	return x;
}


int top(struct stack* s) {

  return (s->data);
}


void sorting_insert_desc(struct stack** s, int x) {

  if (is_empty(*s) || x > top(*s)) {
    push(s, x);
    return;
  }

  int temp = pop(s);
  sorting_insert_desc(s, x);
      
  push(s, temp);
}


void sorting_insert_asc(struct stack** s, int x) {

  if (is_empty(*s) || x < top(*s)) {
    push(s, x);
    return;
  }

  int temp = pop(s);
  sorting_insert_asc(s, x);
      
  push(s, temp);
}


void sort_stack_asc(struct stack** s) {
        
  if (!is_empty(*s)) {
            
    int x = pop(s);
   
    sort_stack_asc(s);

    sorting_insert_asc(s, x);
	}
}


void sort_stack_desc(struct stack** s) {
        
  if (!is_empty(*s)) {
            
    int x = pop(s);
   
    sort_stack_desc(s);

    sorting_insert_desc(s, x);
	}
}


void print_stack(struct stack* s) {
	
  while (s) {
		printf("%d ", s->data);
		s = s->next;
	}

	printf("\n");
}


int main(void) {
  
	struct stack* stack1;
  struct stack* stack2;
  struct stack* stack3;
  int size1, size2, i = 0, value;

  // Primeira Pilha
  printf("Digite o tamanho da primeira pilha: ");
  scanf("%d", &size1);

  initialize_stack(&stack1);

  while (i < size1) {
    printf("Digite um valor a ser inserido na pilha: ");
    scanf("%d", &value);
    push(&stack1, value);

    i++;
  }
  sort_stack_asc(&stack1);
  printf("\n");

  printf("Elementos da Primeira Pilha depois do Sort(Ordem Crescente):\n");
  print_stack(stack1);


  // Segunda Pilha
  printf("\nDigite o tamanho da segunda pilha: ");
  scanf("%d", &size2);

  i = 0;


  initialize_stack(&stack2);

  while (i < size2) {
    printf("Digite um valor a ser inserido na pilha: ");
    scanf("%d", &value);
    push(&stack2, value);

    i++;
  }
  sort_stack_asc(&stack2);
  printf("\n");

  printf("Elementos da Segunda Pilha depois do Sort(Ordem Crescente):\n");
  print_stack(stack2);

  initialize_stack(&stack3);

  struct stack* aux1 = stack1;

  for (i = 0; i < size1; i++) {
    value = aux1 -> data;
    aux1 = aux1 -> next;
    push(&stack3, value);
  }

  struct stack* aux2 = stack2;

  for (i = 0; i < size2; i++) {
    value = aux2 -> data;
    aux2 = aux2 -> next;
    push(&stack3, value);
  }

  sort_stack_asc(&stack3);
  printf("\n");

  printf("Elementos da Nova Pilha depois do Sort(Ordem Crescente):\n");
  print_stack(stack3);

  sort_stack_desc(&stack3);
  printf("\nElementos da Nova Pilha depois do Sort(Ordem Decrescente):\n");
  print_stack(stack3);

	return 0;
}
