cmake_minimum_required(VERSION 3.12)

project ("test-client")

add_executable (testclient
	"test-client.h"
	"test-client.cpp"
)

target_link_libraries (testclient engine)

target_include_directories (testclient PRIVATE
	"${CMAKE_SOURCE_DIR}/engine/include"
)