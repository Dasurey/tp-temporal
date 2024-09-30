#ifndef GESTOR_MEMORIA_H_
#define GESTOR_MEMORIA_H_
//Tratar de no repetir librerias.
//Si cambias algo aca, debes cambiarlo en el main tmb.
//Librerias comunes
//Librerias nuestras
#include "../../utils/include/utils.h"
#include "../../utils/include/inicioYcierre.h"
#include "../../utils/include/protocolo.h"
//Librerias commons

#define LOG_FILE_MEMORIA "memoria.log"
#define LOG_SEC_FILE_MEMORIA "memoria_sec.log"
#define CONFIG_FILE_MEMORIA "memoria.config"

extern t_log* logger_memoria;
extern t_log* logger_sec_memoria;
extern t_config* config_memoria;

extern char* puerto_escucha_memoria;
extern char* ip_filesystem;
extern char* puerto_filesystem;
extern char* path_instrucciones_memoria;
extern char* esquema_memoria;
extern char* algoritmo_busqueda_memoria;
extern char** particiones_memoria; //Es lo que te devuelve el config_get_array_value y dsp hay que liberarlo con string_array_destroy(particiones_memoria).
extern t_log_level log_level_memoria;

extern int32_t tam_memoria;
extern int32_t retardo_respuesta_memoria;

extern int conex_puerto_filesystem;

extern int server_puerto_escucha_memoria;
extern int cpu_cliente_puerto_escucha_memoria_fd;
extern int kernel_cliente_puerto_escucha_memoria_fd;

#endif /* GESTOR_MEMORIA_H_*/