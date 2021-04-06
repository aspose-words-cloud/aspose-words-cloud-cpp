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

cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(aspose_words_cloud_test LANGUAGES CXX)

file(GLOB_RECURSE TEST_SOURCES *.cpp *.h)
add_executable(aspose_words_cloud_test ${TEST_SOURCES})
add_subdirectory(../thirdparty/gtest gtest)
target_link_libraries(aspose_words_cloud_test PRIVATE gtest aspose_words_cloud_sdk)
target_compile_definitions(aspose_words_cloud_test PRIVATE TEST_ROOT="${CMAKE_CURRENT_SOURCE_DIR}")
set_target_properties(aspose_words_cloud_test PROPERTIES CXX_STANDARD 17)

add_test(NAME aspose_words_cloud_test COMMAND aspose_words_cloud_test --gtest_output=xml:test_result.xml WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}) 

if (MSVC)
  set_property(TARGET aspose_words_cloud_test PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
  target_compile_options(aspose_words_cloud_test PRIVATE /bigobj)
endif()
