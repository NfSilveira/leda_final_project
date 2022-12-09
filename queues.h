#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int number;
  struct Node *next;
}Node;

typedef struct Queue {
  Node head; //Nó inicial da fila
  Node tail; //Nó final da fila
  //Quantidade máxima de itens que a fila pode comportar 
  int max_items;
  //Quantidade de elementos presentes na fila 
  int qty; 
}Queue;

int ReturnQty(Queue* q){
   return q->qty;
}

int IsFull(Queue* q){

  int FullCheck = 0;

  if (q->qty==q->max_items) {
    FullCheck = 1;
  }

  if (FullCheck==1) {
    printf("A fila está cheia!\n");
  } else {
    printf("A fila não está cheia!\n");
  }

  return FullCheck;
}

int IsEmpty(Queue* q){

  int EmptyCheck = 0;
    if (q -> qty==0) {
        EmptyCheck=1;
    }

    if (EmptyCheck==1) {
        printf("A fila está vazia!\n");
    } else {
        printf("A fila não está vazia!\n");
    }

  return EmptyCheck;
}

void BuscarElemento(Queue* q, int alvo){
 Node aux=q -> head;
  int check = 0;

  if (IsEmpty(q)) {
    printf("A fila está vazia!\n");
  } else {
      while (aux.next) {
        if (aux.number==alvo) {
          check = 1;
        }
        aux=*aux.next;
        }

        if (check == 1) {
            printf("O alvo foi encontrado!\n");
        }
        else {
            printf("O alvo %d não está presente na fila.\n", alvo);
        }
    }
}

void ExibirElementos(Queue* q){
  Node aux = q->head;
  
  for(int i;i<q->qty;i++){
    printf("%d ", aux.number);
  }
  printf("\n");
}

void InserirElemento(Queue *q, int item){
  
  if(IsFull(q))
    printf("Queue Overflow\n");
  else {
    Node aux, * novo=(Node*)calloc(1, sizeof(Node));
    novo -> number=item;
    novo -> next=NULL;
    if(q==NULL){
      q->head.number=novo->number;
      q->tail.number=novo->number;
      } else {
        aux=q->head;
        while(aux.next){
          aux=*aux.next;
        }
        aux.next=novo;
      }
    q->qty++;
    printf("O valor foi inserido na fila!\n");
  }
}


Node RetirarElemento(Queue* q){
  Node remove;

  if(q->qty!=0){
    remove=q->head;
    q->head=*remove.next;
  } else {
    printf("Fila vazia!\n");
  }
  q->qty--;
  return remove;
}
