/*Grup:28
Habibe Bayram
Fatma Selma Akpýnar
Eren Sancar
Ömer Elmas
Þule Yýlmaz
*/
// command_parser.h
// Komut ayrýþtýrma iþlevleri için baþlýk dosyasý.

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

typedef struct Command {
    char* name;              // Komut adý
    char** args;             // Komutun argümanlarý
    int is_background;       // Arkaplan iþlemi mi?
    int input_redirect;      // Giriþ yönlendirmesi var mý?
    char* input_file;        // Giriþ dosyasý
    int output_redirect;     // Çýkýþ yönlendirmesi var mý?
    char* output_file;       // Çýkýþ dosyasý
    int is_pipe;             // Borulu (pipe) bir komut mu?
    struct Command* piped_commands; // Borulu komutlar
    int num_piped_commands;  // Borulu komut sayýsý
} Command;

// Kullanýcý girdisini komut yapýsýna dönüþtürür.
Command parse_command(const char* input);

// Komut yapýsý için ayrýlmýþ belleði serbest býrakýr.
void free_command(Command cmd);

#endif
