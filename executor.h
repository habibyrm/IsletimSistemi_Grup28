/*Grup:28
Habibe Bayram
Fatma Selma Akp�nar
Eren Sancar
�mer Elmas
�ule Y�lmaz
*/
// executor.h
// Komut �al��t�rma i�levleri i�in ba�l�k dosyas�.

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "command_parser.h"

// Tek bir komutu �al��t�r�r.
void execute_command(Command cmd);

// Borulu (pipe) komutlar� �al��t�r�r.
void execute_pipe(Command* commands, int num_commands);

#endif
