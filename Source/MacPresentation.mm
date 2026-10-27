#include "MacPresentation.h"
#import <Cocoa/Cocoa.h>

void MacPresentation::hideDock()
{
    [NSApp setPresentationOptions:NSApplicationPresentationAutoHideDock];
}
