/* LICENSE PLACEHOLDER */

#include "otx/otx.h"

int main() {
    {
        char *args[] = {"", "test", "3foo"};
        char *val;
        if (arg_to_str(3, args, "test", &val) != OTX_SUCCESS) { assert(0); }
        printf("%s\n", val);
    }

    {
        char *args[] = {"", "test", "3"};
        int16_t val;
        if (arg_to_int16(3, args, "test", &val) != OTX_SUCCESS) { assert(0); }
        printf("%d\n", val);
    }

    {
        char *args[] = {"", "test", "7.15"};
        float val;
        if (arg_to_float(3, args, "test", &val) != OTX_SUCCESS) { assert(0); }
        printf("%lf\n", val);
    }

    printf("\n");

    {
        char *args[] = {"", "test", "3foo"};
        char *val;
        if (arg_to_str_def(3, args, "test", &val, "def") != OTX_SUCCESS) { assert(0); }
        printf("%s\n", val);
    }

    {
        char *args[] = {"", "test", "3"};
        int16_t val;
        if (arg_to_int16_def(3, args, "test", &val, 0) != OTX_SUCCESS) { assert(0); }
        printf("%d\n", val);
    }

    {
        char *args[] = {"", "test", "7.15"};
        float val;
        if (arg_to_float_def(3, args, "test", &val, 0) != OTX_SUCCESS) { assert(0); }
        printf("%lf\n", val);
    }

    printf("\n");

    {
        char *args[] = {"", "test", "3foo"};
        char *val;
        if (arg_to_str_def(3, args, "testx", &val, "def val") != OTX_SUCCESS) { assert(0); }
        printf("%s\n", val);
    }

    {
        char *args[] = {"", "test", "3"};
        int16_t val;
        if (arg_to_int16_def(3, args, "testx", &val, 11) != OTX_SUCCESS) { assert(0); }
        printf("%d\n", val);
    }

    {
        char *args[] = {"", "test", "7.15"};
        float val;
        if (arg_to_float_def(3, args, "testx", &val, 99.99f) != OTX_SUCCESS) { assert(0); }
        printf("%lf\n", val);
    }

    printf("\n");

    {
        char *args[] = {"", "test", "3foo"};
        char *val;
        if (arg_to_str_def(3, args, "test|testx", &val, "def val") != OTX_SUCCESS) { assert(0); }
        printf("%s\n", val);
    }

    {
        char *args[] = {"", "test", "3"};
        int16_t val;
        if (arg_to_int16_def(3, args, "testx|test", &val, 11) != OTX_SUCCESS) { assert(0); }
        printf("%d\n", val);
    }

    {
        char *args[] = {"", "test", "7.15"};
        float val;
        if (arg_to_float_def(3, args, "testx|test", &val, 99.99f) != OTX_SUCCESS) { assert(0); }
        printf("%lf\n", val);
    }

    return 0;
}
