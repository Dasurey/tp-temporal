#include "../../include/utils/utilsCpu.h"

void iniciar_log_y_config(char* archivo)
{
	config_cpu = iniciar_config(archivo);

	ip_memoria = config_get_string_value(config_cpu, "IP_MEMORIA");
	puerto_memoria = config_get_string_value(config_cpu, "PUERTO_MEMORIA");
	
	puerto_escucha_cpu_dispatch = config_get_string_value(config_cpu, "PUERTO_ESCUCHA_DISPATCH");
	puerto_escucha_cpu_interrupt = config_get_string_value(config_cpu, "PUERTO_ESCUCHA_INTERRUPT");
	log_level_cpu = log_level_from_string(config_get_string_value(config_cpu, "LOG_LEVEL"));

	logger_cpu = iniciar_logger(LOG_FILE_CPU, "CPU", false, log_level_cpu);
	logger_sec_cpu = iniciar_logger(LOG_SEC_FILE_CPU, "CPU", true, log_level_cpu);
	log_info(logger_sec_cpu, "Logger_sec_cpu de cpu iniciado");
	log_info(logger_sec_cpu, "Logger_cpu de cpu iniciado");
	log_info(logger_sec_cpu, "Config_cpu de cpu leido");

	log_info(logger_sec_cpu, "PUERTO_ESCUCHA_DISPATCH: %s | PUERTO_ESCUCHA_INTERRUPT: %s | LOG_LEVEL: %s", puerto_escucha_cpu_dispatch, puerto_escucha_cpu_interrupt, config_get_string_value(config_cpu, "LOG_LEVEL"));
	log_info(logger_sec_cpu, "IP_MEMORIA: %s | PUERTO_MEMORIA: %s", ip_memoria, puerto_memoria);
}

void conectarse_cpu_puerto_memoria()
{
	conex_cpu_puerto_memoria = crear_conexion_como_cliente(ip_memoria, puerto_memoria, logger_sec_cpu, "CPU A MEMORIA");
	handshake_cliente(HANDSHAKE_CPU_A_MEMORIA, conex_cpu_puerto_memoria, logger_sec_cpu, "MEMORIA");
}

void iniciar_servidores_cpu()
{
	server_puerto_escucha_cpu_dispatch = iniciar_servidor(puerto_escucha_cpu_dispatch, logger_sec_cpu, "CPU DISPATCH");
	server_puerto_escucha_cpu_interrupt = iniciar_servidor(puerto_escucha_cpu_interrupt, logger_sec_cpu, "CPU INTERRUPT");
}

void esperar_clientes_cpu()
{
	kernel_cliente_puerto_escucha_cpu_interrupt_fd = esperar_cliente(server_puerto_escucha_cpu_interrupt, logger_sec_cpu);
	handshake_servidor(kernel_cliente_puerto_escucha_cpu_interrupt_fd, logger_sec_cpu, "CLIENTE KERNEL");
	
	kernel_cliente_puerto_escucha_cpu_dispatch_fd = esperar_cliente(server_puerto_escucha_cpu_dispatch, logger_sec_cpu);
	handshake_servidor(kernel_cliente_puerto_escucha_cpu_dispatch_fd, logger_sec_cpu, "CLIENTE KERNEL");
}

void administracion_hilos_cpu()
{
	pthread_t hilo_kernel_cliente_puerto_escucha_cpu_interrupt;
	pthread_create(&hilo_kernel_cliente_puerto_escucha_cpu_interrupt, NULL, (void*)administrar_servidor_para_kernel_cliente_puerto_escucha_cpu_interrupt, NULL);
	pthread_detach(hilo_kernel_cliente_puerto_escucha_cpu_interrupt);

	pthread_t hilo_kernel_cliente_puerto_escucha_cpu_dispatch;
	pthread_create(&hilo_kernel_cliente_puerto_escucha_cpu_dispatch, NULL, (void*)administrar_servidor_para_kernel_cliente_puerto_escucha_cpu_dispatch, NULL);

	pthread_join(hilo_kernel_cliente_puerto_escucha_cpu_dispatch, NULL);
}
void terminar_programa_cpu()
{
	//No liberar los punteros con free que sean de del config, el mismo terminar_programa con config_destroy(config) lo hace.
	terminar_programa(conex_cpu_puerto_memoria, logger_sec_cpu, config_cpu);
}

void iterator(char* value) {
	log_info(logger_sec_cpu,"%s", value);
}
