#include <conio.h>
#include <Windows.h>
#include <chrono>
#include "windesk.h"

struct Ball
{
    int x, y, vx, vy, r;
};

int main()
{
    HDC desktop = windesk::GetContext();

    RECT rc;
    GetWindowRect(GetDesktopWindow(), &rc);

    Ball ball = { rc.right / 2, rc.bottom / 2, 1, 1, 15 };
    HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
    HBRUSH white = CreateSolidBrush(RGB(255, 255, 255));

    using namespace std::chrono;

    double elapsedTime = 0.0;
    auto currentTime = steady_clock::now();
    auto previousTime = currentTime;
    auto timePerFrame = 1.0 / 60.0;

    while (!_kbhit())
    {
        previousTime = currentTime;
        currentTime = steady_clock::now();
        elapsedTime += duration_cast<nanoseconds>(currentTime - previousTime).count() / 1000000000.0;

        while (elapsedTime >= timePerFrame)
        {
            elapsedTime -= timePerFrame;

            ball.x += ball.vx * timePerFrame * 200;
            ball.y += ball.vy * timePerFrame * 200;

            if (ball.x + ball.r > rc.right)
            {
                ball.vx = -ball.vx;
                ball.x = rc.right - ball.r;
            }
            else if (ball.x - ball.r < rc.left)
            {
                ball.vx = -ball.vx;
                ball.x = rc.left + ball.r;
            }

            if (ball.y + ball.r > rc.bottom)
            {
                ball.vy = -ball.vy;
                ball.y = rc.bottom - ball.r;
            }
            else if (ball.y - ball.r < rc.top)
            {
                ball.vy = -ball.vy;
                ball.y = rc.top + ball.r;
            }

            RECT ballRect = { ball.x - ball.r, ball.y - ball.r, ball.x + ball.r, ball.y + ball.r };
            FillRect(desktop, &rc, black);
            FillRect(desktop, &ballRect, white);
        }
    }

    // Resets the wallpaper
    windesk::SetWallpaperW(windesk::GetWallpaperW());

    return 0;
}
