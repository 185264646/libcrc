#include "crc.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	unsigned char data[] = "1234";

	uint16_t ans = crc16(data, 4, 0x8005, 0, 0, 0, 0);
    printf("crc16(\"1234\", 4, 0x8005, 0, 0, 0, 0) = %#04hX\n", ans);
	assert(ans == 0xFD59);
	
	ans = crc16(data, 4, 0x8005, 0xFFFF, 0, 0, 0);
    printf("crc16(\"1234\", 4, 0x8005, 0xFFFF, 0, 0, 0) = %#04hX\n", ans);
	assert(ans == 0xFD7D);

	ans = crc16(data, 4, 0x8005, 0, 0xFFFF, 0, 0);
    printf("crc16(\"1234\", 4, 0x8005, 0, 0xFFFF, 0, 0) = %#04hX\n", ans);
	assert(ans == 0x02A6);

	ans = crc16(data, 4, 0x8005, 0, 0, 1, 0);
    printf("crc16(\"1234\", 4, 0x8005, 0, 0, 1, 0) = %#04hX\n", ans);
	assert(ans == 0x5D28);

	ans = crc16(data, 4, 0x8005, 0, 0, 0, 1);
    printf("crc16(\"1234\", 4, 0x8005, 0, 0, 0, 1) = %#04hX\n", ans);
	assert(ans == 0x9ABF);

	ans = crc16_xmodem(data, 4);
	printf("crc16_xmodem(\"1234\", 4) = %#04hX\n", ans);
	assert(ans == 0xD789);

	ans = crc16_ibm(data, 4);
	printf("crc16_ibm(\"1234\", 4) = %#04hX\n", ans);
	assert(ans == 0x14BA);

    return 0;
}
