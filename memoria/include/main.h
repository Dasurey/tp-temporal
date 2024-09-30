#ifndef MAIN_MEMORIA_H_
#define MAIN_MEMORIA_H_

//Si cambias algo aca, debes cambiarlo en el gestor tmb.
//Poner todas las librerias de memoria aca.
#include "gestorMemoria.h"
#include "utils/utilsMemoria.h"
#include "cpuPuertoMemoria/cpuPuertoMemoria.h"
#include "kernelPuertoMemoria/kernelPuertoMemoria.h"

t_log* logger_memoria;
t_log* logger_sec_memoria;
t_config* config_memoria;

char* puerto_escucha_memoria;
char* ip_filesystem;
char* puerto_filesystem;
char* path_instrucciones_memoria;
char* esquema_memoria;
char* algoritmo_busqueda_memoria;
char** particiones_memoria; //Es lo que te devuelve el config_get_array_value y dsp hay que liberarlo con string_array_destroy(particiones_memoria).
t_log_level log_level_memoria;

int32_t tam_memoria;
int32_t retardo_respuesta_memoria;

int conex_puerto_filesystem;

int server_puerto_escucha_memoria;
int cpu_cliente_puerto_escucha_memoria_fd;
int kernel_cliente_puerto_escucha_memoria_fd;

#endif /* MAIN_MEMORIA_H_*/