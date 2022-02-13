#include <stdio.h>
#include <stdlib.h>
#define RogueValue -9595
#define stackSize 10
typedef struct {
    int top;
    int ST[stackSize];
} StackType, *Stack;


int main() {
    Stack initStack();
    int empty(Stack);
    void push(Stack, int);
    int pop(Stack);
    int n;

    Stack S = initStack();
    printf("Press 0 if you want to quit or push some data like integers:\n");
    scanf("%d", &n);
    while (n != 0) {
        push(S, n);
        scanf("%d", &n);
    }
    printf("Numbers in reverse order\n");
    while (!empty(S))
        printf("%d ", pop(S));
    printf("\n");
} 


Stack initStack() {
    Stack sp = (Stack) malloc(sizeof(StackType));
    sp -> top = -1;
    return sp;
} //end initStack
int empty(Stack S) {
    return (S -> top == -1);
} //end empty

void push(Stack S, int n) {
    if (S -> top == stackSize - 1) {
        printf("\nStack Overflow\n");
        exit(1);
    }
    ++(S -> top);
    S -> ST[S -> top]= n;
} //end push
int pop(Stack S) {
    if (empty(S)) return RogueValue;
    int hold = S -> ST[S -> top];
    --(S -> top);
    return hold;
} //end pop
