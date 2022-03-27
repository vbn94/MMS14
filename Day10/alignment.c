#include <stdio.h>
#include <stdint.h>



struct str_b {
    int x;
    char y;
};


union A {
    unsigned short num;
    char byte[2];
};

union B {
    uint64_t qword;
    char byte[8];
};

union  C {
    double realNum;
    uint64_t mask;
};

union D {
    float realNum;
    uint32_t mask;
};

struct str_a {
    unsigned a : 3;   // bit-field
    unsigned b : 2;
};

struct counters {
    short cnt1 : 5;   // bit-field
    short cnt2 : 5;
    short cnt3 : 5;
    short cnt4 : 3;
};


typedef union {
    uint8_t byte;
    struct {
        uint8_t bit0 : 1;
        uint8_t bit1 : 1;
        uint8_t bit2 : 1;
        uint8_t bit3 : 1;
        uint8_t bit4 : 1;
        uint8_t bit5 : 1;
        uint8_t bit6 : 1;
        uint8_t bit7 : 1;
    } ;
} REG1;

typedef union {
    uint16_t word;
    struct {
        uint8_t byte0;
        uint8_t byte1;
    };
    struct {
        uint16_t bit0 : 1;
        uint16_t bit1 : 1;
        uint16_t bit2 : 1;
        uint16_t bit3 : 1;
        uint16_t bit4 : 1;
        uint16_t bit5 : 1;
        uint16_t bit6 : 1;
        uint16_t bit7 : 1;
        uint16_t bit8 : 1;
        uint16_t bit9 : 1;
        uint16_t bit10 : 1;
        uint16_t bit11 : 1;
        uint16_t bit12 : 1;
        uint16_t bit13 : 1;
        uint16_t bit14 : 1;
        uint16_t bit15 : 1;
    } ;
} REG2;

union vars {
    double rnum;
    int znum;
    char sym;
};


void printValue(union vars u, int type){
    if (type == 1){
        printf("%d", u.znum);
    } else if (type == 2){
        printf("%lf", u.rnum);
    } else if (type == 3){
        printf("%c", u.sym);
    }
}


int main(){

    REG2 myreg2;
    myreg2.word = 0xff00;
    myreg2.byte0 = 0xaa;
    myreg2.byte1 = 0xff;
    myreg2.bit0 = 1;
    myreg2.bit1= 0;
    REG1 myreg;
    myreg.bit0 = 1;
    myreg.bit1 = 0;
    myreg.bit2 = 0;
    myreg.bit3 = 1;
    myreg.bit4 = 0;
    myreg.bit5 = 1;
    myreg.bit6 = 0;
    myreg.bit7 = 1;
    
    printf("%x\n", myreg.byte);
    return 0;
}