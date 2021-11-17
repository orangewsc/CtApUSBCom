#include <stdio.h>    
#include <winsock2.h> 
#include <WS2tcpip.h>
#include <string>
#pragma comment(lib,"ws2_32.lib") 
#include "USBCom_DataType_Server.h"
#include <windows.h>
#include <iostream>
#include <stdint.h>
#include <memory.h>

using namespace std;

int CommandWord_Judge(char[]);

int main()
{
	LARGE_INTEGER nFreq;
	LARGE_INTEGER t1_psdsp, t1_apdsp, t1_iecuni, t1_hdmap, t1_ni, t1_nt, t1_ri, t1_asvcf, t1_heart, t1_login, t1_cwh, t1_iecuri;
	LARGE_INTEGER t2_psdsp, t2_apdsp, t2_iecuni, t2_hdmap, t2_ni, t2_nt, t2_ri, t2_asvcf, t2_heart, t2_login, t2_cwh, t2_iecuri;
	QueryPerformanceFrequency(&nFreq);

	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(6666);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}

	if (listen(slisten, 10) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}

	

	SOCKET sclient_msg;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	
	sclient_msg = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);

	printf("Established Successful!\n");

	while (true)
	{
		//sclient_msg = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);

		if (sclient_msg == INVALID_SOCKET)
		{
			printf("sclient_msg accept error !");
			continue;
		}

		static int count_hdmap_choose = 0;
		static int count_hdmap_default = 0;

		char recbuf_msg[12000];
		memset(recbuf_msg, 0, sizeof(recbuf_msg));

		int ret_msg = recv(sclient_msg, recbuf_msg, sizeof(recbuf_msg), 0);
		if (ret_msg > 0)
		{
			if (CommandWord_Judge(recbuf_msg) == 1)
			{
				Dt_RECORD_EmptyAppBody_Socket LogIn_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(LogIn_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(LogIn_RP); k++)
				{
					printf("LogIn_RP content: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(LogIn_RP)-1])
				{
					QueryPerformanceCounter(&t1_login);

					Dt_RECORD_EmptyAppBody_Socket LogIn_FeedBack;
					LogIn_FeedBack.HeaderByte = 0x81;
					LogIn_FeedBack.PacketLength = sizeof(LogIn_FeedBack);
					LogIn_FeedBack.CommandWord = 0x0001;
					LogIn_FeedBack.ControlByte = 0x01;
					LogIn_FeedBack.ProtoVersion = 0x00;					
					char LogIn_FeedBack_Buf[sizeof(LogIn_FeedBack)];
					memset(LogIn_FeedBack_Buf, 0, sizeof(LogIn_FeedBack_Buf));
					memcpy(LogIn_FeedBack_Buf, &LogIn_FeedBack, sizeof(LogIn_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(LogIn_FeedBack)-1; i++)
					{
						sum ^= LogIn_FeedBack_Buf[i];
					}
					LogIn_FeedBack.PacketTail = sum;
					LogIn_FeedBack_Buf[sizeof(LogIn_FeedBack)-1] = sum;
					send(sclient_msg, LogIn_FeedBack_Buf, sizeof(LogIn_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(LogIn_FeedBack_Buf); k++)
					{
						printf("LogIn_FeedBack_Buf content: %02x\n", (unsigned char)LogIn_FeedBack_Buf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_login);
					cout << "LI Internal time:" << t1_login.QuadPart / (double)nFreq.QuadPart << " " << t2_login.QuadPart / (double)nFreq.QuadPart << " " << (t2_login.QuadPart - t1_login.QuadPart) / (double)nFreq.QuadPart << endl;
				}				
			}
			else if (CommandWord_Judge(recbuf_msg) == 257)
			{
				Dt_RECORD_EmptyAppBody_Socket NavigationInfo_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(NavigationInfo_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(NavigationInfo_RP); k++)
				{
					printf("NavigationInfo_RP content: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(NavigationInfo_RP)-1])
				{
					QueryPerformanceCounter(&t1_ni);

					Dt_RECORD_NavigationInfo_Socket NavigationInfo_FeedBack;
					NavigationInfo_FeedBack.HeaderByte = 0x81;					
					NavigationInfo_FeedBack.PacketLength = sizeof(NavigationInfo_FeedBack);
					NavigationInfo_FeedBack.CommandWord = 0x0101;
					NavigationInfo_FeedBack.ControlByte = 0x01;
					NavigationInfo_FeedBack.ProtoVersion = 0x00;
					NavigationInfo_FeedBack.TrfcJamRngNav = 0x01;
					NavigationInfo_FeedBack.DistToTrfcJamNav = 0x01;
					NavigationInfo_FeedBack.DistToDsttnNav = 0x0001;
					NavigationInfo_FeedBack.FICMPosngSysLatd = 0x00000001;
					NavigationInfo_FeedBack.FICMPosngSysLongd = 0x00000001;
					NavigationInfo_FeedBack.SpdLmtNav = 0x01;
					NavigationInfo_FeedBack.SpdLmtPathRngNav = 0x0001;
					NavigationInfo_FeedBack.MnvrngPntTypNav = 0x01;
					NavigationInfo_FeedBack.MnvrngPntDistNav = 0x0001;
					NavigationInfo_FeedBack.CuvtrNav = 0x0001;
					NavigationInfo_FeedBack.CrntLongdGrdValNav = 0x0001;
					char NavigationInfo_FeedBack_Buf[sizeof(NavigationInfo_FeedBack)];
					memset(NavigationInfo_FeedBack_Buf, 0, sizeof(NavigationInfo_FeedBack_Buf));
					memcpy(NavigationInfo_FeedBack_Buf, &NavigationInfo_FeedBack, sizeof(NavigationInfo_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(NavigationInfo_FeedBack)-1; i++)
					{
						sum ^= NavigationInfo_FeedBack_Buf[i];
					}
					NavigationInfo_FeedBack.PacketTail = sum;
					NavigationInfo_FeedBack_Buf[sizeof(NavigationInfo_FeedBack)-1] = sum;
					send(sclient_msg, NavigationInfo_FeedBack_Buf, sizeof(NavigationInfo_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(NavigationInfo_FeedBack_Buf); k++)
					{
						printf("NavigationInfo_FeedBack_Buf content: %02x\n", NavigationInfo_FeedBack_Buf[k]);
					}					

					printf("NavigationInfo_FeedBack.PacketLength: %d\n", NavigationInfo_FeedBack.PacketLength);
					/* ------------------------- */

					QueryPerformanceCounter(&t2_ni);
					cout << "NI Internal time:" << t1_ni.QuadPart / (double)nFreq.QuadPart << " " << t2_ni.QuadPart / (double)nFreq.QuadPart << " " << (t2_ni.QuadPart - t1_ni.QuadPart) / (double)nFreq.QuadPart << endl;
				}
				
			}
			else if (CommandWord_Judge(recbuf_msg) == 258)
			{
				Dt_RECORD_EmptyAppBody_Socket NavigationTrail_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(NavigationTrail_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */				
				for (int k = 0; k < sizeof(NavigationTrail_RP); k++)
				{
					printf("NavigationTrail_RP: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(NavigationTrail_RP)-1])
				{
					QueryPerformanceCounter(&t1_nt);
					printf("NavigationTrail_RP的checksum正确\n");
					Dt_RECORD_NavigationTrail_Socket NavigationTrail_SP;
					NavigationTrail_SP.HeaderByte = 0x81;					
					NavigationTrail_SP.PacketLength = sizeof(NavigationTrail_SP);
					NavigationTrail_SP.CommandWord = 0x0102;
					NavigationTrail_SP.ControlByte = 0x01;
					NavigationTrail_SP.ProtoVersion = 0x00;
					for (int i = 0; i < 10; i++)
					{
						NavigationTrail_SP.NavigationTrail[i] = 1;
					}
					char NavigationTrail_Buf[sizeof(NavigationTrail_SP)];
					memset(NavigationTrail_Buf, 0, sizeof(NavigationTrail_Buf));					
					memcpy(NavigationTrail_Buf, &NavigationTrail_SP, sizeof(NavigationTrail_SP));					
					UINT8 sum = 0;
					for (int i = 0; i < sizeof(NavigationTrail_Buf)-1; i++)
					{
						sum ^= NavigationTrail_Buf[i];						
					}					
					NavigationTrail_SP.PacketTail = sum;
					NavigationTrail_Buf[sizeof(NavigationTrail_Buf)-1] = sum;					
					send(sclient_msg, NavigationTrail_Buf, sizeof(NavigationTrail_SP), 0);
					/* -------------------------- */								
					for (int k = 0; k < 20; k++)
					{
						printf("NavigationTrail_Buf content: %02x\n", NavigationTrail_Buf[k]);
					}					
					/* -------------------------- */

					QueryPerformanceCounter(&t2_nt);
					cout << "NT Internal time:" << t1_nt.QuadPart / (double)nFreq.QuadPart << " " << t2_nt.QuadPart / (double)nFreq.QuadPart << " " << (t2_nt.QuadPart - t1_nt.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 259)
			{
				Dt_RECORD_EmptyAppBody_Socket ReservedInfo_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(ReservedInfo_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(ReservedInfo_RP); k++)
				{
					printf("ReservedInfo_RP: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(ReservedInfo_RP)-1])
				{
					QueryPerformanceCounter(&t1_ri);

					Dt_RECORD_ReservedInfo_Socket ReservedInfo_SP;
					ReservedInfo_SP.HeaderByte = 0x81;					
					ReservedInfo_SP.PacketLength = sizeof(ReservedInfo_SP);
					ReservedInfo_SP.CommandWord = 0x0103;
					ReservedInfo_SP.ControlByte = 0x01;
					ReservedInfo_SP.ProtoVersion = 0x00;
					for (int i = 0; i < 10; i++)
					{
						ReservedInfo_SP.ReservedInfo[i] = 1;
					}
					char ReservedInfo_Buf[sizeof(ReservedInfo_SP)];
					memset(ReservedInfo_Buf, 0, sizeof(ReservedInfo_Buf));
					memcpy(ReservedInfo_Buf, &ReservedInfo_SP, sizeof(ReservedInfo_SP));
					UINT8 sum = 0;
					for (int i = 0; i < sizeof(ReservedInfo_Buf)-1; i++)
					{
						sum ^= ReservedInfo_Buf[i];
					}
					ReservedInfo_SP.PacketTail = sum;
					ReservedInfo_Buf[sizeof(ReservedInfo_Buf)-1] = sum;
					send(sclient_msg, ReservedInfo_Buf, sizeof(ReservedInfo_SP), 0);
					/* ------------------------- */				
					for (int k = 0; k < 20; k++)
					{
						printf("ReservedInfo_Buf content: %02x\n", ReservedInfo_Buf[k]);
					}				
					/* ------------------------- */

					QueryPerformanceCounter(&t2_ri);
					cout << "RI Internal time:" << t1_ri.QuadPart / (double)nFreq.QuadPart << " " << t2_ri.QuadPart / (double)nFreq.QuadPart << " " << (t2_ri.QuadPart - t1_ri.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 513)
			{
				Dt_RECORD_ParkingSpaceDsp_Socket ParkingSpaceDsp_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(ParkingSpaceDsp_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(ParkingSpaceDsp_RP); k++)
				{
					printf("ParkingSpaceDsp_RP: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(ParkingSpaceDsp_RP)-1])
				{
					QueryPerformanceCounter(&t1_psdsp);

					Dt_RECORD_ParkingSpaceDspFeedBack_Socket ParkingSpaceDsp_FeedBack;
					ParkingSpaceDsp_FeedBack.HeaderByte = 0x81;					
					ParkingSpaceDsp_FeedBack.PacketLength = sizeof(ParkingSpaceDsp_FeedBack);
					ParkingSpaceDsp_FeedBack.CommandWord = 0x0201;
					ParkingSpaceDsp_FeedBack.ControlByte = 0x01;
					ParkingSpaceDsp_FeedBack.ProtoVersion = 0x00;
					ParkingSpaceDsp_FeedBack.TgtParkingChosed = 0x01;
					char ParkingSpaceDsp_FeedBack_Buf[sizeof(ParkingSpaceDsp_FeedBack)];
					memset(ParkingSpaceDsp_FeedBack_Buf, 0, sizeof(ParkingSpaceDsp_FeedBack_Buf));
					memcpy(ParkingSpaceDsp_FeedBack_Buf, &ParkingSpaceDsp_FeedBack, sizeof(ParkingSpaceDsp_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(ParkingSpaceDsp_FeedBack)-1; i++)
					{
						sum ^= ParkingSpaceDsp_FeedBack_Buf[i];
					}
					ParkingSpaceDsp_FeedBack.PacketTail = sum;
					ParkingSpaceDsp_FeedBack_Buf[sizeof(ParkingSpaceDsp_FeedBack)-1] = sum;
					send(sclient_msg, ParkingSpaceDsp_FeedBack_Buf, sizeof(ParkingSpaceDsp_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(ParkingSpaceDsp_FeedBack_Buf); k++)
					{
						printf("ParkingSpaceDsp_FeedBack_Buf content: %02x\n", ParkingSpaceDsp_FeedBack_Buf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_psdsp);
					cout << "PSDAP Internal time:" << t1_psdsp.QuadPart / (double)nFreq.QuadPart << " " << t2_psdsp.QuadPart / (double)nFreq.QuadPart << " " << (t2_psdsp.QuadPart - t1_psdsp.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 514)
			{
				Dt_RECORD_AIPilotObjDsp_Socket AIPilotObjDsp_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(AIPilotObjDsp_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(AIPilotObjDsp_RP); k++)
				{
					printf("AIPilotObjDsp_RP: %02x\n", recbuf_msg[k]);
				}						
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(AIPilotObjDsp_RP)-1])
				{
					QueryPerformanceCounter(&t1_apdsp);

					Dt_RECORD_EmptyAppBody_Socket AIPilotObjDsp_FeedBack;
					AIPilotObjDsp_FeedBack.HeaderByte = 0x81;					
					AIPilotObjDsp_FeedBack.PacketLength = sizeof(AIPilotObjDsp_FeedBack);
					AIPilotObjDsp_FeedBack.CommandWord = 0x0202;
					AIPilotObjDsp_FeedBack.ControlByte = 0x01;
					AIPilotObjDsp_FeedBack.ProtoVersion = 0x00;					
					char AIPilotObjDsp_FeedBack_Buf[sizeof(AIPilotObjDsp_FeedBack)];
					memset(AIPilotObjDsp_FeedBack_Buf, 0, sizeof(AIPilotObjDsp_FeedBack_Buf));
					memcpy(AIPilotObjDsp_FeedBack_Buf, &AIPilotObjDsp_FeedBack, sizeof(AIPilotObjDsp_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(AIPilotObjDsp_FeedBack)-1; i++)
					{
						sum ^= AIPilotObjDsp_FeedBack_Buf[i];
					}
					AIPilotObjDsp_FeedBack.PacketTail = sum;
					AIPilotObjDsp_FeedBack_Buf[sizeof(AIPilotObjDsp_FeedBack)-1] = sum;
					send(sclient_msg, AIPilotObjDsp_FeedBack_Buf, sizeof(AIPilotObjDsp_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(AIPilotObjDsp_FeedBack_Buf); k++)
					{
						printf("AIPilotObjDsp_FeedBack_Buf content: %02x\n", AIPilotObjDsp_FeedBack_Buf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_apdsp);
					cout << "APDAP Internal time:" << t1_apdsp.QuadPart / (double)nFreq.QuadPart << " " << t2_apdsp.QuadPart / (double)nFreq.QuadPart << " " << (t2_apdsp.QuadPart - t1_apdsp.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 515)
			{
				Dt_RECORD_IECUNavigationInfo_Socket IECUNavigationInfo_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(IECUNavigationInfo_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(IECUNavigationInfo_RP); k++)
				{
					printf("IECUNavigationInfo_RP: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(IECUNavigationInfo_RP)-1])
				{
					QueryPerformanceCounter(&t1_iecuni);

					Dt_RECORD_EmptyAppBody_Socket IECUNavigationInfo_FeedBack;
					IECUNavigationInfo_FeedBack.HeaderByte = 0x81;					
					IECUNavigationInfo_FeedBack.PacketLength = sizeof(IECUNavigationInfo_FeedBack);
					IECUNavigationInfo_FeedBack.CommandWord = 0x0203;
					IECUNavigationInfo_FeedBack.ControlByte = 0x01;
					IECUNavigationInfo_FeedBack.ProtoVersion = 0x00;					
					char IECUNavigationInfo_FeedBack_Buf[sizeof(IECUNavigationInfo_FeedBack)];
					memset(IECUNavigationInfo_FeedBack_Buf, 0, sizeof(IECUNavigationInfo_FeedBack_Buf));
					memcpy(IECUNavigationInfo_FeedBack_Buf, &IECUNavigationInfo_FeedBack, sizeof(IECUNavigationInfo_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(IECUNavigationInfo_FeedBack)-1; i++)
					{
						sum ^= IECUNavigationInfo_FeedBack_Buf[i];
					}
					IECUNavigationInfo_FeedBack.PacketTail = sum;
					IECUNavigationInfo_FeedBack_Buf[sizeof(IECUNavigationInfo_FeedBack)-1] = sum;
					send(sclient_msg, IECUNavigationInfo_FeedBack_Buf, sizeof(IECUNavigationInfo_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(IECUNavigationInfo_FeedBack_Buf); k++)
					{
						printf("IECUNavigationInfo_FeedBack_Buf content: %02x\n", IECUNavigationInfo_FeedBack_Buf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_iecuni);
					cout << "IECUNI Internal time:" << t1_iecuni.QuadPart / (double)nFreq.QuadPart << " " << t2_iecuni.QuadPart / (double)nFreq.QuadPart << " " << (t2_iecuni.QuadPart - t1_iecuni.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 516)
			{
				Dt_RECORD_HDMapUpdateRequest_Socket HDMapUpdate_Request;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(HDMapUpdate_Request)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(HDMapUpdate_Request); k++)
				{
					printf("HDMapUpdate_Request: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(HDMapUpdate_Request)-1])
				{
					if (count_hdmap_choose < 3 && count_hdmap_default < 80)
					{
						QueryPerformanceCounter(&t1_hdmap);

						Dt_RECORD_HDMapUpdateFeedBack_Socket HDMapUpdate_FeedBack;		
						HDMapUpdate_FeedBack.HeaderByte = 0x81;						
						HDMapUpdate_FeedBack.PacketLength = sizeof(HDMapUpdate_FeedBack);
						HDMapUpdate_FeedBack.CommandWord = 0x0204;
						HDMapUpdate_FeedBack.ControlByte = 0x01;
						HDMapUpdate_FeedBack.ProtoVersion = 0x00;
						HDMapUpdate_FeedBack.HDMapUpdate_FeedBack = 0x01;						
						char HDMapUpdate_FeedBack_Buf[sizeof(HDMapUpdate_FeedBack)];
						memset(HDMapUpdate_FeedBack_Buf, 0, sizeof(HDMapUpdate_FeedBack_Buf));
						memcpy(HDMapUpdate_FeedBack_Buf, &HDMapUpdate_FeedBack, sizeof(HDMapUpdate_FeedBack));
						UINT8 sum = 0;
						for (UINT8 i = 0; i < sizeof(HDMapUpdate_FeedBack)-1; i++)
						{
							sum ^= HDMapUpdate_FeedBack_Buf[i];
						}
						HDMapUpdate_FeedBack.PacketTail = sum;
						HDMapUpdate_FeedBack_Buf[sizeof(HDMapUpdate_FeedBack)-1] = sum;
						if (HDMapUpdate_FeedBack.HDMapUpdate_FeedBack == 0x01 || HDMapUpdate_FeedBack.HDMapUpdate_FeedBack == 0x02)
						{
							count_hdmap_choose = count_hdmap_choose + 1;
							if (count_hdmap_choose < 4)
							{
								send(sclient_msg, HDMapUpdate_FeedBack_Buf, sizeof(HDMapUpdate_FeedBack), 0);
								/* ------------------------- */								
								for (int k = 0; k < sizeof(HDMapUpdate_FeedBack_Buf); k++)
								{
									printf("HDMapUpdate_FeedBack_Buf content: %02x\n", HDMapUpdate_FeedBack_Buf[k]);
								}								
								/* ------------------------- */

								QueryPerformanceCounter(&t2_hdmap);
								cout << "HDMAP Internal time:" << t1_hdmap.QuadPart / (double)nFreq.QuadPart << " " << t2_hdmap.QuadPart / (double)nFreq.QuadPart << " " << (t2_hdmap.QuadPart - t1_hdmap.QuadPart) / (double)nFreq.QuadPart << endl;
							}
						}
						else
						{
							count_hdmap_default = count_hdmap_default + 1;
							if (count_hdmap_default < 81)
							{
								send(sclient_msg, HDMapUpdate_FeedBack_Buf, sizeof(HDMapUpdate_FeedBack), 0);
								/* ------------------------- */								
								for (int k = 0; k < sizeof(HDMapUpdate_FeedBack_Buf); k++)
								{
									printf("HDMapUpdate_FeedBack_Buf content: %02x\n", HDMapUpdate_FeedBack_Buf[k]);
								}								
								/* ------------------------- */

								QueryPerformanceCounter(&t2_hdmap);
								cout << "HDMAP Internal time:" << t1_hdmap.QuadPart / (double)nFreq.QuadPart << " " << t2_hdmap.QuadPart / (double)nFreq.QuadPart << " " << (t2_hdmap.QuadPart - t1_hdmap.QuadPart) / (double)nFreq.QuadPart << endl;
							}
						}
					}
					else
					{
						count_hdmap_choose = 0;
						count_hdmap_default = 0;
						//closesocket(sclient_msg);
					}
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 517)
			{
				Dt_RECORD_ASVCameraFail_Socket ASVCameraFail_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(ASVCameraFail_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(ASVCameraFail_RP); k++)
				{
					printf("ASVCameraFail_RP: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(ASVCameraFail_RP)-1])
				{
					QueryPerformanceCounter(&t1_asvcf);

					Dt_RECORD_EmptyAppBody_Socket ASVCameraFail_FeedBack;
					ASVCameraFail_FeedBack.HeaderByte = 0x81;					
					ASVCameraFail_FeedBack.PacketLength = sizeof(ASVCameraFail_FeedBack);
					ASVCameraFail_FeedBack.CommandWord = 0x0205;
					ASVCameraFail_FeedBack.ControlByte = 0x01;
					ASVCameraFail_FeedBack.ProtoVersion = 0x00;		
					char ASVCameraFail_FeedBack_Buf[sizeof(ASVCameraFail_FeedBack)];
					memset(ASVCameraFail_FeedBack_Buf, 0, sizeof(ASVCameraFail_FeedBack_Buf));
					memcpy(ASVCameraFail_FeedBack_Buf, &ASVCameraFail_FeedBack, sizeof(ASVCameraFail_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(ASVCameraFail_FeedBack)-1; i++)
					{
						sum ^= ASVCameraFail_FeedBack_Buf[i];
					}
					ASVCameraFail_FeedBack.PacketTail = sum;
					ASVCameraFail_FeedBack_Buf[sizeof(ASVCameraFail_FeedBack)-1] = sum;
					send(sclient_msg, ASVCameraFail_FeedBack_Buf, sizeof(ASVCameraFail_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(ASVCameraFail_FeedBack_Buf); k++)
					{
						printf("ASVCameraFail_FeedBack_Buf content: %02x\n", ASVCameraFail_FeedBack_Buf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_asvcf);
					cout << "ASVCF Internal time:" << t1_asvcf.QuadPart / (double)nFreq.QuadPart << " " << t2_asvcf.QuadPart / (double)nFreq.QuadPart << " " << (t2_asvcf.QuadPart - t1_asvcf.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 518)
			{
				Dt_RECORD_ConeWaterHorse_Socket ConeWaterHorse_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(ConeWaterHorse_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(ConeWaterHorse_RP); k++)
				{
					printf("ConeWaterHorse_RP: %02x\n", recbuf_msg[k]);
				}				
				printf("sum_check: %d\n", sum_check);
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(ConeWaterHorse_RP)-1])
				{
					QueryPerformanceCounter(&t1_cwh);
					Dt_RECORD_EmptyAppBody_Socket ConeWaterHorse_SP;
					ConeWaterHorse_SP.HeaderByte = 0x81;
					ConeWaterHorse_SP.PacketLength = sizeof(ConeWaterHorse_SP);
					ConeWaterHorse_SP.CommandWord = 0x0206;
					ConeWaterHorse_SP.ControlByte = 0x01;
					ConeWaterHorse_SP.ProtoVersion = 0x00;					
					char ConeWaterHorse_SPBuf[sizeof(ConeWaterHorse_SP)];
					memset(ConeWaterHorse_SPBuf, 0, sizeof(ConeWaterHorse_SPBuf));
					memcpy(ConeWaterHorse_SPBuf, &ConeWaterHorse_SP, sizeof(ConeWaterHorse_SP));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(ConeWaterHorse_SP)-1; i++)
					{
						sum ^= ConeWaterHorse_SPBuf[i];
					}
					ConeWaterHorse_SP.PacketTail = sum;
					ConeWaterHorse_SPBuf[sizeof(ConeWaterHorse_SP)-1] = sum;
					send(sclient_msg, ConeWaterHorse_SPBuf, sizeof(ConeWaterHorse_SP), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(ConeWaterHorse_SPBuf); k++)
					{
						printf("ConeWaterHorse_SPBuf content: %02x\n", ConeWaterHorse_SPBuf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_cwh);
					cout << "CWH Internal time:" << t1_cwh.QuadPart / (double)nFreq.QuadPart << " " << t2_cwh.QuadPart / (double)nFreq.QuadPart << " " << (t2_cwh.QuadPart - t1_cwh.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 519)
			{
				Dt_RECORD_IECUReservedInfo_Socket IECUReservedInfo_RP;
				UINT8 sum_check = 0;
				for (int i = 0; i < sizeof(IECUReservedInfo_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(IECUReservedInfo_RP); k++)
				{
					printf("IECUReservedInfo_RP: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(IECUReservedInfo_RP)-1])
				{
					QueryPerformanceCounter(&t1_iecuri);

					Dt_RECORD_IECUReservedInfoFeedBack_Socket IECUReservedInfo_FeedBack;
					IECUReservedInfo_FeedBack.HeaderByte = 0x81;
					IECUReservedInfo_FeedBack.PacketLength = sizeof(IECUReservedInfo_FeedBack);
					IECUReservedInfo_FeedBack.CommandWord = 0x0207;
					IECUReservedInfo_FeedBack.ControlByte = 0x01;
					IECUReservedInfo_FeedBack.ProtoVersion = 0x00;
					IECUReservedInfo_FeedBack.FICMFeedBack = 1;
					char IECUReservedInfo_FeedBack_Buf[sizeof(IECUReservedInfo_FeedBack)];
					memset(IECUReservedInfo_FeedBack_Buf, 0, sizeof(IECUReservedInfo_FeedBack_Buf));
					memcpy(IECUReservedInfo_FeedBack_Buf, &IECUReservedInfo_FeedBack, sizeof(IECUReservedInfo_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(IECUReservedInfo_FeedBack_Buf)-1; i++)
					{
						sum ^= IECUReservedInfo_FeedBack_Buf[i];
					}
					IECUReservedInfo_FeedBack.PacketTail = sum;
					IECUReservedInfo_FeedBack_Buf[sizeof(IECUReservedInfo_FeedBack_Buf)-1] = sum;					
					send(sclient_msg, IECUReservedInfo_FeedBack_Buf, sizeof(IECUReservedInfo_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(IECUReservedInfo_FeedBack_Buf); k++)
					{
						printf("IECUReservedInfo_FeedBack_Buf content: %02x\n", IECUReservedInfo_FeedBack_Buf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_iecuri);
					cout << "IECURI Internal time:" << t1_iecuri.QuadPart / (double)nFreq.QuadPart << " " << t2_iecuri.QuadPart / (double)nFreq.QuadPart << " " << (t2_iecuri.QuadPart - t1_iecuri.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else if (CommandWord_Judge(recbuf_msg) == 2)
			{
				Dt_RECORD_EmptyAppBody_Socket HeartBeat_RP;
				UINT8 sum_check = 0;
				for (UINT8 i = 0; i < sizeof(HeartBeat_RP)-1; i++)
				{
					sum_check ^= recbuf_msg[i];
				}
				/* ---------------------- */
				printf("recv_mesg length: %d\n", ret_msg);				
				for (int k = 0; k < sizeof(HeartBeat_RP); k++)
				{
					printf("HeartBeat_RP: %02x\n", recbuf_msg[k]);
				}				
				/* ---------------------- */
				if (sum_check == (UINT8)recbuf_msg[sizeof(HeartBeat_RP)-1])
				{
					QueryPerformanceCounter(&t1_heart);

					Dt_RECORD_EmptyAppBody_Socket HeartBeat_FeedBack;
					HeartBeat_FeedBack.HeaderByte = 0x81;
					HeartBeat_FeedBack.PacketLength = sizeof(HeartBeat_FeedBack);
					HeartBeat_FeedBack.CommandWord = 0x0001;
					HeartBeat_FeedBack.ControlByte = 0x01;
					HeartBeat_FeedBack.ProtoVersion = 0x00;					
					char HeartBeat_FeedBack_Buf[sizeof(HeartBeat_FeedBack)];
					memset(HeartBeat_FeedBack_Buf, 0, sizeof(HeartBeat_FeedBack_Buf));
					memcpy(HeartBeat_FeedBack_Buf, &HeartBeat_FeedBack, sizeof(HeartBeat_FeedBack));
					UINT8 sum = 0;
					for (UINT8 i = 0; i < sizeof(HeartBeat_FeedBack)-1; i++)
					{
						sum ^= HeartBeat_FeedBack_Buf[i];
					}
					HeartBeat_FeedBack.PacketTail = sum;
					HeartBeat_FeedBack_Buf[sizeof(HeartBeat_FeedBack)-1] = sum;
					send(sclient_msg, HeartBeat_FeedBack_Buf, sizeof(HeartBeat_FeedBack), 0);
					/* ------------------------- */					
					for (int k = 0; k < sizeof(HeartBeat_FeedBack_Buf); k++)
					{
						printf("HeartBeat_FeedBack_Buf content: %02x\n", HeartBeat_FeedBack_Buf[k]);
					}					
					/* ------------------------- */

					QueryPerformanceCounter(&t2_heart);
					cout << "HB Internal time:" << t1_heart.QuadPart / (double)nFreq.QuadPart << " " << t2_heart.QuadPart / (double)nFreq.QuadPart << " " << (t2_heart.QuadPart - t1_heart.QuadPart) / (double)nFreq.QuadPart << endl;
				}
			}
			else 
			{
				//cout << "Recv Test_msg successful!" << endl;
				//char testRecvBuf[1024];
				//recv(sclient_msg, testRecvBuf, sizeof(testRecvBuf), 0);
				cout << "Recv Test_msg successful: " << *((uint16_t*)(&recbuf_msg[3])) << endl;

				char testSendBuf[1024];
				sprintf_s(testSendBuf, "This is Server!");
				send(sclient_msg, testSendBuf, sizeof(testSendBuf), 0);
				cout << "Send Test_msg successful: " << testSendBuf << endl;
			}
		}
		else
		{
			cout << "客户端已关闭，Exit!" << endl;
			system("pause");
			return 0;
		}

		//closesocket(sclient_msg);		
		//Sleep(100);  // 100ms发送一次
	}
	//closesocket(slisten); 
	//WSACleanup();
	
	return 0;
}



int CommandWord_Judge(char recvbuf[])
{
	int Value_CommandWord;
	Value_CommandWord = *((uint16_t*)(&recvbuf[3]));
	return Value_CommandWord;
}