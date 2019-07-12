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

CPP = clang++
SDL = -lSDL2
SDL_IMG = -lSDL2_image
CPPFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL) $(SDL_IMG)
SRC_DIR = src
BUILD_DIR = build
EXE = game

ARTIFACTS = SDL2_Boilerplate SDL2image_Boilerplate Game main

OBJECTS := $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(ARTIFACTS) ) )
#SOURCES := $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(ARTIFACTS) ) )

.PHONY : all
all: $(EXE)

$(EXE): $(OBJECTS)
	$(CPP) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp 
	$(CPP) $(CPPFLAGS) $^ -o $@

.PHONY : clean
clean :
	-@rm build/*.o 2> /dev/null || true
	-@rm game 2> /dev/null || true

#proto:
#	g++ main.cpp -g -pedantic -o test -lSDL2
