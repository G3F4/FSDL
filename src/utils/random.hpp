#include <bits/stringfwd.h>

#ifndef RANDOM_HPP_DEFINE
#define RANDOM_HPP_DEFINE

#include <string>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n

static std::string random_string(int length) {
    auto randchar = []() -> char
    {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

#endif /* RANDOM_HPP_DEFINE */