PROJECT         = bus

# Source files
INCLUDES        =  -Iinclude
SRCS            =  $(wildcard src/*.cpp)
OBJS            := $(SRCS:.cpp=.o)

# Compiler settings
CC              = g++
CSTD            = c++23
CFLAGS          = -ansi -std=$(CSTD) -Wall -Werror -g -v ${INCLUDES}
LDFLAGS         = -lstdc++ -lm


# Ensure the build directory exists
$(shell mkdir -p build)
# Define the output directory
TARGET          = build/$(PROJECT)

# PHONY commands
.PHONY: all clean

# Default target
all: $(TARGET)

# Build rules
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf build/ $(OBJS)
