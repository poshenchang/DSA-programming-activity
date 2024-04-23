#include <stdbool.h>
#ifndef CSET_H
#define CSET_H
#define TABLE_MAX 1000003

typedef long long ll;

typedef struct CodeSet CodeSet;
struct CodeSet {
    int size;
    ll table[TABLE_MAX];
};

void cset_init(CodeSet *set);
void cset_destroy(CodeSet *set);
bool cset_insert(CodeSet *set, const char *value);   // return true if the insertion is successful, false otherwise
bool cset_remove(CodeSet *set, const char *value);   // return true if the removal is successful, false otherwise
bool cset_contains(const CodeSet *set, const char *value);

#endif