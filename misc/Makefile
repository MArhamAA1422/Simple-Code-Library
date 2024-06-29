# BISMILLAH
# Compiler
CXX=g++
# Compiler flags
# CXXFLAGS=-Wall -Wextra -std=c++17
CXXFLAGS = -DLOCAL -std=c++17 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

# ​​g++ -DLOCAL -std=c++17 -Wshadow -Wall -o "h" "h.cpp" -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g (in directory: /home/marhamaa1422/Coding)

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
