#include "../../include/utils/utilsKernel.h"

void iniciar_log_y_config(char* archivo)
{
	config_kernel = iniciar_config(archivo);

	ip_memoria = config_get_string_value(config_kernel, "IP_MEMORIA");
	puerto_memoria = config_get_string_value(config_kernel, "PUERTO_MEMORIA");

	ip_cpu = config_get_string_value(config_kernel, "IP_CPU");
	puerto_cpu_dispatch = config_get_string_value(config_kernel, "PUERTO_CPU_DISPATCH");
	puerto_cpu_interrupt = config_get_string_value(config_kernel, "PUERTO_CPU_INTERRUPT");
	algoritmo_planificacion_kernel = config_get_string_value(config_kernel, "ALGORITMO_PLANIFICACION");
	log_level_kernel = log_level_from_string(config_get_string_value(config_kernel, "LOG_LEVEL"));
	
	quantum_kernel = config_get_int_value(config_kernel, "QUANTUM");
	
	logger_kernel = iniciar_logger(LOG_FILE_KERNEL, "KERNEL", false, log_level_kernel);
	logger_sec_kernel = iniciar_logger(LOG_SEC_FILE_KERNEL, "KERNEL", true, log_level_kernel);
	log_info(logger_sec_kernel, "Logger_sec_kernel de kernel iniciado");
	log_info(logger_sec_kernel, "Logger_kernel de kernel iniciado");
	log_info(logger_sec_kernel, "Config_kernel de kernel leido");

	log_info(logger_sec_kernel, "ALGORITMO_PLANIFICACION: %s | QUANTUM: %s | LOG_LEVEL: %s", algoritmo_planificacion_kernel, config_get_string_value(config_kernel, "QUANTUM"), config_get_string_value(config_kernel, "LOG_LEVEL"));
	log_info(logger_sec_kernel, "IP_MEMORIA: %s | PUERTO_MEMORIA: %s", ip_memoria, puerto_memoria);
	log_info(logger_sec_kernel, "IP_CPU: %s | PUERTO_CPU_DISPATCH: %s | PUERTO_CPU_INTERRUPT: %s", ip_cpu, puerto_cpu_dispatch, puerto_cpu_interrupt);
}

void conectarse_kernel_puerto_cpu_dispatch()
{
	conex_cpu_puerto_dispath = crear_conexion_como_cliente(ip_cpu, puerto_cpu_dispatch, logger_sec_kernel, "KERNEL A CPU DISPATCH");
	handshake_cliente(HANDSHAKE_KERNEL_A_CPU_DISPATCH, conex_cpu_puerto_dispath, logger_sec_kernel, "CPU");
}

void conectarse_kernel_puerto_cpu_interrupt()
{
	conex_cpu_puerto_interrupt = crear_conexion_como_cliente(ip_cpu, puerto_cpu_interrupt, logger_sec_kernel, "KERNEL A CPU INTERRUPT");
	handshake_cliente(HANDSHAKE_KERNEL_A_CPU_INTERRUPT, conex_cpu_puerto_interrupt, logger_sec_kernel, "CPU");
}

void conectarse_kernel_puerto_memoria()
{
	conex_kernel_memoria = crear_conexion_como_cliente(ip_memoria, puerto_memoria, logger_sec_kernel, "KERNEL A MEMORIA");
	handshake_cliente(HANDSHAKE_KERNEL_A_MEMORIA, conex_kernel_memoria, logger_sec_kernel, "MEMORIA");
}

void enviar_mensajes_kernel()
{
	enviar_mensaje("Hola desde Kernel", conex_cpu_puerto_interrupt);
	enviar_mensaje("Hola desde Kernel", conex_cpu_puerto_dispath);
	enviar_mensaje("Hola desde Kernel", conex_kernel_memoria);
}

void enviar_paquetes_kernel()
{
	/*Siempre primero el de memoria, interrupcion y despues dispatch. Hasta arreglar el tema de la planificacion y 
	todo lo otro para organizar el programa.*/
	paquete(conex_kernel_memoria);
	paquete(conex_cpu_puerto_interrupt);
	paquete(conex_cpu_puerto_dispath);
}

void terminar_programa_kernel()
{
	//No liberar los punteros con free que sean de del config, el mismo terminar_programa con config_destroy(config) lo hace.
	liberar_conexion(conex_cpu_puerto_dispath);
	liberar_conexion(conex_cpu_puerto_interrupt);
	terminar_programa(conex_kernel_memoria, logger_sec_kernel, config_kernel);
}
