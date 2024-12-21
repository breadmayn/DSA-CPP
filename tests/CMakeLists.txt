cmake_minimum_required(VERSION 3.31.2)

set(This DSA-CPP-Tests)

set(Sources

)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    DSA-CPP
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
