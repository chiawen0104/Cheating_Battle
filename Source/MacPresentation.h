#ifndef MACPRESENTATION_H
#define MACPRESENTATION_H

// Platform specific window behaviour for macOS. A no-op on other platforms.
class MacPresentation
{
    public:
        // Auto-hide the Dock while the game is the active app.
        static void hideDock();
};

#endif
