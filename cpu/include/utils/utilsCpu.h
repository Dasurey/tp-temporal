#ifndef UTILS_CPU_H_
#define UTILS_CPU_H_

#include "../gestorCpu.h"
#include "../kernelCpuDispatch/kernelCpuDispatch.h"
#include "../kernelCpuInterrupt/kernelCpuInterrupt.h"

void iniciar_log_y_config(char* archivo);
void conectarse_cpu_puerto_memoria();
void iniciar_servidores_cpu();
void esperar_clientes_cpu();
void administracion_hilos_cpu();
void terminar_programa_cpu();
void iterator(char* value);

#endif /* UTILS_CPU_H_*/