#ifndef MAIN_KERNEL_H_
#define MAIN_KERNEL_H_

// Si cambias algo aca, debes cambiarlo en el gestor tmb.
// Poner todas las librerias de kernel aca.
#include "gestorKernel.h"
#include "utils/utilsKernel.h"

t_log* logger_kernel;
t_log* logger_sec_kernel;
t_config* config_kernel;

char* ip_memoria;
char* puerto_memoria;
char* ip_cpu;
char* puerto_cpu_dispatch;
char* puerto_cpu_interrupt;
char* algoritmo_planificacion_kernel;
t_log_level log_level_kernel;

int32_t quantum_kernel;

int conex_cpu_puerto_dispath;
int conex_cpu_puerto_interrupt;
int conex_kernel_memoria;

#endif /* MAIN_KERNEL_H_*/