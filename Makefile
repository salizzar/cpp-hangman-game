NAME      := hangman-game
CC        := g++
DBG       := gdb
OUTDIR    := bin
BIN       := $(OUTDIR)/$(NAME)
TESTBIN   := $(OUTDIR)/$(NAME)-test
FLAGS     := -I include src/** -o
DBGFLAGS  := -I include -g src/** -o
MKDIR     := mkdir

clean:
	$(RM)     -rf $(OUTDIR)
	$(MKDIR)  -p  $(OUTDIR)

build: clean
	$(CC) $(FLAGS) $(BIN)

debug: clean
	$(CC) $(DBGFLAGS) $(TESTBIN)
	$(DBG) $(TESTBIN)

run:
	$(BIN)

all: build run

