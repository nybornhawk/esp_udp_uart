/*
 * UDP_source.h
 *
 *  Created on: 22 ���. 2016 �.
 *      Author: ������
 */

#ifndef INCLUDE_DRIVER_UDP_SOURCE_H_
#define INCLUDE_DRIVER_UDP_SOURCE_H_

#include "espconn.h"

void UDP_Init();
void   UDP_recv_callback (void *arg,char *pdata,unsigned short len);


#endif /* INCLUDE_DRIVER_UDP_SOURCE_H_ */
