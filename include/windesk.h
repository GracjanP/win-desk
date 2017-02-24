#ifndef WINDESK_H
#define WINDESK_H

#include <Windows.h>
#include <string>

namespace windesk
{
    HDC GetContext();

    std::string GetWallpaperA();
    void SetWallpaperA(const std::string& path);

    std::wstring GetWallpaperW();
    void SetWallpaperW(const std::wstring& path);
} // namespace windesk

#endif // WINDESK_H
