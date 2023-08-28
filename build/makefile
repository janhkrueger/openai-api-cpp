REPO=$(HOME)/
SRC=src
BIN=bin
BINCOV=coverage

CC=clang++
CFLAGS=
CWARNINGS=-Wextra -Wconversion -Wsign-conversion -Wformat-nonliteral -Wstack-protector -Wno-unused-parameter -Wformat=2 -Wformat-security -Winit-self -Wuninitialized -Wswitch-default -Wswitch-enum -Wunused-but-set-parameter -Wunused-parameter -Wunused-but-set-variable -Wfloat-equal -Wshadow -Wunreachable-code
CINCLUDES=-I$(SRC) -I/usr/local/lib/ -I frameworks/rapidjson/include/ -I frameworks/spdlog/include/ -I frameworks/spdlog/include/spdlog/ -I/usr/include -Iinclude
CLIBS=-Llib -lcurl -lyaml-cpp

EXECUTABLE=$(parm)

SOURCES=$(SRC)/$(EXECUTABLE).cpp
OBJECTS=$(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(CINCLUDES)

all: $(OBJECTS)
	$(CC) $(CFLAGS) -O3 $(OBJECTS) $(CLIBS) -o $(BIN)/$(EXECUTABLE)

debug: CFLAGS += -g -O3
debug: all

.PHONY: coverage
coverage: CFLAGS += -O0 -fprofile-arcs -ftest-coverage -g
coverage: all

full: CFLAGS += -O3 $(CWARNINGS)
full: all

security: all
	valgrind --undef-value-errors=yes --time-stamp=yes --leak-check=full --track-fds=yes --show-reachable=yes --log-file=code-maintenance/valgrind_$(EXECUTABLE).log -v $(BIN)/$(EXECUTABLE)
