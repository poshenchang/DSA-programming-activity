#include ".\cset.h"
#include <stdio.h>
#include <assert.h>

int main(){
    freopen(".\registration_codes.txt", "r", stdin);

    CodeSet* dataset;
    cset_init(dataset);
    char* str;
    while(scanf("%s", &str) == 1){
        cset_insert(dataset, str);
        assert(cset_contains(dataset, str));
    }

    return 0;
}