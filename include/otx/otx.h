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

class NotFound : public OtxException {
public:
    NotFound() = default;

    NotFound(const std::initializer_list<const std::string> &argNames) {
        _message = "Cannot find argument: ";
        for (auto it = argNames.begin(); it != argNames.end(); ++it) {
            if (it != argNames.begin()) {
                _message += " | ";
            }
            _message += *it;
        }
    }

    [[nodiscard]] const char *what() const noexcept override {
        return _message.empty() ? exception::what() : _message.c_str();
    }

protected:
    std::string _message{};
};

class IncorrectFormat : public OtxException {};

class InternalError : public OtxException {};

class UninitializedError : public OtxException {};

}
/*endregion */

/* region Private API */
namespace otx {
namespace detail {

std::string findArg(int argc, const char *const argv[], const std::initializer_list<const std::string> &argNames) {
    assert(argc % 2 == 1);
    for (int i = 1; i < argc; i += 2) {
        std::string arg{argv[i]};
        for (auto &argName: argNames) {
            if (argName == arg) {
                return std::string{argv[i + 1]};
            }
        }
    }

    throw NotFound{argNames};
}

}
}
/* endregion */

/* region public API */
namespace otx {

void printArgs(int argc, const char *const argv[], std::ostream &os, const std::string &suffix = "\n") {
    for (int i = 0; i < argc; ++i) {
        os << argv[i] << " ";
    }
    std::cout << suffix;
}

template<class T>
inline T argTo(int argc, const char *const argv[], const std::initializer_list<const std::string> &names) {
    auto argStr = detail::findArg(argc, argv, names);
    std::stringstream ss{argStr};

    T argValue;
    if (ss >> argValue && ss.eof()) {
        return argValue;
    }

    throw IncorrectFormat{};
}

template<class T>
inline T argTo(int argc, const char *const argv[], const std::string &name) {
    return argTo<T>(argc, argv, {name});
}

template<class T>
inline T argTo(int argc, const char *const argv[], const std::initializer_list<const std::string> &names,
               const T &defaultValue) {
    try {
        auto argValue = argTo<T>(argc, argv, names);
        return argValue;
    } catch (const NotFound &) {
        return defaultValue;
    }
}

template<class T>
inline T argTo(int argc, const char *const argv[], const std::string &name, const T &defaultValue) {
    return argTo<T>(argc, argv, {name}, defaultValue);
}

// Initialized

void init(int argc, const char *const argv[]);

void init(int argc, const char *const argv[], std::ostream &os, const std::string &suffix = "\n") {
    init(argc, argv);
    printArgs(argc, argv, os, suffix);
}

[[nodiscard]] std::pair<int, const char *const *> getArgs();

void printArgs(std::ostream &os, const std::string &suffix = "\n") {
    auto [argc, argv] = getArgs();
    printArgs(argc, argv, os, suffix);
}

template<class T>
inline T argTo(const std::initializer_list<const std::string> &names) {
    auto [argc, argv] = getArgs();
    return argTo<T>(argc, argv, names);
}

template<class T>
inline T argTo(const std::string &name) {
    auto [argc, argv] = getArgs();
    return argTo<T>(argc, argv, name);
}

template<class T>
inline T argTo(const std::initializer_list<const std::string> &names, const T &defaultValue) {
    auto [argc, argv] = getArgs();
    return argTo<T>(argc, argv, names, defaultValue);
}

template<class T>
inline T argTo(const std::string &name, const T &defaultValue) {
    auto [argc, argv] = getArgs();
    return argTo<T>(argc, argv, name, defaultValue);
}

}
/* endregion */

#endif //OTX_OTX_H
