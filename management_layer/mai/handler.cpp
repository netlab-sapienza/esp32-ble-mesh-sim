//
// Created by thecave3 on 31/01/20.
//

#include "handler.hpp"

/* Null, because instance will be initialized on demand. */
MediumAccessInterface *MediumAccessInterface::instance = nullptr;

MediumAccessInterface *MediumAccessInterface::getInstance() {
  if (instance == nullptr) {
    instance = new MediumAccessInterface();
  }

  return instance;
}

/**
 * <p>
 * Function responsible of understanding what is coming from an IPC.
 * After detecting its type, the message will be casted and
 * forwarded to the core.
 * </p>
 * @param ipcMessage message passed from the ipc
 */
static void on_ipc_message_received(IPCMessage ipcMessage) {
  switch (ipcMessage.getType()) {
  case IPCMessageType::SCAN_REQUEST:
    break;

  case IPCMessageType::SCAN_RESPONSE:
    break;

  case IPCMessageType::WRITE_CHAR:
    break;

  case IPCMessageType::READ_CHAR:
    break;

  case IPCMessageType::NOTIFY:
    break;

  case IPCMessageType::CONNECTION_REQUEST:
    break;

  case IPCMessageType::CONNECTION_RESPONSE:
    break;

  default:
    return;
  }
};

MediumAccessInterface::MediumAccessInterface() = default;