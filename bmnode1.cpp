/* This file is generated by BUSMASTER */
/* VERSION [1.2] */
/* BUSMASTER VERSION [2.6.4] */
/* PROTOCOL [CAN] */

/* Start BUSMASTER include header */
#include <Windows.h>
#include <CANIncludes.h>
#include <inttypes.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <stdio.h>
#include <math.h>
#include <exception>

/* End BUSMASTER include header */
/* Start BUSMASTER global variable */
uint8_t i = 0;
int k = 0;
float latd,lond,h,lat,lad,lod,lon,m_lat,m_lon,m_h;
time_t  t;
/* End BUSMASTER global variable */


/* Start BUSMASTER Function Prototype  */
GCC_EXTERN void GCC_EXPORT OnTimer_timer_1000ms_1000( );
//GCC_EXTERN void GCC_EXPORT OnMsg_All();

GCC_EXTERN void GCC_EXPORT OnMsg_All(STCAN_MSG RxMsg);
GCC_EXTERN void GCC_EXPORT OnMsgID_102(STCAN_MSG RxMsg);
GCC_EXTERN void GCC_EXPORT OnError_Active(SCAN_ERR ErrorMsg);
GCC_EXTERN void GCC_EXPORT OnError_Frame(SCAN_ERR ErrorMsg);
/* End BUSMASTER Function Prototype  */

/* Start BUSMASTER generated function - OnTimer_timer_100ms_100 */
void OnTimer_timer_1000ms_1000( )
{
}/* End BUSMASTER generated function - OnTimer_timer_100ms_100 */


// Error Active Handler which will print error counter values
//and channel number

void OnError_Active(SCAN_ERR ErrorMsg)
{
Trace( "Tx Error: %d Rx Error: %d Channel: %d",
ErrorMsg.m_ucTxError,
ErrorMsg.m_ucRxError,
ErrorMsg.m_ucChannel );
}

/* Start BUSMASTER generated function - OnMsg_All */
void OnMsg_All(STCAN_MSG RxMsg)
{
}/* End BUSMASTER generated function - OnMsg_All */

double compute(float latd,float lond, float h)
{
  float lat, lad, lod, lon, m_lat, m_lon, m_h;
  lad = floor(latd / 100.);
  lat = latd - lad * 100.;
  lod = floor(lond / 100.);
  lon = lond - lod * 100.;
  // Changing Longitude and Latitude to Radians
  m_lat = (lad + lat / 60.0) * M_PI / 180;
  m_lon = (lod + lon / 60.0) * M_PI / 180;
  m_h = h;
  Trace("m_lat = %f, m_lon= %f, m_h = %f", m_lat, m_lon,m_h);
  //Send result back to bm_server
  STCAN_MSG sMsgStruct;
  sMsgStruct.id = 0x101;
  sMsgStruct.dlc = 12;
  sMsgStruct.cluster = 1;
  memcpy(sMsgStruct.data, &m_lat, sizeof(float));
  Trace("2.1Sending m_lat");
  SendMsg(sMsgStruct);
  memcpy(sMsgStruct.data, &m_lon, sizeof(float));
  Trace("2.2Sending m_lon");
  SendMsg(sMsgStruct);
  memcpy(sMsgStruct.data, &m_h, sizeof(float));
  Trace("2.3Sending m_h");
  SendMsg(sMsgStruct);
}
/* Start BUSMASTER generated function - OnMsgID_100 */
void OnMsgID_102(STCAN_MSG RxMsg)
{
  k++;
  float rec_val = 0.0;
  memcpy(&rec_val, RxMsg.data, sizeof(float));
  Trace("2.Received message - %f", rec_val);
  if(k==1){
    latd = rec_val;
  }
  else if(k==2){
    lond = rec_val;  
  }
  else if(k==3){
    h = rec_val;
    k=0;
    Trace("2.computing with latd,lond,h = %f %f %f ",latd,lond,h);
    compute(latd,lond,h);
  }
 free(&rec_val);
}
/* End BUSMASTER generated function - OnMsgID_100 */

/* Start BUSMASTER generated function - OnError_Active */

/* Start BUSMASTER generated function - OnError_Frame */
void OnError_Frame(SCAN_ERR ErrorMsg)
{
/* TODO */
Trace("error frame");
}/* End BUSMASTER generated function - OnError_Frame */
