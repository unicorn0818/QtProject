#include "m_checkbox.h"

m_checkbox::m_checkbox(QWidget *parent) :
QCheckBox(parent)
{
    setStyleSheet("QCheckBox::indicator{border-image:url(:./png/state_1);}");
    value=0;
}
int m_checkbox::get_value()
{
    return value;
}
void m_checkbox::set_value(int index)
{
    switch (index) {
    case 0:
        value=0;
        setStyleSheet("QCheckBox::indicator{border-image:url(:./png/state_1);}");
        break;
    case 1:
        value=1;
        setStyleSheet("QCheckBox::indicator{border-image:url(:./png/state_2);}");
        break;
    case 2:
        value=2;
        setStyleSheet("QCheckBox::indicator{border-image:url(:./png/state_3);}");
        break;
    default:
        value=2;
        setStyleSheet("QCheckBox::indicator{border-image:url(:./png/state_3);}");
        break;
    }
}
