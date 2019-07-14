# Makefile ref:
# AUTOMATIC VARIABLES:
#   $^ - all the prerequisites of a rule
#   $@ - the target
#
# SETTING VARIABLES
#  := - expand at define time
#  += - append to variable
#
# FUNCTIONS:
#  $(addprefix prefix,names…) - prefixname1 prefixname2 etc

COMPILER = clang++
SDL = -lSDL2
SDL_IMG = -lSDL2_image
CPPFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL) $(SDL_IMG)
SRC_DIR = src
BUILD_DIR = build
EXE = app

CPPs := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)%.cpp,$(BUILD_DIR)%.o,$(CPPs))

.PHONY : all
all: $(EXE)

$(EXE): $(OBJECTS)
	$(COMPILER) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp 
	$(COMPILER) $(CPPFLAGS) $^ -o $@

.PHONY : clean
clean :
	-@rm $(BUILD_DIR)/*.o 2> /dev/null || true
	-@rm $(EXE) 2> /dev/null || true

.PHONY : print #for debuggery
print:
	@echo $(OBJECTS)