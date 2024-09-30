#include "../include/main.h"

int main(int argc, char* argv[])
{
	char* archivo = CONFIG_FILE_KERNEL;
	iniciar_log_y_config(archivo);

	conectarse_kernel_puerto_cpu_interrupt();

	conectarse_kernel_puerto_cpu_dispatch();

	conectarse_kernel_puerto_memoria();

	enviar_mensajes_kernel();

	enviar_paquetes_kernel();

	terminar_programa_kernel();
	return 0;
}
