#ifndef MAIN_FILESYSTEM_H_
#define MAIN_FILESYSTEM_H_

//Si cambias algo aca, debes cambiarlo en el gestor tmb.
//Poner todas las librerias de filesystem aca.
#include "gestorFilesystem.h"
#include "utils/utilsFilesystem.h"
#include "memoriaFilesystem/memoriaFilesystem.h"

t_log* logger_filesystem;
t_log* logger_sec_filesystem;
t_config* config_filesystem;

char* puerto_escucha_filesystem;
char* mount_dir_filesystem;
t_log_level log_level_filesystem;

int32_t block_size_filesystem;
int32_t block_count_filesystem;
int32_t retardo_acceso_bloque_filesystem;

int server_puerto_escucha_filesystem;
int memoria_cliente_puerto_escucha_filesystem_fd;

void iterator(char* value);

#endif /* MAIN_FILESYSTEM_H_*/