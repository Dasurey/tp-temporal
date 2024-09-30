#ifndef GESTOR_CPU_H_
#define GESTOR_CPU_H_
// Tratar de no repetir librerias.
// Si cambias algo aca, debes cambiarlo en el main tmb.
// Librerias comunes
// Librerias nuestras
#include "../../utils/include/utils.h"
#include "../../utils/include/inicioYcierre.h"
#include "../../utils/include/protocolo.h"
// Librerias commons

#define LOG_FILE_CPU "cpu.log"
#define LOG_SEC_FILE_CPU "cpu_sec.log"
#define CONFIG_FILE_CPU "cpu.config"

extern t_log* logger_cpu;
extern t_log* logger_sec_cpu;
extern t_config* config_cpu;

extern char* ip_memoria;
extern char* puerto_memoria;
extern char* puerto_escucha_cpu_dispatch;
extern char* puerto_escucha_cpu_interrupt;
extern t_log_level log_level_cpu;

extern int conex_cpu_puerto_memoria;

extern int server_puerto_escucha_cpu_dispatch;
extern int server_puerto_escucha_cpu_interrupt;
extern int kernel_cliente_puerto_escucha_cpu_dispatch_fd;
extern int kernel_cliente_puerto_escucha_cpu_interrupt_fd;

#endif /* GESTOR_CPU_H_*/