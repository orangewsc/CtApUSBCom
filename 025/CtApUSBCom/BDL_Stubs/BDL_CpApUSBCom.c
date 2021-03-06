/*** ******************************************************************************/
/*** Copyright (C) 2014 TTTech Automotive GmbH. All rights reserved             ***/
/*** Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office\tttech-automotive.com ***/
/*** ******************************************************************************/
/*** Module BDL_CpApUSBCom/PIE data transfer stubs ***/
/*** IFSet version: 1.1.20 ***/
/*** Generated by : sc_bdl_stubs ***/

/** \file BDL_CpApUSBCom.c */


#include "bdlif.h"
/* \metric COMF Generated code. COMF No further commenting needed                                                               */
/* PRQA S 3408 EOF                                                                                                              */
/*   3408: Allow usage of non declared functions.                                                                               */
/*         (to be removed after creating internal header files)                                                                 */

/* 3214: Allow to add unused definitions. Justification, these deffinitions could be used by commented functions:               */
/*       BDL_FrameReceived and BDL_StartUpload                                                                                  */
#define PIE_BDL_DOWNLOAD_ACK (156) /* PRQA S 3214 */
#define PIE_BDL_UPLOAD_DATA (158) /* PRQA S 3214 */
 

 
/* #define BUFFER_SIZE                     10000                                                                                */
/* static uint8 Buffer[BUFFER_SIZE] = { 0 };                                                                                    */
/* static BdlState State;                                                                                                       */


/* \metric STNAM BDL_FrameReceived_CpApUSBCom             */
/* \metric STAV1 functions contains operands/operatorsper statement more than 9 */
/* \metric CALLING TTTech BDL APIs should be supported regardless of usage      */
/* \metric STMT : the number of instructions per function is above limits.      */
/*         Any attempt to split it into more subfunctions than now would only   */
/*         damage the code readability and increase the runtime.                */
/* \metric PATH paths are independent from each other (add subfunctions at cost */
/*         of runtime)                                                          */
void BDL_FrameReceived_CpApUSBCom
    ( const uint8 __attribute__((unused)) *Payload /* PRQA S 3206 */
    , uint32 FrameId /* PRQA S 3206 */
    )
{
    /* BDLIF_FrameReceived (PIE_BDL_DOWNLOAD_ACK, Payload, Buffer, BUFFER_SIZE);                                      */
}

/* \metric STNAM BDL_RequestUpload_CpApUSBCom             */
/* \metric STAV1 functions contains operands/operatorsper statement more than 9 */
/* \metric CALLING TTTech BDL APIs should be supported regardless of usage      */
/* \metric STMT : the number of instructions per function is above limits.      */
/*         Any attempt to split it into more subfunctions than now would only   */
/*         damage the code readability and increase the runtime.                */
/* \metric PATH paths are independent from each other (add subfunctions at cost */
/*         of runtime)                                                          */
void BDL_RequestUpload_CpApUSBCom
    ( const uint8 __attribute__((unused)) *Payload /* PRQA S 3206 */
    , uint32 FrameId  /* PRQA S 3206 */
    )
{
    /* BDLIF_StartUpload (PIE_BDL_UPLOAD_DATA, &State, Buffer, BUFFER_SIZE);                                                      */
}

/* \metric STNAM BDL_UploadFrameAck_CpApUSBCom            */
/* \metric STAV1 functions contains operands/operatorsper statement more than 9 */
/* \metric CALLING TTTech BDL APIs should be supported regardless of usage      */
/* \metric STMT : the number of instructions per function is above limits.      */
/*         Any attempt to split it into more subfunctions than now would only   */
/*         damage the code readability and increase the runtime.                */
/* \metric PATH paths are independent from each other (add subfunctions at cost */
/*         of runtime)                                                          */
void BDL_UploadFrameAck_CpApUSBCom
    ( const uint8 __attribute__((unused)) *Payload /* PRQA S 3206 */
    , uint32 FrameId  /* PRQA S 3206 */
    )
{
    /* BDLIF_ContinueUpload (&State, Payload);                                                                        */
}
