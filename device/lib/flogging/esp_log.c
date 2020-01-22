/*
 * esp_log.c
 * Fake esp_log.h implementation for simulation purposes. Can redirect
 * log prints to our simulator.
 */

#include "esp_log.h"

void ESP_LOGI(char const* tag, char* format, ...) {
  return;
}

void ESP_LOGE(char const* tag, char* format, ...) {
  printf("Wololol\n");
  return;
}

void esp_log_buffer_hex(char const* tag, uint8_t* buffer, unsigned int buffer_len) {
  return;
}
