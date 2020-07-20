/* LICENSE PLACEHOLDER */

#ifndef OTX_COMMON_H
#define OTX_COMMON_H

typedef enum  {
    OTX_SUCCESS = 0,
    OTX_NOT_FOUND,
    OTX_INCORRECT_FORMAT,
    OTX_INTERNAL_ERROR
} OTX_code;

#define DEFINE_ALL(MACRO_NAME)              \
    MACRO_NAME(int8,   int8_t,   SCNd8)     \
    MACRO_NAME(int16,  int16_t,  SCNd16)    \
    MACRO_NAME(int32,  int32_t,  SCNd32)    \
    MACRO_NAME(int64,  int64_t,  SCNd64)    \
    MACRO_NAME(uint8,  uint8_t,  SCNu8)     \
    MACRO_NAME(uint16, uint16_t, SCNu16)    \
    MACRO_NAME(uint32, uint32_t, SCNu32)    \
    MACRO_NAME(uint64, uint64_t, SCNu64)    \
    MACRO_NAME(float,  float,    "f")       \
    MACRO_NAME(double, double,   "lf")      \

#endif //OTX_COMMON_H
