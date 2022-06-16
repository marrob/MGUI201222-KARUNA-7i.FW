/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId typography)
{
    switch (typography)
    {
    case Typography::DEFAULT:
        // Asap_Regular_40_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[0]);
    case Typography::DESC:
        // micross_25_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[1]);
    case Typography::VALUE:
        // micross_65_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[2]);
    case Typography::SETTINGS:
        // corbell_30_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[3]);
    case Typography::TYPOGRAPHY_00:
        // consola_70_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[4]);
    case Typography::SWTEXT_HIGH:
        // arialbd_40_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[5]);
    case Typography::SWTEXT:
        // arial_35_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[6]);
    default:
        return 0;
    }
}
