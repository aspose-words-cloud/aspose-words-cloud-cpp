# <copyright company="Aspose" file="CMakeLists.h">
#   Copyright (c) 2018 Aspose.Words for Cloud
# </copyright>
# <summary>
#   Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
# 
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
# 
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
# </summary> 

cmake_minimum_required (VERSION 3.1 FATAL_ERROR)
#PROJECT's NAME
project(CppRestSwaggerClient CXX)
# THE LOCATION OF OUTPUT BINARIES
set(CMAKE_LIBRARY_DIR ${PROJECT_BINARY_DIR}/lib)
set(LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_DIR})

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
# BUILD TYPE
message("A ${CMAKE_BUILD_TYPE} build configuration is detected")
# Update require components as necessary
find_package(Boost 1.68.0 REQUIRED COMPONENTS thread system regex date_time program_options filesystem)

# TODO: ============================= Написать FindCppRest.cmake и использовать find_package(CppRest) ==========================
# build and set path to cpp rest sdk
set(CPPREST_ROOT ${PROJECT_SOURCE_DIR}/../thirdparty/cpprest)
set(CPPREST_INCLUDE_DIR ${CPPREST_ROOT}/include)
set(CPPREST_LIBRARY_DIR ${CPPREST_ROOT}/lib)
if( NOT DEFINED CPPREST_ROOT )
    message( FATAL_ERROR "Failed to find cpprest SDK (or missing components). Double check that \"CPPREST_ROOT\" is properly set")
endif( NOT DEFINED CPPREST_ROOT )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(../libs/gtest ${PROJECT_BINARY_DIR}/gtest)

#SUPPORTING FILES
set(SUPPORTING_FILES  "ApiClient" "ApiConfiguration" "ApiException" "HttpContent" "IHttpBody" "JsonBody" "ModelBase" "MultipartFormData" "Object")
#SOURCE FILES
file(GLOB SOURCE_FILES  "api/*"  "model/* "model/requests/*)

add_library(${PROJECT_NAME} ${SUPPORTING_FILES} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR} api model ${CPPREST_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# https://cmake.org/cmake/help/latest/module/FindBoost.html 
target_link_libraries(${PROJECT_NAME} Boost::boost Boost::thread Boost::system Boost::regex Boost::date_time Boost::program_options Boost::filesystem)

enable_testing()
add_subdirectory(../tests ${PROJECT_BINARY_DIR}/tests)