#include "../../include/kernelCpuInterrupt/kernelCpuInterrupt.h"

void administrar_servidor_para_kernel_cliente_puerto_escucha_cpu_interrupt(){
    bool recibir = 1;
    t_list* lista;
	while (recibir) {
		int cod_op = recibir_operacion(kernel_cliente_puerto_escucha_cpu_interrupt_fd);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(kernel_cliente_puerto_escucha_cpu_interrupt_fd, logger_sec_cpu);
			break;
        case PAQUETE:
			lista = recibir_paquete(kernel_cliente_puerto_escucha_cpu_interrupt_fd);
			log_info(logger_sec_cpu, "Me llegaron los siguientes valores:");
			list_iterate(lista, (void*)iterator);
			break;
		case -1:
			log_error(logger_sec_cpu, "Desconexion de del servidor CPU INTERRUPT al cliente KERNEL");
			recibir = 0;
            break;
		default:
			log_warning(logger_sec_cpu,"Operacion desconocida de del servidor CPU INTERRUPT al cliente KERNEL");
			break;
		}
	}
}
