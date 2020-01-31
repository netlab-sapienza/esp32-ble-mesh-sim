/*
 * ipc_message.hpp
 */

#pragma once

class IPCMessage {
public:

};

class IPCScanRequest : protected IPCMessage {

};

class IPCScanResponse : protected IPCMessage {

};

class IPCWriteChar : protected IPCMessage {

};

class IPCReadChar : protected IPCMessage {

};

class IPCNotify : protected IPCMessage {

};

class IPCConnectRequest : protected IPCMessage {

};

class IPCConnectResponse : protected IPCMessage {

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