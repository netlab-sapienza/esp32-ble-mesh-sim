/*
 * esp_log.h
 * Fake esp_log.h implementation for simulation purposes. Can redirect
 * log prints to our simulator.
 */

#pragma once

#include <stdio.h>
#include <stdint.h>

#define GATTC_TAG "GATT_CLIENT"
#define GATTS_TAG "GATT_CLIENT"

void ESP_LOGI(const char* tag, char* format, ...);
void ESP_LOGE(const char* tag, char* format, ...);
void esp_log_buffer_hex(const char* tag, uint8_t* buffer, unsigned int buffer_len);
