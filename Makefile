BUILD_CMD=gcc main.c module/client/client.c module/server/server.c module/network/network.c src/app_manager.c src/event_manager.c src/ui/ui.c src/ui/cui/cui_main_window.c src/ui/cui/cui_standard_calculation_window.c src/ui/cui/cui_exit_window.c src/ui/cui/utility/cui_input_validation.c src/backend/standard_calculation.c -o build/complex-calculator -Iinc -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion -Wnull-dereference -Wsign-conversion -g -O0

# Detect the operating system
UNAME_S := $(shell uname -s)

# Define compiler and linker flags based on OS
ifeq ($(UNAME_S), Linux)
  SHELL=/bin/bash
  CLEAN_CMD=rm -rf build
  MAKEBUILDDIR_CMD=mkdir build
  RUN_CMD=build/complex-calculator
elseif eq ($(UNAME_S), Darwin)
  SHELL=/bin/bash
  CLEAN_CMD=rm -rf build
  MAKEBUILDDIR_CMD=mkdir build
  RUN_CMD=build/complex-calculator
else
  SHELL=cmd.exe
  CLEAN_CMD=rmdir build /s /q
  MAKEBUILDDIR_CMD=mkdir build
  RUN_CMD=./build/complex-calculator
endif

# Phony targets for common build actions
.PHONY: clean build run

clean:
	-$(CLEAN_CMD)

build:
	-$(MAKEBUILDDIR_CMD)
	$(BUILD_CMD)

run:
	$(RUN_CMD)