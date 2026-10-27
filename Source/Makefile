CXX      := clang++
CXXFLAGS := -std=c++11 -Wall $(shell pkg-config --cflags sdl2 SDL2_image SDL2_ttf SDL2_mixer)
LDFLAGS  := $(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf SDL2_mixer)

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET := CheatingBattle

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run clean
