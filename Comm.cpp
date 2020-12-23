//---------------------------------------------------------------------------

#pragma hdrstop

#include "Comm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



CSocketMulticast::CSocketMulticast() {
	///***** INIT *****///
	m_sock = INVALID_SOCKET;
}
//---------------------------------------------------------------------------

CSocketMulticast::~CSocketMulticast() {
	FormMain->PringMsg(L"THREAD END");
}
//---------------------------------------------------------------------------

bool __fastcall CSocketMulticast::Open() {

	///***** COMMON INIT *****///
	UnicodeString tempStr = L"";

	///***** MULTICAST SOCKET OPEN ROUTINE *****///
	m_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(m_sock < 0) {
		FormMain->PringMsg(L"FUCK you");
    } else {
		FormMain->PringMsg(L"SUC");
    }

	memset((char *) &m_st_multicast_group_socket, 0, sizeof(m_st_multicast_group_socket));

//	struct sockaddr_in st_multicast_group_socket;
	m_st_multicast_group_socket.sin_family = AF_INET;
	//m_st_multicast_group_socket.sin_addr.s_addr = inet_addr(MULTICAST_GROUP_IP);
    m_st_multicast_group_socket.sin_addr.S_un.S_un_b.s_b1 = 234;
    m_st_multicast_group_socket.sin_addr.S_un.S_un_b.s_b2 = 234;
    m_st_multicast_group_socket.sin_addr.S_un.S_un_b.s_b3 = 234;
    m_st_multicast_group_socket.sin_addr.S_un.S_un_b.s_b4 = 234;
	m_st_multicast_group_socket.sin_port = htons(MULTICAST_GROUP_PORT);

	///***** SET SOCKET OPTION *****///
   	/*int reuse=1;
	if(setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR,(char *)&reuse, sizeof(reuse)) == SOCKET_ERROR)
	{
		FormMain->PringMsg(L"ERROR : SETSOCKETOPT-REUSEADDR");
		return false;
	}
    */
	// Disable loopback so you do not receive your own datagrams.
	char loopch=0;
	if (setsockopt(m_sock, IPPROTO_IP, IP_MULTICAST_LOOP, (char *)&loopch, sizeof(loopch)) < 0)
	{
		FormMain->PringMsg(L"ERROR : SETSOCKETOPT-LOOP");
		return false;
	}


                                         /*
	struct in_addr localInterface;
	//localInterface.s_addr = inet_addr("10.68.1.131");
    localInterface.S_un.S_un_b.s_b1 = 10;
    localInterface.S_un.S_un_b.s_b2 = 68;
    localInterface.S_un.S_un_b.s_b3 = 1;
    localInterface.S_un.S_un_b.s_b4 = 131;
	if (setsockopt(m_sock, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0)
	{
		FormMain->PringMsg(L"ERROR : SETSOCKETOPT-IF");
		return false;
	}                                      */

	/*
	tempStr.sprintf(L"multicast group address: %s, %d", inet_ntoa(*(struct in_addr*)&mcast_addr), mcast_port);
	FormMain->PringMsg(tempStr);

	printf("multicast group address: %s, %d \r\n", inet_ntoa(*(struct in_addr*)&mcast_addr), mcast_port);
	printf("local address: %s \r\n", inet_ntoa(*(struct in_addr*)&local_addr));
    */


	FormMain->PringMsg(L"Open Success");
	return true;
}
//---------------------------------------------------------------------------

int __fastcall CSocketMulticast::Send() {

	char databuf[255] = {0, };
    for(int i = 0 ; i < 255 ; i++) {
        databuf[i] = i;
    }

	if(sendto(m_sock, databuf, 255, 0, (struct sockaddr*)&m_st_multicast_group_socket, sizeof(m_st_multicast_group_socket)) < 0)
	{
		FormMain->PringMsg(L"Send Fail");
	} else {
		FormMain->PringMsg(L"Send Success");
    }
}
//---------------------------------------------------------------------------






///**************************************************************************///
///**************************************************************************///
///***** THREAD CLASS AREA *****///
///**************************************************************************///
///**************************************************************************///

CThreadMulticast::CThreadMulticast() {
	///**** INIT *****///
	m_eThreadWork = THREAD_STOP;

}
//---------------------------------------------------------------------------

__fastcall CThreadMulticast::~CThreadMulticast() {

}
//---------------------------------------------------------------------------

ThreadWorkingType __fastcall CThreadMulticast::GetThreadStatus() {
	return m_eThreadWork;
}
//---------------------------------------------------------------------------

void __fastcall CThreadMulticast::Stop() {
	m_eThreadWork = THREAD_STOP;
}
//---------------------------------------------------------------------------

void __fastcall CThreadMulticast::Execute() {

	UnicodeString tempStr = L"";
	int cnt = 0;
	m_eThreadWork = THREAD_RUNNING;

	///***** SOCKET OPEN ROUTINE *****///
	while(m_eThreadWork == THREAD_RUNNING) {
		if(m_socket_multicast.Open()) {
			m_eThreadWork = THREAD_STOP;
			//break;
		}


		// TEST
		tempStr.sprintf(L"%d", cnt);
		FormMain->PringMsg(tempStr);
		if(++cnt == 10) break;

		// SLEEP
		WaitForSingleObject((void*)this->Handle, 500);
	}


	///***** SEND MULTICAST PACKET ROUTINE *****///
	m_eThreadWork = THREAD_RUNNING;
	while(m_eThreadWork == THREAD_RUNNING) {

		m_socket_multicast.Send();
		FormMain->PringMsg(L"SEND MSG");
		WaitForSingleObject((void*)this->Handle, 100);
	}
}
//---------------------------------------------------------------------------

void __fastcall CThreadMulticast::ForceDisconnect() {
	m_eThreadWork = THREAD_STOP;
	Terminate();
}
//---------------------------------------------------------------------------
