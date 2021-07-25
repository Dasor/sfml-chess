
OUTPUT=chess
SFML_LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: CXXFLAGS += -O3
all: $(OUTPUT)

debug: CXXFLAGS += -g -O0
debug: $(OUTPUT)

$(OUTPUT): Makefile game.cpp main.cpp pieces.cpp game.hpp pieces.hpp
	g++ $(CXXFLAGS) game.cpp main.cpp pieces.cpp $(SFML_LIBS) -o $@

clean:
	rm -f $(OUTPUT)
