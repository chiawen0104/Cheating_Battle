#ifndef APPRESOURCES_H
#define APPRESOURCES_H

// Knows where the game's pictures, music and fonts live.
class AppResources
{
    public:
        // Make "./Picture", "./Music" and "./Word" resolve correctly no matter where the
        // game was started from: inside the .app bundle it is Contents/Resources,
        // otherwise the folder holding the executable.
        static bool useResourceDirectory();
};

#endif
