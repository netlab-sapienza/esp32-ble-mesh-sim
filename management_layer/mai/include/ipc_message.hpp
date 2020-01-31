/*
 * ipc_message.hpp
 */

#pragma once

class IPCMessage {
public:
  virtual unserialize(std::istream& istr);
};

class IPCScanRequest : protected IPCMessage {

};

class IPCScanResponse : protected IPCMessage {

};

class IPCWrite : protected IPCMessage {

};

class IPCRead : protected IPCMessage {

};

class IPCNotify : protected IPCMessage {

};

class IPCConnectRequest : protected IPCMessage {

};

class IPCConnectAck : protected IPCMessage {

};
