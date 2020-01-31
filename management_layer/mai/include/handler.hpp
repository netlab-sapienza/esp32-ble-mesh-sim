//
// Created by thecave3 on 31/01/20.
//

#ifndef ESP32_BLE_MESH_SIM_HANDLER_HPP
#define ESP32_BLE_MESH_SIM_HANDLER_HPP


/**
 * Singleton pattern of the MediumAccessInterface
 *
 * This class is created once and then shared between all the devices and it is responsible of the comm
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

enum IPCMessageType {
  SCAN_REQUEST,
  SCAN_RESPONSE,
  WRITE_MESSAGE,
  READ_MESSAGE,
  NOTIFY,
  CONNECTION_REQUEST,
  CONNECTION_RESPONSE
};


#endif //ESP32_BLE_MESH_SIM_HANDLER_HPP
