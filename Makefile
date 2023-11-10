# Compiler and compiler flags
CXX = g++

# Source files and output executable
SRC_FILES = ./src/main.cpp ./src/flag_handler.cpp ./src/tokenizer.cpp ./src/add_standard_functions.cpp ./src/translator.cpp
EXECUTABLE = ./bin/zinc

# Object files directory
OBJ_DIR = ./obj

# Create a list of object files based on source files
OBJ_FILES = $(patsubst ./src/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile each source file into an object file
$(OBJ_DIR)/%.o: ./src/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to create the ./bin directory
$(EXECUTABLE): | ./bin

./bin:
	mkdir -p ./bin

# Clean up object files, the ./obj directory, and the ./bin directory
clean:
	rm -rf $(OBJ_DIR) ./bin

# Phony target to ensure 'clean' is always executed, even if a 'clean' file exists
.PHONY: clean