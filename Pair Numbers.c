#include <stdio.h>

int main() {
    int i=0 ,current = 1, increment = 8, count = 7;

    for(i; i < count; i++) {
        printf("%d ", current);
        current += increment;
        increment += 8;
    }

    return 0;
}
