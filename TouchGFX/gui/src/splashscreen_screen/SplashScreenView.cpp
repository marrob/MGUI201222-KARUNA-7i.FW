#include <gui/splashscreen_screen/SplashScreenView.hpp>

int splashCnt;
int mSplashCount;
int defWidth = 920;

SplashScreenView::SplashScreenView()
{

}

void SplashScreenView::setupScreen()
{
    SplashScreenViewBase::setupScreen();
    lblDeviceName.setAlpha(0);
    lblCoreAudio.setAlpha(0);
    lblCoreAudio.invalidate();
    lblDeviceName.invalidate();
}

void SplashScreenView::tearDownScreen()
{
    SplashScreenViewBase::tearDownScreen();
}


void SplashScreenView::handleTickEvent() 
{
    splashCnt++;
    if (splashCnt < 100)
    {
        return;
    }

    if (mSplashCount < defWidth)
    {
        lineMidle.setWidth(mSplashCount);

        if (mSplashCount < defWidth / 2)
        {
            lblCoreAudio.setAlpha(mSplashCount / 2);
        }
        else
        {
            lblDeviceName.setAlpha((mSplashCount - defWidth / 2) / 2);
        } 
    }

    mSplashCount+=10;


    lblCoreAudio.invalidate();
    lblDeviceName.invalidate();
    lineMidle.invalidate();

    if (mSplashCount > defWidth + 500)
    {
        application().gotoMainScreenSlideTransitionEast();
    }
}