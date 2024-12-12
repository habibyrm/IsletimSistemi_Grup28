/*Grup:28
Habibe Bayram
Fatma Selma Akpýnar
Eren Sancar
Ömer Elmas
Þule Yýlmaz
*/
// executor.h
// Komut çalýþtýrma iþlevleri için baþlýk dosyasý.

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "command_parser.h"

// Tek bir komutu çalýþtýrýr.
void execute_command(Command cmd);

// Borulu (pipe) komutlarý çalýþtýrýr.
void execute_pipe(Command* commands, int num_commands);

#endif
