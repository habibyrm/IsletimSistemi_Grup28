/*Grup:28
Habibe Bayram
Fatma Selma Akp�nar
Eren Sancar
�mer Elmas
�ule Y�lmaz
*/
// command_parser.h
// Komut ayr��t�rma i�levleri i�in ba�l�k dosyas�.

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

typedef struct Command {
    char* name;              // Komut ad�
    char** args;             // Komutun arg�manlar�
    int is_background;       // Arkaplan i�lemi mi?
    int input_redirect;      // Giri� y�nlendirmesi var m�?
    char* input_file;        // Giri� dosyas�
    int output_redirect;     // ��k�� y�nlendirmesi var m�?
    char* output_file;       // ��k�� dosyas�
    int is_pipe;             // Borulu (pipe) bir komut mu?
    struct Command* piped_commands; // Borulu komutlar
    int num_piped_commands;  // Borulu komut say�s�
} Command;

// Kullan�c� girdisini komut yap�s�na d�n��t�r�r.
Command parse_command(const char* input);

// Komut yap�s� i�in ayr�lm�� belle�i serbest b�rak�r.
void free_command(Command cmd);

#endif
