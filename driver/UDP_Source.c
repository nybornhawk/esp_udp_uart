#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"
#include "user_config.h"
#include "user_interface.h"
#include "driver/uart.h"
#include "driver/UDP_source.h"
#include "espconn.h"
#include "at_custom.h"
#include "mem.h"
//#include "c_math.h"

//#include "c_math.h"

int UDP_Transmit_flag=0;
struct espconn * connection;

void UDP_Init(){

	//system_set_os_print(0);
	struct espconn *UDP_P =(struct espconn *) os_zalloc(sizeof(struct espconn));
		UDP_P->proto.udp =(esp_udp *) os_zalloc(sizeof (esp_udp));
		UDP_P->state=ESPCONN_NONE;
		UDP_P->type=ESPCONN_UDP;

		UDP_P->proto.udp->local_port=(int)5555 ;   //The port on which we want the esp to serve
		UDP_P->proto.udp->remote_port=5555 ;   //The port on which we want the esp to serve

		//Set The call back functions
		espconn_regist_recvcb(UDP_P,UDP_recv_callback);
		//espconn_regist_sentcb(UDP_P,UDP_sent_callback);
		espconn_create(UDP_P);



}

void   UDP_recv_callback (void *arg,char *pdata,unsigned short len){

	struct espconn * u= (struct espconn *)arg;
    if(UDP_Transmit_flag==0)
	  connection=u;
    ets_uart_printf("Received data: \"%s\"\r\n", (uint8 *)pdata);
	//uart0_tx_buffer((uint8 *)pdata,len);
    //espconn_sent(connection,pdata,len);

	UDP_Transmit_flag=1;

}
