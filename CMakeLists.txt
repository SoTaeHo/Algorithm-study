cmake_minimum_required(VERSION 3.24)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

# compile option
#ADD_COMPILE_OPTIONS ( -Wall -Wextra -Werror )

#add_executable(Algorithm main.cpp problem_25206.cpp problem_2751.cpp problem_test.cpp)
add_executable(problem_25206 problem_25206.cpp problem_1700.cpp problem_1806.cpp problem_2933.cpp problem_7576_bfs.cpp problem_1012.cpp problem_13460.cpp problem_12100.cpp)
add_executable(problem_2751 problem_2751.cpp)
add_executable(problem_test problem_test.cpp)
add_executable(problem_1700 problem_1700.cpp)
add_executable(problem_1806 problem_1806.cpp)
add_executable(problem_1181 problem_1181.cpp)
add_executable(problem_2933 problem_2933.cpp)
add_executable(problem_7576_bfs problem_7576_bfs.cpp)
add_executable(problem_1012 problem_1012.cpp)
add_executable(problem_13460 problem_13460.cpp)
add_executable(problem_12100 problem_12100.cpp)