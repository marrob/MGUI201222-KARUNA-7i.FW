#ifndef SAVERSCREENPRESENTER_HPP
#define SAVERSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SaverScreenView;

class SaverScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SaverScreenPresenter(SaverScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SaverScreenPresenter() {};

private:
    SaverScreenPresenter();

    SaverScreenView& view;
};

#endif // SAVERSCREENPRESENTER_HPP
