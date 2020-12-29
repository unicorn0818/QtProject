#include "customplothasroll.h"
#include <qdebug.h>

CustomPlotHasRoll::CustomPlotHasRoll(QWidget *parent)
    : QCustomPlot(parent)
{
	setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
		QCP::iSelectLegend | QCP::iSelectPlottables);

    connect(this, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    connect(this, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(this, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));

}

CustomPlotHasRoll::~CustomPlotHasRoll()
{

}
void CustomPlotHasRoll::mousePress()
{
    if (xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"xAxis Press";
        axisRect()->setRangeDrag(xAxis->orientation());
    }else if (xAxis2->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"xAxis2 Press";
        axisRect()->setRangeDrag(xAxis2->orientation());
    }else if (yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"yAxis Press";
        axisRect()->setRangeDrag(yAxis->orientation());
    }else if(yAxis2->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"yAxis2 Press";
        axisRect()->setRangeDrag(yAxis2->orientation());
    }else
    {
        //qDebug() <<"other Press";
        axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
    }
}
void CustomPlotHasRoll::mouseWheel()
{
    if (xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"xAxis whell";
        axisRect()->setRangeZoom(xAxis->orientation());
    }else if (xAxis2->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"xAxis2 whell";
        axisRect()->setRangeZoom(xAxis2->orientation());
    }else if (yAxis->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"yAxis whell";
        axisRect()->setRangeZoom(yAxis->orientation());
    }else if (yAxis2->selectedParts().testFlag(QCPAxis::spAxis))
    {
        //qDebug() <<"yAxis2 whell";
        axisRect()->setRangeZoom(yAxis2->orientation());
    }else
    {
        axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
    }
}
void CustomPlotHasRoll::selectionChanged()
{
    // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if(xAxis->selectedParts().testFlag(QCPAxis::spAxis) || xAxis->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        //qDebug() <<"xAxis select";
        xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }
    if(xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        //qDebug() <<"xAxis2 select";
        xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }
    // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if(yAxis->selectedParts().testFlag(QCPAxis::spAxis) || yAxis->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        //qDebug() <<"yAxis select";
        yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }
    if(yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        //qDebug() <<"yAxis2 select";
        yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }

    // synchronize selection of graphs with selection of corresponding legend items:

    for (int i=0; i<graphCount(); ++i)
    {
        QCPGraph *gra = this->graph(i);
        QCPPlottableLegendItem *item = legend->itemWithPlottable(gra);
        if (item->selected() || gra->selected())
        {
            //qDebug() << i << "isSetSel";
            item->setSelected(true);
            gra->setSelection(QCPDataSelection(gra->data()->dataRange()));
        }
    }
}
