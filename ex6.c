#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct {

  char wine_name[50];
  char wine_country[50];
  char wine_grape_kind[50];
  char wine_harvest_year[50];

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


Queue *init_queue() {

  Queue *q;

  q = (Queue *) calloc(1, sizeof(*q));

  q -> head = q -> tail = NULL;
  q -> amount = 0;

  return q;
}


bool is_empty(Queue *q) {

	if (q -> amount == 0) {
		return true;
    }

	return false;
}


Wine *create_new_wine() {

  Wine *wine = (Wine *) calloc(1, sizeof(*wine));

  printf("Vamos começar! Qual é o nome do vinho a ser adicionado? \n");
  scanf(" %[^\n]", wine -> wine_name);
  getchar();

  printf("Agora, em que país ele foi produzido? \n");
  scanf(" %[^\n]", wine -> wine_country);
  getchar();

  printf("Entendi... Qual uva foi utilizada na sua produção? \n");
  scanf(" %[^\n]", wine -> wine_grape_kind);
  getchar();

  printf("É a última pergunta, te juro! Qual é o ano da safra desse vinho? \n");
  scanf(" %[^\n]", wine -> wine_harvest_year);
  getchar();

  return wine;
}


void push(Queue *q, Wine *wine) {

  Node *node = (Node *) calloc(1, sizeof(*node));
  
  node -> wine = wine;
  node -> next = NULL;

  if (is_empty(q)) {

    q -> head = node;
    node -> prev = NULL;
  } else {
    
    node -> prev = q -> tail;
    q -> tail -> next = node;
  }

  q -> tail = node;
  q -> amount++;
}


void i_like_to_move_it(Queue *q) {

  if (is_empty(q)) {

    printf("Parceiro(a), a fila tá vazia.\n");
    return;
  }

  Node *aux = q -> head;

  if (q -> head -> next != NULL) {

    q -> head = q -> head -> next;
  }
  else {

    q -> head = NULL;
  }

  q -> amount--;
  free(aux);
}


void display_wine_information(Wine *wine) {

  printf("\n");

  printf("Nome: %s\n", wine -> wine_name);
  printf("País: %s\n", wine -> wine_country);
  printf("Tipo da uva: %s\n", wine -> wine_grape_kind);
  printf("Safra: %s\n", wine -> wine_harvest_year);

  printf("\n");
}


void show_5_most_recent_additions(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("Amigão, não tem nenhum vinho na adega. Acho que você bebeu demais...\n");
    return;
  }
  printf("\nOk, aqui estão os 5 vinhos mais recentes: \n");

  Node *tail = wine_house -> tail;
  int i = 0;

  while (tail && i < 5) {
    display_wine_information(tail -> wine);
    tail = tail -> prev;
    i++;
  }
}


void show_5_oldest_additions(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("Amigão, não tem nenhum vinho na adega. Acho que você bebeu demais...\n");
    return;
  }
  printf("\nBeleza, aqui estão os 5 vinhos mais antigos: \n");

  Node *head = wine_house -> head;
  int i = 0;

  while (head && i < 5) {

    display_wine_information(head -> wine);
    head = head -> next;
    i++;
  }
}


void oldest_wine(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("Amigão, não tem nenhum vinho na adega. Acho que você bebeu demais...\n");
    return;
  }

  display_wine_information(wine_house -> head -> wine);
  i_like_to_move_it(wine_house);
}


void recently_registered_wine(Queue *wine_house) {

  if (is_empty(wine_house)) {

    printf("Amigão, não tem nenhum vinho na adega. Acho que você bebeu demais...\n");
    return;
  }

  display_wine_information(wine_house -> tail -> wine);
}


void display_wine_information_queue(Queue *q) {

  if (is_empty(q)) {

    printf("A adega está vazia...\n");
    return;
  }

  Node *head = q -> head;

  while (head) {
    display_wine_information(head -> wine);
    head = head -> next;
  }
}


void add_new_wine(Queue *wine_house) {

  Wine *wine = create_new_wine();
  push(wine_house, wine);
}


int main(void) {

  Queue *wine_house = init_queue();
  Queue *special_occasion_wines = init_queue();

  char wine_name[50]; 

  int choice;

  printf("\nBem-vindo à sua adega!\n");

  while (choice != 0) {

    printf("\n1 - Quero adicionar um vinho!\n");
    printf("2 - Quero ver todos os vinhos!\n");
    printf("3 - Quero ver e abrir o vinho mais antigo (não especial)!\n");
    printf("4 - Quero disponibilizar o vinho mais recente (ocasião especial) em uma adega especial!\n");
    printf("5 - Quero ver o vinho mais recente (ocasião especial)!\n");
    printf("6 - Quero ver os 5 vinhos mais antigos!\n");
    printf("7 - Quero ver os 5 vinhos mais recentes!\n");
    printf("0 - Quero sair.\n\n");
    printf("Escolha a opção: ");
    scanf("%d", &choice);


    switch(choice) {
      case 1:

        printf("\n");
        add_new_wine(wine_house);
        break;

      case 2:

        printf("\n");
        display_wine_information_queue(wine_house);
        break;

      case 3:

        printf("\n");
        oldest_wine(wine_house);
        break;

      case 4:

        push(special_occasion_wines, wine_house->tail->wine);
        printf("\nO vinho mais recente foi inserido em uma seleção especial! Você ainda pode vê-lo na lista geral(opção 2) e exibição das adegas finais(opção 0)!\n");
        break;

      case 5:

        printf("\n");
        recently_registered_wine(wine_house);
        break;

      case 6:

        printf("\n");
        show_5_oldest_additions(wine_house);
        break;

      case 7:

        printf("\n");
        show_5_most_recent_additions(wine_house);
        break;
    }
  }

  printf("\n\nAdega: \n\n");
  display_wine_information_queue(wine_house);

  printf("\n\nVinhos para Ocasiões Especiais: \n\n");
  display_wine_information_queue(special_occasion_wines);

  return 0;
}
