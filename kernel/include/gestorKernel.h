#ifndef GESTOR_KERNEL_H_
#define GESTOR_KERNEL_H_
// Tratar de no repetir librerias.
// Si cambias algo aca, debes cambiarlo en el main tmb.
// Librerias comunes
// Librerias nuestras
#include "../../utils/include/utils.h"
#include "../../utils/include/inicioYcierre.h"
#include "../../utils/include/protocolo.h"
// Librerias commons
#include <commons/temporal.h>
#include <commons/collections/queue.h>
#include <commons/collections/dictionary.h>

#define LOG_FILE_KERNEL "kernel.log"
#define LOG_SEC_FILE_KERNEL "kernel_sec.log"
#define CONFIG_FILE_KERNEL "kernel.config"

extern t_log* logger_kernel;
extern t_log* logger_sec_kernel;
extern t_config* config_kernel;

extern char* ip_memoria;
extern char* puerto_memoria;
extern char* ip_cpu;
extern char* puerto_cpu_dispatch;
extern char* puerto_cpu_interrupt;
extern char* algoritmo_planificacion_kernel;
extern t_log_level log_level_kernel;

extern int32_t quantum_kernel;

extern int conex_cpu_puerto_dispath;
extern int conex_cpu_puerto_interrupt;
extern int conex_kernel_memoria;

#endif /* GESTOR_KERNEL_H_*/