/* LICENSE PLACEHOLDER */

#include "otx/otx.h"

int main() {
    {
        char *args[] = {"", "test", "3"};
        int16_t val;
        if (arg_to_INT16(3, args, "test", &val) != OTX_SUCCESS) {assert(0);}
        printf("%d\n", val);
    }

    {
        char *args[] = {"", "test", "7.15"};
        float val;
        if (arg_to_FLOAT(3, args, "test", &val) != OTX_SUCCESS) {assert(0);}
        printf("%lf\n", val);
    }


    return 0;
}
