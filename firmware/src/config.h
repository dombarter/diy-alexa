// WiFi credentials
#define WIFI_SSID "The Vicarage"
#define WIFI_PSWD "happyhouse"

// are you using an I2S microphone - comment this out if you want to use an analog mic and ADC input
#define USE_I2S_MIC_INPUT

// I2S Microphone Settings

// Which channel is the I2S microphone on? I2S_CHANNEL_FMT_ONLY_LEFT or I2S_CHANNEL_FMT_ONLY_RIGHT
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_RIGHT
// #define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_RIGHT
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_14
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_15
#define I2S_MIC_SERIAL_DATA GPIO_NUM_32

// Analog Microphone Settings - ADC1_CHANNEL_7 is GPIO35
#define ADC_MIC_CHANNEL ADC1_CHANNEL_7

// speaker settings
#define I2S_SPEAKER_SERIAL_CLOCK GPIO_NUM_17
#define I2S_SPEAKER_LEFT_RIGHT_CLOCK GPIO_NUM_21
#define I2S_SPEAKER_SERIAL_DATA GPIO_NUM_16

// command recognition settings
#define COMMAND_RECOGNITION_ACCESS_KEY "A6NWMFSVFJ6436HLCKK3Y7OZ7YHWGB2Q"
