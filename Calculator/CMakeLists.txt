cmake_minimum_required(VERSION 3.2)
project(Calculator)

#set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -pedantic -g3 -Og -Wuninitialized -ansi")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Ofast")

add_executable(calculator.run calculator.c)

add_executable(calculator-global.run calculator-global.c)

add_executable(calculator-v2.run calculator-v2.c)