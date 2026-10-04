# VAYUDEX Hardware Master Pinout

| ESP32-S3 GPIO | Bus / Signal | Connected Peripheral | Electrical Details |
| :--- | :--- | :--- | :--- |
| **GPIO 14** | SD_CLK | MicroSD Card Socket | 1-Bit SDMMC Clock (33 Ohm series damping) |
| **GPIO 15** | SD_CMD | MicroSD Card Socket | 1-Bit SDMMC Command (10k pull-up to 3.3V) |
| **GPIO 2** | SD_DAT0 | MicroSD Card Socket | 1-Bit SDMMC Data line (10k pull-up to 3.3V) |
| **GPIO 3** | SD_CD | MicroSD Card Socket | Card Detect (Active Low interrupt) |
| **GPIO 13** | SPI_SCK | Display / CC1101 / PN532 | Shared Master SPI Clock |
| **GPIO 11** | SPI_MOSI | Display / CC1101 / PN532 | Shared Master SPI Data Out |
| **GPIO 12** | SPI_MISO | CC1101 / PN532 | Shared Master SPI Data In |
| **GPIO 6** | TFT_CS | ST7796 3.5" IPS Display | Dedicated Chip Select (Active Low) |
| **GPIO 7** | TFT_DC | ST7796 3.5" IPS Display | Data / Command Select line |
| **GPIO 47** | TFT_RST | ST7796 3.5" IPS Display | Hardware Reset |
| **GPIO 1** | TFT_BL | Display Backlight Circuit | PWM brightness control via 2N7002 MOSFET |
| **GPIO 4** | CC1101_CS | TI CC1101 RF Transceiver | Dedicated Chip Select (10k pull-up to 3.3V) |
| **GPIO 10** | CC1101_GDO0| TI CC1101 RF Transceiver | Async raw pulse interrupt input |
| **GPIO 5** | PN532_CS | PN532 NFC Breakout | Dedicated Chip Select (10k pull-up to 3.3V) |
| **GPIO 16** | RFID_RX | RDM6300 125kHz Reader | UART RX (9600 baud serial stream) |
| **GPIO 8** | IR_TX | 940nm IR Transmitter | 38kHz PWM modulated via 2N2222 NPN driver |
| **GPIO 9** | IR_RX | TSOP38238 Receiver | 38kHz demodulated active-low input |
| **GPIO 18** | USB_D- | USB Type-C OTG | Native USB Full-Speed (BadUSB engine) |
| **GPIO 19** | USB_D+ | USB Type-C OTG | Native USB Full-Speed (BadUSB engine) |
| **GPIO 35-38**| D-PAD | UP, DOWN, LEFT, RIGHT | Tactile buttons (Active Low, 100nF debounce) |
| **GPIO 39-42**| ABXY | A, B, X, Y Action Keys | Tactile buttons (Active Low, 100nF debounce) |
| **GPIO 48** | BATT_STAT | AP2112K LDO / TP4056 | Power good & low battery voltage alert |
