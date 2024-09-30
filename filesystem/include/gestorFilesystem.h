#ifndef GESTOR_FILESYSTEM_H_
#define GESTOR_FILESYSTEM_H_
//Tratar de no repetir librerias.
//Si cambias algo aca, debes cambiarlo en el main tmb.
//Librerias comunes
#include <sys/mman.h>
#include <math.h>
#include <dirent.h>
#include <sys/stat.h>
//Librerias nuestras
#include "../../utils/include/utils.h"
#include "../../utils/include/inicioYcierre.h"
#include "../../utils/include/protocolo.h"
//Librerias commons
#include <commons/bitarray.h>

#define LOG_FILE_FILESYSTEM "filesystem.log"
#define LOG_SEC_FILE_FILESYSTEM "filesystem_sec.log"
#define CONFIG_FILE_FILESYSTEM "filesystem.config"

extern t_log* logger_filesystem;
extern t_log* logger_sec_filesystem;
extern t_config* config_filesystem;

extern char* puerto_escucha_filesystem;
extern char* mount_dir_filesystem;
extern t_log_level log_level_filesystem;

extern int32_t block_size_filesystem;
extern int32_t block_count_filesystem;
extern int32_t retardo_acceso_bloque_filesystem;

extern int server_puerto_escucha_filesystem;
extern int memoria_cliente_puerto_escucha_filesystem_fd;

#endif /* GESTOR_FILESYSTEM_H_*/