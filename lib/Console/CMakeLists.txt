#add_subdirectory()
cmake_minimum_required(VERSION 3.9)
project(BerkeleyLogicConsole)

# Find Flex and Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Generate Flex and Bison files
flex_target(BerkeleyLexer berkeley_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/berkeley_lexer.cpp)
bison_target(BerkeleyParser berkeley_parser.y ${CMAKE_CURRENT_BINARY_DIR}/berkeley_parser.cpp)

# Add Flex and Bison dependency
add_flex_bison_dependency(BerkeleyLexer BerkeleyParser)

# Add executable target
add_executable(BerkeleyLogicConsole 
    ${FLEX_BerkeleyLexer_OUTPUTS}
    ${BISON_BerkeleyParser_OUTPUTS}
    main.cpp
)

# Include directory for Flex and Bison generated files
target_include_directories(BerkeleyLogicConsole PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Set C++ standard
set_property(TARGET BerkeleyLogicConsole PROPERTY CXX_STANDARD 11)

