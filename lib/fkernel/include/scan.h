/*
 * scan.h
 * Definitions related to scanning procedure
 */

#pragma once

#include <stdint.h>

#define SCAN_LIMIT 20 // Scan is limited up to 100 different devices

struct device {
	uint8_t* dev_name; // Name of the device
	uint8_t* mac; // Mac address of the device
	uint8_t addr_type; // BLE addr type
	uint8_t clients_num; // Number of clients connected to that device
	uint8_t rssi; // Received signal strength indication
};
