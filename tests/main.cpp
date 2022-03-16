/* LICENSE PLACEHOLDER */

#include <iostream>

#include <otx/otx.h>


int main(int argc, char *argv[]) {
    {
        otx::printArgs(argc, argv, std::cout);
    }

    {
        const char *args[] = {"", "test", "3foo"};
        otx::printArgs(3, args, std::cout);
    }

    std::cout << std::endl;

    {
        const char *args[] = {"", "test", "3foo"};
        auto val = otx::argTo<std::string>(3, args, "test");
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "3"};
        auto val = otx::argTo<int16_t>(3, args, "test");
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, "test");
        std::cout << val << std::endl;
    }

    std::cout << std::endl;

    {
        const char *args[] = {"", "test", "3foo"};
        auto val = otx::argTo<std::string>(3, args, "test", "def");
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "3"};
        auto val = otx::argTo<int16_t>(3, args, "test", -1);
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, "test", 3.14);
        std::cout << val << std::endl;
    }

    std::cout << std::endl;

    {
        const char *args[] = {"", "test", "3foo"};
        auto val = otx::argTo<std::string>(3, args, "testx", "def");
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "3"};
        auto val = otx::argTo<int16_t>(3, args, "testx", -1);
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, "testx", 3.14);
        std::cout << val << std::endl;
    }

    std::cout << std::endl;

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, {"test"}, 3.14);
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, {"testx"}, 3.14);
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, {"testx", "test"}, 3.14);
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, {"test", "testx"}, 3.14);
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "3foo"};
        auto val = otx::argTo<std::string>(3, args, {"test", "testx"});
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "3"};
        auto val = otx::argTo<int16_t>(3, args, {"test", "testx"});
        std::cout << val << std::endl;
    }

    {
        const char *args[] = {"", "test", "7.15"};
        auto val = otx::argTo<float>(3, args, {"test", "testx"});
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
    {
        try {
            const char *args[] = {"", "test", "3x"};
            auto val = otx::argTo<int16_t>(3, args, {"test", "testx"});
            std::cout << val << std::endl;
        } catch (const otx::IncorrectFormat &) {
            std::cout << "IncorrectFormat" << std::endl;
        }

    }

    {
        try {
            const char *args[] = {"", "test", "x3"};
            auto val = otx::argTo<int16_t>(3, args, {"test", "testx"});
            std::cout << val << std::endl;
        } catch (const otx::IncorrectFormat &) {
            std::cout << "IncorrectFormat" << std::endl;
        }
    }

}

