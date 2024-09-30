#ifndef UTILS_KERNEL_H_
#define UTILS_KERNEL_H_

#include "../gestorKernel.h"

void iniciar_log_y_config(char* archivo);
void conectarse_kernel_puerto_cpu_interrupt();
void conectarse_kernel_puerto_cpu_dispatch();
void conectarse_kernel_puerto_memoria();
void enviar_mensajes_kernel();
void enviar_paquetes_kernel();
void terminar_programa_kernel();

#endif /* UTILS_KERNEL_H_*/