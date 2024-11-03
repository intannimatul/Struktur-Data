#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void createStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

int push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack penuh, tidak bisa menambahkan elemen.\n");
        return 0;
    }
    stack->top++;
    stack->data[stack->top] = value;
    return 1;
}

int pop(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak bisa menghapus elemen.\n");
        return 0;
    }
    *value = stack->data[stack->top];
    stack->top--;
    return 1;
}

int top(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak ada elemen teratas.\n");
        return 0;
    }
    *value = stack->data[stack->top];
    return 1;
}

int main() {
    Stack stack;
    int value;

    createStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    if (top(&stack, &value)) {
        printf("Elemen teratas: %d\n", value);
    }

    if (pop(&stack, &value)) {
        printf("Elemen yang di-pop: %d\n", value);
    }

    if (top(&stack, &value)) {
        printf("Elemen teratas setelah pop: %d\n", value);
    }

    return 0;
}
