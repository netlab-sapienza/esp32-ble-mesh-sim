/*
 * kernel.c
 * This is the fake kernel implementation used by the simulator to mask all
 * esp behaviours
 */

#include "kernel.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t wants_to_discover;
uint8_t wants_to_send_routing_table;
uint8_t reset;

// kernel related calls
uint8_t write_CHR(uint16_t gattc_if, uint16_t conn_id, uint8_t chr, uint8_t* array, uint8_t len) { // Returns 1 if an error occurs, 0 otherwise
  return 0;
}

uint8_t* read_CHR(uint16_t gattc_if, uint16_t conn_id, uint8_t chr) {
  return 0;
}

uint8_t get_CHR_value_len(uint8_t chr) { // Get the lenght of the last read value of a characteristic
  return 0;
}

void gatt_client_main() { // Registration of an ESP client
  return 0;
}
void gatt_server_main() { // Registration of an ESP server
  return 0;
}


uint8_t notify_client(uint8_t conn_id, uint8_t chr, uint8_t* data, uint8_t data_size) { // Send notification to a client (conn_id) using a characteristic channel
  return 0;
}

void start_internal_client(uint8_t client) { // internal clients are SERVER_S1, SERVER_S2, SERVER_S3. This includes the registration
  return;
}


// SERVER / CLIENT FUNCTIONS
uint8_t** get_connected_MACS() { // List of all connected devices, either clients or servers
  return NULL;
}


uint8_t* get_connid_MAC(uint8_t conn_id) { // Returns the MAC of a connected device conn_id
  return NULL;
}

uint8_t get_MAC_connid(uint8_t* mac_addr) { // Returns the conn_id from a MAC of a connected device
  return 0;
}
uint8_t* get_my_MAC() { // Returns the MAC address of the device calling the function
  return NULL;
}
uint8_t MAC_check(uint8_t* mac1, uint8_t* mac2) { // 1 if mac1==mac2, 0 otherwise
  return 0;
}


uint8_t get_gatt_if() { //  Returns the interface of the device calling it, either server or client
  return 0;
}
uint8_t get_client_connid() { // Returns the conn_id that is assigned from the client to a server (if exists)
  return 0;
}
// Returns an array of 1 and 0. Position i has value 1 if i is an assigned conn_id, 0 otherwise.
// The array has length TOTAL_NUMBER_LIMIT. Use get_type_connection to know if a conn_id refers to a server or a client
uint8_t* get_server_connids() {
  return NULL;
}

uint8_t get_type_connection(uint8_t conn_id) { // Returns CLIENT or SERVER depending on the link with conn_id
  return 0;
}


// INTERNAL CLIENTS FUNCTIONS
// These functions have to be executed if the device is a server
// and the internal client of interest has been registered using register_internal_client(client_num);
// Client ids are: SERVER_S1, SERVER_S2, SERVER_S3
uint8_t get_internal_client_connid(uint8_t client_id) {
  return 0;
}

uint8_t get_internal_client_gattif(uint8_t client_id) {
  return 0;
}
uint8_t* get_internal_client_serverMAC(uint8_t client_id) { // Returns the MAC address of the server which is connected to
  return 0;
}
void unregister_internal_client(uint8_t client_num) {
  return 0;
}
						  


uint8_t connectTo(struct device dev,uint8_t flag_internal, uint8_t num_internal_client) { // Establish a connection with dev and returns 1 if an error eccurs, 0 otherwise. flag internal is 1 if an internal_client is calling it => set num_internal client. otherwise both parameters are 0.

  return 0;
}
// Mutation functions
void becomeServer() { // If no servers were found during the scanning let the client become a server.
  return 0;
}

uint8_t has_ended_scanning() {
  return 0;
}

/*
 * kernel handler for simulator purposes.
 * The function will act as event handler for
 * signals and pipes coming from the sim-core.
 */
void __kernel_handler(void) {
  return;
}


