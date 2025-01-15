#[[
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CMakeLists.txt">
*   Copyright (c) 2025 Aspose.Words for Cloud
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

cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(aspose_words_cloud_sdk LANGUAGES CXX)

find_package(OpenSSL REQUIRED)

add_library(aspose_words_cloud_sdk SHARED)
include_directories(${OPENSSL_INCLUDE_DIR})

file(GLOB_RECURSE srcs "../include/*.h" "*.cpp")
target_sources(aspose_words_cloud_sdk PRIVATE ${srcs})
target_link_libraries(aspose_words_cloud_sdk OpenSSL::Crypto)
target_link_libraries(aspose_words_cloud_sdk OpenSSL::SSL)
set_target_properties(aspose_words_cloud_sdk PROPERTIES CXX_STANDARD 17)
target_compile_features(aspose_words_cloud_sdk PRIVATE cxx_std_17)

if(MSVC)
  target_compile_options(aspose_words_cloud_sdk PRIVATE /bigobj)
endif()
