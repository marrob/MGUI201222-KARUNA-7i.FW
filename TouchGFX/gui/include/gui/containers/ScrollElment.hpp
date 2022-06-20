#ifndef SCROLLELMENT_HPP
#define SCROLLELMENT_HPP

#include <gui_generated/containers/ScrollElmentBase.hpp>

class ScrollElment : public ScrollElmentBase
{
public:
    ScrollElment();
    virtual ~ScrollElment() {}

    virtual void initialize();

    void SetText(char* logText);

protected:
};

#endif // SCROLLELMENT_HPP
