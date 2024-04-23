#add_subdirectory()
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

flex_target(ConsoleLexer lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
bison_target(ConsoleParser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)

add_flex_bison_dependency(ConsoleLexer ConsoleParser)

add_executable(console ${FLEX_ConsoleLexer_OUTPUTS} ${BISON_ConsoleParser_OUTPUTS} main.cpp)

