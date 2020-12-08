#ifndef SUBMITREPORT_H
#define SUBMITREPORT_H

#include <QObject>
#include "qtsoap.h"
class SubmitReport : public QObject
{
    Q_OBJECT
public:
    explicit SubmitReport(QObject *parent = nullptr);
signals:
    void sendToMainWin(bool flag,QString info);
public slots:
    void onResponse(const QtSoapMessage &);
private slots:
    void slot_qtsoap_send(QStringList);
private:
    QtSoapHttpTransport *m_pHttp;
};

#endif // SUBMITREPORT_H
