#ifndef M_CHECKBOX_H
#define M_CHECKBOX_H

#include <QWidget>
#include <QCheckBox>

class m_checkbox : public QCheckBox
{
    Q_OBJECT
public:
    explicit m_checkbox(QWidget *parent = 0);
    int get_value();
    void set_value( int i);
private:
    int value;
};

#endif // M_CHECKBOX_H
