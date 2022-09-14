#include <otx/otx.h>

namespace otx {

static bool initialized = false;
static int _argc;
static const char *const *_argv;

void init(int argc, const char *const argv[]) {
    initialized = true;
    _argc = argc;
    _argv = argv;
}

std::pair<int, const char *const *> getArgs() {
    if (!initialized) { throw otx::UninitializedError{}; }
    return {_argc, _argv};
}

}