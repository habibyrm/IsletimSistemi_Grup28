#include <stdio.h>
#include <stdlib.h>

int main() {
    int value;
    while (scanf("%d", &value) != EOF) {
        printf("%d\n", value + 1);
    }
    return 0;
}
