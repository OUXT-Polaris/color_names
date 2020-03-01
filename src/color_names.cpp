#include <color_names/color_names.h>

namespace color_names
{
    std_msgs::msg::ColorRGBA makeColorMsg(std::string preset_name, double alpha)
    {
        std_msgs::msg::ColorRGBA c_msg;
        c_msg.a = alpha;
        if (c_msg.a < 0.) c_msg.a = 0.;
        if (c_msg.a > 1.) c_msg.a = 1.;

        auto found_itr = COLOR_NAME_DICT.find(preset_name);
        if (found_itr != COLOR_NAME_DICT.end())
        {
            c_msg.r = found_itr->second[0];
            c_msg.g = found_itr->second[1];
            c_msg.b = found_itr->second[2];
        }
        else
        {
            c_msg.r = 0;
            c_msg.g = 0;
            c_msg.b = 0;
        }
        return c_msg;
    }
}