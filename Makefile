# Compiler and compiler flags
CXX = g++

# Source files and output executable
SRC_FILES = ./src/zinc.cpp ./src/flag_handler.cpp ./src/tokenizer.cpp
EXECUTABLE = ./bin/zinc

# Object files directory
OBJ_DIR = ./

# Create a list of object files based on source files
OBJ_FILES = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Default target
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile each source file into an object file
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)

# Phony target to ensure 'clean' is always executed, even if a 'clean' file exists
.PHONY: clean
