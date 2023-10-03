
#ifndef YAPP_H
#define YAPP_H

#include <array>
#include <SFML/Graphics.hpp>

namespace YAPP{

    #define YAPP_DEF_RESOLUTION_X 800
    #define YAPP_DEF_RESOLUTION_Y 600

    enum YAPP_ERR{
        YAPP_OK,
        YAPP_MAP_LOADED,
        YAPP_MAP_LOAD_ERR,
        YAPP_INPUT_VALUE_ERR,
    };

}
#endif // YAPP_DISPLAY_H
