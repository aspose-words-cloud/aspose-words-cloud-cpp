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

project(tests CXX)
file(GLOB TEST_SOURCES *.cpp api/*.cpp TestBase.h)
add_executable(words-cloud-test ${TEST_SOURCES})
add_subdirectory(../thirdparty/gtest gtest)
target_link_libraries(words-cloud-test PRIVATE gtest Aspose::Words.Cloud)

target_compile_definitions(words-cloud-test PRIVATE TEST_ROOT="${CMAKE_CURRENT_SOURCE_DIR}")

add_test(NAME words-cloud-test COMMAND words-cloud-test --gtest_output=xml:test_result.xml) 

if (MSVC)
  set_property(TEST words-cloud-test PROPERTY ENVIRONMENT "PATH=${DLL_ROOT_DEBUG};$ENV{PATH}")

  if (MSVC_IDE)
    configure_file(custom.user.props custom.user.props @ONLY)
    set_property(TARGET words-cloud-test PROPERTY VS_USER_PROPS "${CMAKE_CURRENT_BINARY_DIR}/custom.user.props")
  endif()
endif()
