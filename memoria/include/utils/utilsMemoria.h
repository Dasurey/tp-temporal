#ifndef UTILS_MEMORIA_H_
#define UTILS_MEMORIA_H_

#include "../gestorMemoria.h"

#include "../cpuPuertoMemoria/cpuPuertoMemoria.h"
#include "../kernelPuertoMemoria/kernelPuertoMemoria.h"

void iniciar_log_y_config(char* archivo);
void conectarse_memoria_puerto_filesystem();
void iniciar_servidor_memoria();
void esperar_clientes_memoria();
void administracion_hilos_memoria();
void terminar_programa_memoria();
void iterator(char* value);

#endif /* UTILS_MEMORIA_H_*/