#include "../../include/memoriaFilesystem/memoriaFilesystem.h"

void administrar_servidor_para_memoria_cliente_puerto_escucha_filesystem(){
    bool recibir = 1;
    t_list* lista;
	while (recibir) {
		int cod_op = recibir_operacion(memoria_cliente_puerto_escucha_filesystem_fd);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(memoria_cliente_puerto_escucha_filesystem_fd, logger_sec_filesystem);
			break;
        case PAQUETE:
			lista = recibir_paquete(memoria_cliente_puerto_escucha_filesystem_fd);
			log_info(logger_sec_filesystem, "Me llegaron los siguientes valores:");
			list_iterate(lista, (void*)iterator);
			break;
		case -1:
			log_error(logger_sec_filesystem, "Desconexion del servidor FILESYSTEM al cliente MEMORIA");
			recibir = 0;
            break;
		default:
			log_warning(logger_sec_filesystem,"Operacion desconocida del servidor FILESYSTEM al cliente MEMORIA");
			break;
		}
	}
}
