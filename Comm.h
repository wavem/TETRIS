#include "Main.h"
//---------------------------------------------------------------------------
#ifndef CommH
#define CommH
//---------------------------------------------------------------------------

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <mswsock.h>
#pragma link "Ws2_32.lib"


#define MULTICAST_GROUP_IP "224.224.224.224"
#define MULTICAST_GROUP_PORT 11111

enum ThreadWorkingType {
	THREAD_STOP = 0,
	THREAD_RUNNING = 1,
	THREAD_TERMINATED = 2,
};
//---------------------------------------------------------------------------

class CSocketMulticast {

private:
    SOCKET m_sock;

public:

	CSocketMulticast();
	~CSocketMulticast();
	bool __fastcall Open();
	int __fastcall Send();
	struct sockaddr_in m_st_multicast_group_socket;
};
//---------------------------------------------------------------------------

class CThreadMulticast : public TThread {
private:
	CSocketMulticast m_socket_multicast;
	ThreadWorkingType m_eThreadWork;

public:
	CThreadMulticast();
	__fastcall ~CThreadMulticast();

	void __fastcall Execute();
	void __fastcall ForceDisconnect();
	void __fastcall Stop();
	ThreadWorkingType __fastcall GetThreadStatus();
};
//---------------------------------------------------------------------------











//---------------------------------------------------------------------------
#endif
