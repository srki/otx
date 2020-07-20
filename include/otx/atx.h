/* LICENSE PLACEHOLDER */

#ifndef OTX_ATX_H
#define OTX_ATX_H

#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

#include "common.h"

static int
arg_to_str(int argc, char *argv[], char *arg_name, char **arg_val) {
    int i;

    assert(argc % 2 == 1);

    for (i = 1; i < argc; i += 2) {
        if (strcmp(arg_name, argv[i]) == 0) {
            *arg_val = argv[i + 1];
            return OTX_SUCCESS;
        }
    }

    return OTX_NOT_FOUND;
}

static int
arg_to_str_def(int argc, char *argv[], char *arg_name, char **arg_val,
               char *default_val) {
    int ret_code;

    ret_code = arg_to_str(argc, argv, arg_name, arg_val);
    if (ret_code == OTX_SUCCESS) {
        return OTX_SUCCESS;
    }

    if (ret_code == OTX_NOT_FOUND) {
        *arg_val = default_val;
        return OTX_SUCCESS;
    }

    return OTX_INTERNAL_ERROR;
}

#define DEFINE_ATX(FN_NAME, TYPE, SCN)                                         \
static int                                                                     \
arg_to_##FN_NAME(int argc, char *argv[], char *arg_name, TYPE *arg_val) {      \
    int ret_code;                                                              \
    char *arg_val_str;                                                         \
                                                                               \
    ret_code = arg_to_str(argc, argv, arg_name, &arg_val_str);                 \
    if (ret_code != OTX_SUCCESS) {                                             \
        return ret_code;                                                       \
    }                                                                          \
                                                                               \
    ret_code = sscanf(arg_val_str, "%" SCN, arg_val);                          \
    if (ret_code != 1) {                                                       \
        return OTX_INCORRECT_FORMAT;                                           \
    }                                                                          \
                                                                               \
    return OTX_SUCCESS;                                                        \
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

DEFINE_ALL(DEFINE_ATX)

#pragma clang diagnostic pop

#undef DEFINE_ATX


#define DEFINE_ATX_DEF(FN_NAME, TYPE, SCN)                                     \
static int                                                                     \
arg_to_##FN_NAME##_def(int argc, char *argv[], char *arg_name, TYPE *arg_val,  \
               TYPE default_val) {                                             \
    int ret_code;                                                              \
                                                                               \
    ret_code = arg_to_##FN_NAME(argc, argv, arg_name, arg_val);                \
    if (ret_code == OTX_SUCCESS) {                                             \
        return OTX_SUCCESS;                                                    \
    }                                                                          \
                                                                               \
    if (ret_code == OTX_NOT_FOUND) {                                           \
        *arg_val = default_val;                                                \
        return OTX_SUCCESS;                                                    \
    }                                                                          \
                                                                               \
    return OTX_INTERNAL_ERROR;                                                 \
}

DEFINE_ALL(DEFINE_ATX_DEF)

#undef DEFINE_ATX_DEF

#endif //OTX_ATX_H
