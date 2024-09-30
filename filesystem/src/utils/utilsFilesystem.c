#include "../../include/utils/utilsFilesystem.h"

void iniciar_log_y_config(char* archivo)
{
	config_filesystem = iniciar_config(archivo);
	
    puerto_escucha_filesystem = config_get_string_value(config_filesystem, "PUERTO_ESCUCHA");
	mount_dir_filesystem = config_get_string_value(config_filesystem, "MOUNT_DIR");
    log_level_filesystem = log_level_from_string(config_get_string_value(config_filesystem, "LOG_LEVEL"));
    
	block_size_filesystem = config_get_int_value(config_filesystem, "BLOCK_SIZE");
    block_count_filesystem = config_get_int_value(config_filesystem, "BLOCK_COUNT");
    retardo_acceso_bloque_filesystem = config_get_int_value(config_filesystem, "RETARDO_ACCESO_BLOQUE");

	logger_filesystem = iniciar_logger(LOG_FILE_FILESYSTEM, "FILESYSTEM", false, log_level_filesystem);
    logger_sec_filesystem = iniciar_logger(LOG_SEC_FILE_FILESYSTEM, "FILESYSTEM", true, log_level_filesystem);
	log_info(logger_sec_filesystem, "Logger_sec_filesystem de memoria iniciado");
	log_info(logger_sec_filesystem, "Logger_filesystem de memoria iniciado");
	log_info(logger_sec_filesystem, "Config_filesystem de memoria leido");

	log_info(logger_sec_filesystem, "PUERTO_ESCUCHA: %s | MOUNT_DIR: %s | BLOCK_SIZE: %s | BLOCK_COUNT: %s | RETARDO_ACCESO_BLOQUE: %s | LOG_LEVEL: %s", puerto_escucha_filesystem, mount_dir_filesystem, config_get_string_value(config_filesystem, "BLOCK_SIZE"), config_get_string_value(config_filesystem, "BLOCK_COUNT"), config_get_string_value(config_filesystem, "RETARDO_ACCESO_BLOQUE"), config_get_string_value(config_filesystem, "LOG_LEVEL"));
}

void iniciar_servidor_filesystem()
{
	server_puerto_escucha_filesystem = iniciar_servidor(puerto_escucha_filesystem, logger_sec_filesystem, "FILESYSTEM");
}

void esperar_cliente_filesystem()
{
	memoria_cliente_puerto_escucha_filesystem_fd = esperar_cliente(server_puerto_escucha_filesystem, logger_sec_filesystem);
    handshake_servidor(memoria_cliente_puerto_escucha_filesystem_fd, logger_sec_filesystem, "CLIENTE MEMORIA");
}

void terminar_programa_filesystem()
{
	//No liberar los punteros con free que sean de del config, el mismo terminar_programa con config_destroy(config) lo hace.
    log_info(logger_sec_filesystem, "Se cerraran los archivos y se termina el programa.");
    if (logger_sec_filesystem != NULL)
	{
		log_destroy(logger_sec_filesystem);
	}
	if (config_filesystem != NULL)
	{
		config_destroy(config_filesystem);
	}
}

void iterator(char* value) {
	log_info(logger_sec_filesystem,"%s", value);
}
