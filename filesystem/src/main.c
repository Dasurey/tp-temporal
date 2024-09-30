#include "../include/main.h"

int main(int argc, char* argv[])
{
    char* archivo = CONFIG_FILE_FILESYSTEM;
	iniciar_log_y_config(archivo);
	
	iniciar_servidor_filesystem();

	esperar_cliente_filesystem();
	
	administrar_servidor_para_memoria_cliente_puerto_escucha_filesystem();

	terminar_programa_filesystem();
	return 0;
}
