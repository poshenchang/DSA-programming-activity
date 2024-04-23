#include "cset_ls.h"
#include <stdlib.h>
#include <string.h>

typedef long long ll;

void cset_init(CodeSet *set){
    set = (CodeSet*)malloc(sizeof(CodeSet));
    set->size = 0;
}

void cset_destroy(CodeSet *set){
    free(set);
}

// return true if the insertion is successful, false otherwise
bool cset_insert(CodeSet *set, const char *value){
    if(cset_contains(set, value)) return false;
    if(set->size >= TABLE_MAX) return false;

    ll num = atoi(value);
    set->table[set->size] = num;
    set->size++;
    return true;
}

// return true if the removal is successful, false otherwise
bool cset_remove(CodeSet *set, const char *value){
    ll num = atoi(value);
    
    for(int i=0; i<set->size; i++){
        if(set->table[i] == num){
            set->table[i] = set->table[set->size-1];
            set->size--;
            return true;
        }
    }

    return false;
}

bool cset_contains(const CodeSet *set, const char *value){
    ll num = atoi(value);
    for(int i=0; i<set->size; i++){
        if(set->table[i] == num){
            return true;
        }
    }
    return false;
}