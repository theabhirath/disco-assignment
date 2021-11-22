# MAKEFILE

CXX = gcc
CFLAGS = -c -Iinclude
HEADER = include/helper.h
SRC_DIR = ./src
VIS_DIR = ./src/visualiser
OUTPUT_DIR = ./bin
OBJ_LIST = $(addprefix $(OUTPUT_DIR)/, main.o closures.o csv.o latticeOps.o matrixType.o partitions.o\
 posetOps.o visualiser.o visualise_hasse.o)
OUTPUT = $(OUTPUT_DIR)

all : $(OUTPUT)

$(OUTPUT_DIR)/main.o: $(SRC_DIR)/main.c $(HEADER)
	$(CXX) $(CFLAGS) $(SRC_DIR)/main.c -o $(OUTPUT_DIR)/main.o 

$(OUTPUT) : $(OBJ_LIST) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(OBJ_LIST) 

# Here's the key:
$(OUTPUT_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

$(OUTPUT_DIR)/%.o : $(VIS_DIR)/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

clean :
	rm -rf $(OBJ_LIST)

.PHONY: all clean