#include "mbed.h"

class LCD1602{
    public:
    LCD1602(PinName rs, PinName E , PinName D4, PinName D5, PinName D6, PinName D7);
    //ShiftRegister lcd(D11, D13, D10);

    void set_command_mode();
    void set_write_mode();
    void pulse_latch();
    void set_cursor(int row, int col);
    void write_char(char letter);
    void print_lcd(char *string, int beginrow, int begincol);
    void print(char*string, int beginrow, int begincol);
    void send_byte(uint8_t byte, bool is_data);
    void send_nibble(uint8_t nibble);
    void init();
    void shiftLCD(char value);
    private:
    DigitalOut _rs, _E, _D4, _D5, _D6,_D7;
    
    int _address;
};

class ShiftRegister {
public:
    ShiftRegister(PinName data, PinName clk, PinName latch);
    void shift_out(uint8_t value);
    void printSR(char* string);
    void write_SR(uint8_t letter);
    void set_cursor_RS(int row, int col);
    void send_command_RS(uint8_t value);
    void send_nibble(uint8_t nibble, bool rs);
    void init_RS();
    void clear();
private:
    DigitalOut _data;
    DigitalOut _clk;
    DigitalOut _latch;
};

