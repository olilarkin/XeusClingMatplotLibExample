#pragma cling add_include_path("/usr/local/include/python3.7m")
#pragma cling add_library_path("/usr/local/lib")
#pragma cling load("python3.7m")

#define WITHOUT_NUMPY 1
#include "matplotlib-cpp/matplotlibcpp.h"
#include "icst-audiofile/AudioFile.h"
#include "icst-audiofile/AudioFile.cpp"

namespace plt = matplotlibcpp;


#include <iostream>
#include <string>
#include <fstream>

#include "xtl/xbase64.hpp"
#include "xeus/xjson.hpp"

namespace im
{
    struct image
    {   
        inline image(const std::string& filename)
        {
            std::ifstream fin(filename, std::ios::binary);   
            m_buffer << fin.rdbuf();
        }
        
        std::stringstream m_buffer;
    };
    
    xeus::xjson mime_bundle_repr(const image& i)
    {
        auto bundle = xeus::xjson::object();
        bundle["image/png"] = xtl::base64encode(i.m_buffer.str());
        return bundle;
    }
}

namespace au
{
    struct audio
    {
        inline audio(const std::string& filename)
        {
            std::ifstream fin(filename, std::ios::binary);
            m_buffer << fin.rdbuf();
        }
        
        std::stringstream m_buffer;
    };
  
    xeus::xjson mime_bundle_repr(const audio& a)
    {
        auto bundle = xeus::xjson::object();
        bundle["text/html"] =
        std::string("<audio controls=\"controls\"><source src=\"data:audio/wav;base64,")
        + xtl::base64encode(a.m_buffer.str()) +
        "\" type=\"audio/wav\" /></audio>";
        return bundle;
    }
}

