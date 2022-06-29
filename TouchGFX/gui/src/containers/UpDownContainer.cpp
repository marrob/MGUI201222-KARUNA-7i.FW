#include <gui/containers/UpDownContainer.hpp>

int mValue;
 

UpDownContainer::UpDownContainer()
{
    mValue = 0;
}

void UpDownContainer::initialize()
{
    UpDownContainerBase::initialize();
}

void UpDownContainer::OnBtnUpClick()
{
    mValue++; 
    RefreshValue();
    emitValueChangedTriggerCallback(mValue);
}


void UpDownContainer::OnBtnDownClick()
{
    mValue--;
    RefreshValue(); 
    emitValueChangedTriggerCallback(mValue);
}

void UpDownContainer::RefreshValue()
{
    Unicode::snprintf(lblValueBuffer, LBLVALUE_SIZE, "%d", mValue);
    lblValue.invalidate();
}

int UpDownContainer::GetValue()
{
    return mValue;
}

void UpDownContainer::SetValue(int value)
{
    mValue = value;
    RefreshValue();
}
