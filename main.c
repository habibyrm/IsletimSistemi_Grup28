/*Grup:28
Habibe Bayram
Fatma Selma Akp�nar
Eren Sancar
�mer Elmas
�ule Y�lmaz
*/
// main.c
// Kabuk uygulamas�n�n giri� noktas�.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "command_parser.h"
#include "executor.h"

#define MAX_INPUT 1024

// Komut istemini ekrana yazd�r�r.
void display_prompt() {
    printf("> ");
    fflush(stdout); // ��kt� tamponunu temizler.
}

int main() {
    char input[MAX_INPUT];
    display_prompt();


    // Kullan�c� giri�ini s�rekli okur.
    while (fgets(input, MAX_INPUT, stdin)) {
        // Yeni sat�r karakterini temizler.
        input[strcspn(input, "\n")] = 0;

        // Kullan�c� "quit" yazarsa ��k�� yapar.
        if (strcmp(input, "quit") == 0) {
            printf("Kabuk kapat�l�yor...\n");
            break;
        }

        // Kullan�c� girdisini komut yap�s�na d�n��t�r�r.
        Command cmd = parse_command(input);
        if (cmd.is_pipe) {
            // Borulu (pipe) komutlar� i�ler.
            execute_pipe(cmd.piped_commands, cmd.num_piped_commands);
        }
        else {
            // Tek bir komutu �al��t�r�r.
            execute_command(cmd);
        }

        // Komut i�in ayr�lm�� belle�i serbest b�rak�r.
        free_command(cmd);
        display_prompt();
    }
    return 0;
}
