#include "cset.h"
#include <stdlib.h>
#include <string.h>

int hash_func(const char* value){
    int key = 0;
    int i = 0;
    int len = strlen(value);
    for(int i=0; i<len; i++){
        key = (key*37 + value[i]) % TABLE_SIZE;
    }
    return key;
}

void cset_init(CodeSet *set){
    set = malloc(sizeof(CodeSet));
    set->table = malloc(sizeof(CNode*)*TABLE_SIZE);
    
    for(int i=0; i<TABLE_SIZE; i++){
        set->table[i] = NULL;
    }
}

void cset_destroy(CodeSet *set){
    for(int i=0; i<TABLE_SIZE; i++){
        CNode *node = set->table[i];
        while(node != NULL){
            CNode* temp = node;
            node = node->next;
            free(temp->str);
            free(temp);
        }
    }
    free(set->table);
    free(set);
}

// return true if the insertion is successful, false otherwise
bool cset_insert(CodeSet *set, const char *value){
    if(cset_contains(set, value)) return false;

    int key = hash_func(value);
    CNode *newNode = (CNode*)malloc(sizeof(CNode));
    if(newNode == NULL) return false;

    CNode *node = set->table[key];
    newNode->next = set->table[key];
    return true;
}

// return true if the removal is successful, false otherwise
bool cset_remove(CodeSet *set, const char *value){
    int key = hash_func(value);
    CNode *node = set->table[key];
    CNode *prev = NULL;
    
    while(node != NULL){
        if(strcmp(node->str, value) == 0){
            if(prev != NULL){
                prev->next = node->next;
            }
            else{
                set->table[key] = node->next;
            }
            free(node->str);
            free(node);
            return true;
        }
        prev = node;
        node = node->next;
    }

    return false;
}

bool cset_contains(const CodeSet *set, const char *value){
    int key = hash_func(value);
    CNode *node = set->table[key];
    
    while(node != NULL){
        if(strcmp(node->str, value) == 0){
            return true;
        }
        node = node->next;
    }
    return false;
}