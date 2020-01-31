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

static void on_ipc_message_received(IPCMessage ipcMessage) {
  switch (ipcMessage) {
    case :
      break;

    case :
      break;
    case :
      break;

    default:
      throw
  }


};

MediumAccessInterface::MediumAccessInterface() = default;