#ifndef CUSTOMPLOTHASROLL_H
#define CUSTOMPLOTHASROLL_H

#include "QCustomPlot/qcustomplot.h"

class CustomPlotHasRoll : public QCustomPlot
{
	Q_OBJECT

public:
	CustomPlotHasRoll(QWidget *parent = 0);
	~CustomPlotHasRoll();
private:
    bool mZoomMode;
      QRubberBand * mRubberBand;
      QPoint mOrigin;
private slots:
    void mousePress();
    void mouseWheel();
	void selectionChanged();
};

#endif // CUSTOMPLOTHASROLL_H
