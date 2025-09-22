# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++14

# Linker flags for libcurl
LDFLAGS = 

# Source files
SRCS = BinomialTreeModel.cpp Option01.cpp OptionPricer01.cpp

# Object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = OptionPricer01

# Default target: build the executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)
