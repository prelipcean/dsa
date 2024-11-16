cmake_minimum_required(VERSION 3.22)

#---------------------------------------------------
cmake_policy(VERSION 3.21)
#New policy : option() honors normal variables (if defined earlier in CMakeLists).
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
#---------------------------------------------------

project(
  "LL_Project"
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (UNIX)
  message(STATUS "Unix system")
else()
  message(STATUS "Windows system")
endif()

# add_compile_options must be before add_executable
# Show all warnings and treat warnings as errors
# add_compile_options(-Werror -Wall)
# Show all warnings but don't treat them as errors
add_compile_options(-Wall -Wfatal-errors)

# Create a list with name LIST_SRC for source files
set(LIST_SRC
  src/main.cpp
  src/Node.cpp
  src/LinkedList.cpp
)
list(LENGTH LIST_SRC LIST_SRC_LEN)
message(STATUS "Length of list LIST_SRC is: ${LIST_SRC_LEN}")

# Create a list with name LIST_INC for include files
set(LIST_INC
  inc
)
list(LENGTH LIST_INC LIST_INC_LEN)
message(STATUS "Length of list LIST_INC is: ${LIST_INC_LEN}")

add_executable(${PROJECT_NAME}
  ${LIST_SRC}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  ${LIST_INC}
)

add_compile_definitions(
  #DEFINES
)

# target_link_libraries(${PROJECT_NAME} fmt::fmt)