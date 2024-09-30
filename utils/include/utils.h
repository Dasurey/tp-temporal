#ifndef UTILS_H_
#define UTILS_H_
//Tratar de no repetir librerias, y de no eliminar librerias aca.
//Librerias basicas
#include <stdio.h> // Funciones de entrada y salida
#include <stdlib.h> // Funciones de manejo de memoria
#include <string.h> // Funciones de manejo de cadenas
//Librerias commons
#include <commons/string.h>
#include <commons/collections/list.h>
#include <commons/log.h>
//Librerias comunes
#include <sys/socket.h>
#include <semaphore.h>
#include <pthread.h>
#include <readline/readline.h>
//Librerias nuestras
#include "inicioYcierre.h"

typedef enum
{
	MENSAJE,
	PAQUETE
}op_code;

typedef struct
{
	int size;
	void* stream;
} t_buffer;

typedef struct
{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;

/**
* @brief Imprime un saludo por consola
* @param quien Módulo desde donde se llama a la función
* @return No devuelve nada
*/
void saludar(char* quien);

t_log* iniciar_logger(char* archivo, char* nombre, bool b, t_log_level logger_level);
void leer_consola(t_log* logger);
t_config* iniciar_config(char* archivo);

#endif /* UTILS_H_*/
