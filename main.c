/*Grup:28
Habibe Bayram
Fatma Selma Akpýnar
Eren Sancar
Ömer Elmas
Þule Yýlmaz
*/
// main.c
// Kabuk uygulamasýnýn giriþ noktasý.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "command_parser.h"
#include "executor.h"

#define MAX_INPUT 1024

// Komut istemini ekrana yazdýrýr.
void display_prompt() {
    printf("> ");
    fflush(stdout); // Çýktý tamponunu temizler.
}

int main() {
    char input[MAX_INPUT];
    display_prompt();


    // Kullanýcý giriþini devamlý olmak üzere okur.
    while (fgets(input, MAX_INPUT, stdin)) {
        // Yeni satýr karakterini temizler.
        input[strcspn(input, "\n")] = 0;

        // Kullanýcý "quit" yazarsa döngüden çýkýþ yapar.
        if (strcmp(input, "quit") == 0) {
            printf("Kabuk kapatýlýyor...\n");
            break;
        }

        // Kullanýcý girdisini komut yapýsýna dönüþtürür.
        Command cmd = parse_command(input);
        if (cmd.is_pipe) 
            execute_pipe(cmd.piped_commands, cmd.num_piped_commands); // Borulu (pipe) komutlarý iþler.
            
        else 
            execute_command(cmd); // Tek bir komutu çalýþtýrýr.
        

        
        free_command(cmd); // Komut için ayrýlmýþ belleði serbest býrakýr.
        display_prompt();
    }
    return 0;
}
