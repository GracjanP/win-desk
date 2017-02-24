# win-desk
A tiny library that lets you draw on Windows desktop.

## About
Win-desk is a library which provides you with HDC you can use to draw over a Windows wallpaper and under the icons. It also gives you convenient functions to get the current wallpaper's path or to set it to something else.

To accomplish this I used a trick described by Mr. Gerald Degeneve [here](https://www.codeproject.com/articles/856020/draw-behind-desktop-icons-in-windows). I tested it on Windows 10 but it should also work on Windows 8.

## Usage
To use the library, you can either add the win-desk project to your Visual Studio solution and reference it in another project or simply copy the `windesk.h` and `windesk.cpp` and add them to your project.
Here's some example code that uses the library:
```
#include <windows.h>
#include "windesk.h"
int main()
{
    // Get the needed context
    HDC context = windesk::GetContext();
    
    // Create a rectangle and a red brush
    RECT rect = {0, 0, 50, 50};
    HBRUSH brush = CreateSolidBrush(RGB(255,0,0));
    
    // Draw a red 50x50 rectangle between the wallpaper and the icons
    FillRect(context, &rect, brush);
    
    return 0;
}
```
You can find a better example in the `main.cpp` file in `example` directory.