project(radian_test LANGUAGES C)

include(FetchContent)

FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG db878ccaedaea3d07b3c5443a00d131ecacd30b3
)
FetchContent_MakeAvailable(unity)

file(
    COPY        ${CMAKE_CURRENT_SOURCE_DIR}/deadbeef.bin
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

include(RadianTest)
radian_test(read_be)
radian_test(read_le)
