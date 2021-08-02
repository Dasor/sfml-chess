
OUTPUT=chess
SFML_LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: CXXFLAGS += -O3
all: $(OUTPUT)

debug: CXXFLAGS += -g -O0
debug: $(OUTPUT)

$(OUTPUT): Makefile game.cpp main.cpp pieces.cpp main.hpp definitions.hpp
	g++ game.cpp main.cpp pieces.cpp $(CXXFLAGS) $(SFML_LIBS) -o $@

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)
