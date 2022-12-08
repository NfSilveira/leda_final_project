#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {

    int number;
    struct Node* next;
};


struct Stack {

    struct Node* stack_top;

    // Maximum amount of items that the stack can handle
    int max_items_amount;

    // Current amount of items in the stack
    int stack_items_amount;
};


int print_items_amount (Stack* s) {

    return s -> stack_items_amount;
}


bool is_full(Stack* s) {

    bool is_full_check = false;

    if (s -> stack_items_amount == s -> max_items_amount) {
        is_full_check = true;
    }

    if (is_full_check == true) {
        return true;
    }

    else {
        return false;
    }
}


bool is_empty(Stack *s) {

    bool is_empty_check = false;

    if (s -> stack_items_amount == NULL) {
        is_empty_check = true;
    }

    if (is_empty_check == true) {
        return true;
    }

    else {
        return false;
    }
}


void find_stack_element(Stack* s, int element) {
    Node* aux = s -> stack_top;
    int check = 0;

    if (is_empty(s)) {
        printf("The stack is empty!\n");
    }

    else {
        while (aux != NULL) {
            printf("%d\n", aux -> number);

            if (aux -> number == element) {
                check = 1;
            }

            aux = aux -> next;
        }

        if (check == 1) {
            printf("The element %d exists within the stack!\n", element);
        }
        else {
            printf("The element %d does not exist within the stack.\n", element);
        }
    }
}


void print_all_elements(Stack* s) {
    Node* aux = s -> stack_top;

    if (is_empty(s)) {
        printf("The stack is empty!\n");
    }

    else {
        while (aux != NULL) {
            printf("%d\n", aux -> number);
            aux = aux -> next;
        }
    }
}


void push(Stack* s, int data) {


    if (is_full(s)) {
        printf("The stack is full!\n");
    }

    else {
        if (s) {
            struct Node* new_element = (struct Node*) calloc(1, sizeof(struct Node));

            new_element -> number = data;
            new_element -> next = s -> stack_top;
            s -> stack_top = new_element;

            s -> stack_items_amount += 1;

        }

        printf("The value was inserted into the stack!\n");
    }
}


int pop(Stack* s) {

    if (is_empty(s)) {
        printf("The stack is empty!\n");
    }

    else {
        if(s) {
            struct Node* next_element = s -> stack_top;

            if (next_element) {
                int value = next_element -> number;
                s -> stack_top = s -> stack_top -> next;

                free(next_element);
                s -> stack_items_amount -= 1;

                return value;
            }
        }
    }
}

