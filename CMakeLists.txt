cmake_minimum_required(VERSION 3.20)

project(serial_mouse)

add_custom_target(serial_mouse DEPENDS
	"${CMAKE_CURRENT_BINARY_DIR}/upload.log"
)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/serial_mouse.ino.elf
	COMMAND arduino-cli compile --build-path "${CMAKE_CURRENT_BINARY_DIR}" --fqbn arduino:avr:uno "${CMAKE_CURRENT_SOURCE_DIR}"
	DEPENDS serial_mouse.ino
)

add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/upload.log"
	COMMAND arduino-cli upload --build-path "${CMAKE_CURRENT_BINARY_DIR}" --fqbn arduino:avr:uno -p /dev/ttyACM0 --log-file "${CMAKE_CURRENT_BINARY_DIR}/upload.log" "${CMAKE_CURRENT_SOURCE_DIR}"
	DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/serial_mouse.ino.elf
)

