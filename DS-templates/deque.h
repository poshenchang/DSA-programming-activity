#include <stdlib.h>
typedef long long ll;

typedef struct pair{
    int id; ll val;
} pair;

typedef struct dqNode{
    int id; ll val;
    struct dqNode *prev, *next;
} dqNode;

typedef struct deque{
    int size;
    dqNode *head, *tail;
} deque;

deque* dq_initEmpty(){
    deque* dq = (deque*)malloc(sizeof(deque));
    dq->size = 0;
    dq->head = NULL; dq->tail = NULL;
    return dq;
}

void dq_pushFront(deque* dq, int id, ll val){
    dqNode* node = (dqNode*)malloc(sizeof(dqNode));
    node->id = id; node->val = val; node->prev = NULL;
    if(dq->size == 0){
        node->next = NULL;
        dq->head = node; dq->tail = node;
    }
    else{
        node->next = dq->head; dq->head->prev = node;
        dq->head = node;
    }
    ++dq->size;
}

void dq_pushBack(deque* dq, int id, ll val){
    dqNode* node = (dqNode*)malloc(sizeof(dqNode));
    node->id = id; node->val = val; node->next = NULL;
    if(dq->size == 0){
        node->prev = NULL;
        dq->head = node; dq->tail = node;
    }
    else{
        node->prev = dq->tail; dq->tail->next = node;
        dq->tail = node;
    }
    ++dq->size;
}

pair dq_popFront(deque* dq){
    if(dq->size == 0) return {-1, 0};
    pair p = {dq->head->id, dq->head->val};
    dqNode* newHead = dq->head->next;
    free(dq->head); dq->head = newHead;
    if(dq->head != NULL){
        dq->head->prev = NULL;
    }
    else{
        dq->tail = NULL;
    }
    --dq->size;
    return p;
}

pair dq_popBack(deque* dq){
    if(dq->size == 0) return {-1, 0};
    pair p = {dq->head->id, dq->head->val};
    dqNode* newTail = dq->tail->prev;
    free(dq->tail); dq->tail = newTail;
    if(dq->tail != NULL){
        dq->tail->next = NULL;
    }
    else{
        dq->head = NULL;
    }
    --dq->size;
    return p;
}