# Directories
BUILD_DIR = build
SRC_DIR = src
DEPS_DIR = dependencies/SFML

# Compiler and flags
CXX = g++
CXXFLAGS = -g
LDFLAGS = -L $(BUILD_DIR)
INCLUDES = -I $(DEPS_DIR)/include
LIBS = -lsfml-graphics-2 -lsfml-window-2 -lsfml-system-2

# List of source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Output executable name
EXEC = $(BUILD_DIR)/main.exe

# SFML DLLs to copy
DLLS = $(DEPS_DIR)/bin/sfml-graphics-2.dll $(DEPS_DIR)/bin/sfml-window-2.dll $(DEPS_DIR)/bin/sfml-system-2.dll

$(EXEC): $(SOURCES)
	@mkdir -p $(BUILD_DIR)               
	$(MAKE) copy_dlls                      
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC) $(INCLUDES) $(LDFLAGS) $(LIBS)
	@echo "Compilation successful!"
	
	

# Rule to copy SFML DLLs into the build directory
copy_dlls:
	@mkdir -p $(BUILD_DIR)
	@for dll in $(DLLS); do \
		if [ ! -f "$(BUILD_DIR)/$$(basename $$dll)" ]; then \
			cp $$dll $(BUILD_DIR)/; \
			echo "Copied $$dll"; \
		else \
			echo "$$(basename $$dll) already exists, skipping..."; \
		fi; \
	done

# Rule to run the executable
run: $(EXEC)
	@echo "Running the program..."
	./$(EXEC)

# Rule to clean the build directory
clean:
	@echo "Cleaning up..."
	rm -rf $(BUILD_DIR)

.PHONY: run clean copy_dlls
