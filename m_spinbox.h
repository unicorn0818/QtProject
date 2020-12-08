#ifndef M_SPINBOX_H
#define M_SPINBOX_H
#include <QSpinBox>
#include <QLineEdit>
#include <QWidget>
#include <QDebug>
#include <QStandardItemModel>
#include <QListView>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>

#include "QMainWindow"
class M_view : public QListView
{
    Q_OBJECT
public:
    explicit M_view(QWidget *parent = 0);
    void focusOutEvent(QFocusEvent *e);
};
class M_spinbox : public QSpinBox
{
    Q_OBJECT
public:
    explicit M_spinbox(QWidget *parent = 0);
    QVector<QString> get_items();
    void set_items(QVector<QString> now_items);
    QString get_item(int index);
    void add_item(QString item);
    void remove_item(int index);
    void clear_item();
    void set_view_parent(QWidget * parent);
    void set_text(QString str);
signals:
    void clicked(QMouseEvent * event);
private slots:
    void show_pop();
    void set_value(QModelIndex);
    void set_help(int i);
protected:
    void set_width(int width);
    virtual QString textFromValue(int value) const;
    virtual int valueFromText(const QString& text) const;
    QStandardItemModel * model;
    QVector<QString> items;
    M_view * view;
    bool eventFilter(QObject *target, QEvent *event);
    QRect deskRect;
};

#endif // M_SPINBOX_H
