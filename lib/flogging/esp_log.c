/*
 * esp_log.h
 * Fake esp_log.h implementation for simulation purposes. Can redirect
 * log prints to our simulator.
 */

#include "esp_log.h"

void ESP_LOGI(const char* tag, char* format, ...) {
  return;
}

void ESP_LOGE(const char* tag, char* format, ...) {
  return;
}

void esp_log_buffer_hex(const char* tag, uint8_t* buffer, unsigned int buffer_len) {
  return;
}
