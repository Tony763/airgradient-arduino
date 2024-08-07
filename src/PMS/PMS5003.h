#ifndef _AIR_GRADIENT_PMS5003_H_
#define _AIR_GRADIENT_PMS5003_H_

#include "../Main/BoardDef.h"
#include "PMS.h"
#include "Stream.h"

/**
 * @brief The class define how to handle PMS5003 sensor bas on @ref PMS class
 */
class PMS5003 {
public:
  PMS5003(BoardType def);
#if defined(ESP8266)
  bool begin(Stream *_debugStream);
#else
  bool begin(HardwareSerial &serial);
#endif
  void end(void);
  void handle(void);
  bool isFailed(void);
  int getPm01Ae(void);
  int getPm25Ae(void);
  int getPm10Ae(void);
  int getPm03ParticleCount(void);
  int convertPm25ToUsAqi(int pm25);
  int getFirmwareVersion(void);
  uint8_t getErrorCode(void);

private:
  bool _isBegin = false;
  int _ver;
  BoardType _boardDef;
  PMSBase pms;
  const BoardDef *bsp;
#if defined(ESP8266)
  Stream *_debugStream;
  const char *TAG = "PMS5003";
#else
  HardwareSerial *_serial;
#endif
  bool begin(void);
  bool isBegin(void);
};
#endif /** _AIR_GRADIENT_PMS5003_H_ */
