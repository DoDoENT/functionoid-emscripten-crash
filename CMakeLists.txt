cmake_minimum_required(VERSION 3.10)

project( functionoid )

add_compile_options(
    -fstrict-aliasing
    $<$<COMPILE_LANGUAGE:CXX>:-fstrict-enums>
    -fvisibility=hidden
    $<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>
    -fPIC
    -flto
    -fwhole-program-vtables
    $<$<COMPILE_LANGUAGE:CXX>:-std=gnu++2a>
    $<$<NOT:$<COMPILE_LANGUAGE:CXX>>:-std=gnu11>
    -fno-threadsafe-statics
    -fno-rtti
    -fomit-frame-pointer
    -ffunction-sections
    -fmerge-all-constants
    -fno-stack-protector
    -Wall
    -Wextra
    -Wstrict-aliasing
    "SHELL:-s WASM=1"
)

add_executable( ftest main.cpp )
target_include_directories( ftest PRIVATE ${CMAKE_CURRENT_LIST_DIR}/functionoid/include ${CMAKE_CURRENT_LIST_DIR}/config_ex/include ${CMAKE_CURRENT_LIST_DIR}/boost/include )
