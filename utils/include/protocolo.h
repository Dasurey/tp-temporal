#ifndef PROTOCOLO_H_
#define PROTOCOLO_H_
//Tratar de no repetir librerias, y de no eliminar librerias aca.
//Librerias comunes
#include <sys/socket.h>
//Librerias nuestras
#include "utils.h"

void* serializar_paquete(t_paquete* paquete, int bytes);
void crear_buffer(t_paquete* paquete);
t_paquete* crear_paquete(void);
void paquete(int conexion);
void agregar_a_paquete(t_paquete* paquete, void* valor, int tamanio);
void enviar_paquete(t_paquete* paquete, int socket_cliente);
void eliminar_paquete(t_paquete* paquete);
int recibir_operacion(int socket_cliente);
void recibir_mensaje(int socket_cliente, t_log* logger);
void* recibir_buffer(int* size, int socket_cliente);
t_list* recibir_paquete(int socket_cliente);
void enviar_mensaje(char* mensaje, int socket_cliente);

#endif /* PROTOCOLO_H_ */