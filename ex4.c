#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647
// Maximum value for a variable of type int

typedef struct Node {
  int num;
  struct Node *next;
} Node;
Node fila[3];
int qty = 0;

void InserirFilas() {
  int NewNum, PreNum;

  printf("Insira a primeira fila em ordem crescente:\n");
  printf("(Para encerrar, quebre a ordem crescente)");
  for (int i = 0, encerrar = 0, FirstTime = 0; encerrar == 0; i++) {
    Node *aux, *novo = malloc(sizeof(Node));
    printf("\n%dº Elemento: ", i + 1);
    scanf("%d", &NewNum);
    novo->num = NewNum;
    novo->next = NULL;
    if (FirstTime == 0) {
      fila[0] = *novo;
      FirstTime = 1;
      PreNum = NewNum;
      qty++;
    } else if (NewNum >= PreNum) {
      aux = &fila[0];
      while (aux->next != NULL) {
        aux = aux->next;
      }
      aux->next = novo;
      PreNum = NewNum;
      qty++;
    } else {
      encerrar = 1;
    }
  }

  printf("\nInsira a segunda fila em ordem crescente:\n");
  printf("(Para encerrar, quebre a ordem crescente)");
  for (int i = 0, encerrar = 0, FirstTime = 0; encerrar == 0; i++) {
    Node *aux, *novo = malloc(sizeof(Node));
    printf("\n%dº Elemento: ", i + 1);
    scanf("%d", &NewNum);
    novo->num = NewNum;
    novo->next = NULL;
    if (FirstTime == 0) {
      fila[1] = *novo;
      FirstTime = 1;
      PreNum = NewNum;
      qty++;
    } else if (NewNum >= PreNum) {
      aux = &fila[1];
      while (aux->next) {
        aux = aux->next;
      }
      aux->next = novo;
      PreNum = NewNum;
      qty++;
    } else {
      encerrar = 1;
    }
  }

  for (int i = 0, FirstTime = 0, ctrl0 = 0, ctrl1 = 0; i < qty; i++) {
    Node *aux, *novo = malloc(sizeof(Node));
    int NextNum;

    if (fila[0].num <= fila[1].num && ctrl0 < 2) {
      NextNum = fila[0].num;
      if (ctrl0 == 1)
        ctrl0 = 2;
      fila[0].num = MAX;
      if (fila[0].next && ctrl0 == 0) {
        fila[0] = *fila[0].next;
        if (!fila[0].next)
          ctrl0 = 1;
      }
    } else if (ctrl1 < 2) {
      NextNum = fila[1].num;
      if (ctrl1 == 1)
        ctrl1 = 2;
      fila[1].num = MAX;
      if (fila[1].next && ctrl1 == 0) {
        fila[1] = *fila[1].next;
        if (!fila[1].next)
          ctrl1 = 1;
      }
    }
    novo->num = NextNum;
    novo->next = NULL;

    if (FirstTime == 0) {
      fila[2] = *novo;
      FirstTime = 1;
    } else {
      aux = &fila[2];
      while (aux->next) {
        aux = aux->next;
      }
      aux->next = novo;
    }
  }
}

int main(void) {
  InserirFilas();

  printf("\nFila mista em ordem crescente: ");
  for (int i = 0; fila[2].next; i++) {
    printf("%d ", fila[2].num);
    fila[2] = *fila[2].next;
  }
  printf("%d", fila[2].num);

  return 0;
}
