#ifndef ESP32_BLE_COMBO_KEYBOARD_H
#define ESP32_BLE_COMBO_KEYBOARD_H
#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#if CONFIG_TINYUSB_HID_ENABLED
#include "class/hid/hid.h"
#include "class/hid/hid_device.h"
#else 
#include "hidKeys.h"
#endif

#include "BleConnectionStatus.h"
#include "BLEHIDDevice.h"
#include "BLECharacteristic.h"
#include "Print.h"

#ifndef KEY_LEFT_CTRL
#define CREATE_KEYREPORT 1
const uint8_t KEY_LEFT_CTRL = 0x80;
const uint8_t KEY_LEFT_SHIFT = 0x81;
const uint8_t KEY_LEFT_ALT = 0x82;
const uint8_t KEY_LEFT_GUI = 0x83;
const uint8_t KEY_RIGHT_CTRL = 0x84;
const uint8_t KEY_RIGHT_SHIFT = 0x85;
const uint8_t KEY_RIGHT_ALT = 0x86;
const uint8_t KEY_RIGHT_GUI = 0x87;

const uint8_t KEY_UP_ARROW = 0xDA;
const uint8_t KEY_DOWN_ARROW = 0xD9;
const uint8_t KEY_LEFT_ARROW = 0xD8;
const uint8_t KEY_RIGHT_ARROW = 0xD7;
const uint8_t KEY_BACKSPACE = 0xB2;
const uint8_t KEY_TAB = 0xB3;
const uint8_t KEY_RETURN = 0xB0;
const uint8_t KEY_ESC = 0xB1;
const uint8_t KEY_INSERT = 0xD1;
const uint8_t KEY_DELETE = 0xD4;
const uint8_t KEY_PAGE_UP = 0xD3;
const uint8_t KEY_PAGE_DOWN = 0xD6;
const uint8_t KEY_HOME = 0xD2;
const uint8_t KEY_END = 0xD5;
const uint8_t KEY_CAPS_LOCK = 0xC1;
const uint8_t KEY_F1 = 0xC2;
const uint8_t KEY_F2 = 0xC3;
const uint8_t KEY_F3 = 0xC4;
const uint8_t KEY_F4 = 0xC5;
const uint8_t KEY_F5 = 0xC6;
const uint8_t KEY_F6 = 0xC7;
const uint8_t KEY_F7 = 0xC8;
const uint8_t KEY_F8 = 0xC9;
const uint8_t KEY_F9 = 0xCA;
const uint8_t KEY_F10 = 0xCB;
const uint8_t KEY_F11 = 0xCC;
const uint8_t KEY_F12 = 0xCD;
const uint8_t KEY_F13 = 0xF0;
const uint8_t KEY_F14 = 0xF1;
const uint8_t KEY_F15 = 0xF2;
const uint8_t KEY_F16 = 0xF3;
const uint8_t KEY_F17 = 0xF4;
const uint8_t KEY_F18 = 0xF5;
const uint8_t KEY_F19 = 0xF6;
const uint8_t KEY_F20 = 0xF7;
const uint8_t KEY_F21 = 0xF8;
const uint8_t KEY_F22 = 0xF9;
const uint8_t KEY_F23 = 0xFA;
const uint8_t KEY_F24 = 0xFB;


// Power Control
#define CONSUMER_CONTROL_POWER                             0x0030
#define CONSUMER_CONTROL_RESET                             0x0031
#define CONSUMER_CONTROL_SLEEP                             0x0032

// Screen Brightness
#define CONSUMER_CONTROL_BRIGHTNESS_INCREMENT              0x006F
#define CONSUMER_CONTROL_BRIGHTNESS_DECREMENT              0x0070

// These HID usages operate only on mobile systems (battery powered) and
// require Windows 8 (build 8302 or greater).
#define CONSUMER_CONTROL_WIRELESS_RADIO_CONTROLS           0x000C
#define CONSUMER_CONTROL_WIRELESS_RADIO_BUTTONS            0x00C6
#define CONSUMER_CONTROL_WIRELESS_RADIO_LED                0x00C7
#define CONSUMER_CONTROL_WIRELESS_RADIO_SLIDER_SWITCH      0x00C8

// Media Control
#define CONSUMER_CONTROL_PLAY_PAUSE                        0x00CD
#define CONSUMER_CONTROL_SCAN_NEXT                         0x00B5
#define CONSUMER_CONTROL_SCAN_PREVIOUS                     0x00B6
#define CONSUMER_CONTROL_STOP                              0x00B7
#define CONSUMER_CONTROL_VOLUME                            0x00E0
#define CONSUMER_CONTROL_MUTE                              0x00E2
#define CONSUMER_CONTROL_BASS                              0x00E3
#define CONSUMER_CONTROL_TREBLE                            0x00E4
#define CONSUMER_CONTROL_BASS_BOOST                        0x00E5
#define CONSUMER_CONTROL_VOLUME_INCREMENT                  0x00E9
#define CONSUMER_CONTROL_VOLUME_DECREMENT                  0x00EA
#define CONSUMER_CONTROL_BASS_INCREMENT                    0x0152
#define CONSUMER_CONTROL_BASS_DECREMENT                    0x0153
#define CONSUMER_CONTROL_TREBLE_INCREMENT                  0x0154
#define CONSUMER_CONTROL_TREBLE_DECREMENT                  0x0155

// Application Launcher
#define CONSUMER_CONTROL_CONFIGURATION                     0x0183
#define CONSUMER_CONTROL_EMAIL_READER                      0x018A
#define CONSUMER_CONTROL_CALCULATOR                        0x0192
#define CONSUMER_CONTROL_LOCAL_BROWSER                     0x0194

// Browser/Explorer Specific
#define CONSUMER_CONTROL_SEARCH                            0x0221
#define CONSUMER_CONTROL_HOME                              0x0223
#define CONSUMER_CONTROL_BACK                              0x0224
#define CONSUMER_CONTROL_FORWARD                           0x0225
#define CONSUMER_CONTROL_BR_STOP                           0x0226
#define CONSUMER_CONTROL_REFRESH                           0x0227
#define CONSUMER_CONTROL_BOOKMARKS                         0x022A

// Mouse Horizontal scroll
#define CONSUMER_CONTROL_PAN                               0x0238

#endif

// Keep the old key definitions for backwards capability
const uint8_t KEY_PRTSC = 0xCE;
const uint8_t KEY_NUM_0 = 0xEA;
const uint8_t KEY_NUM_1 = 0xE1;
const uint8_t KEY_NUM_2 = 0xE2;
const uint8_t KEY_NUM_3 = 0xE3;
const uint8_t KEY_NUM_4 = 0xE4;
const uint8_t KEY_NUM_5 = 0xE5;
const uint8_t KEY_NUM_6 = 0xE6;
const uint8_t KEY_NUM_7 = 0xE7;
const uint8_t KEY_NUM_8 = 0xE8;
const uint8_t KEY_NUM_9 = 0xE9;
const uint8_t KEY_NUM_SLASH = 0xDC;
const uint8_t KEY_NUM_ASTERISK = 0xDD;
const uint8_t KEY_NUM_MINUS = 0xDE;
const uint8_t KEY_NUM_PLUS = 0xDF;
const uint8_t KEY_NUM_ENTER = 0xE0;
const uint8_t KEY_NUM_PERIOD = 0xEB;
typedef uint8_t MediaKeyReport[2];

const MediaKeyReport KEY_MEDIA_NEXT_TRACK = {1, 0};
const MediaKeyReport KEY_MEDIA_PREVIOUS_TRACK = {2, 0};
const MediaKeyReport KEY_MEDIA_STOP = {4, 0};
const MediaKeyReport KEY_MEDIA_PLAY_PAUSE = {8, 0};
const MediaKeyReport KEY_MEDIA_MUTE = {16, 0};
const MediaKeyReport KEY_MEDIA_VOLUME_UP = {32, 0};
const MediaKeyReport KEY_MEDIA_VOLUME_DOWN = {64, 0};
const MediaKeyReport KEY_MEDIA_WWW_HOME = {128, 0};
const MediaKeyReport KEY_MEDIA_LOCAL_MACHINE_BROWSER = {0, 1}; // Opens "My Computer" on Windows
const MediaKeyReport KEY_MEDIA_CALCULATOR = {0, 2};
const MediaKeyReport KEY_MEDIA_WWW_BOOKMARKS = {0, 4};
const MediaKeyReport KEY_MEDIA_WWW_SEARCH = {0, 8};
const MediaKeyReport KEY_MEDIA_WWW_STOP = {0, 16};
const MediaKeyReport KEY_MEDIA_WWW_BACK = {0, 32};
const MediaKeyReport KEY_MEDIA_CONSUMER_CONTROL_CONFIGURATION = {0, 64}; // Media Selection
const MediaKeyReport KEY_MEDIA_EMAIL_READER = {0, 128};

#ifdef CREATE_KEYREPORT
//  Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
} KeyReport;
#endif
enum BLEConnectionMode {KEYBOARD_MEDIA_MOUSE_MODE, MEDIA_MODE};

class BleComboKeyboard : public Print
{
private:
  BleConnectionStatus* connectionStatus;
  BLEHIDDevice* hid;
  BLECharacteristic* inputKeyboard;
  BLECharacteristic* outputKeyboard;
  BLECharacteristic* inputMediaKeys;
  
  KeyReport _keyReport;
  MediaKeyReport _mediaKeyReport;
  static void taskServer(void* pvParameter);

public:
  BleComboKeyboard(std::string deviceName = "ESP32 Keyboard/Mouse", std::string deviceManufacturer = "Espressif", uint8_t batteryLevel = 100);
  void begin(void);
  void end(void);
  void sendReport(KeyReport* keys);
  void sendReport(MediaKeyReport* keys);
  size_t press(uint8_t k);
  size_t press(const MediaKeyReport k);
  size_t release(uint8_t k);
  size_t release(const MediaKeyReport k);
  size_t write(uint8_t c);
  size_t write(const MediaKeyReport c);
  size_t write(const uint8_t *buffer, size_t size);
  
  void releaseAll(void);
  bool isConnected(void);
  void setBatteryLevel(uint8_t level);
  uint8_t batteryLevel;
  std::string deviceManufacturer;
  std::string deviceName;

  BLECharacteristic* inputMouse;
  
  BLEConnectionMode bleConnectionMode = KEYBOARD_MEDIA_MOUSE_MODE;
};

#endif // CONFIG_BT_ENABLED
#endif // ESP32_BLE_COMBO_KEYBOARD_H
