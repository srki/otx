/* LICENSE PLACEHOLDER */

#ifndef OTX_COMMON_H
#define OTX_COMMON_H

#define OTX_SUCCESS 0
#define OTX_NOT_FOUND 1
#define OTX_INCORRECT_FORMAT 2

#define DEFINE_ALL(MACRO_NAME)              \
    MACRO_NAME(INT8,   int8_t,   SCNd8)     \
    MACRO_NAME(INT16,  int16_t,  SCNd16)    \
    MACRO_NAME(INT32,  int32_t,  SCNd32)    \
    MACRO_NAME(INT64,  int64_t,  SCNd64)    \
    MACRO_NAME(UINT8,  uint8_t,  SCNu8)     \
    MACRO_NAME(UINT16, uint16_t, SCNu16)    \
    MACRO_NAME(UINT32, uint32_t, SCNu32)    \
    MACRO_NAME(UINT64, uint64_t, SCNu64)    \
    MACRO_NAME(FLOAT,  float,    "f")       \
    MACRO_NAME(DOUBLE, double,   "lf")      \

#endif //OTX_COMMON_H
