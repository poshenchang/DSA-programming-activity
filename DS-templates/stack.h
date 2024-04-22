#include <stdlib.h>

typedef struct stack{
    int size, cap;
    int* val;
} stack;

stack* stack_init(){
    stack* stk = (stack*)malloc(sizeof(stack));
    stk->size = 0; stk->cap = 1;
    stk->val = (int*)malloc(sizeof(int));
}

void stack_push(stack* stk, int val){
    if(stk->size == stk->cap){
        stk->cap *= 2;
        int* nval = (int*)malloc(sizeof(int)*(stk->cap));
        for(int i=0; i<stk->size; i++){
            nval[i] = stk->val[i];
        }
        free(stk->val); stk->val = nval;
    }
    stk->val[stk->size] = val;
    stk->size++;
}

int stack_peep(stack* stk){
    return stk->val[stk->size-1];
}

int stack_pop(stack* stk){
    stk->size--;
    return stk->val[stk->size];
}