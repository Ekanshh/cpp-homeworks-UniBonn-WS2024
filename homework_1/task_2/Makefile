SRC_DIR = ./src
BUILD_DIR = ./build
INCLUDE_DIR=./include
RESULTS_DIR= ./results

CXXFLAGS = -std=c++17 -I $(INCLUDE_DIR)

all: output copy

output: $(BUILD_DIR)/sum.o $(BUILD_DIR)/subtract.o $(BUILD_DIR)/main.o $(BUILD_DIR)/libipb_arithmetic.a | $(BUILD_DIR)
	@echo "..compiling main program.."
	c++ $(CXXFLAGS) "$(SRC_DIR)/main.cpp"  -L $(BUILD_DIR) -lipb_arithmetic -o "$(BUILD_DIR)/test_ipb_arithmetic"

$(BUILD_DIR)/sum.o:  $(SRC_DIR)/sum.cpp | $(BUILD_DIR)
	@echo "..creating sum object.."
	c++ $(CXXFLAGS) -c "$(SRC_DIR)/sum.cpp" -o "$(BUILD_DIR)/sum.o"

$(BUILD_DIR)/subtract.o: $(SRC_DIR)/subtract.cpp | $(BUILD_DIR)
	@echo "..creating subtract object.."
	c++ $(CXXFLAGS) -c "$(SRC_DIR)/subtract.cpp" -o "$(BUILD_DIR)/subtract.o"

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp | $(BUILD_DIR)
	@echo "..creating main object.."
	c++ $(CXXFLAGS) -c "$(SRC_DIR)/main.cpp" -o "$(BUILD_DIR)/main.o"

$(BUILD_DIR)/libipb_arithmetic.a: $(BUILD_DIR)/subtract.o $(BUILD_DIR)/sum.o | $(BUILD_DIR)
	@echo "..creating library.."
	ar rcs "$(BUILD_DIR)/libipb_arithmetic.a" "$(BUILD_DIR)/subtract.o" "$(BUILD_DIR)/sum.o"

$(BUILD_DIR): 
	@echo "Building process started..."
	mkdir -p $(BUILD_DIR)

copy: cp_test_ipb_arithmetic cp_libipb_arithmetic | $(RESULTS_DIR)
	@echo "...copying executable and libraries from build to results ..."

cp_test_ipb_arithmetic: | $(RESULTS_DIR)
	cp $(BUILD_DIR)/test_ipb_arithmetic $(RESULTS_DIR)/bin/


cp_libipb_arithmetic: | $(RESULTS_DIR)
	cp $(BUILD_DIR)/libipb_arithmetic.a $(RESULTS_DIR)/lib/

$(RESULTS_DIR): 
	mkdir -p $(RESULTS_DIR)/bin $(RESULTS_DIR)/lib