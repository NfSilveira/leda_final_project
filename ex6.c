#include <stdio.h>
#include <stdlib.h>


typedef struct {
  char wine_name[50];
  char wine_country[50];
  char wine_grape_kind[50];
  int wine_harvest_year;
} Wine;

typedef struct Node {
  Wine *wine;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct {

  Node *head;

  Node *tail;

  int amount;
} Queue;


Queue *initialize_queue() {

  Queue *q = malloc(sizeof(Queue));

  q->head = NULL;
  q->tail = NULL;
  q->amount = 0;

  return q;
}


void clear_inputs() {

  fflush(stdin);
  __fpurge(stdin);
}


int is_empty(Queue *q) {

  return q->amount == 0;
}


Wine *create_new_wine() {

  Wine *wine = malloc(sizeof(Wine));

  clear_inputs();
  printf("Digite o nome do vinho: \n");
  fgets(wine->wine_name, 50, stdin);

  clear_inputs();
  printf("Digite o país de origem do vinho: \n");
  fgets(wine->wine_country, 50, stdin);

  clear_inputs();
  printf("Digite o tipo da uva do vinho: \n");
  fgets(wine->wine_grape_kind, 50, stdin);

  clear_inputs();
  printf("Digite o ano da safra do vinho: \n");
  scanf("%d", &wine->wine_harvest_year);

  return wine;
}


void push(Queue *q, Wine *wine) {

  Node *node = malloc(sizeof(Node));
  node->wine = wine;
  node->next = NULL;

  if (is_empty(q)) {

    q->head = node;
    node->prev = NULL;
  }
  else {

    node->prev = q->tail;
    q->tail->next = node;
  }

  q->tail = node;
  q->amount++;
}


void shift(Queue *q) {

  if (is_empty(q)) {

    printf("A fila está vazia!\n");
    return;
  }

  Node *aux = q->head;

  if (q->head->next != NULL) {

    q->head = q->head->next;
  }
  else {

    q->head = NULL;
  }

  q->amount--;
  free(aux);
}


void print_wine(Wine *wine) {

  printf("\n");

  printf("Nome do vinho: %s\n", wine->wine_name);
  printf("País de origem: %s\n", wine->wine_country);
  printf("Tipo da uva: %s\n", wine->wine_grape_kind);
  printf("Safra: %d\n", wine->wine_harvest_year);

  printf("\n");
}


void print_5_most_recent_records(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("Não há vinhos adicionados à \"adega\"!\n");
    return;
  }

  printf("\n5 Vinhos mais recentes: \n");

  Node *tail = wine_house->tail;
  int i = 0;

  while (tail && i < 5) {

    print_wine(tail->wine);
    tail = tail->prev;
    i++;
  }
}


void print_5_oldest_registered_wines(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("Não há vinhos adicionados à \"adega\"!\n");
    return;
  }
  printf("\nVinhos mais antigos: \n");

  Node *head = wine_house->head;
  int i = 0;

  while (head && i < 5) {

    print_wine(head->wine);
    head = head->next;
    i++;
  }
}


void oldest_registered_wine(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("A \"adega\" está vazia!\n");
    return;
  }

  print_wine(wine_house->head->wine);
  shift(wine_house);
}


void recent_registered_wine(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("A \"adega\" está vazia!\n");
    return;
  }

  print_wine(wine_house->tail->wine);
}


void print_wine_queue(Queue *q) {

  if (is_empty(q)) {

    printf("A \"adega\" está vazia!\n");
    return;
  }

  Node *head = q->head;

  while (head) {
    print_wine(head->wine);
    head = head->next;
  }
}


int asc_order_check(Queue *q) {

  Node *head = q->head;

  while (head) {

    if (!head->next) {

      break;
    }

    if (head->wine->wine_harvest_year > head->next->wine->wine_harvest_year) {

      return 0;
    }

    head = head->next;
  }

  return 1;
}


void asc_order_queue(Queue *q) {

  while (!asc_order_check(q)) {

    Node *head = q->head;

    while (head) {

      if (!head->next) {

        break;
      }

      if (head->wine->wine_harvest_year > head->next->wine->wine_harvest_year) {

        Wine *aux = head->wine;
        head->wine = head->next->wine;
        head->next->wine = aux;
      }

      head = head->next;
    }
  }
}


void add_new_wine(Queue *wine_house) {

  Wine *wine = create_new_wine();
  push(wine_house, wine);
  asc_order_queue(wine_house);
}


int main(void) {

  Queue *wine_house = initialize_queue();
  Queue *special_occasion_wines = initialize_queue();

  while (1) {

    int choice;
    printf("\n\"Sistema de Adega Virtual Ifense! Escolha a opção:\"\n");
    printf("1 - Quero adicionar um vinho!\n");
    printf("2 - Quero ver todos os vinhos!\n");
    printf("3 - Quero ver todos os vinhos na lista especial!\n");
    printf("4 - Quero ver o vinho mais antigo (não especial)!\n");
    printf("5 - Quero guardar o vinho mais recente (ocasião especial) em outra "
           "estrutura\n");
    printf("6 - Quero ver o vinho mais recente (ocasião especial)!\n");
    printf("7 - Quero ver os 5 vinhos mais antigos!\n");
    printf("8 - Quero ver os 5 vinhos mais recentes!\n");
    printf("Insira qualquer outro caractere para sair.\n\n");
    scanf("%d", &choice);


    switch(choice) {
      case 1:

        add_new_wine(wine_house);

      case 2:

        print_wine_queue(wine_house);

      case 3:

        print_wine_queue(special_occasion_wines);

      case 4:

        oldest_registered_wine(wine_house);

      case 5:

        push(special_occasion_wines, wine_house->tail->wine);

      case 6:

        recent_registered_wine(wine_house);

      case 7:

        print_5_oldest_registered_wines(wine_house);

      case 8:

        print_5_most_recent_records(wine_house);

      default:
        break;
    }
  }

  printf("\n\nAdega de Vinhos: \n\n");
  print_wine_queue(wine_house);

  printf("\n\nSeleção de Vinhos Especiais: \n\n");
  print_wine_queue(special_occasion_wines);

  return 0;
}
