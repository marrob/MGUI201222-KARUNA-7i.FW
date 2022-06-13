#ifndef PASSWORDSCREENPRESENTER_HPP
#define PASSWORDSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PasswordScreenView;

class PasswordScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PasswordScreenPresenter(PasswordScreenView& v);

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

    virtual ~PasswordScreenPresenter() {};

private:
    PasswordScreenPresenter();

    PasswordScreenView& view;
};

#endif // PASSWORDSCREENPRESENTER_HPP
