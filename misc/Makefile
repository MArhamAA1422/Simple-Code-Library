# BISMILLAH
# Compiler
CXX=g++
# Compiler flags
CXXFLAGS=-Wall -Wextra -std=c++17

# Directories containing source files
SRCDIRS := $(wildcard */)
# Executable names (same as the folder names)
TARGETS := $(patsubst %/,%,$(SRCDIRS))

# Default rule
all: $(TARGETS)

# Rule for building the executables
$(TARGETS):
	$(CXX) $(CXXFLAGS) -o $@/$@ $@/*.cpp

# Phony targets for each directory
.PHONY: $(TARGETS)

# Clean rule
clean:
	rm -f $(addsuffix /$(TARGETS), $(TARGETS))
