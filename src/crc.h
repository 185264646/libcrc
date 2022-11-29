#include<stdbool.h>
#include<stdint.h>

#if defined(_WIN32)
#   define __export         __declspec(dllexport)
#elif defined(__GNUC__) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3))
#   define __export         __attribute__((visibility("default")))
#else
#   define __export
#endif

/*! calculate crc16(), this is a generic crc16 function, no table method is used
 *
 * @param data     points to data to calculate crc
 * @param len      data length
 * @param poly     polynomial
 * @param xorin    xorin
 * @param xorout   xorout
 * @param refin    refin
 * @param refout   refout
 *
 * @return      the result
 */
__export uint16_t crc16(const unsigned char *data, size_t len, uint16_t poly, uint16_t init, uint16_t xorout, bool refin, bool refout);

/*! calculate crc16_xmodem()
 * argument of CRC16_XMODEM:
 * poly: 0x1021
 * init: 0
 * xorout: 0
 * refin: false
 * refout: false
 *
 * @param data     points to data to calculate crc
 * @param len      data length
 *
 * @return      the result
 */
__export uint16_t crc16_xmodem(const unsigned char *data, size_t len);

/*! calculate crc16_ibm()
 * argument of CRC16_IBM:
 * poly: 0x8005
 * init: 0
 * xorout: 0
 * refin: true
 * refout:true
 *
 * @param data     points to data to calculate crc
 * @param len      data length
 *
 * @return      the result
 */
__export uint16_t crc16_ibm(const unsigned char *data, size_t len);
