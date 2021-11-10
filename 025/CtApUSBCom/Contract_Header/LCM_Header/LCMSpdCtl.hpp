#ifndef _LCMSpdCtl_hpp_
#define _LCMSpdCtl_hpp_

#include "Socket_Status.h"



class lcm_Handler
{
	public:
		lcm_Handler(){};
		~lcm_Handler(){};
        SpeedControl_IECU2FICM m_msg;
		void handleMessage(const lcm::ReceiveBuffer* recvbuf, const std::string& chan, const SpeedControl_IECU2FICM *msg)
		{
#ifdef SPEEDCONTROL_DEBUG
			printf("================== [0x0207] SpeedControl LCM Recv Successful! ==================\n");
			printf("SpeedControl_FICM2IECU_Msg_LCM.CSCVcCmdDspCmdR: %d\n",msg->CSCVcCmdDspCmdR);
			printf("SpeedControl_FICM2IECU_Msg_LCM.CDisCVoCndCfm: %d\n",msg->CDisCVoCndCfm);
#endif
			m_msg.CSCVcCmdDspCmdR = msg->CSCVcCmdDspCmdR;
			m_msg.CDisCVoCndCfm = msg->CDisCVoCndCfm;
        }
};


#endif
