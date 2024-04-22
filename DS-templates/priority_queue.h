#include <stdlib.h>
#include <limits.h>
typedef long long ll;

typedef struct pair{
    ll val; int id;
} pair;

typedef struct PriorityQueue{
    int size, cap;
    pair* p;
} PriorityQueue;

PriorityQueue* pq_initEmpty(){
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 1; pq->cap = 2;
    pq->p = (pair*)malloc(sizeof(pair)*2);
    pq->p[1].id = 0; pq->p[1].val = INT_MAX;
    return pq;
}

void pq_push(PriorityQueue* pq, ll val, int id){
    ++pq->size;
    if(pq->size >= pq->cap){
        (pq->cap)<<=1;
        pair* np = (pair*)malloc(sizeof(pair)*(pq->cap));
        for(int i=1; i<pq->size; ++i){
            np[i] = pq->p[i];
        }
        free(pq->p);
        pq->p = np;
    }

    pq->p[pq->size].val = val; pq->p[pq->size].id = id;
    int cur = pq->size;
    while(cur>1 && pq->p[cur].val > pq->p[cur>>1].val){
        pair buff = pq->p[cur]; pq->p[cur] = pq->p[cur>>1]; pq->p[cur>>1] = buff;
        cur>>=1;
    }
}

pair pq_top(PriorityQueue* pq){
    return pq->p[1];
}

pair pq_pop(PriorityQueue* pq){
    pair _p = pq->p[1];
    pq->p[1] = pq->p[pq->size];
    int cur = 1;
    while(cur < pq->size){
        if((cur<<1)<pq->size && pq->p[cur<<1].val>pq->p[cur].val && pq->p[cur<<1].val>pq->p[cur<<1|1].val){
            pair buff = pq->p[cur]; pq->p[cur] = pq->p[cur<<1]; pq->p[cur<<1] = buff;
            cur<<=1;
        }
        else if((cur<<1|1)<pq->size && pq->p[cur<<1|1].val>pq->p[cur].val && pq->p[cur<<1|1].val>pq->p[cur<<1].val){
            pair buff = pq->p[cur]; pq->p[cur] = pq->p[cur<<1|1]; pq->p[cur<<1|1] = buff;
            cur<<=1; cur|=1;
        }
        else break;
    }
    --pq->size;
    return _p;
}