// 7 segment led display settings.
#define Decimal_Point 0x7F // 7 th(Port* of 7) bit should be zero if decimal point is required.
#define LCD_DISPLAY_OFF 0xFF
#define LCD_DISPLAY_ON 0x00
// Display selected digit on 7 segment led display.
#define LED_1 0x1
#define LED_2 0x2
#define LED_3 0x4
#define LED_4 0x8
// Display selected digit on 7 segment led display.
#define DIGIT_0 0x40
#define DIGIT_1 0x79
#define DIGIT_2 0x24
#define DIGIT_3 0x30
#define DIGIT_4 0x19
#define DIGIT_5 0x12
#define DIGIT_6 0x02
#define DIGIT_7 0x78
#define DIGIT_8 0x00
#define DIGIT_9 0x10

const unsigned char code DIGIT_MAP[10] = {
    DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4,
    DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9
};