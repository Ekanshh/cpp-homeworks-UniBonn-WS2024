SRC_DIR = ./src
BUILD_DIR = ./build
INCLUDE_DIR=./include
RESULTS_DIR= ./results

CXXFLAGS = -std=c++17 -I $(INCLUDE_DIR)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Targets
all: output copy

output: $(BUILD_DIR)/test_ipb_arithmetic
	@echo "Build process completed."

$(BUILD_DIR)/test_ipb_arithmetic: $(OBJ_FILES) $(BUILD_DIR)/libipb_arithmetic.a | $(BUILD_DIR)
	@echo "..link and create main executable.."
	c++ $(CXXFLAGS) "$(SRC_DIR)/main.cpp" -L $(BUILD_DIR) -lipb_arithmetic -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@echo "..compile source files into object files.."
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/libipb_arithmetic.a: $(BUILD_DIR)/subtract.o $(BUILD_DIR)/sum.o | $(BUILD_DIR)
	@echo "..create static library.."
	ar rcs $@ $^

$(BUILD_DIR):
ifeq ("$(wildcard $(BUILD_DIR))", "")
	@echo "..create build dir.."
	mkdir -p "$(BUILD_DIR)"
endif


copy: $(RESULTS_DIR)/bin/test_ipb_arithmetic $(RESULTS_DIR)/lib/libipb_arithmetic.a

$(RESULTS_DIR)/bin/test_ipb_arithmetic: $(BUILD_DIR)/test_ipb_arithmetic | $(RESULTS_DIR)
	cp -p $< $@

$(RESULTS_DIR)/lib/libipb_arithmetic.a: $(BUILD_DIR)/libipb_arithmetic.a | $(RESULTS_DIR)
	cp -p $< $@

$(RESULTS_DIR): 
ifeq ("$(wildcard $(RESULTS_DIR)/bin)", "")
	@echo "..create results/bin dir.."
	mkdir -p "$(RESULTS_DIR)/bin"
endif
ifeq ("$(wildcard $(RESULTS_DIR)/lib)", "")
	@echo "..create results/lib dir.."
	mkdir -p "$(RESULTS_DIR)/lib"
endif
