#include "../../include/utils/utilsMemoria.h"

void iniciar_log_y_config(char* archivo)
{
	config_memoria = iniciar_config(archivo);

	ip_filesystem = config_get_string_value(config_memoria, "IP_FILESYSTEM");
	puerto_filesystem = config_get_string_value(config_memoria, "PUERTO_FILESYSTEM");
	
	puerto_escucha_memoria = config_get_string_value(config_memoria, "PUERTO_ESCUCHA");
	path_instrucciones_memoria = config_get_string_value(config_memoria, "PATH_INSTRUCCIONES");
	esquema_memoria = config_get_string_value(config_memoria, "ESQUEMA");
	algoritmo_busqueda_memoria = config_get_string_value(config_memoria, "ALGORITMO_BUSQUEDA");
	particiones_memoria = config_get_array_value(config_memoria, "PARTICIONES");
    log_level_memoria = log_level_from_string(config_get_string_value(config_memoria, "LOG_LEVEL"));
	
	tam_memoria = config_get_int_value(config_memoria, "TAM_MEMORIA");
	retardo_respuesta_memoria = config_get_int_value(config_memoria, "RETARDO_RESPUESTA");

	logger_memoria = iniciar_logger(LOG_FILE_MEMORIA, "MEMORIA", false, log_level_memoria);
    logger_sec_memoria = iniciar_logger(LOG_SEC_FILE_MEMORIA, "MEMORIA", true, log_level_memoria);
	log_info(logger_sec_memoria, "Logger_sec_memoria de memoria iniciado");
	log_info(logger_sec_memoria, "Logger_memoria de memoria iniciado");
	log_info(logger_sec_memoria, "Config_memoria de memoria leido");

	log_info(logger_sec_memoria, "PUERTO_ESCUCHA: %s | TAM_MEMORIA: %s | PATH_INSTRUCCIONES: %s | RETARDO_RESPUESTA: %s | ESQUEMA: %s | ALGORITMO_BUSQUEDA: %s | PARTICIONES: %s | LOG_LEVEL: %s", puerto_escucha_memoria, config_get_string_value(config_memoria, "TAM_MEMORIA"), path_instrucciones_memoria, config_get_string_value(config_memoria, "RETARDO_RESPUESTA"), esquema_memoria, algoritmo_busqueda_memoria, config_get_string_value(config_memoria, "PARTICIONES"), config_get_string_value(config_memoria, "LOG_LEVEL"));
	log_info(logger_sec_memoria, "IP_FILESYSTEM: %s | PUERTO_FILESYSTEM: %s", ip_filesystem, puerto_filesystem);
}

void conectarse_memoria_puerto_filesystem()
{
	conex_puerto_filesystem = crear_conexion_como_cliente(ip_filesystem, puerto_filesystem, logger_sec_memoria, "MEMORIA");
	handshake_cliente(HANDSHAKE_MEMORIA_A_FILESYSTEM, conex_puerto_filesystem, logger_sec_memoria, "FILESYSTEM");
}

void iniciar_servidor_memoria()
{
	server_puerto_escucha_memoria = iniciar_servidor(puerto_escucha_memoria, logger_sec_memoria, "MEMORIA");
}

void esperar_clientes_memoria()
{
	cpu_cliente_puerto_escucha_memoria_fd = esperar_cliente(server_puerto_escucha_memoria, logger_sec_memoria);
    handshake_servidor(cpu_cliente_puerto_escucha_memoria_fd, logger_sec_memoria, "CLIENTE CPU");

	kernel_cliente_puerto_escucha_memoria_fd = esperar_cliente(server_puerto_escucha_memoria, logger_sec_memoria);
    handshake_servidor(kernel_cliente_puerto_escucha_memoria_fd, logger_sec_memoria, "CLIENTE KERNEL");
}

void administracion_hilos_memoria()
{
	pthread_t hilo_cpu_cliente_puerto_escucha_memoria;
	pthread_create(&hilo_cpu_cliente_puerto_escucha_memoria, NULL, (void*)administrar_servidor_para_cpu_cliente_puerto_escucha_memoria, NULL);

	pthread_t hilo_kernel_cliente_puerto_escucha_memoria;
	pthread_create(&hilo_kernel_cliente_puerto_escucha_memoria, NULL, (void*)administrar_servidor_para_kernel_cliente_puerto_escucha_memoria, NULL);
	
	pthread_join(hilo_cpu_cliente_puerto_escucha_memoria, NULL);
}

void terminar_programa_memoria()
{
	//No liberar los punteros con free que sean de del config, el mismo terminar_programa con config_destroy(config) lo hace.
	terminar_programa(conex_puerto_filesystem, logger_sec_memoria, config_memoria);
}

void iterator(char* value) {
	log_info(logger_sec_memoria,"%s", value);
}