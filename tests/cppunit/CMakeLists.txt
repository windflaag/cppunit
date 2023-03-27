add_custom_target(
  cppunit-tests-source-code
  COMMAND cppunit-cli ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS cppunit
  DEPENDS cppunit-cli
)

set_property(SOURCE main.cpp PROPERTY GENERATED 1)
add_executable(
  cppunit-tests
  main.cpp
)
add_dependencies(cppunit-tests cppunit-tests-source-code)

target_link_libraries(
  cppunit-tests cppunit
)

add_custom_target(
  cppunit-tests-run
  COMMAND cppunit-tests
  DEPENDS cppunit-tests
)
