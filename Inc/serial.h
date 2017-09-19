/*
 * serial.h
 *
 *  Created on: May 20, 2017
 *      Author: sid
 */

#ifndef COM_SERIAL_H_
#define COM_SERIAL_H_

#ifdef __cplusplus
extern "C" {
#endif


#include <stdbool.h>
#include "stm32l4xx.h"
#include "stm32l4xx_hal_uart.h"

#include "circular_buffer.h"

typedef struct serial_t
{
	UART_HandleTypeDef *uart;
	circBuf_t *rx_crc_buf;
	int pushed_cmds;
	int pulled_cmds;
} serial_t;

serial_t *serial_init(UART_HandleTypeDef *uart);

bool serial_poll(serial_t *serial, char *line, int num);

void serial_print(serial_t *serial, char *str);

#ifdef __cplusplus
}
#endif

#endif /* COM_SERIAL_H_ */
