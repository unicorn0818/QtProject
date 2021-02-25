#include "m_spinbox.h"


M_spinbox::M_spinbox(QWidget *parent) :
QSpinBox(parent)
{
    lineEdit()->installEventFilter(this);
    setFocusPolicy(Qt::NoFocus);
    setWrapping(true);
    model=new QStandardItemModel();
    view=new M_view();
    view->hide();
    view->setModel(model);
    connect(view,SIGNAL(clicked(QModelIndex)),view,SLOT(hide()));
    connect(view,SIGNAL(clicked(QModelIndex)),this,SLOT(set_value(QModelIndex)));
    connect(this,SIGNAL(valueChanged(int)),SLOT(set_help(int)));
    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    deskRect = QApplication::desktop()->availableGeometry();
}
M_view::M_view(QWidget *parent) :
QListView(parent)
{
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowDoesNotAcceptFocus);
}
void M_view::focusOutEvent(QFocusEvent *e)
{
    hide();
}
QVector<QString> M_spinbox::get_items()
{
    return items;
}
void M_spinbox::set_items(QVector<QString> now_items)
{
    QStandardItem * item;
    setRange(0,now_items.length()-1);
    items=now_items;
    int max=0;
    for(int i=0;i<items.count();i++)
    {
        item=new QStandardItem(items.at(i));
        item->setToolTip(items.at(i));
        model->appendRow(item);
        if(items.at(i).length()>max)
            max=items.at(i).length();
    }
    QSize size;
    int width=max/15;
    if (width<1)
        width=1;
    size.setWidth(width*100);
    size.setHeight(items.count()*20+5);
    view->resize(size);
    setToolTip(items.at(0));
}
QString M_spinbox::get_item(int index)
{
    return items.at(index);
}
void M_spinbox::add_item(QString item)
{
    items<<item;
}
void M_spinbox::remove_item(int index)
{
    items.remove(index);
}
void M_spinbox::clear_item()
{
    items.clear();
}

QString M_spinbox::textFromValue(int value) const
{
    if(value<0||items.count()==0)
    {
        return QString(" ");
    }
    return items.at(value);
}
int M_spinbox::valueFromText(const QString& text) const
{
    return items.indexOf(text);
}
void M_spinbox::show_pop()
{
    if(view!=NULL)
    {
        view->setFocus();
        QWidget * p=this;
        QPoint pp=pos();
        for(;!p->isWindow();)
        {
            p=(QWidget *)p->parent();
            pp=p->mapToParent(pp);
        }
        QSize size=view->size();
        set_width(width());
        qDebug()<<deskRect.height()<<view->height();
        if(pp.ry()+view->height()>deskRect.height())
        {
            if(pp.ry()>deskRect.height())
            {
                pp.setY(deskRect.height());
            }else
            {
                pp.setY(deskRect.height()-view->height());
            }
        }
        view->move(pp);
        view->setCurrentIndex(model->index(value(),0));
        view->show();
    }
}

void M_spinbox::set_width(int width)
{
    QSize size=view->size();
    size.setWidth(width);
    view->resize(size);
}
bool M_spinbox::eventFilter(QObject *target, QEvent *event)
{
    if(target == lineEdit())
    {
        if(!isEnabled())
            return 0;
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                show_pop();
            }
            return true;
        }
    }
    return 0;
}

void M_spinbox::set_view_parent(QWidget *parent)
{

}
void M_spinbox::set_value(QModelIndex index)
{
    if(index.row()==value())
    {
        emit valueChanged(index.row());
    }
    setValue(view->currentIndex().row());
}
void M_spinbox::set_help(int i)
{
        setToolTip(items.at(i));
}
void M_spinbox::set_text(QString str)
{
    for(int i=0;i<items.count();i++)
    {
        if(items.at(i).compare(str)==0)
        {
            setValue(i);
            return;
        }
    }
}
