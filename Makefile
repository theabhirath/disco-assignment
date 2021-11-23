MKDIR   := mkdir -p
RMDIR   := rm -rf
CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
VIS		:= ./src/visualiser
SRCS    := $(wildcard $(SRC)/*.c)
VISRCS  := $(wildcard $(VIS)/*.c)
OBJS    := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
VISOBJS := $(patsubst $(VIS)/%.c, $(OBJ)/%.o, $(VISRCS))
EXE     := $(BIN)/main.exe
CFLAGS  := -I$(INCLUDE)
LDLIBS  := -lm

.PHONY: all run clean

all: $(EXE)

$(EXE): $(OBJS) $(VISOBJS) | $(BIN)
	$(CC) $^ -o $@ $(LDLIBS) 
	cp -r $(VIS)/plotting $(BIN)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(VIS)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	$(MKDIR) $@

clean:
	$(RMDIR) $(OBJ) $(BIN)