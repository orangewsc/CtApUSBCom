/*** Module Rte_Type, written by TTX-Mwcodegenerator/Contract_Header.py    ***/
/*** (Version 0.17.0, 18-Apr-2018) on Fri 21-May-2021 08:03:28             ***/
/*** IFSet version: 1.1.20                                                 ***/
/* PRQA S 0602 4                                                             */

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

/* IFSet version                                                             */
#define IFSET_VERSION_VARIANT (1) 
#define IFSET_VERSION_MAJOR (1) 
#define IFSET_VERSION_MINOR (20) 

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
#define RTE_E_NOT_UPDATED (0x40) 
#define Rte_TypeDef_Dem_EventIdType 
typedef uint16 Dem_EventIdType; 
# define Dem_EventIdType_LowerLimit (0U)
# define Dem_EventIdType_UpperLimit (65535U)
#define Rte_TypeDef_Dem_EventStatusExtendedType 
typedef uint8 Dem_EventStatusExtendedType; 
# define Dem_EventStatusExtendedType_LowerLimit (0U)
# define Dem_EventStatusExtendedType_UpperLimit (255U)
# ifndef DEM_UDS_STATUS_TF 
#  define DEM_UDS_STATUS_TF (1U)
# endif 
# ifndef DEM_UDS_STATUS_TFTOC 
#  define DEM_UDS_STATUS_TFTOC (2U)
# endif 
# ifndef DEM_UDS_STATUS_PDTC 
#  define DEM_UDS_STATUS_PDTC (4U)
# endif 
# ifndef DEM_UDS_STATUS_CDTC 
#  define DEM_UDS_STATUS_CDTC (8U)
# endif 
# ifndef DEM_UDS_STATUS_TNCSLC 
#  define DEM_UDS_STATUS_TNCSLC (16U)
# endif 
# ifndef DEM_UDS_STATUS_TFSLC 
#  define DEM_UDS_STATUS_TFSLC (32U)
# endif 
# ifndef DEM_UDS_STATUS_TNCTOC 
#  define DEM_UDS_STATUS_TNCTOC (64U)
# endif 
# ifndef DEM_UDS_STATUS_WIR 
#  define DEM_UDS_STATUS_WIR (128U)
# endif 
#define Rte_TypeDef_Dem_EventStatusType 
typedef uint8 Dem_EventStatusType; 
# define Dem_EventStatusType_LowerLimit (0U)
# define Dem_EventStatusType_UpperLimit (255U)
# ifndef DEM_EVENT_STATUS_PASSED 
#  define DEM_EVENT_STATUS_PASSED (0U)
# endif 
# ifndef DEM_EVENT_STATUS_FAILED 
#  define DEM_EVENT_STATUS_FAILED (1U)
# endif 
# ifndef DEM_EVENT_STATUS_PREPASSED 
#  define DEM_EVENT_STATUS_PREPASSED (2U)
# endif 
# ifndef DEM_EVENT_STATUS_PREFAILED 
#  define DEM_EVENT_STATUS_PREFAILED (3U)
# endif 
#define Rte_TypeDef_Dt_ARRAY5_ReleaseType 
typedef uint8 Dt_ARRAY5_ReleaseType[5]; 
#define Rte_TypeDef_Dt_BOOL 
typedef uint8 Dt_BOOL; 
# define Dt_BOOL_LowerLimit (0U)
# define Dt_BOOL_UpperLimit (1U)
#define Rte_TypeDef_Dt_BuildRevision 
typedef uint32 Dt_BuildRevision; 
# define Dt_BuildRevision_LowerLimit (0U)
# define Dt_BuildRevision_UpperLimit (4294967295U)
#define Rte_TypeDef_Dt_ENUM_CLKSOURCE 
typedef uint8 Dt_ENUM_CLKSOURCE; 
# define Dt_ENUM_CLKSOURCE_LowerLimit (0U)
# define Dt_ENUM_CLKSOURCE_UpperLimit (255U)
# ifndef LOCAL 
#  define LOCAL (0U)
# endif 
# ifndef EGT 
#  define EGT (1U)
# endif 
#define Rte_TypeDef_Dt_ENUM_EHErrorID 
typedef uint16 Dt_ENUM_EHErrorID; 
# define Dt_ENUM_EHErrorID_LowerLimit (0U)
# define Dt_ENUM_EHErrorID_UpperLimit (65535U)
# ifndef EHErrorID_UNDEFINED 
#  define EHErrorID_UNDEFINED (65535U)
# endif 
#define Rte_TypeDef_Dt_ENUM_LCS_State 
typedef uint8 Dt_ENUM_LCS_State; 
# define Dt_ENUM_LCS_State_LowerLimit (0U)
# define Dt_ENUM_LCS_State_UpperLimit (255U)
# ifndef LCS_STATE_INIT 
#  define LCS_STATE_INIT (0U)
# endif 
# ifndef LCS_STATE_EST 
#  define LCS_STATE_EST (1U)
# endif 
# ifndef LCS_STATE_STA 
#  define LCS_STATE_STA (2U)
# endif 
# ifndef LCS_STATE_SBY 
#  define LCS_STATE_SBY (3U)
# endif 
# ifndef LCS_STATE_RUN 
#  define LCS_STATE_RUN (4U)
# endif 
# ifndef LCS_STATE_SHU 
#  define LCS_STATE_SHU (5U)
# endif 
# ifndef LCS_STATE_WPO 
#  define LCS_STATE_WPO (6U)
# endif 
# ifndef LCS_STATE_NOTPRESENT 
#  define LCS_STATE_NOTPRESENT (7U)
# endif 
#define Rte_TypeDef_Dt_ENUM_SWCID 
typedef uint8 Dt_ENUM_SWCID; 
# define Dt_ENUM_SWCID_LowerLimit (0U)
# define Dt_ENUM_SWCID_UpperLimit (255U)
# ifndef SWCID_INIT 
#  define SWCID_INIT (0U)
# endif 
# ifndef SWCID_CtApDiagnosticManager 
#  define SWCID_CtApDiagnosticManager (1U)
# endif 
# ifndef SWCID_CtApE2ETranASILB 
#  define SWCID_CtApE2ETranASILB (2U)
# endif 
# ifndef SWCID_CtApE2ETranASILD 
#  define SWCID_CtApE2ETranASILD (3U)
# endif 
# ifndef SWCID_CtApSysManager 
#  define SWCID_CtApSysManager (5U)
# endif 
# ifndef SWCID_CtApUltrasonicHandler 
#  define SWCID_CtApUltrasonicHandler (6U)
# endif 
# ifndef SWCID_CtCdEyeQCom 
#  define SWCID_CtCdEyeQCom (7U)
# endif 
# ifndef SWCID_CtApDR 
#  define SWCID_CtApDR (9U)
# endif 
# ifndef SWCID_CtApFreeSpaceFusion 
#  define SWCID_CtApFreeSpaceFusion (10U)
# endif 
# ifndef SWCID_CtApHighFrequencyPositioning 
#  define SWCID_CtApHighFrequencyPositioning (11U)
# endif 
# ifndef SWCID_CtApImageProcess_FreeRunning 
#  define SWCID_CtApImageProcess_FreeRunning (12U)
# endif 
# ifndef SWCID_CtApInertialProcess 
#  define SWCID_CtApInertialProcess (13U)
# endif 
# ifndef SWCID_CtApIntegratedPositioning 
#  define SWCID_CtApIntegratedPositioning (14U)
# endif 
# ifndef SWCID_CtApInteractionProcess 
#  define SWCID_CtApInteractionProcess (15U)
# endif 
# ifndef SWCID_CtApLaneFusion 
#  define SWCID_CtApLaneFusion (16U)
# endif 
# ifndef SWCID_CtApLocBuffer 
#  define SWCID_CtApLocBuffer (17U)
# endif 
# ifndef SWCID_CtApMeProcess 
#  define SWCID_CtApMeProcess (20U)
# endif 
# ifndef SWCID_CtApMiddleMapmatching 
#  define SWCID_CtApMiddleMapmatching (21U)
# endif 
# ifndef SWCID_CtApMirrorDataManager_FreeRunning 
#  define SWCID_CtApMirrorDataManager_FreeRunning (22U)
# endif 
# ifndef SWCID_CtApMwrProcess 
#  define SWCID_CtApMwrProcess (24U)
# endif 
# ifndef SWCID_CtApObstacleFusion 
#  define SWCID_CtApObstacleFusion (25U)
# endif 
# ifndef SWCID_CtApParkingLot 
#  define SWCID_CtApParkingLot (26U)
# endif 
# ifndef SWCID_CtApPathPlanner 
#  define SWCID_CtApPathPlanner (27U)
# endif 
# ifndef SWCID_CtApPrediction 
#  define SWCID_CtApPrediction (29U)
# endif 
# ifndef SWCID_CtApSOMEIPGW 
#  define SWCID_CtApSOMEIPGW (30U)
# endif 
# ifndef SWCID_CtApStateMonitor 
#  define SWCID_CtApStateMonitor (31U)
# endif 
# ifndef SWCID_CtApTrafficElementFusion 
#  define SWCID_CtApTrafficElementFusion (32U)
# endif 
# ifndef SWCID_CtApTransformer 
#  define SWCID_CtApTransformer (33U)
# endif 
# ifndef SWCID_CtApUSBCom 
#  define SWCID_CtApUSBCom (35U)
# endif 
# ifndef SWCID_CtApApa_FreeRunning 
#  define SWCID_CtApApa_FreeRunning (36U)
# endif 
# ifndef SWCID_APPLICATION_UPPERLIMIT 
#  define SWCID_APPLICATION_UPPERLIMIT (150U)
# endif 
# ifndef SWCID_PF_LOWERLIMIT 
#  define SWCID_PF_LOWERLIMIT (200U)
# endif 
# ifndef SWCID_CtCdMiddlewareQM_SH00 
#  define SWCID_CtCdMiddlewareQM_SH00 (201U)
# endif 
# ifndef SWCID_CtApMiddlewareASIL_SH00 
#  define SWCID_CtApMiddlewareASIL_SH00 (202U)
# endif 
# ifndef SWCID_CtApComQM 
#  define SWCID_CtApComQM (203U)
# endif 
# ifndef SWCID_CtCdLCSM_SH00 
#  define SWCID_CtCdLCSM_SH00 (204U)
# endif 
# ifndef SWCID_CtCdTimeMonitor_SH00 
#  define SWCID_CtCdTimeMonitor_SH00 (205U)
# endif 
# ifndef SWCID_CtApComASILB 
#  define SWCID_CtApComASILB (206U)
# endif 
# ifndef SWCID_CtCdErrorHandlerMaster_SH00 
#  define SWCID_CtCdErrorHandlerMaster_SH00 (208U)
# endif 
# ifndef SWCID_CtApPer_SH00 
#  define SWCID_CtApPer_SH00 (209U)
# endif 
# ifndef SWCID_CtApComASILD 
#  define SWCID_CtApComASILD (210U)
# endif 
# ifndef SWCID_CtCdErrorHandlerProxy_PH00 
#  define SWCID_CtCdErrorHandlerProxy_PH00 (211U)
# endif 
# ifndef SWCID_CtCdTimeMonitor_PH00 
#  define SWCID_CtCdTimeMonitor_PH00 (213U)
# endif 
# ifndef SWCID_CtCdLCSS_PH00 
#  define SWCID_CtCdLCSS_PH00 (214U)
# endif 
# ifndef SWCID_CtApStbMASIL_PH00 
#  define SWCID_CtApStbMASIL_PH00 (215U)
# endif 
# ifndef SWCID_CtApStbMASIL_SH00 
#  define SWCID_CtApStbMASIL_SH00 (216U)
# endif 
# ifndef SWCID_CtCdDebug_PH00 
#  define SWCID_CtCdDebug_PH00 (219U)
# endif 
# ifndef SWCID_CtApDSC_PH00 
#  define SWCID_CtApDSC_PH00 (220U)
# endif 
# ifndef SWCID_CtApHostSupervisionSlave_PH00 
#  define SWCID_CtApHostSupervisionSlave_PH00 (221U)
# endif 
# ifndef SWCID_CtApPer_PH00 
#  define SWCID_CtApPer_PH00 (222U)
# endif 
# ifndef SWCID_CtCdMiddlewareQM_PH00 
#  define SWCID_CtCdMiddlewareQM_PH00 (223U)
# endif 
# ifndef SWCID_CtCdCalibration_PH00 
#  define SWCID_CtCdCalibration_PH00 (224U)
# endif 
# ifndef SWCID_CtCdDebug_SH00 
#  define SWCID_CtCdDebug_SH00 (227U)
# endif 
# ifndef SWCID_CtApDSC_SH00 
#  define SWCID_CtApDSC_SH00 (230U)
# endif 
# ifndef SWCID_CtCdCalibration_SH00 
#  define SWCID_CtCdCalibration_SH00 (231U)
# endif 
# ifndef SWCID_CtApBISTQM_SH00 
#  define SWCID_CtApBISTQM_SH00 (232U)
# endif 
# ifndef SWCID_CtApBISTASIL_SH00 
#  define SWCID_CtApBISTASIL_SH00 (233U)
# endif 
# ifndef SWCID_CtApBswProxy_SH00 
#  define SWCID_CtApBswProxy_SH00 (234U)
# endif 
# ifndef SWCID_CtApHostSupervisionMaster_SH00 
#  define SWCID_CtApHostSupervisionMaster_SH00 (235U)
# endif 
# ifndef SWCID_PF_BSW 
#  define SWCID_PF_BSW (236U)
# endif 
# ifndef SWCID_PF_BSW_SAFE 
#  define SWCID_PF_BSW_SAFE (237U)
# endif 
# ifndef SWCID_PF_COM 
#  define SWCID_PF_COM (238U)
# endif 
# ifndef SWCID_PF_COM_SAFE 
#  define SWCID_PF_COM_SAFE (239U)
# endif 
# ifndef SWCID_PF_DRIVER 
#  define SWCID_PF_DRIVER (240U)
# endif 
# ifndef SWCID_PF_DRIVER_SAFE 
#  define SWCID_PF_DRIVER_SAFE (241U)
# endif 
# ifndef SWCID_PF_OS 
#  define SWCID_PF_OS (242U)
# endif 
# ifndef SWCID_PF_OS_SAFE 
#  define SWCID_PF_OS_SAFE (243U)
# endif 
# ifndef SWCID_PF_SIL 
#  define SWCID_PF_SIL (244U)
# endif 
# ifndef SWCID_PF_SW 
#  define SWCID_PF_SW (245U)
# endif 
# ifndef SWCID_PF_SW_SAFE 
#  define SWCID_PF_SW_SAFE (246U)
# endif 
# ifndef SWCID_CtApMiddlewareASIL_PH00 
#  define SWCID_CtApMiddlewareASIL_PH00 (247U)
# endif 
# ifndef SWCID_CtApBISTASIL_PH00 
#  define SWCID_CtApBISTASIL_PH00 (248U)
# endif 
# ifndef SWCID_CtApBISTQM_PH00 
#  define SWCID_CtApBISTQM_PH00 (249U)
# endif 
#define Rte_TypeDef_Dt_ENUM_VAR_HWVariant 
typedef uint8 Dt_ENUM_VAR_HWVariant; 
# define Dt_ENUM_VAR_HWVariant_LowerLimit (0U)
# define Dt_ENUM_VAR_HWVariant_UpperLimit (255U)
# ifndef VARIANT_UNKNOWN 
#  define VARIANT_UNKNOWN (0U)
# endif 
# ifndef ADAS 
#  define ADAS (1U)
# endif 
#define Rte_TypeDef_UINT_GAP_8 
typedef uint8 UINT_GAP_8; 
# define UINT_GAP_8_LowerLimit (0U)
# define UINT_GAP_8_UpperLimit (255U)
#define Rte_TypeDef_Dt_IFSET_VERSION 
typedef struct _Dt_IFSET_VERSION
  {
    uint8 DeMajor;
    uint8 DeMinor;
    uint8 DePatch;
    UINT_GAP_8 PaddingGap8_1;
  } Dt_IFSET_VERSION; 
#define Rte_TypeDef_Dt_ARRAY_UINT64_1_0 
typedef uint32 Dt_ARRAY_UINT64_1_0[2]; 
#define Rte_TypeDef_Dt_RECORD_HEADER 
typedef struct _Dt_RECORD_HEADER
  {
    uint16 Counter;
    uint8 FrameID;
    UINT_GAP_8 PaddingGap8_1;
    Dt_ARRAY_UINT64_1_0 TimeStamp;
  } Dt_RECORD_HEADER; 
#define Rte_TypeDef_UINT_GAP_16 
typedef uint16 UINT_GAP_16; 
# define UINT_GAP_16_LowerLimit (0U)
# define UINT_GAP_16_UpperLimit (65535U)
#define Rte_TypeDef_Dt_RECORD_AIPilotObj 
typedef struct _Dt_RECORD_AIPilotObj
  {
    Dt_RECORD_HEADER stHeader;
    uint8 AIPilotObjId;
    UINT_GAP_8 PaddingGap8_1;
    uint16 AIPilotObjLongtRltvDist;
    uint16 AIPilotObjLatRltvDist;
    uint8 AIPilotObjStyle;
    boolean AIPilotObjCrashRisk;
    uint16 AIPilotObjAngle;
    uint16 AIPilotObjLongtRltvSpd;
    uint16 AIPilotObjSyncCtr;
    UINT_GAP_16 PaddingGap16_2;
  } Dt_RECORD_AIPilotObj; 
#define Rte_TypeDef_Dt_ARRAY_16_AIPilotObj 
typedef Dt_RECORD_AIPilotObj Dt_ARRAY_16_AIPilotObj[16]; 
#define Rte_TypeDef_Dt_RECORD_AIPilotObjsDsp 
typedef struct _Dt_RECORD_AIPilotObjsDsp
  {
    Dt_RECORD_HEADER stHeader;
    Dt_ARRAY_16_AIPilotObj gstAIPilotObjects;
  } Dt_RECORD_AIPilotObjsDsp; 
#define Rte_TypeDef_Dt_RECORD_AVCameraFail 
typedef struct _Dt_RECORD_AVCameraFail
  {
    Dt_RECORD_HEADER stHeader;
    uint8 Front_AV_Camera_Status;
    uint8 Rear_AV_Camera_Status;
    uint8 Left_AV_Camera_Status;
    uint8 Right_AV_Camera_Status;
  } Dt_RECORD_AVCameraFail; 
#define Rte_TypeDef_Dt_UINT8_1_0 
typedef uint8 Dt_UINT8_1_0; 
# define Dt_UINT8_1_0_LowerLimit (0U)
# define Dt_UINT8_1_0_UpperLimit (255U)
#define Rte_TypeDef_Dt_RECORD_Diag_Coding 
typedef struct _Dt_RECORD_Diag_Coding
  {
    Dt_UINT8_1_0 FW_Dummy;
        /* Lnder Variante                                            */
    UINT_GAP_8 PaddingGap8_1;
    UINT_GAP_16 PaddingGap16_2;
  } Dt_RECORD_Diag_Coding; 
#define Rte_TypeDef_Dt_ARRAY_10_uint8 
typedef uint8 Dt_ARRAY_10_uint8[10]; 
#define Rte_TypeDef_Dt_RECORD_DrivingModeSts 
typedef struct _Dt_RECORD_DrivingModeSts
  {
    Dt_RECORD_HEADER stHeader;
    uint8 nWarningLevel;
    uint8 nDrivingStatus;
    uint8 nDrivingMode;
    Dt_ARRAY_10_uint8 ngBKP;
    UINT_GAP_8 PaddingGap8_1;
    UINT_GAP_16 PaddingGap16_2;
  } Dt_RECORD_DrivingModeSts; 
#define Rte_TypeDef_Dt_RECORD_EHReporterID 
typedef struct _Dt_RECORD_EHReporterID
  {
    Dt_ENUM_SWCID swcid;
    UINT_GAP_8 PaddingGap8_1;
    uint16 token;
  } Dt_RECORD_EHReporterID; 
#define Rte_TypeDef_Dt_RECORD_FICM2IECUSpdCtrl 
typedef struct _Dt_RECORD_FICM2IECUSpdCtrl
  {
    uint8 CSCVcCmdDspCmd;
    uint8 CSCDecIncVoCmd;
    uint8 CDisCtrVoCmd;
    uint8 CSCVoCmd;
    uint8 CDisCVoCmd;
    Dt_ARRAY_10_uint8 USBComReserved;
    UINT_GAP_8 PaddingGap8_1;
  } Dt_RECORD_FICM2IECUSpdCtrl; 
#define Rte_TypeDef_Dt_RECORD_TrafficLight 
typedef struct _Dt_RECORD_TrafficLight
  {
    Dt_RECORD_HEADER stHeader;
    uint8 TrafficLightShap;
    uint8 TrafficLightColr;
    uint8 TrafficLightTim;
    UINT_GAP_8 PaddingGap8_1;
  } Dt_RECORD_TrafficLight; 
#define Rte_TypeDef_Dt_ARRAY_4_TrafficLight 
typedef Dt_RECORD_TrafficLight Dt_ARRAY_4_TrafficLight[4]; 
#define Rte_TypeDef_Dt_RECORD_IECUNavigationInfo 
typedef struct _Dt_RECORD_IECUNavigationInfo
  {
    Dt_RECORD_HEADER stHeader;
    uint8 NavigationTrafficLightInfo;
    UINT_GAP_8 PaddingGap8_1;
    UINT_GAP_16 PaddingGap16_2;
    Dt_ARRAY_4_TrafficLight gstTrafficLights;
    uint8 RoadSpeedLimitSign;
    uint8 SpeedingWrnng;
    uint8 TrafficbanSign;
    uint8 TrafficWrnngSign;
  } Dt_RECORD_IECUNavigationInfo; 
#define Rte_TypeDef_Dt_RECORD_ParkingSpaceDspFeedBack 
typedef struct _Dt_RECORD_ParkingSpaceDspFeedBack
  {
    Dt_RECORD_HEADER stHeader;
    uint8 FeedBack;
    UINT_GAP_8 PaddingGap8_1;
    UINT_GAP_16 PaddingGap16_2;
  } Dt_RECORD_ParkingSpaceDspFeedBack; 
#define Rte_TypeDef_Dt_RECORD_ParkingSpace 
typedef struct _Dt_RECORD_ParkingSpace
  {
    Dt_RECORD_HEADER stHeader;
    uint8 ParkngSpaceID;
    UINT_GAP_8 PaddingGap8_1;
    uint16 ParkngSpaceLongtRltvDist;
    uint16 ParkngSpaceLatRltvDist;
    uint8 ParkngSpaceAngle;
    uint8 ParkngSpaceSts;
    uint16 ParkngSpaceSyncCtr;
    UINT_GAP_16 PaddingGap16_2;
  } Dt_RECORD_ParkingSpace; 
#define Rte_TypeDef_Dt_ARRAY_16_ParkingSpace 
typedef Dt_RECORD_ParkingSpace Dt_ARRAY_16_ParkingSpace[16]; 
#define Rte_TypeDef_Dt_RECORD_ParkingSpacesDsp 
typedef struct _Dt_RECORD_ParkingSpacesDsp
  {
    Dt_RECORD_HEADER stHeader;
    Dt_ARRAY_16_ParkingSpace gstParkingSpaces;
    uint8 TgtParkngSpaceID;
    UINT_GAP_8 PaddingGap8_1;
    UINT_GAP_16 PaddingGap16_2;
  } Dt_RECORD_ParkingSpacesDsp; 
#define Rte_TypeDef_Dt_ARRAY_8_uint8 
typedef uint8 Dt_ARRAY_8_uint8[8]; 
#define Rte_TypeDef_Dt_RECORD_SVCameraFail 
typedef struct _Dt_RECORD_SVCameraFail
  {
    Dt_RECORD_HEADER stHeader;
    uint8 Front_SV_Camera_Status;
    uint8 Rear_SV_Camera_Status;
    uint8 Left_SV_Camera_Status;
    uint8 Right_SV_Camera_Status;
    Dt_ARRAY_8_uint8 nReserved;
  } Dt_RECORD_SVCameraFail; 
#define Rte_TypeDef_Dt_RECORD_SWVersion_ZStage 
typedef struct _Dt_RECORD_SWVersion_ZStage
  {
    uint8 DeVersion0;
    uint8 DeVersion1;
    uint8 DeVersion2;
    uint8 DeVersion3;
  } Dt_RECORD_SWVersion_ZStage; 
#define Rte_TypeDef_Dt_RECORD_SW_Version 
typedef struct _Dt_RECORD_SW_Version
  {
    uint8 DeMajor;
    uint8 DeMinor;
    UINT_GAP_16 PaddingGap16_1;
  } Dt_RECORD_SW_Version; 
#define Rte_TypeDef_Dt_RECORD_BuildDate 
typedef struct _Dt_RECORD_BuildDate
  {
    uint16 DeYear;
    uint8 DeMonth;
    uint8 DeDay;
    uint8 DeHour;
    uint8 DeMinute;
    uint8 DeSecond;
    UINT_GAP_8 PaddingGap8_1;
  } Dt_RECORD_BuildDate; 
#define Rte_TypeDef_Dt_RECORD_SWC_Identification 
typedef struct _Dt_RECORD_SWC_Identification
  {
    Dt_RECORD_SWVersion_ZStage DeZStage;
        /* Version of the SW-C                                       */
    Dt_IFSET_VERSION DeSwcIFSET;
        /* IF-SET against the SW-C has been compiled.                */
    Dt_RECORD_SW_Version DePlatformVersion;
    Dt_RECORD_BuildDate DeBuildDatePlatform;
        /* 64-bit build number. UTC UNIX Timestamp of the build      */
    Dt_RECORD_SW_Version DeSWCVersion;
    Dt_RECORD_BuildDate DeBuildDateSWC;
  } Dt_RECORD_SWC_Identification; 
#define Rte_TypeDef_Dt_RECORD_StbmTimestamp 
typedef struct _Dt_RECORD_StbmTimestamp
  {
    uint8 status;
    UINT_GAP_8 PaddingGap8_1;
    UINT_GAP_16 PaddingGap16_2;
    uint32 nanoseconds;
    uint32 seconds;
    uint16 secondsHigh;
    UINT_GAP_16 PaddingGap16_3;
  } Dt_RECORD_StbmTimestamp; 
#define Rte_TypeDef_Dt_RECORD_SysManager2USBCom 
typedef struct _Dt_RECORD_SysManager2USBCom
  {
    uint8 CSCVcCmdDspCmdR;
    uint8 CDisCVoCndCfm;
    Dt_ARRAY_10_uint8 BKP;
  } Dt_RECORD_SysManager2USBCom; 
#define Rte_TypeDef_Dt_RECORD_Timestamp 
typedef struct _Dt_RECORD_Timestamp
  {
    uint32 DeTimestampHigh;
        /* [Call Cycle][/Call Cycle]                                 */
        /* [Signal Availability][/Signal Availability]               */
        /* [Min][/Min]                                               */
        /* [Max][/Max]                                               */
        /* [Logical][/Logical]                                       */
        /* [ASIL LEVEL][/ASIL LEVEL]                                 */
        /* [Init][/Init]                                             */
        /* [Description (short)][/Description (short)]               */
        /* [Unit][/Unit]                                             */
        /* [Accuracy][/Accuracy]                                     */
    uint32 DeTimestampLow;
        /* [Call Cycle][/Call Cycle]                                 */
        /* [Signal Availability][/Signal Availability]               */
        /* [Min][/Min]                                               */
        /* [Max][/Max]                                               */
        /* [Logical][/Logical]                                       */
        /* [ASIL LEVEL][/ASIL LEVEL]                                 */
        /* [Init][/Init]                                             */
        /* [Description (short)][/Description (short)]               */
        /* [Unit][/Unit]                                             */
        /* [Accuracy][/Accuracy]                                     */
  } Dt_RECORD_Timestamp; 
#define Rte_TypeDef_Dt_ENUM_PdDatablockStatus 
typedef uint16 Dt_ENUM_PdDatablockStatus; 
# define Dt_ENUM_PdDatablockStatus_LowerLimit (0U)
# define Dt_ENUM_PdDatablockStatus_UpperLimit (65535U)
# ifndef DATABLOCK_INIT 
#  define DATABLOCK_INIT (0U)
# endif 
# ifndef DATABLOCK_OK 
#  define DATABLOCK_OK (1U)
# endif 
# ifndef DATABLOCK_NOT_OK 
#  define DATABLOCK_NOT_OK (2U)
# endif 
# ifndef DATABLOCK_WRONGCRC 
#  define DATABLOCK_WRONGCRC (3U)
# endif 
# ifndef DATABLOCK_ERASED 
#  define DATABLOCK_ERASED (4U)
# endif 
#define Rte_TypeDef_Dt_RECORD_PdVersion 
typedef struct _Dt_RECORD_PdVersion
  {
    Dt_RECORD_SW_Version DeExpectedVersion;
    Dt_RECORD_SW_Version DeVersion;
  } Dt_RECORD_PdVersion; 
#define Rte_TypeDef_Dt_ARRAY_10_sint32 
typedef sint32 Dt_ARRAY_10_sint32[10]; 
#define Rte_TypeDef_Dt_ARRAY_10_float32 
typedef float32 Dt_ARRAY_10_float32[10]; 
#define Rte_TypeDef_Dt_RECORD_Save 
typedef struct _Dt_RECORD_Save
  {
    Dt_ARRAY_10_sint32 ngSignal;
    Dt_ARRAY_10_float32 fgSignal;
  } Dt_RECORD_Save; 
#define Rte_TypeDef_Dt_RECORD_USBCom_Critical 
typedef struct _Dt_RECORD_USBCom_Critical
  {
    Dt_ENUM_PdDatablockStatus DeStatus;
    UINT_GAP_16 PaddingGap16_1;
    Dt_RECORD_PdVersion DeVersion;
    Dt_RECORD_Save DeData;
  } Dt_RECORD_USBCom_Critical; 
#define Rte_TypeDef_Dt_RECORD_UserCLB 
typedef struct _Dt_RECORD_UserCLB
  {
    Dt_ARRAY_10_sint32 ngSignal;
    Dt_ARRAY_10_float32 fgSignal;
    Dt_RECORD_HEADER stHeader;
  } Dt_RECORD_UserCLB; 
#define Rte_TypeDef_Dt_Record_Version 
typedef struct _Dt_Record_Version
  {
    uint8 DeMajor;
    uint8 DeMinor;
    uint8 DePatch;
    UINT_GAP_8 PaddingGap8_1;
  } Dt_Record_Version; 
typedef enum _Rnbl_IDs 
  { RCtApUSBCom_Init_ID = 33
  , RCtApUSBCom_100ms_ID = 131
  } Rte_Rnbl_IDs; 



/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/




/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/




/* begin Fileversion check */
# ifndef SKIP_MAGIC_NUMBER
#  ifdef RTE_MAGIC_NUMBER
#   if RTE_MAGIC_NUMBER != 0
#    error "The magic number is different. Please check time and date of the generated RTE files!"
#   endif
#  else
#   define RTE_MAGIC_NUMBER 0
#  endif  /* RTE_MAGIC_NUMBER */
# endif  /* SKIP_MAGIC_NUMBER */
/* end Fileversion check */

#endif /* RTE_TYPE_H */
