/* LICENSE PLACEHOLDER */

#ifndef OTX_OTX_H
#define OTX_OTX_H

#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <exception>
#include <initializer_list>
#include <cassert>

/* region Exceptions */
namespace otx {
    class OtxException : public std::exception {};

    class NotFound : public OtxException {};

    class IncorrectFormat : public OtxException {};

    class InternalError : public OtxException {};
}
/*endregion */

/* region Private API */
namespace otx {
    namespace detail {
        std::string findArg(int argc, const char * const argv[], const std::initializer_list<const std::string> &argNames) {
            assert(argc % 2 == 1);
            for (int i = 1; i < argc; i += 2) {
                std::string arg{argv[i]};
                for (auto &argName : argNames) {
                    if (argName == arg) {
                        return std::string{argv[i + 1]};
                    }
                }
            }

            throw NotFound{};
        }
    }
}
/* endregion */

/* region public API */
namespace otx {

    void printArgs(int argc, const char * const argv[], std::ostream &os, const std::string &suffix = "\n") {
        for (int i = 0; i < argc; ++i) {
            os << argv[i] << " ";
        }
        std::cout << suffix;
    }

    template<class T>
    inline T
    argTo(int argc, const char * const argv[], const std::initializer_list<const std::string> &names) {
        auto argStr = detail::findArg(argc, argv, names);
        std::stringstream ss{argStr};

        T argValue;
        if (ss >> argValue && ss.eof()) {
            return argValue;
        }

        throw IncorrectFormat{};
    }

    template<class T>
    inline T
    argTo(int argc, const char * const argv[], const std::string &name) {
        return argTo<T>(argc, argv, {name});
    }

    template<class T>
    inline T
    argTo(int argc, const char * const argv[], const std::initializer_list<const std::string> &names, const T &defaultValue) {
        try {
            auto argValue = argTo<T>(argc, argv, names);
            return argValue;
        } catch (const NotFound &) {
            return defaultValue;
        }
    }

    template<class T>
    inline T
    argTo(int argc, const char * const argv[], const std::string &name, const T &defaultValue) {
        return argTo<T>(argc, argv, {name}, defaultValue);
    }

}
/* endregion */

#endif //OTX_OTX_H
