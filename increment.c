/*Grup:28
Habibe Bayram
Fatma Selma Akp�nar
Eren Sancar
�mer Elmas
�ule Y�lmaz
*/
// increment.c
// Standart giri�ten al�nan say�lar� bir art�r�r ve ��kt� olarak verir.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int value;
    while (scanf("%d", &value) != EOF) { // Giri�ten bir say� okuyana kadar devam eder.
        printf("%d\n", value + 1);       // Say�y� bir art�r�r ve ��kt� olarak verir.
    }
    return 0;
}
