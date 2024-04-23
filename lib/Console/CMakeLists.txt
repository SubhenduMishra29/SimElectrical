#add_subdirectory()
cmake_minimum_required(VERSION 3.9)
project(BLIFParser)

# Find Flex and Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Generate Flex and Bison files
flex_target(BLIFLexer blif_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/blif_lexer.cpp)
bison_target(BLIFParser blif_parser.y ${CMAKE_CURRENT_BINARY_DIR}/blif_parser.cpp)

# Add Flex and Bison dependency
add_flex_bison_dependency(BLIFLexer BLIFParser)

# Add executable target
add_executable(BLIFParser 
    ${FLEX_BLIFLexer_OUTPUTS}
    ${BISON_BLIFParser_OUTPUTS}
    main.cpp
)

# Include directory for Flex and Bison generated files
target_include_directories(BLIFParser PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Set C++ standard
set_property(TARGET BLIFParser PROPERTY CXX_STANDARD 11)


