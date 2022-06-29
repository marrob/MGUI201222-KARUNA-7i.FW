#ifndef UPDOWNCONTAINER_HPP
#define UPDOWNCONTAINER_HPP

#include <gui_generated/containers/UpDownContainerBase.hpp>

class UpDownContainer : public UpDownContainerBase
{
public:
	UpDownContainer();
	virtual ~UpDownContainer() {}

	virtual void initialize();
	virtual void OnBtnUpClick();
	virtual void OnBtnDownClick();
	void RefreshValue();
	 
	int GetValue();
	void SetValue(int value);

protected:
};

#endif // UPDOWNCONTAINER_HPP
