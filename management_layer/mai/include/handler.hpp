//
// Created by thecave3 on 31/01/20.
//

#ifndef ESP32_BLE_MESH_SIM_HANDLER_HPP
#define ESP32_BLE_MESH_SIM_HANDLER_HPP

#include "ipc_message.hpp"

/**
 * Singleton pattern of the MediumAccessInterface
 *
 * This class is created once and then shared between all the devices and it is
 * responsible of the communication between the single devices and the core of
 * the simulator.
 *
 */
class MediumAccessInterface {
private:
  /* Here will be the instance stored. */
  static MediumAccessInterface *instance;

  /* Private constructor to prevent instancing. */
  MediumAccessInterface();

public:
  /* Static access method. */
  static MediumAccessInterface *getInstance();
};

#endif // ESP32_BLE_MESH_SIM_HANDLER_HPP
