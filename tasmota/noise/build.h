// copy to user_config_override.h

#if !defined(FIRMWARE_SAFEBOOT) && !defined(FIRMWARE_MINIMAL)


// ### ### ###
// ### ### ###
// changes 2025.01.25



#ifdef ESP32
#undef USE_ENHANCED_GUI_WIFI_SCAN // do not work here
#undef USE_4K_RSA
#define USE_4K_RSA
#endif



#define USE_INFLUXDB
#define USE_UNISHOX_COMPRESSION

#undef INFLUXDB_INITIAL       // it need to be
#define INFLUXDB_INITIAL 30   // fixed in driver too

// ### ### ###
// tasmota-4M

#ifdef ESP8266
#define USE_UFILESYS
#define UFSYS_SIZE 5900
#define GUI_TRASH_FILE
#define GUI_EDIT_FILE
#endif

// ### ### ###
// user_config_override.h
// sml configs

#undef USE_RULES
#define USE_SCRIPT


// misc

#if defined(USE_SCRIPT)
#define USE_SCRIPT_WEB_DISPLAY
#define USE_GOOGLE_CHARTS
#define USE_SCRIPT_JSON_EXPORT
#define MAXVARS 58
#define MAXSVARS 21
#define MAXFILT 5
#define USE_SCRIPT_FATFS_EXT
#endif

#if defined(ESP32) && defined(USE_SCRIPT)
#define LARGE_ARRAYS
#define SCRIPT_LARGE_VNBUFF
#define SCRIPT_MAXSSIZE 128
#define USE_FEXTRACT
#undef MAXVARS
#define MAXVARS 100
#undef MAXSVARS
#define MAXSVARS 50
#undef MAXFILT
#define MAXFILT 10
#endif



// Default Configs

#undef  APP_TIMEZONE
#define APP_TIMEZONE 99

#undef  TIME_DST_HEMISPHERE
#define TIME_DST_HEMISPHERE    0
#undef  TIME_DST_WEEK
#define TIME_DST_WEEK          0
#undef  TIME_DST_MONTH
#define TIME_DST_MONTH         3
#undef  TIME_DST_DAY
#define TIME_DST_DAY           1
#undef  TIME_DST_HOUR
#define TIME_DST_HOUR          1
#undef  TIME_DST_OFFSET
#define TIME_DST_OFFSET        60

#undef  TIME_STD_HEMISPHERE
#define TIME_STD_HEMISPHERE    0
#undef  TIME_STD_WEEK
#define TIME_STD_WEEK          0
#undef  TIME_STD_MONTH
#define TIME_STD_MONTH         10
#undef  TIME_STD_DAY
#define TIME_STD_DAY           1
#undef  TIME_STD_HOUR
#define TIME_STD_HOUR          2
#undef  TIME_STD_OFFSET
#define TIME_STD_OFFSET        0

// clang-format off

#if defined(ESP8266)
#undef USER_BACKLOG
#define USER_BACKLOG "WebLog 2; Sleep 75; WifiPower 15; Template {\"NAME\":\"e5.easyhan.pt\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}; Module 0; SaveData 9; SerialLog 0; WifiConfig 2; Script 1"
//
#elif defined(HAN_C6_HW51) || defined(HAN_C6_HW50)
#define USER_BACKLOG "WebLog 2; Sleep 75; WifiPower 15; Template {\"NAME\":\"hw5x.c6.easyhan.pt\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1}; Module 0; SaveData 9; WifiConfig 2; Script 1"
//
#elif defined(HAN_S3_ETH)
#define USER_BACKLOG "WebLog 4; Sleep 50; WifiPower 15; Template {\"NAME\":\"eth.s3.easyhan.pt\",\"GPIO\":[1,4704,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,672,5536,704,736,5568,5600,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1}; Module 0; SaveData 9; WifiConfig 2; EthType 8; Script 1"
//
#else
#define USER_BACKLOG "WebLog 2; Sleep 75; WifiPower 15; Module 0; SaveData 9; WifiConfig 2; Script 1"
#endif

// clang-format on

#undef TELE_PERIOD
#define TELE_PERIOD 31

#undef MQTT_TOPIC
#define MQTT_TOPIC "edpbox99"

#undef WIFI_DEFAULT_HOSTNAME
#define WIFI_DEFAULT_HOSTNAME "Easy-HAN-EB99"

#undef MQTT_CLIENT_ID
#define MQTT_CLIENT_ID "Easy_HAN_%06X"

#undef MQTT_USER
#define MQTT_USER "none"

#undef MQTT_PASS
#define MQTT_PASS "none"



#endif // ! FIRMWARE_SAFEBOOT ! FIRMWARE_MINIMAL

// EOF
