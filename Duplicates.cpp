#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = 4;
    int a[4];
    int i;
    
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), compare);
    
    int c = 0;
    for(i = 0; i < n - 1; i++) {
        if(a[i] == a[i+1]) {
            c++;
        }
    }
    
    printf("%d\n", c);
    
    return 0;
}
