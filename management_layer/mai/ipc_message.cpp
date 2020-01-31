/*
 * ipc_message.cpp
 */

#include "ipc_message.hpp"

IPCMessageType IPCMessage::getType(void) const {
  return m_type;
}

int IPCMessage::getSource(void) const {
  return m_ipc_src;
}
