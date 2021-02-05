#[[
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CMakeLists.txt">
*   Copyright (c) 2021 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/
]]

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(Aspose.Words.Cloud LANGUAGES CXX)

add_library(Words.Cloud)

file(GLOB_RECURSE srcs "*.h" "*.cpp")
target_sources(Words.Cloud PRIVATE ${srcs})
target_include_directories(Words.Cloud PUBLIC api model model/requests ${CMAKE_CURRENT_SOURCE_DIR})

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.68 REQUIRED COMPONENTS thread system regex date_time program_options filesystem)
find_package(cpprestsdk CONFIG REQUIRED)
target_link_libraries(Words.Cloud PUBLIC Boost::boost  Boost::thread Boost::system Boost::regex Boost::date_time Boost::program_options Boost::filesystem cpprestsdk::cpprest)
target_compile_definitions(Words.Cloud PUBLIC _TURN_OFF_PLATFORM_STRING BOOST_ALL_NO_LIB)
target_link_libraries(Words.Cloud PUBLIC $<$<CXX_COMPILER_ID:MSVC>:Bcrypt>)

if(MSVC)
  target_compile_options(Words.Cloud PRIVATE /bigobj)
endif()

if (COMMAND cotire)
    cotire(Words.Cloud)
endif()

add_library(Aspose::Words.Cloud ALIAS Words.Cloud)
