/* This file is generated by BUSMASTER */
/* VERSION [1.2] */
/* BUSMASTER VERSION [2.6.4] */
/* PROTOCOL [CAN] */

/* Start BUSMASTER include header */
#include <Windows.h>
#include <CANIncludes.h>
#include <inttypes.h>
#include <ctime>
#include <iostream>
#include <sys/time.h>

/* End BUSMASTER include header */


/* Start BUSMASTER global variable */
uint8_t i = 0;
time_t t;
/* End BUSMASTER global variable */


/* Start BUSMASTER Function Prototype  */
GCC_EXTERN void GCC_EXPORT OnTimer_timer2_4_1( );
/* End BUSMASTER Function Prototype  */

/* Start BUSMASTER Function Wrapper Prototype  */
/* End BUSMASTER Function Wrapper Prototype  */

/* Start BUSMASTER Function Wrapper Prototype  */
/* End BUSMASTER Function Wrapper Prototype  */


/* Start BUSMASTER generated function - OnTimer_timer_100ms_100 */

/* Start BUSMASTER generated function - OnTimer_timer2_4_1 */
void OnTimer_timer2_4_1( )
{

  STCAN_MSG sMsgStruct;
  sMsgStruct.id = 0x108;
  sMsgStruct.dlc = 8;
  sMsgStruct.cluster = 1;
  sMsgStruct.data[0] = 4;
  //Trace("time=%s",dt);
  SendMsg(sMsgStruct);
  // SendMsg(sMsgStruct);
}/* End BUSMASTER generated function - OnTimer_timer2_4_1 */
