# CMakeList.txt: проект CMake для titleCapture; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (titleCapture "src/titleCapture.cpp" )

target_link_libraries(titleCapture PRIVATE cpr::cpr)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET titleCapture PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
