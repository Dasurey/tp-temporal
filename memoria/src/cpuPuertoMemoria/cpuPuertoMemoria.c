#include "../../include/cpuPuertoMemoria/cpuPuertoMemoria.h"

void administrar_servidor_para_cpu_cliente_puerto_escucha_memoria(){
    bool recibir = 1;
    t_list* lista;
	while (recibir) {
		int cod_op = recibir_operacion(cpu_cliente_puerto_escucha_memoria_fd);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(cpu_cliente_puerto_escucha_memoria_fd, logger_sec_memoria);
			break;
        case PAQUETE:
			lista = recibir_paquete(cpu_cliente_puerto_escucha_memoria_fd);
			log_info(logger_sec_memoria, "Me llegaron los siguientes valores:");
			list_iterate(lista, (void*)iterator);
			break;
		case -1:
			log_error(logger_sec_memoria, "Desconexion del servidor MEMORIA al cliente CPU");
			recibir = 0;
            break;
		default:
			log_warning(logger_sec_memoria,"Operacion desconocida del servidor MEMORIA al cliente CPU");
			break;
		}
	}
}
