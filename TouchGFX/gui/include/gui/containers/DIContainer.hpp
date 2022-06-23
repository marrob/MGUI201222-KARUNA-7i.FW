#ifndef DICONTAINER_HPP
#define DICONTAINER_HPP

#include <gui_generated/containers/DIContainerBase.hpp>

class DIContainer : public DIContainerBase
{
public:
    DIContainer();
    virtual ~DIContainer() {}

    virtual void initialize();
protected:
};

#endif // DICONTAINER_HPP
