#ifndef MAIN_CPU_H_
#define MAIN_CPU_H_

// Si cambias algo aca, debes cambiarlo en el gestor tmb.
// Poner todas las librerias de cpu aca.
#include "gestorCpu.h"
#include "kernelCpuDispatch/kernelCpuDispatch.h"
#include "kernelCpuInterrupt/kernelCpuInterrupt.h"
#include "utils/utilsCpu.h"

t_log* logger_cpu;
t_log* logger_sec_cpu;
t_config* config_cpu;

char* ip_memoria;
char* puerto_memoria;
char* puerto_escucha_cpu_dispatch;
char* puerto_escucha_cpu_interrupt;
t_log_level log_level_cpu;

int conex_cpu_puerto_memoria;

int server_puerto_escucha_cpu_dispatch;
int server_puerto_escucha_cpu_interrupt;
int kernel_cliente_puerto_escucha_cpu_dispatch_fd;
int kernel_cliente_puerto_escucha_cpu_interrupt_fd;

#endif /* MAIN_CPU_H_*/