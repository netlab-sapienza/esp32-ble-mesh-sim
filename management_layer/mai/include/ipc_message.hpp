/*
 * ipc_message.hpp
 */

#pragma once

class IPCMessage {
  // Message Type
  IPCMessageType m_type;
  // Source IPC uuid.
  int m_ipc_src;
public:
  IPCMessageType getType(void) const;
  int getSource(void) const;
};

class IPCScanRequest : protected IPCMessage {
public:
  IPCScanRequest(int t_uid) : m_type(SCAN_REQUEST),
			      m_ipc_src(t_uid);
};

class IPCScanResponse : protected IPCMessage {
  
public:
  IPCScanResponse(int t_uid) : m_type(SCAN_RESPONSE),
			       m_ipc_src(t_uid);
};

class IPCWriteChar : protected IPCMessage {
public:
  IPCWriteChar(int t_uid) : m_type(WRITE_MESSAGE),
			    m_ipc_src(t_uid);
};

class IPCReadChar : protected IPCMessage {
public:
  IPCReadChar(int t_uid) : m_type(READ_MESSAGE),
			   m_ipc_src(t_uid);
};

class IPCNotify : protected IPCMessage {
public:
  IPCNotify(int t_uid) : m_type(NOTIFY),
			 m_ipc_src(t_uid);
};

class IPCConnectRequest : protected IPCMessage {
public:
  IPCConnectRequest(int t_uid) : m_type(CONNECTION_REQUEST),
				 m_ipc_src(t_uid);
};

class IPCConnectResponse : protected IPCMessage {
public:
  IPCConnectResponse(int t_uid) : m_type(CONNECTION_RESPONSE),
				  m_ipc_src(t_uid);
};

enum IPCMessageType {
  SCAN_REQUEST,
  SCAN_RESPONSE,
  WRITE_MESSAGE,
  READ_MESSAGE,
  NOTIFY,
  CONNECTION_REQUEST,
  CONNECTION_RESPONSE
};
