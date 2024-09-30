#include "../include/main.h"

int main(int argc, char* argv[])
{
	char* archivo = CONFIG_FILE_MEMORIA;
	iniciar_log_y_config(archivo);

	conectarse_memoria_puerto_filesystem();

	iniciar_servidor_memoria();

	esperar_clientes_memoria();

	administracion_hilos_memoria();

	terminar_programa_memoria();
    return 0;
}
