/** \file USBCom_DataType_Server.h */

#ifndef _USBCom_DataType_Server_H
#define _USBCom_DataType_Server_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#pragma pack(1)

typedef struct _Dt_RECORD_EmptyAppBody_Socket
  {
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT8 PacketTail;
  } Dt_RECORD_EmptyAppBody_Socket;  

typedef struct _Dt_RECORD_NavigationInfo_Socket
  {
    UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT8 TrfcJamRngNav;
    UINT8 DistToTrfcJamNav;
    UINT16 DistToDsttnNav;
    INT32 FICMPosngSysLatd;
	INT32 FICMPosngSysLongd;
	UINT8 SpdLmtNav;
	UINT16 SpdLmtPathRngNav;
	UINT8 MnvrngPntTypNav;
	UINT16 MnvrngPntDistNav;
	UINT16 CuvtrNav;
	UINT16 CrntLongdGrdValNav;
    UINT8 PacketTail;	
  } Dt_RECORD_NavigationInfo_Socket; 

typedef UINT8 Dt_ARRAY_10000_uint8[10000]; 

typedef struct _Dt_RECORD_NavigationTrail_Socket
  {
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	Dt_ARRAY_10000_uint8 NavigationTrail;	
	UINT8 PacketTail;
  } Dt_RECORD_NavigationTrail_Socket;
 
typedef struct _Dt_RECORD_ReservedInfo_Socket
  {
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	Dt_ARRAY_10000_uint8 ReservedInfo;	
	UINT8 PacketTail;
  } Dt_RECORD_ReservedInfo_Socket; 

typedef struct _Dt_RECORD_ParkingSpace_Socket
  {
	UINT8 ParkngSpaceID;
	UINT16 ParkngSpaceLongtRltvDist;
	UINT16 ParkngSpaceLatRltvDist;
	UINT8 ParkngSpaceAngle;
	UINT8 ParkngSpaceSts;
	UINT16 ParkngSpaceSyncCtr;	
  } Dt_RECORD_ParkingSpace_Socket;
  
typedef struct _Dt_RECORD_ParkingSpaceDsp_Socket
  {	
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT64 IECUTimeStamp;
	Dt_RECORD_ParkingSpace_Socket ParkingSpace_Socket[8];	
	UINT8 TgtParkngSpaceID;	
	UINT8 PacketTail;
  } Dt_RECORD_ParkingSpaceDsp_Socket;

typedef struct _Dt_RECORD_ParkingSpaceDspFeedBack_Socket
  {
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;		
	UINT8 TgtParkingChosed;
	UINT8 PacketTail;
  } Dt_RECORD_ParkingSpaceDspFeedBack_Socket;

typedef struct _Dt_RECORD_AIPilotObj_Socket
  {
	UINT16 AIPilotObjId;
	UINT16 AIPilotObjLongtRltvDist;
	UINT16 AIPilotObjLatRltvDist;
	UINT8 AIPilotObjStyle;
	boolean AIPilotObjCrashRisk;
	UINT16 AIPilotObjAngle;
	UINT16 AIPilotObjLongtRltvSpd;
	UINT16 AIPilotObjSyncCtr;
  } Dt_RECORD_AIPilotObj_Socket;

typedef struct _Dt_RECORD_AIPilotObjDsp_Socket
  {	
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;	
	UINT64 IECUTimeStamp;
	Dt_RECORD_AIPilotObj_Socket AIPilotObj_Socket[16];
	UINT16 FollowCarID;
	UINT8 FrtLeftObstacleDist;
	UINT8 FrtRightObstacleDist;
	UINT8 FrtObstacleDist;
	UINT8 RearLeftObstacleDist;
	UINT8 RearRightObstacleDist;
	UINT8 RearObstacleDist;
	UINT8 PacketTail;
  } Dt_RECORD_AIPilotObjDsp_Socket;

typedef struct _Dt_RECORD_TrafficLight_Socket
  {
	UINT8 TrafficLightShap;
	UINT8 TrafficLightColr;
	UINT8 TrafficLightTim;   
  } Dt_RECORD_TrafficLight_Socket;

typedef struct _Dt_RECORD_IECUNavigationInfo_Socket
  {
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT8 NavigationTrafficLightInfo;
	Dt_RECORD_TrafficLight_Socket TrafficLight_Socket[4];
	UINT8 RoadSpeedLimitSign;
	UINT8 RoadSpeedLimitSignDist;
	UINT8 SpeedingWrnng;
	UINT8 TrafficbanSign;
	UINT8 TrafficbanSignDist;
	UINT8 TrafficWrnngSign;
	UINT8 TrafficWrnngSignDist;
	UINT8 TrafficSignINF;
	UINT8 TrafficSignINFDist;
	UINT8 AIPilotRedLghtSig;
	UINT8 P2PSpdLimit;
	UINT8 P2PAverageSpd;
	UINT8 DistOfP2PSpdLimitEndPoint;
	UINT8 P2PSpdLimitPromptSts;
	UINT8 PacketTail;
  } Dt_RECORD_IECUNavigationInfo_Socket;

typedef struct _Dt_RECORD_HDMapUpdateRequest_Socket
  {
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT8 HDMapUpdate_Request;
	UINT8 PacketTail;
  } Dt_RECORD_HDMapUpdateRequest_Socket;

typedef struct _Dt_RECORD_HDMapUpdateFeedBack_Socket
  {
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;	
	UINT8 HDMapUpdate_FeedBack;
	UINT8 PacketTail;
  } Dt_RECORD_HDMapUpdateFeedBack_Socket;

typedef struct _Dt_RECORD_ASVCameraFail_Socket
{
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT16 CSQ;
	UINT8 PacketTail;
} Dt_RECORD_ASVCameraFail_Socket;

typedef struct _Dt_RECORD_ConeWaterHorse_Socket
{
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT8 LeftLaneArrowType;
	UINT16 LeftLaneArrowLongtRltvDist;
	UINT16 LeftLaneArrowLatRltvDist;
	UINT8 RightLaneArrowType;
	UINT16 RightLaneArrowLongtRltvDist;
	UINT16 RightLaneArrowLatRltvDist;
	UINT8 MainLaneArrowType;
	UINT16 MainLaneArrowLongtRltvDist;
	UINT16 MainLaneArrowLatRltvDist;
	UINT8 PacketTail;
} Dt_RECORD_ConeWaterHorse_Socket;

typedef UINT8 Dt_ARRAY_1024_uint8[1024];

typedef struct _Dt_RECORD_IECUReservedInfo_Socket
{
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	Dt_ARRAY_1024_uint8 IECUReservedInfo;
	UINT8 PacketTail;
} Dt_RECORD_IECUReservedInfo_Socket;

typedef struct _Dt_RECORD_IECUReservedInfoFeedBack_Socket
{
	UINT8 HeaderByte;
	UINT16 PacketLength;
	UINT16 CommandWord;
	UINT8 ControlByte;
	UINT8 ProtoVersion;
	UINT64 FICMFeedBack;
	UINT8 PacketTail;
} Dt_RECORD_IECUReservedInfoFeedBack_Socket;

  
#pragma pack()
#endif /* USBCom_DataType_Server_H */






