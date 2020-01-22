/*
 * fcallbacks.h
 */

#pragma once
#include <stdint.h>


/****** SERVER - SERVER COMMUNICATION [SSC]
 * 	ACTIVE: internal_client connects to a server: can perform a write_chr / read_chr
 *  PASSIVE: server has a new internal_client connected: can only perform a notification
*******/

typedef void(*SSC_Active)(uint8_t internal_client_id); // internal_client_id is the client calling the cb, can be SERVER_S1 / S2 / S3
typedef void(*SSC_Passive)(uint8_t conn_id); // conn_id is the connection id given by the server to the new internal_client

typedef void(*NotifyCb)(uint16_t,uint8_t,uint8_t,uint8_t*,uint8_t);
typedef void(*InitCb)(uint8_t);
typedef void(*ShutDownCb)(uint8_t);
//This callback function pass the newly updated MAC table entry to the master object.
typedef void(*ServerUpdateCb)(uint8_t*,uint8_t,uint16_t,uint8_t,uint8_t);
//This callback function is triggered whenever two servers meet for the first time so that they
//can exchange their routing tables.
typedef void(*ExchangeRoutingTableCb)(uint8_t*,uint8_t*,uint16_t,uint8_t);
typedef void (*SendRoutingTableCb)(uint8_t*,uint8_t*,uint16_t,uint8_t,uint8_t);
typedef void(*ReceivedPacketCb)(uint8_t* packet,uint16_t len);

typedef void(*EndScanning)(struct device* list, uint8_t scan_seq,uint8_t internal_flag,
                                uint8_t server_id); // Returns details of nearby devices
typedef void(*ServerLost)();


// CALLBACKS
uint8_t install_NotifyCb(NotifyCb cb); // Returns 0 on succes, 1 otherwise
uint8_t install_InitCb(InitCb cb); //Same as above.
uint8_t install_ServerUpdateCb(ServerUpdateCb cb); //Same as above
uint8_t install_ExchangeRoutingTableCb(ExchangeRoutingTableCb cb); //Same as above
uint8_t install_ReceivedPacketCb(ReceivedPacketCb cb); //Same as above
uint8_t install_ShutDownCb(ShutDownCb cb); //Same as above
uint8_t install_SendRoutingTableCb(SendRoutingTableCb cb); //Same as above.

uint8_t install_EndScanning(EndScanning cb); // Triggered when the scan process of a client is over (including an internal_client)
uint8_t install_ServerLost(ServerLost cb); // Triggered when the client is connected to a server and the connection is lost

uint8_t install_SSC_Active(SSC_Active cb);
uint8_t install_SSC_Passive(SSC_Passive cb);

uint8_t install_RetryCb(EndScanning cb);
