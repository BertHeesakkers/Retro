################################################
# Generic Makefile to help get started
# Requires sh.exe on Windows.
# Assumes GNUMake.
# Made by Rapptz (https://gist.github.com/Rapptz/eb32184865e435168403)
# Adapted for Gameboy Classic by Bert Heesakkers
# name of final output
ifeq ($(GBDKPATH),)
$(error "Please set GBDKPATH in your environment.")
endif

PROGRAM_NAME ?= $(notdir $(CURDIR))

# where to store the debug and release final output
RELEASE_DIR := ./release
DEBUG_DIR := ./debug

# where to store debug and release object files
RELEASE_OBJ_DIR := ./release/obj
DEBUG_OBJ_DIR := ./debug/obj

# where the source files are
SRC_DIR := .

# compiler name
CXX := $(GBDKPATH)\bin\lcc.exe

# general compiler and linker flags
CXXFLAGS += -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG #-Wall -Wextra -pedantic
LDFLAGS += -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG

# debug and release compiler and linker flags
RELEASE_CXXFLAGS := #-DNDEBUG
RELEASE_LDFLAGS :=

DEBUG_CXXFLAGS := #-DDEBUG
DEBUG_LDFLAGS :=

# ignored warnings, emit the -Wno- prefix
IGNORED_WARNINGS :=

# These are flags without the prefixes
# these prefixes are -I, -L, and -l respectively
INCLUDE_DIRS := .
LIBRARY_DIRS :=
LIBRARIES :=

RM ?= rm -rf
MKDIR ?= mkdir
RMDIR ?= rmdir

# Input and Output file extension
IN_EXT := c
OUT_EXT := o

DEBUG ?= 0

# Modying past this point is usually for internal tinkering.
###############################################################################
ifeq ($(DEBUG), 1)
	BIN_DIR := $(DEBUG_DIR)
	OBJ_DIR := $(DEBUG_OBJ_DIR)
else
	BIN_DIR := $(RELEASE_DIR)
	OBJ_DIR := $(RELEASE_OBJ_DIR)
endif

###############################################################################
# Modifying the flags
###############################################################################
#CXXFLAGS += $(foreach dir,$(INCLUDE_DIRS),-I$(dir))
#CXXFLAGS += $(foreach warn,$(IGNORED_WARNINGS),-Wno-$(warn))
LDFLAGS += $(foreach dir,$(LIBRARY_DIRS),-L$(dir))
LDFLAGS += $(foreach lib,$(LIBRARIES),-l$(lib))

###############################################################################
# Default rules
###############################################################################
all: $(BIN_DIR)/$(PROGRAM_NAME)

clean:
	-$(RM) $(OBJ_DIR)/* $(BIN_DIR)/*
	-$(RMDIR) $(OBJ_DIR)
	-$(RMDIR) $(BIN_DIR)

help:
	@echo "Available targets: "
	@echo "all         - builds everything"
	@echo "clean       - removes object and clean files"
	@echo "help        - shows this message"
	@echo ""
	@echo "You can set debug build by doing 'make DEBUG=1 target'"

.PHONY: all clean distclean uninstall help

###############################################################################
# Compiling rules
###############################################################################
SOURCES := $(wildcard $(SRC_DIR)/*.$(IN_EXT))
OBJECTS := $(SOURCES:$(SRC_DIR)/%.$(IN_EXT)=$(OBJ_DIR)/%.$(OUT_EXT))
DEPENDENCIES := ($OBJECTS:.$(OUT_EXT)=.d)

-include $(DEPENDENCIES)

ifeq ($(DEBUG), 1)
	CXXFLAGS += $(DEBUG_CXXFLAGS)
	LDFLAGS += $(DEBUG_LDFLAGS)
else
	CXXFLAGS += $(RELEASE_CXXFLAGS)
	LDFLAGS += $(RELEASE_LDFLAGS)
endif

$(OBJ_DIR)/%.$(OUT_EXT):%.$(IN_EXT) | object_dir
	$(CXX) $(CXXFLAGS) -c -o  $@ $<

$(BIN_DIR)/$(PROGRAM_NAME): $(OBJECTS) | binary_dir
	$(CXX) $(LDFLAGS) -o $@.gb $(OBJECTS)

object_dir:
ifeq "$(wildcard $(OBJ_DIR))" ""
	-$(MKDIR) $(OBJ_DIR)
endif

binary_dir:
ifeq "$(wildcard $(BIN_DIR))" ""
	-$(MKDIR) $(BIN_DIR)
endif
