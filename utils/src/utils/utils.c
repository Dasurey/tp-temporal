#include "../include/utils.h"

void saludar(char* quien) {
    printf("Hola desde %s!!\n", quien);
}

t_log* iniciar_logger(char* archivo, char* nombre, bool b, t_log_level logger_level)
{
	t_log* nuevo_logger = log_create(archivo, nombre, b, logger_level);

	if (nuevo_logger == NULL) {
    // ¡No se pudo crear el nuevo_logger!
	perror("¡No se pudo crear el nuevo_logger! Terminemos el programa"); // Terminemos el programa
	}
	return nuevo_logger;
}

void leer_consola(t_log* logger) // Puse esta función aca porque veo que la usaremos mucho
{
	char* leido;
	// Las vamos leyendo y logueando hasta recibir un string vacío
	// ¡No te olvides de liberar las lineas antes de regresar!
	while (1) {
        leido = readline("> ");
        if (!strcmp(leido, "")) {
            free(leido);
            break;
        }
        log_info(logger, ">> %s", leido);
        free(leido);
    };

}

t_config* iniciar_config(char* archivo)
{
	t_config* nuevo_config = config_create(archivo);

	if (nuevo_config == NULL) {
    // ¡No se pudo crear el nuevo_config!
	perror("¡No se pudo crear el nuevo_config! Terminemos el programa"); // Terminemos el programa
	}
	return nuevo_config;
}
