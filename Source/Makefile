CXX      := clang++
CXXFLAGS := -std=c++11 -Wall $(shell pkg-config --cflags sdl2 SDL2_image SDL2_ttf SDL2_mixer)
LDFLAGS  := $(shell pkg-config --libs sdl2 SDL2_image SDL2_ttf SDL2_mixer) -framework Cocoa

SRCS := $(wildcard *.cpp) $(wildcard *.mm)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
TARGET := CheatingBattle
APP    := ../Release/$(TARGET).app

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.mm
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

# Build a double-clickable macOS app with the SDL libraries and game files inside.
# Needs: brew install dylibbundler
# sdl2-compat loads SDL3 at run time, so dylibbundler cannot see it and it is copied by hand.
SDL3_LIB := $(shell brew --prefix sdl3)/lib/libSDL3.0.dylib
app: $(TARGET)
	rm -rf $(APP)
	mkdir -p $(APP)/Contents/MacOS $(APP)/Contents/Resources $(APP)/Contents/Frameworks
	cp $(TARGET) $(APP)/Contents/MacOS/
	cp Info.plist $(APP)/Contents/Info.plist
	cp -R Picture Music Word $(APP)/Contents/Resources/
	dylibbundler -od -b -x $(APP)/Contents/MacOS/$(TARGET) -d $(APP)/Contents/Frameworks -p @executable_path/../Frameworks/
	cp -L $(SDL3_LIB) $(APP)/Contents/Frameworks/libSDL3.dylib
	codesign --force --deep --sign - $(APP)

# Zip the app for sharing (ditto keeps the code signature intact).
zip: app
	rm -f ../Release/$(TARGET)-mac.zip
	ditto -c -k --sequesterRsrc --keepParent $(APP) ../Release/$(TARGET)-mac.zip

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run app zip clean
