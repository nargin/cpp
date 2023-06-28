#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    std::string something;
    std::string doesnt;
    std::string exist;
    std::string supreme;
    std::string power;
};

struct Serializer
{
    static uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); };
    static Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw);};
};