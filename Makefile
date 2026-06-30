# hinput - Custom input() with type validation
# Makefile for building library and tests

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -I$(SRC_DIR)
LDFLAGS = -lm

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Targets
LIB_NAME = libhinput
TEST_NAME = test_input

# Source files
LIB_SRC = $(SRC_DIR)/input.c
LIB_OBJ = $(BUILD_DIR)/input.o
TEST_SRC = $(TEST_DIR)/main.c
TEST_BIN = $(BUILD_DIR)/$(TEST_NAME)

# Default target
all: $(TEST_BIN)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile library object
$(LIB_OBJ): $(LIB_SRC) $(SRC_DIR)/input.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile and link test binary
$(TEST_BIN): $(TEST_SRC) $(LIB_OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< $(LIB_OBJ) -o $@ $(LDFLAGS)

# Run tests
test: $(TEST_BIN)
	./$(TEST_BIN)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Install library (optional)
install: $(LIB_OBJ)
	install -d $(DESTDIR)/usr/local/lib
	install -d $(DESTDIR)/usr/local/include
	install $(LIB_OBJ) $(DESTDIR)/usr/local/lib/$(LIB_NAME).a
	install $(SRC_DIR)/input.h $(DESTDIR)/usr/local/include/

.PHONY: all test clean install
