CXX = g++
CXXFLAGS = -I./include -Wall -Wextra -g

SRC_DIR = src
TEST_DIR = tests
INCLUDE_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

TEST_BINS = $(patsubst $(TEST_DIR)/%.cpp, %, $(TEST_FILES))

all: test

test: $(TEST_BINS)
	@for t in $(TEST_BINS); do ./$$t; done

test_qcap2_buffer: $(TEST_DIR)/test_qcap2_buffer.cpp $(SRC_DIR)/qcap2.buffer.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

test_qcap2_utils: $(TEST_DIR)/test_qcap2_utils.cpp $(SRC_DIR)/qcap2.utils.cpp $(SRC_DIR)/qcap2.buffer.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TEST_BINS)

.PHONY: all test clean
