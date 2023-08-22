#include <stdio.h> 
#include <ctype.h>
#include <string.h>

unsigned short calculateCRC16(const unsigned char *buf, long int len)
{
#define CRC16_MASK  0xFFFF
    static unsigned short crc_16_table[16] = 
    {   0x0000, 0xcc01, 0xD801, 0x1400,
        0xF001, 0x3C00, 0x2800, 0xE401,
        0xA001, 0x6C00, 0x7800, 0xB401,
        0x5000, 0x9C01, 0x8801, 0x4400 
    };

    unsigned short wCRC = (unsigned short) CRC16_MASK;
    for (long int i = 0; i < len; ++i)
    {   unsigned char ch = buf[i];
        wCRC = (unsigned short) (  crc_16_table[(ch ^ wCRC) & 15] ^((wCRC & CRC16_MASK) >> 4));
        wCRC = (unsigned short) (  crc_16_table[((ch >> 4) ^ wCRC) & 15] ^ ((wCRC & CRC16_MASK) >> 4));
    }
    
    return wCRC;
}


unsigned short crc16LookUpTable(const unsigned char *buf,  int len) 
{ 
    static unsigned short crc_16_table[16] = 
    {   0x0000, 0xcc01, 0xD801, 0x1400,
        0xF001, 0x3C00, 0x2800, 0xE401,
        0xA001, 0x6C00, 0x7800, 0xB401,
        0x5000, 0x9C01, 0x8801, 0x4400 
    };
 
    unsigned short int CRC16 = 0xFFFF; //start
    unsigned short int r;
 
    // while there is more data to process 
 
    for (; len > 0; --len, ++buf) 
    {    
        // compute checksum of lower four bits of *buf 
        r = crc_16_table[CRC16 & 0xF];
        CRC16 = (CRC16 >> 4) & 0x0FFF;
        CRC16 = CRC16 ^ r ^ crc_16_table[*buf & 0xF];
        
        /* now compute checksum of upper four bits of *buf */
        r = crc_16_table[CRC16 & 0xF];
        CRC16 = (CRC16 >> 4) & 0x0FFF;
        CRC16 = CRC16 ^ r ^ crc_16_table[(*buf >> 4) & 0xF];
    }
    
    return(CRC16);
}

void main(void)
{
    const char *test = "test abc 12344567";    
    unsigned short r1 = calculateCRC16( (const unsigned char*)test, strlen(test));
    unsigned short r2 = crc16LookUpTable( (const unsigned char*)test, strlen(test));
    printf ( "output: r1=%x, r2=%x\n", r1, r2);
}

