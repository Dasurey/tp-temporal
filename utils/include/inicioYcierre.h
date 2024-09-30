#ifndef INICIO_Y_CIERRE_H_
#define INICIO_Y_CIERRE_H_
// Tratar de no repetir librerias, y de no eliminar librerias aca.
//Librerias basicas
#include <stdio.h> // Funciones de entrada y salida
#include <stdlib.h> // Funciones de manejo de memoria
#include <string.h> // Funciones de manejo de cadenas
// Librerias comunes
#include <unistd.h> //Proporciona acceso a la API del sistema operativo POSIX
#include <sys/socket.h>
#include <netdb.h>
#include <assert.h>
// Librerias commons
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
// Librerias nuestras
#include "utils.h"

#define HANDSHAKE_KERNEL_A_CPU_DISPATCH 1
#define HANDSHAKE_KERNEL_A_CPU_INTERRUPT 2
#define HANDSHAKE_KERNEL_A_MEMORIA 3
#define HANDSHAKE_CPU_A_MEMORIA 4
#define HANDSHAKE_MEMORIA_A_FILESYSTEM 5

int iniciar_servidor(char* puerto, t_log* logger, const char* nombre_servidor);
int crear_conexion(char* ip, char* puerto, t_log* logger, const char* nombre_cliente);
int esperar_cliente(int socket_servidor, t_log* logger);
void liberar_conexion(int socket_cliente);
void terminar_programa(int conexion, t_log* logger, t_config* config);
int crear_conexion_como_cliente(char* ip, char* puerto, t_log* logger, char* nombre_cliente);
void handshake_cliente(uint32_t handshake, int conexion, t_log* logger, char* nombre_servidor);
int32_t handshake_servidor(int socket_cliente, t_log* logger, char* nombre_cliente);

#endif /* INICIO_Y_CIERRE_H_*/
