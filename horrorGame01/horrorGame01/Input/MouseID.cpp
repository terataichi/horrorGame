#include "MouseID.h"
#include <type_traits>

MouseID begin(MouseID)
{
    return MouseID::Left;
}

MouseID end(MouseID)
{
    return MouseID::Max;
}

MouseID operator++(MouseID& id)
{
    return id = static_cast<MouseID>(std::underlying_type<MouseID>::type(id) + 1);
}

MouseID operator*(MouseID key)
{
    return key;
}
