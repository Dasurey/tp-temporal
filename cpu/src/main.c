#include "../include/main.h"

int main(int argc, char* argv[])
{
	char* archivo = CONFIG_FILE_CPU;
	iniciar_log_y_config(archivo);

	conectarse_cpu_puerto_memoria();

	enviar_mensaje("Hola desde CPU", conex_cpu_puerto_memoria);
	//paquete(conex_cpu_puerto_memoria);

	iniciar_servidores_cpu();

	esperar_clientes_cpu();
	
	administracion_hilos_cpu();
	
	terminar_programa_cpu();
	return 0;
}
