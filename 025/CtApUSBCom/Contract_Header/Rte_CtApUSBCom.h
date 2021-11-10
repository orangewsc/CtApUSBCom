/*** Module Rte_CtApUSBCom, written by TTX-                                ***/
/*** Mwcodegenerator/Contract_Header.py (Version 0.17.0, 18-Apr-2018) on   ***/
/*** Thu 01-Apr-2021 02:53:56                                              ***/
/*** IFSet version: 1.1.20                                                 ***/
/* PRQA S 0602 6                                                             */

/** \file Rte_CtApUSBCom.h */

/* double include prevention */
#ifndef RTE_CTAPUSBCOM_H
# define RTE_CTAPUSBCOM_H

#ifndef RTE_CORE
# ifdef RTE_APPLICATION_HEADER_FILE
#     error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
#endif /* ifndef RTE_CORE */

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Type.h"



/* PRQA S 0380, 0602, 0777, 0779, 0786, 0787, 0791, 0639, 3449, 4901 EOF     */
/*   0380: Number of macro definitions exceeds 4095-program does not conform */
/*     (Justification: Known limitation by design.)                          */
/*   0602: Allow TTTech-python-C-libs and CGL; usage of names starting with  */
/* _.                                                                        */
/*   0639: number of members in struct: supported by used compilers,         */
/* unacceptable increase in complexity if split.                             */
/*   0777/0779: Allow usage of names from model longer than 31 chars.        */
/*   3449: Allow multiple declarations of external object or function.       */
/*   0786/0787/0791: Allow usage of macro identifiers which match in the     */
/* first 63 chars.                                                           */

/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#ifndef RTE_CORE
  # define Rte_InitValue_PpPFProvidedData_DeLCSPH00State (0U)
  # define Rte_InitValue_PpPFProvidedData_DeLCSSH00State (0U)
  # define Rte_InitValue_PpPFProvidedData_DeLCSSH01State (0U)
  # define Rte_InitValue_PpPFProvidedData_DeLCSSystemState (0U)
  # define Rte_InitValue_PpPFProvidedData_DeVARHWVariant (0U)
  # define Rte_InitValue_PpPfInformation_DeBuildRevision (0U)
#endif /* ifndef RTE_CORE */




/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
/** \brief get one entry from a queued RTE buffer
 *
 * \param data receive buffer for element 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Receive_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared] {1247796}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared (P2VAR(Dt_BOOL, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpDiagCoding_DeCoding] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpDiagCoding_DeCoding (P2VAR(Dt_RECORD_Diag_Coding, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpDiagCoding_DeCoding] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpDiagCoding_DeCoding (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail (P2VAR(Dt_RECORD_AVCameraFail, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail (P2VAR(Dt_RECORD_SVCameraFail, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp (P2VAR(Dt_RECORD_AIPilotObjsDsp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo (P2VAR(Dt_RECORD_IECUNavigationInfo, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp (P2VAR(Dt_RECORD_ParkingSpacesDsp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical (P2VAR(Dt_RECORD_USBCom_Critical, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate] {1357185}
 **/
extern FUNC_P2CONST(Dt_RECORD_StbmTimestamp,AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision] {1357185}
 **/
extern FUNC(Dt_BuildRevision, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion] {1357185}
 **/
extern FUNC_P2CONST(Dt_Record_Version,AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType] {1357185}
 **/
extern FUNC_P2CONST(Dt_ARRAY5_ReleaseType,AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion] {1357185}
 **/
extern FUNC_P2CONST(Dt_IFSET_VERSION,AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion] {1357185}
 **/
extern FUNC_P2CONST(Dt_IFSET_VERSION,AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State] {1357185}
 **/
extern FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State] {1357185}
 **/
extern FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State] {1357185}
 **/
extern FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState] {1357185}
 **/
extern FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant] {1357185}
 **/
extern FUNC(Dt_ENUM_VAR_HWVariant, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant (void);
/** \brief get a pointer to the RTE buffer where the consumer runnable can read the data
 *
 * \param void 
 *
 * \return readable RTE buffer
 * \decomposed_from [Rte_IRead_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB] {1357185}
 **/
extern FUNC_P2CONST(Dt_RECORD_UserCLB,AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB (void);
/** \brief current status of the data element
 *
 * \param void 
 *
 * \return status of the RTE buffer page (RTE_E_OK, error code)
 * \decomposed_from [Rte_IStatus_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB] {1247091}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_IStatus_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts (P2VAR(Dt_RECORD_DrivingModeSts, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts (void);
/** \brief copy data from the RTE buffer to the buffer provided by the consumer
 *
 * \param data buffer provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Read_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom] {1330078}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom (P2VAR(Dt_RECORD_SysManager2USBCom, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data);
/** \brief update status of a data element
 *
 * \param void 
 *
 * \return TRUE if unread, FALSE if already seen
 * \decomposed_from [Rte_IsUpdated_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom] {1247458}
 **/
extern FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom (void);
/** \brief copy data of an element from the buffer provided by the producer runnable into the RTE buffer
 *
 * \param data element data provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Write_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical] {1246332}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical (P2CONST(Dt_RECORD_USBCom_Critical, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) data);
/** \brief copy data of an element from the buffer provided by the producer runnable into the RTE buffer
 *
 * \param data element data provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl] {1246332}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl (P2CONST(Dt_RECORD_FICM2IECUSpdCtrl, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) data);
/** \brief copy data of an element from the buffer provided by the producer runnable into the RTE buffer
 *
 * \param data element data provided 
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack] {1246332}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack (P2CONST(Dt_RECORD_ParkingSpaceDspFeedBack, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) data);
/** \brief call the runnable GetErrorStatus
 *
 * \param is_qualified
 * \param reporter_id
 * \param error_id
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEHEvent_GetErrorStatus( P2VAR(Dt_BOOL, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) is_qualified, Dt_ENUM_SWCID reporter_id, Dt_ENUM_EHErrorID error_id);
/** \brief call the runnable ReportError
 *
 * \param reporter_id
 * \param error_id
 * \param set
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEHEvent_ReportError( P2CONST(Dt_RECORD_EHReporterID, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) reporter_id, Dt_ENUM_EHErrorID error_id, Dt_BOOL set);
/** \brief call the runnable GetEventStatus
 *
 * \param EventId
 * \param EventStatusExtended
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEventHandling_GetEventStatus( Dem_EventIdType EventId, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) EventStatusExtended);
/** \brief call the runnable SetEventStatus
 *
 * \param EventId
 * \param EventStatus
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEventHandling_SetEventStatus( Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
/** \brief call the runnable SetSwcInfo
 *
 * \param swc_id
 * \param swc_info
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_SetSwcInfo( Dt_ENUM_SWCID swc_id, P2CONST(Dt_RECORD_SWC_Identification, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) swc_info);
/** \brief call the runnable TS_GetEgtTime
 *
 * \param timestamp
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTime (P2VAR(Dt_RECORD_StbmTimestamp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) timestamp);
/** \brief call the runnable TS_GetEgtTimestamp
 *
 * \param Timestamp
 * \param Clock
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp( P2VAR(Dt_RECORD_Timestamp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) Timestamp, P2VAR(Dt_ENUM_CLKSOURCE, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) Clock);
/** \brief call the runnable TS_GetRemainingTimeBudget
 *
 * \param RemainingTimeBudget
 *
 * \return status of the operation (RTE_E_OK, error code)
 * \decomposed_from [Rte_Call_<s>_<p>_<f>] {1247618}
 **/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_TS_GetRemainingTimeBudget (P2VAR(sint32, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) RemainingTimeBudget);





/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/

#ifndef RTE_CORE 

/**********************************************************************************************************************
 * Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
# define Rte_Receive_PpDiagGlobalRead_DeFSPCleared Rte_Receive_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared




/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_PpDiagCoding_DeCoding Rte_Read_CtApUSBCom_PpDiagCoding_DeCoding
# define Rte_Read_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail Rte_Read_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail
# define Rte_Read_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail Rte_Read_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail
# define Rte_Read_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp
# define Rte_Read_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo
# define Rte_Read_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp
# define Rte_Read_PpPdUSBComRead_DeUSBCom_Critical Rte_Read_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical
# define Rte_Read_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts
# define Rte_Read_PpSysManager2USBCom_100ms_DeSysManager2USBCom Rte_Read_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_IsUpdated_PpDiagCoding_DeCoding Rte_IsUpdated_CtApUSBCom_PpDiagCoding_DeCoding
# define Rte_IsUpdated_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail Rte_IsUpdated_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail
# define Rte_IsUpdated_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail Rte_IsUpdated_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail
# define Rte_IsUpdated_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp
# define Rte_IsUpdated_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo
# define Rte_IsUpdated_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp
# define Rte_IsUpdated_PpPdUSBComRead_DeUSBCom_Critical Rte_IsUpdated_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical
# define Rte_IsUpdated_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts Rte_IsUpdated_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Write_PpPdUSBComWrite_DeUSBCom_Critical Rte_Write_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical
# define Rte_Write_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl
# define Rte_Write_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/

# define Rte_Call_PpEHEvent_GetErrorStatus Rte_Call_CtApUSBCom_PpEHEvent_GetErrorStatus
# define Rte_Call_PpEHEvent_ReportError Rte_Call_CtApUSBCom_PpEHEvent_ReportError
# define Rte_Call_PpEventHandling_GetEventStatus Rte_Call_CtApUSBCom_PpEventHandling_GetEventStatus
# define Rte_Call_PpEventHandling_SetEventStatus Rte_Call_CtApUSBCom_PpEventHandling_SetEventStatus
# define Rte_Call_PpPFServer_SetSwcInfo Rte_Call_CtApUSBCom_PpPFServer_SetSwcInfo
# define Rte_Call_PpPFServer_TS_GetEgtTime Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTime
# define Rte_Call_PpPFServer_TS_GetEgtTimestamp Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp
# define Rte_Call_PpPFServer_TS_GetRemainingTimeBudget Rte_Call_CtApUSBCom_PpPFServer_TS_GetRemainingTimeBudget



#endif /* #ifndef RTE_CORE */ 

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApUSBCom_100ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtApUSBCom_100ms RCtApUSBCom_100ms
/** \brief Runnable entity: RCtApUSBCom_100ms,
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 * \param void
 * \return void
 **/
extern FUNC(void, RTE_CTAPUSBCOM_APPL_CODE) RCtApUSBCom_100ms(void); /* PRQA S 0850, 3449, 3451 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApUSBCom_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtApUSBCom_Init RCtApUSBCom_Init
/** \brief Runnable entity: RCtApUSBCom_Init,
 * Executed once after the RTE is started
 * \param void
 * \return void
 **/
extern FUNC(void, RTE_CTAPUSBCOM_APPL_CODE) RCtApUSBCom_Init(void); /* PRQA S 0850, 3449, 3451 */ /* MD_MSR_19.8 */

/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#ifndef RTE_CORE
  # define RTE_E_PiEHEvent_INTERNAL (63U)
  # define RTE_E_PiEHEvent_INVALID_ERROR_ID (3U)
  # define RTE_E_PiEHEvent_INVALID_REPORTER_ID (2U)
  # define RTE_E_PiEHEvent_NO_RIGHTS (5U)
  # define RTE_E_PiEHEvent_UNKNOWN_REPORTER (4U)
  # define RTE_E_PiPFServer_MW_E_TIMESTAMP (16U)
#endif /* ifndef RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

/* begin Fileversion check */
#ifndef RTE_CORE
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 0
#    error "The magic number is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 0
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
#endif /* ifndef RTE_CORE */
/* end Fileversion check */

#endif /* RTE_CTAPUSBCOM_H */
