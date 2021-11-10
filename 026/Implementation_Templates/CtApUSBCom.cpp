/**********************************************************************************************************************
 *	 Copyright (C) 2019 TTTech-Auto AG. All rights reserved.
 *   Operngasse 7, 1040 Wien, Austria. office@tttech-auto.com
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtApUSBCom.c
 *        Config:  
 *     SW-C Type:  CtApUSBCom
 *  Generated at:  Fri May 21 05:12:15 2021
 *
 *     Generator:  Implementation Template generator ITG
 *
 *   Description:  C-Code implementation template for SW-C <CtApUSBCom>
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CtApUSBCom.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */

#include "Socket_Status.h"

	int 								g_ret_USBCom = 0;
	char 								g_recvjudge_USBCom[8];
	// uint32_t 							recv_num_NT = 0;
	// uint32_t 							recv_num_RI = 0;
	uint8_t 							g_USBCom_LCM_DEBUG = 0;
	_USBComMsg_LCM 						USBComMsgLCM;   //Only for LCM Debug, renenber delete it when SOP !!
	static uint8_t 						g_flag_drivingmode_USBCom = 0;
	static uint8_t						g_USBComWrongDataCnt = 0;
	Dt_ENUM_CLKSOURCE 					ClockSourceRte = 1;
	Dt_RECORD_Timestamp 				IECUTimestampRte={0,0};
	Dt_RECORD_DrivingModeSts 			g_DrivingModeSts_RTE_USBCom;
	Dt_RECORD_ParkingSpaceDspFeedBack 	g_ParkngSpaceDspFeedBack_RTE_USBCOm;
	
	Socket_Status 						g_SocketStatus_Strc = { 0, 0, 0, 0, 0, 0 };
	shared_ptr<USB_SOCKET_STATUS>		pUSB_SOCKET_STATUS(new USB_SOCKET_STATUS(g_SocketStatus_Strc));
	shared_ptr<USBParkingSpaceDsp>		pUSBParkingSpaceDsp(new USBParkingSpaceDsp(g_SocketStatus_Strc));
	shared_ptr<USBAIPilotObjDsp>		pUSBAIPilotObjDsp(new USBAIPilotObjDsp(g_SocketStatus_Strc));
	shared_ptr<USBIECUNavigationInfo>	pUSBIECUNavigationInfo(new USBIECUNavigationInfo(g_SocketStatus_Strc));
	shared_ptr<USBSpeedControl>			pUSBSpeedControl(new USBSpeedControl(g_SocketStatus_Strc));
	shared_ptr<lcm::LCM> 				pUSBComMsg_LCM(new lcm::LCM("udpm://239.255.76.67:7667?ttl=1"));

	// shared_ptr<USBNavigationInfo>		pUSBNavigationInfo(new USBNavigationInfo(g_SocketStatus_Strc));
	// shared_ptr<USBNavigationTrail>		pUSBNavigationTrail(new USBNavigationTrail(g_SocketStatus_Strc));
	// shared_ptr<USBReservedInfo>			pUSBReservedInfo(new USBReservedInfo(g_SocketStatus_Strc));
	// shared_ptr<USBHDMapUpdateRequest>	pUSBHDMapUpdateRequest(new USBHDMapUpdateRequest(g_SocketStatus_Strc));
	// shared_ptr<USBHDCameraBlocked>		pUSBHDCameraBlocked(new USBHDCameraBlocked(g_SocketStatus_Strc));
	// shared_ptr<USBConeWaterHorse>		pUSBConeWaterHorse(new USBConeWaterHorse(g_SocketStatus_Strc));
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define CtApUSBCom_START_SEC_CODE
#include "CtApUSBCom_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApUSBCom_100ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
*   Std_ReturnType Rte_Read_CtApUSBCom_PpDiagCoding_DeCoding(P2VAR(Dt_RECORD_Diag_Coding, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpDiagCoding_DeCoding(void)
*   Std_ReturnType Rte_Receive_CtApUSBCom_PpDiagGlobalRead_DeFSPCleared(P2VAR(Dt_BOOL, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail(P2VAR(Dt_RECORD_AVCameraFail, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpEthernetCom_AVCameraFail_100ms_DeAVCameraFail(void)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail(P2VAR(Dt_RECORD_SVCameraFail, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpImageProcess_SVCameraFail_60ms_DeSurroundCameraFail(void)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp(P2VAR(Dt_RECORD_AIPilotObjsDsp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeAIPilotObjsDsp(void)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo(P2VAR(Dt_RECORD_IECUNavigationInfo, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeIECUNavigationInfo(void)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp(P2VAR(Dt_RECORD_ParkingSpacesDsp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpInteractionProcess_USBCom_100ms_DeParkingSpacesDsp(void)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical(P2VAR(Dt_RECORD_USBCom_Critical, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpPdUSBComRead_DeUSBCom_Critical(void)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts(P2VAR(Dt_RECORD_DrivingModeSts, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
*   FUNC(boolean, RTE_CODE) Rte_IsUpdated_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts(void)
*   Std_ReturnType Rte_Read_CtApUSBCom_PpSysManager2USBCom_100ms_DeSysManager2USBCom(P2VAR(Dt_RECORD_SysManager2USBCom, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) data)
 *
 *   Implicit S/R API:
 *   -----------------
*   FUNC_P2CONST(Dt_RECORD_StbmTimestamp, AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildDate(void)
*   FUNC(Dt_BuildRevision, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeBuildRevision(void)
*   FUNC_P2CONST(Dt_Record_Version, AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DePlatformVersion(void)
*   FUNC_P2CONST(Dt_ARRAY5_ReleaseType, AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeReleaseType(void)
*   FUNC_P2CONST(Dt_IFSET_VERSION, AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfInformation_DeSystemVersion(void)
*   FUNC_P2CONST(Dt_IFSET_VERSION, AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeIFSETVersion(void)
*   FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSPH00State(void)
*   FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH00State(void)
*   FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSH01State(void)
*   FUNC(Dt_ENUM_LCS_State, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeLCSSystemState(void)
*   FUNC(Dt_ENUM_VAR_HWVariant, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPFProvidedData_DeVARHWVariant(void)
*   FUNC_P2CONST(Dt_RECORD_UserCLB, AUTOMATIC, RTE_CODE) Rte_IRead_RCtApUSBCom_100ms_PpPfTpUSBCom_CLB_100ms_DeUSBComCLB(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
*   Std_ReturnType Rte_Write_CtApUSBCom_PpPdUSBComWrite_DeUSBCom_Critical(P2CONST(Dt_RECORD_USBCom_Critical, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) data)
*   Std_ReturnType Rte_Write_CtApUSBCom_PpUSBCom_CtApSysManager_100ms_DeFICM2IECUSpdCtrl(P2CONST(Dt_RECORD_FICM2IECUSpdCtrl, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) data)
*   Std_ReturnType Rte_Write_CtApUSBCom_PpUSBCom_InteractionProcess_100ms_DeParkingSpaceDspFeedBack(P2CONST(Dt_RECORD_ParkingSpaceDspFeedBack, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEHEvent_GetErrorStatus(P2VAR(Dt_BOOL, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) is_qualified, Dt_ENUM_SWCID reporter_id, Dt_ENUM_EHErrorID error_id)
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEHEvent_ReportError(P2CONST(Dt_RECORD_EHReporterID, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) reporter_id, Dt_ENUM_EHErrorID error_id, Dt_BOOL set)
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEventHandling_GetEventStatus(Dem_EventIdType EventId, P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) EventStatusExtended)
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpEventHandling_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTime(P2VAR(Dt_RECORD_StbmTimestamp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) timestamp)
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_TS_GetEgtTimestamp(P2VAR(Dt_RECORD_Timestamp, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) Timestamp, P2VAR(Dt_ENUM_CLKSOURCE, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) Clock)
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_TS_GetRemainingTimeBudget(P2VAR(sint32, AUTOMATIC, RTE_CTAPUSBCOM_APPL_VAR) RemainingTimeBudget)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApUSBCom_100ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtApUSBCom_CODE) RCtApUSBCom_100ms(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApUSBCom_100ms
 *********************************************************************************************************************/

#ifdef 	DEBUG_FILE
	freopen("/opt/tttech/motionwise/app/etc/01_CtApUSBCom.txt", "a", stdout);
#endif
	
	/* ------------------------              上电初始化登录             ------------------------*/
	static uint8_t init_status = 0;   // represent the first connection status
	while (init_status == 0)
	{
		pUSB_SOCKET_STATUS->Start_Connect();
		pUSB_SOCKET_STATUS->Start_Login();
		init_status = 1;
	}
	
	
	// /* ------------------------              从缓冲区接收报文前先判断是否有数据是否超时异常            ------------------------*/
	// if (((recv(pUSB_SOCKET_STATUS->m_sockfd_mes, g_recvjudge_USBCom, 8, MSG_DONTWAIT|MSG_PEEK)) <= 0) && (pUSB_SOCKET_STATUS-> Start_Recvable() <= 0))   //linux下需要改为MSG_DONTWAIT|MSG_PEEK 非阻塞模式 缓冲区无数据并500ms内无数据到达则记一次超时
	// {
	// 	pUSB_SOCKET_STATUS->m_flag_wrongdata = 2;  //1：数据接收错误  2：等待超时
	// 	pUSB_SOCKET_STATUS->m_timeoutcnt++;
	// 	pUSB_SOCKET_STATUS->Start_Heartbeat();
	// }
 
	/* ------------------------                          从缓冲区接收报文                           ------------------------*/
	if((recv(pUSB_SOCKET_STATUS->m_sockfd_mes, g_recvjudge_USBCom, 8, MSG_DONTWAIT|MSG_PEEK)) > 0)
	{
		while ((recv(pUSB_SOCKET_STATUS->m_sockfd_mes, g_recvjudge_USBCom, 8, MSG_DONTWAIT|MSG_PEEK)) > 0)             //linux下需要改为MSG_DONTWAIT|MSG_PEEK 非阻塞模式
		{
			uint16_t RecvCw = pUSB_SOCKET_STATUS->Start_Recv_CwJudge();
	#ifdef 	DEBUG_FILE	
			printf("<<<<<<<<<<<<<<<<<<        ENUMMsgCw RecvCw: %d        >>>>>>>>>>>>>>>>>>>>\n", RecvCw);
	#endif
			switch (RecvCw)
			{
				default:
	#ifdef 	DEBUG_FILE
					printf("!!!!!!!!!!!!!!!!!!!      Wrong Msg CommandWord Recv!      !!!!!!!!!!!!!!!!!!!\n ");
	#endif
				break;

	// 			case NavigationInfoCw:
	// 				g_ret_USBCom = pUSBNavigationInfo->Start_RecvMsg(pUSBNavigationInfo->m_NavigationInfo_Socket_RP,
	// 																 pUSBNavigationInfo->pNavigationInfo_RPBuf,
	// 																 pUSB_SOCKET_STATUS->pmsg_recv_databuf);
	// 				if (g_ret_USBCom > 0)
	// 				{
	// #ifdef NAVIGATIONINFO_DEBUG
	// 					printf("m_NavigationInfo_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
	// 					pUSBNavigationTrail->Print_Sock_Recv();
	// #endif
	// 					pUSBNavigationInfo->Rte_Write();
	// 				}
	// 				break;
	// 			case NavigationTrailCw:
	// 				g_ret_USBCom = pUSBNavigationTrail->Start_RecvMsg(pUSBNavigationTrail->m_NavigationTrail_Socket_RP,
	// 																  pUSBNavigationTrail->pNavigationTrail_RPBuf,
	// 																  pUSB_SOCKET_STATUS->pmsg_recv_databuf);
	// 				if (g_ret_USBCom > 0)
	// 				{
	// #ifdef NAVIGATIONTRAIL_DEBUG
	// 					printf("m_NavigationTrail_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
	// 					pUSBNavigationTrail->Print_Sock_Recv();
	// #endif
	// 					recv_num_NT++;
	// 					pUSBNavigationTrail->Rte_Write();
	// 				}
	// 				break;
	// 			case ReservedInfoCw:
	// 				g_ret_USBCom = pUSBReservedInfo->Start_RecvMsg(pUSBReservedInfo->m_ReservedInfo_Socket_RP,
	// 															   pUSBReservedInfo->pReservedInfo_RPBuf,
	// 															   pUSB_SOCKET_STATUS->pmsg_recv_databuf);
	// 				if (g_ret_USBCom > 0)
	// 				{
	// #ifdef RESERVEDINFO_DEBUG
	// 					printf("m_ReservedInfo_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
	// 					pUSBReservedInfo->Rte_Write();
	// #endif
	// 					recv_num_RI++;
	// 					pUSBReservedInfo->Rte_Write();
	// 				}
	// 				break;

				case ParkingSpaceDspCw:
					g_ret_USBCom = pUSBParkingSpaceDsp->Start_RecvMsg(pUSBParkingSpaceDsp->m_ParkingSpaceDsp_Socket_RP,
																	pUSBParkingSpaceDsp->pParkingSpaceDsp_RPBuf,
																	pUSB_SOCKET_STATUS->pmsg_recv_databuf);

					if (g_ret_USBCom > 0)
					{
	#ifdef PARKINGSPACEDSP_DEBUG
						printf("m_ParkingSpaceDsp_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
						pUSBParkingSpaceDsp->Print_Sock_Recv();
	#endif
						pUSBParkingSpaceDsp->Rte_Write();
					}

					break;

				case AIPilotObjDspCw:
					g_ret_USBCom = pUSBAIPilotObjDsp->Start_RecvMsg(pUSBAIPilotObjDsp->m_AIPilotObjDsp_Socket_RP,
																	pUSBAIPilotObjDsp->pAIPilotObjDsp_RPBuf,
																	pUSB_SOCKET_STATUS->pmsg_recv_databuf);

					if (g_ret_USBCom > 0)
					{
	#ifdef AIPILOTOBJDSP_DEBUG
						printf("m_AIPilotObjDsp_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
						pUSBAIPilotObjDsp->Print_Sock_Recv();
	#endif
						//pUSBAIPilotObjDsp->Rte_Write();  //AIPilot模式下暂无通过RTE发送的信号
					}

					break;

				case IECUNavigationInfoCw:
					g_ret_USBCom = pUSBIECUNavigationInfo->Start_RecvMsg(pUSBIECUNavigationInfo->m_IECUNavigationInfo_Socket_RP,
																		pUSBIECUNavigationInfo->pIECUNavigationInfo_RPBuf,
																		pUSB_SOCKET_STATUS->pmsg_recv_databuf);

					if (g_ret_USBCom > 0)
					{
	#ifdef IECUNAVIGATIONINFO_DEBUG
						printf("m_IECUNavigationInfo_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
						pUSBIECUNavigationInfo->Print_Sock_Recv();
	#endif
						//pUSBIECUNavigationInfo->Rte_Write();  // 无通过RTE发送的信号
					}

					break;

	// 			case HDMapUpdateRequestCw:
	// 				g_ret_USBCom = pUSBHDMapUpdateRequest->Start_RecvMsg(pUSBHDMapUpdateRequest->m_HDMapUpdateRequest_Socket_RP,
	// 																	 pUSBHDMapUpdateRequest->pHDMapUpdateRequest_RPBuf,
	// 																	 pUSB_SOCKET_STATUS->pmsg_recv_databuf);
	// 				if (g_ret_USBCom > 0)
	// 				{
	// #ifdef HDMAPUPDATEREQUEST_DEBUG
	// 					printf("m_HDMapUpdateRequest_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
	// 					pUSBHDMapUpdateRequest->Print_Sock_Recv();
	// #endif
	// 					pUSBHDMapUpdateRequest->Rte_Write();
	// 				}
	// 				break;
	// 			case ASVCameraFailCw:
	// 				g_ret_USBCom = pUSBHDCameraBlocked->Start_RecvMsg(pUSBHDCameraBlocked->m_ASVCameraFail_Socket_RP,
	// 																  pUSBHDCameraBlocked->pASVCameraFail_RPBuf,
	// 																  pUSB_SOCKET_STATUS->pmsg_recv_databuf);
	// 				if (g_ret_USBCom > 0)
	// 				{
	// #ifdef ASVCAMERAFAIL_DEBUG
	// 					printf("m_ASVCameraFail_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
	// 					pUSBHDCameraBlocked->Print_Sock_Recv();
	// #endif
	// 					pUSBHDCameraBlocked->Rte_Write();
	// 				}
	// 				break;
	// 			case ConeWaterHorseCw:
	// 				g_ret_USBCom = pUSBConeWaterHorse->Start_RecvMsg(pUSBConeWaterHorse->m_ConeWaterHorse_Socket_RP,
	// 																 pUSBConeWaterHorse->pConeWaterHorse_RPBuf,
	// 																 pUSB_SOCKET_STATUS->pmsg_recv_databuf);
	// 				if (g_ret_USBCom > 0)
	// 				{
	// #ifdef CONEWATERHORSE_DEBUG
	// 					printf("m_ConeWaterHorse_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
	// 					pUSBConeWaterHorse->Print_Sock_Recv();
	// #endif
	// 					pUSBConeWaterHorse->Rte_Write();
	// 				}
	// 				break;

				case FICM2IECUSpeedControlCw:
					g_ret_USBCom = pUSBSpeedControl->Start_RecvMsg(pUSBSpeedControl->m_SpeedControl_Socket_RP,
																pUSBSpeedControl->pSpeedControl_RPBuf,
																pUSB_SOCKET_STATUS->pmsg_recv_databuf);

					if (g_ret_USBCom > 0)
					{
	#ifdef SPEEDCONTROL_DEBUG
						printf("m_SpeedControl_Socket_RP SocketBuf Recv length: %d\n", g_ret_USBCom);
						pUSBSpeedControl->Print_Sock_Recv();
	#endif
						pUSBSpeedControl->Rte_Write();
						pUSBSpeedControl->SpdCtrl_FlashFlag = 1;
					}

					break;
			}
		}
	}
	else
	{
		pUSB_SOCKET_STATUS->m_flag_wrongdata = 1;
	}




	/* ------------------------         判断当前车辆模式： 3为泊车        ------------------------*/
	Rte_Read_CtApUSBCom_PpSysManager_DrivingModeSts_50ms_DeDrivingModeSts(&g_DrivingModeSts_RTE_USBCom);
	g_flag_drivingmode_USBCom = g_DrivingModeSts_RTE_USBCom.nDrivingMode;

	/* ------------------------              SOCK发送报文             ------------------------*/
	switch (g_flag_drivingmode_USBCom)
	{
		default:
			// pUSBNavigationInfo->Start_SendMsg();         //地图相关的三个命令字信号现阶段不上
			// pUSBNavigationTrail->Start_SendMsg();        //地图相关的三个命令字信号现阶段不上
			// pUSBReservedInfo->Start_SendMsg();           //地图相关的三个命令字信号现阶段不上
			// pUSBHDMapUpdateRequest->Start_SendMsg();     //现阶段不上
			// pUSBHDCameraBlocked->Start_SendMsg();        //现阶段不上
			// pUSBConeWaterHorse->Start_SendMsg();         //现阶段不上

			
			pUSBParkingSpaceDsp->Ddefult_ParkID_RTE_Write();//特殊的泊车信号：不进入泊车模式时，要默认发255
			pUSBSpeedControl->SpdCtrl_Reset0();				//语音巡航信号3个周期后复位
			pUSBAIPilotObjDsp->Start_SendMsg();
			pUSBIECUNavigationInfo->Start_SendMsg();
			pUSBSpeedControl->Start_SendMsg();
			break;
		case 3:
			pUSBParkingSpaceDsp->Start_SendMsg();
			pUSBAIPilotObjDsp->Start_SendMsg();
			break;
	}

	/* ------------------------                         控制LCM的发送                     ------------------------*/
	if (g_USBCom_LCM_DEBUG == 1)
	{	
		if(pUSBComMsg_LCM->good())
		{
			pUSBComMsg_LCM->publish("USBComMsg",&USBComMsgLCM);
		}
	}


/* ------------------------         每周期检查一次不合法数据计数，累计达到次数时发送心跳         ------------------------*/
	switch (pUSB_SOCKET_STATUS->m_flag_wrongdata)
	{
		case 1:  //接收错误，可能连接正常数据错误，也可能等待超时，详见int USB_SOCKET_STATUS::Start_RecvMsg();
			g_USBComWrongDataCnt++;
			if(g_USBComWrongDataCnt%5==0)
			{
				g_USBComWrongDataCnt = 0;
				pUSB_SOCKET_STATUS->m_timeoutcnt++;
				pUSB_SOCKET_STATUS->Start_Heartbeat();
				break;
			}
		case 2:  //暂无针对2的状态;
			break;
			
		default: //数据正常时m_flag_wrongdata被置0，将m_timeoutcnt也置0，防止其累加发送心跳；
			pUSB_SOCKET_STATUS->m_timeoutcnt = 0;
			break;
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApUSBCom_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *    FUNC(Std_ReturnType, RTE_CODE) Rte_Call_CtApUSBCom_PpPFServer_SetSwcInfo(Dt_ENUM_SWCID swc_id, P2CONST(Dt_RECORD_SWC_Identification, AUTOMATIC, RTE_CTAPUSBCOM_APPL_DATA) swc_info)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApUSBCom_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtApUSBCom_CODE) RCtApUSBCom_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApUSBCom_Init
 *********************************************************************************************************************/

	try
	{
		//std::ifstream f_in_dev("conf/devops_deploy.json");
		//nlohmann::json j_dev;
		//f_in_dev >> j_dev;
		//f_in_dev.close();

		std::ifstream f_in_USBComJson("conf/CtApUSBCom/CtApUSBCom_Conf.json");
		nlohmann::json j_USBComLCM_Reader;
		f_in_USBComJson >> j_USBComLCM_Reader;
		g_USBCom_LCM_DEBUG = j_USBComLCM_Reader["USBComLCM_Debug"] == "on" ? true : false;
		f_in_USBComJson.close();
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << '\n';
		g_USBCom_LCM_DEBUG = 1;
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtApUSBCom_STOP_SEC_CODE
#include "CtApUSBCom_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


