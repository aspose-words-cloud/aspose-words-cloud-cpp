include(GoogleTest)
#################
#Unit Tests
#################
add_executable(runUnitTests oauthtest.cpp)

target_link_libraries(runUnitTests gtest)
target_link_libraries(runUnitTests CppRestSwaggerClient)
target_link_libraries(runUnitTests Boost::boost)

#set(CREDS_PATH  ${CMAKE_CURRENT_BINARY_DIR}/servcreds.json)
#configure_file(servcreds.json ${CREDS_PATH})

#target_sources(runUnitTests PUBLIC ${CREDS_PATH})

#add_custom_command(TARGET runUnitTests POST_BUILD 
#COMMAND ${CMAKE_COMMAND} -E copy ${CREDS_PATH} $<TARGET_FILE_DIR:runUnitTests>)

gtest_discover_tests(runUnitTests)