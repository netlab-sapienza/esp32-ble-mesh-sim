/*
 * fcallbacks.c
 */

#include "fcallbacks.h"

uint8_t install_NotifyCb(NotifyCb cb) { // Returns 0 on succes, 1 otherwise
  return 0;
}

uint8_t install_InitCb(InitCb cb) { //Same as above.
  return 0;
}

uint8_t install_ServerUpdateCb(ServerUpdateCb cb) { //Same as above
  return 0;
}

uint8_t install_ExchangeRoutingTableCb(ExchangeRoutingTableCb cb) { //Same as above
  return 0;
}

uint8_t install_ReceivedPacketCb(ReceivedPacketCb cb) { //Same as above
  return 0;
}

uint8_t install_ShutDownCb(ShutDownCb cb) { //Same as above
  return 0;
}

uint8_t install_SendRoutingTableCb(SendRoutingTableCb cb) { //Same as above.
  return 0;
}


uint8_t install_EndScanning(EndScanning cb) { // Triggered when the scan process of a client is over (including an internal_client)
  return 0;
}

uint8_t install_ServerLost(ServerLost cb) { // Triggered when the client is connected to a server and the connection is lost
  return 0;
}

uint8_t install_SSC_Active(SSC_Active cb) {
  return 0;
}

uint8_t install_SSC_Passive(SSC_Passive cb) {
  return 0;
}

uint8_t install_RetryCb(EndScanning cb) {
  return 0;
}

