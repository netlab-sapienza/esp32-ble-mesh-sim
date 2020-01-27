/*
 * esp_log.c
 * Fake esp_log.h implementation for simulation purposes. Can redirect
 * log prints to our simulator.
 */

#include "esp_log.h"

void ESP_LOGI(char const* tag, char* format, ...) {
  va_list argp;
  va_start(argp, format);
  printf("[%s] ", tag);
  vprintf(format, argp);
  printf("\n");
  va_end(argp);
  return;
}

void ESP_LOGE(char const* tag, char* format, ...) {
  va_list argp;
  va_start(argp, format);
  printf("\033[0;31m");
  printf("[%s] ", tag);
  vprintf(format, argp);
  printf("\n");
  printf("\033[0m");
  va_end(argp);
  return;
}

void esp_log_buffer_hex(char const* tag, uint8_t* buffer, unsigned int buffer_len) {
  printf("[%s] ", tag);
  for(int i=0;i<buffer_len;++i) {
    printf("%02x", buffer[i]);
  }
  printf("\n");
  return;
}
