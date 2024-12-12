/*Grup:28
Habibe Bayram
Fatma Selma Akpýnar
Eren Sancar
Ömer Elmas
Þule Yýlmaz
*/
// increment.c
// Standart giriþten alýnan sayýlarý bir artýrýr ve çýktý olarak verir.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int value;
    while (scanf("%d", &value) != EOF) { // Giriþten bir sayý okuyana kadar devam eder.
        printf("%d\n", value + 1);       // Sayýyý bir artýrýr ve çýktý olarak verir.
    }
    return 0;
}
