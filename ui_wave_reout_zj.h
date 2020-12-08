/********************************************************************************
** Form generated from reading UI file 'wave_reout_zj.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVE_REOUT_ZJ_H
#define UI_WAVE_REOUT_ZJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplothasroll.h>

QT_BEGIN_NAMESPACE

class Ui_wave_reout_ZJ
{
public:
    QGridLayout *gridLayout_11;
    CustomPlotHasRoll *widget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_15;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QPushButton *btAdd;
    QPushButton *btRemove;
    QPushButton *stopOutput;
    QPushButton *startOutput;
    QFrame *frame_5;
    QGridLayout *gridLayout_6;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpinBox *show_start;
    QSpinBox *show_end;
    QLabel *label_2;
    QPushButton *btViewWave;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QRadioButton *eleRev;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_23;
    QDoubleSpinBox *sample;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QComboBox *insertMode;
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_35;
    QDoubleSpinBox *ua_max;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_36;
    QDoubleSpinBox *ia_max;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *output_mode;
    QVBoxLayout *verticalLayout;
    QLabel *label_45;
    QDoubleSpinBox *energy;
    QWidget *tab_2;
    QGridLayout *gridLayout_7;
    QFrame *frame_11;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *eleRev_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QComboBox *insertMode_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_24;
    QDoubleSpinBox *sample_2;
    QFrame *frame_9;
    QGridLayout *gridLayout_12;
    QLabel *label_8;
    QLabel *label_7;
    QSpinBox *show_end_2;
    QSpinBox *show_start_2;
    QPushButton *btViewWave_2;
    QFrame *frame_7;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QComboBox *output_mode_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_46;
    QDoubleSpinBox *energy_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_37;
    QDoubleSpinBox *ua_max_2;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_38;
    QDoubleSpinBox *ia_max_2;
    QFrame *frame_10;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_14;
    QPushButton *stopOutput_2;
    QPushButton *startOutput_2;
    QPushButton *configPipe;
    QPushButton *btRemove_2;
    QPushButton *btAdd_2;
    QPushButton *overlayWave;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableView *scene;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *wave_reout_ZJ)
    {
        if (wave_reout_ZJ->objectName().isEmpty())
            wave_reout_ZJ->setObjectName(QStringLiteral("wave_reout_ZJ"));
        wave_reout_ZJ->resize(800, 600);
        wave_reout_ZJ->setMinimumSize(QSize(0, 0));
        wave_reout_ZJ->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_11 = new QGridLayout(wave_reout_ZJ);
        gridLayout_11->setSpacing(2);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(2, 2, 2, 2);
        widget = new CustomPlotHasRoll(wave_reout_ZJ);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 200));
        widget->setMaximumSize(QSize(16777215, 200));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(170, 85, 127);"));

        gridLayout_11->addWidget(widget, 0, 0, 1, 1);

        tabWidget = new QTabWidget(wave_reout_ZJ);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 220));
        tabWidget->setMaximumSize(QSize(16777215, 220));
        tabWidget->setStyleSheet(QStringLiteral("QTabBar::tab{ min-height: 50px; min-width:60px;}"));
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_15 = new QGridLayout(tab);
        gridLayout_15->setSpacing(2);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(2, 2, 2, 2);
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btAdd = new QPushButton(frame);
        buttonGroup = new QButtonGroup(wave_reout_ZJ);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(btAdd);
        btAdd->setObjectName(QStringLiteral("btAdd"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btAdd->sizePolicy().hasHeightForWidth());
        btAdd->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(btAdd, 1, 0, 1, 1);

        btRemove = new QPushButton(frame);
        buttonGroup->addButton(btRemove);
        btRemove->setObjectName(QStringLiteral("btRemove"));
        sizePolicy2.setHeightForWidth(btRemove->sizePolicy().hasHeightForWidth());
        btRemove->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(btRemove, 1, 1, 1, 1);

        stopOutput = new QPushButton(frame);
        buttonGroup->addButton(stopOutput);
        stopOutput->setObjectName(QStringLiteral("stopOutput"));
        sizePolicy2.setHeightForWidth(stopOutput->sizePolicy().hasHeightForWidth());
        stopOutput->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(stopOutput, 0, 1, 1, 1);

        startOutput = new QPushButton(frame);
        buttonGroup->addButton(startOutput);
        startOutput->setObjectName(QStringLiteral("startOutput"));
        sizePolicy2.setHeightForWidth(startOutput->sizePolicy().hasHeightForWidth());
        startOutput->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(startOutput, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_15->addWidget(frame, 0, 0, 1, 1);

        frame_5 = new QFrame(tab);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_5);
        gridLayout_6->setSpacing(2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(2, 2, 2, 2);
        frame_2 = new QFrame(frame_5);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy3);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 2, 1, 1);

        show_start = new QSpinBox(frame_2);
        show_start->setObjectName(QStringLiteral("show_start"));
        sizePolicy2.setHeightForWidth(show_start->sizePolicy().hasHeightForWidth());
        show_start->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(show_start, 1, 1, 1, 1);

        show_end = new QSpinBox(frame_2);
        show_end->setObjectName(QStringLiteral("show_end"));
        sizePolicy2.setHeightForWidth(show_end->sizePolicy().hasHeightForWidth());
        show_end->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(show_end, 1, 3, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        btViewWave = new QPushButton(frame_2);
        buttonGroup->addButton(btViewWave);
        btViewWave->setObjectName(QStringLiteral("btViewWave"));
        sizePolicy2.setHeightForWidth(btViewWave->sizePolicy().hasHeightForWidth());
        btViewWave->setSizePolicy(sizePolicy2);
        btViewWave->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(btViewWave, 0, 0, 1, 2);


        gridLayout_6->addWidget(frame_2, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frame_3 = new QFrame(frame_5);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setSpacing(2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        eleRev = new QRadioButton(frame_3);
        eleRev->setObjectName(QStringLiteral("eleRev"));

        gridLayout_4->addWidget(eleRev, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_23 = new QLabel(frame_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_23);

        sample = new QDoubleSpinBox(frame_3);
        sample->setObjectName(QStringLiteral("sample"));
        sizePolicy2.setHeightForWidth(sample->sizePolicy().hasHeightForWidth());
        sample->setSizePolicy(sizePolicy2);
        sample->setMaximum(40);
        sample->setValue(20);

        horizontalLayout_2->addWidget(sample);


        gridLayout_4->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_9);

        insertMode = new QComboBox(frame_3);
        insertMode->setObjectName(QStringLiteral("insertMode"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(insertMode->sizePolicy().hasHeightForWidth());
        insertMode->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(insertMode);


        gridLayout_4->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        horizontalLayout_3->addWidget(frame_3);


        gridLayout_6->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        frame_4 = new QFrame(frame_5);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(frame_4);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_35 = new QLabel(frame_4);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy3.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy3);

        horizontalLayout_26->addWidget(label_35);

        ua_max = new QDoubleSpinBox(frame_4);
        ua_max->setObjectName(QStringLiteral("ua_max"));
        sizePolicy2.setHeightForWidth(ua_max->sizePolicy().hasHeightForWidth());
        ua_max->setSizePolicy(sizePolicy2);
        ua_max->setDecimals(5);
        ua_max->setMinimum(0);
        ua_max->setMaximum(999);
        ua_max->setValue(50);

        horizontalLayout_26->addWidget(ua_max);


        verticalLayout_3->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_36 = new QLabel(frame_4);
        label_36->setObjectName(QStringLiteral("label_36"));
        sizePolicy3.setHeightForWidth(label_36->sizePolicy().hasHeightForWidth());
        label_36->setSizePolicy(sizePolicy3);

        horizontalLayout_27->addWidget(label_36);

        ia_max = new QDoubleSpinBox(frame_4);
        ia_max->setObjectName(QStringLiteral("ia_max"));
        sizePolicy2.setHeightForWidth(ia_max->sizePolicy().hasHeightForWidth());
        ia_max->setSizePolicy(sizePolicy2);
        ia_max->setDecimals(5);
        ia_max->setMinimum(0);
        ia_max->setMaximum(999);
        ia_max->setValue(5);

        horizontalLayout_27->addWidget(ia_max);


        verticalLayout_3->addLayout(horizontalLayout_27);


        gridLayout_5->addLayout(verticalLayout_3, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        output_mode = new QComboBox(frame_4);
        output_mode->setObjectName(QStringLiteral("output_mode"));
        sizePolicy2.setHeightForWidth(output_mode->sizePolicy().hasHeightForWidth());
        output_mode->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(output_mode);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_45 = new QLabel(frame_4);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_45);

        energy = new QDoubleSpinBox(frame_4);
        energy->setObjectName(QStringLiteral("energy"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(energy->sizePolicy().hasHeightForWidth());
        energy->setSizePolicy(sizePolicy5);
        energy->setFocusPolicy(Qt::NoFocus);
        energy->setStyleSheet(QLatin1String("QDoubleSpinBox\n"
"{\n"
"	border:1px solid #242424;\n"
"}\n"
" \n"
"QDoubleSpinBox::up-button,QDoubleSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));
        energy->setDecimals(9);
        energy->setMinimum(-1e+09);
        energy->setMaximum(1e+09);

        verticalLayout->addWidget(energy);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout_5->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_4, 0, 0, 1, 2);


        gridLayout_15->addWidget(frame_5, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_7 = new QGridLayout(tab_2);
        gridLayout_7->setSpacing(2);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(2, 2, 2, 2);
        frame_11 = new QFrame(tab_2);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setMinimumSize(QSize(0, 0));
        frame_11->setMaximumSize(QSize(16777215, 16777215));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_11);
        gridLayout_8->setSpacing(2);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(2, 2, 2, 2);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        eleRev_2 = new QRadioButton(frame_11);
        eleRev_2->setObjectName(QStringLiteral("eleRev_2"));

        verticalLayout_7->addWidget(eleRev_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(frame_11);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_10);

        insertMode_2 = new QComboBox(frame_11);
        insertMode_2->setObjectName(QStringLiteral("insertMode_2"));
        sizePolicy4.setHeightForWidth(insertMode_2->sizePolicy().hasHeightForWidth());
        insertMode_2->setSizePolicy(sizePolicy4);

        horizontalLayout_5->addWidget(insertMode_2);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_24 = new QLabel(frame_11);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy1.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(label_24);

        sample_2 = new QDoubleSpinBox(frame_11);
        sample_2->setObjectName(QStringLiteral("sample_2"));
        sizePolicy2.setHeightForWidth(sample_2->sizePolicy().hasHeightForWidth());
        sample_2->setSizePolicy(sizePolicy2);
        sample_2->setMaximum(9999);
        sample_2->setValue(20);

        horizontalLayout_7->addWidget(sample_2);


        verticalLayout_7->addLayout(horizontalLayout_7);


        gridLayout_8->addLayout(verticalLayout_7, 0, 0, 1, 1);

        frame_9 = new QFrame(frame_11);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        sizePolicy3.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy3);
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_9);
        gridLayout_12->setSpacing(2);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(2, 2, 2, 2);
        label_8 = new QLabel(frame_9);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_12->addWidget(label_8, 1, 2, 1, 1);

        label_7 = new QLabel(frame_9);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_12->addWidget(label_7, 1, 0, 1, 1);

        show_end_2 = new QSpinBox(frame_9);
        show_end_2->setObjectName(QStringLiteral("show_end_2"));
        sizePolicy2.setHeightForWidth(show_end_2->sizePolicy().hasHeightForWidth());
        show_end_2->setSizePolicy(sizePolicy2);

        gridLayout_12->addWidget(show_end_2, 1, 3, 1, 1);

        show_start_2 = new QSpinBox(frame_9);
        show_start_2->setObjectName(QStringLiteral("show_start_2"));
        sizePolicy2.setHeightForWidth(show_start_2->sizePolicy().hasHeightForWidth());
        show_start_2->setSizePolicy(sizePolicy2);

        gridLayout_12->addWidget(show_start_2, 1, 1, 1, 1);

        btViewWave_2 = new QPushButton(frame_9);
        btViewWave_2->setObjectName(QStringLiteral("btViewWave_2"));
        sizePolicy2.setHeightForWidth(btViewWave_2->sizePolicy().hasHeightForWidth());
        btViewWave_2->setSizePolicy(sizePolicy2);

        gridLayout_12->addWidget(btViewWave_2, 0, 0, 1, 2);


        gridLayout_8->addWidget(frame_9, 0, 1, 1, 1);


        gridLayout_7->addWidget(frame_11, 1, 1, 1, 1);

        frame_7 = new QFrame(tab_2);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_7);
        gridLayout_10->setSpacing(2);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_6 = new QLabel(frame_7);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_6);

        output_mode_2 = new QComboBox(frame_7);
        output_mode_2->setObjectName(QStringLiteral("output_mode_2"));
        sizePolicy.setHeightForWidth(output_mode_2->sizePolicy().hasHeightForWidth());
        output_mode_2->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(output_mode_2);


        gridLayout_10->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_46 = new QLabel(frame_7);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_46);

        energy_2 = new QDoubleSpinBox(frame_7);
        energy_2->setObjectName(QStringLiteral("energy_2"));
        sizePolicy5.setHeightForWidth(energy_2->sizePolicy().hasHeightForWidth());
        energy_2->setSizePolicy(sizePolicy5);
        energy_2->setFocusPolicy(Qt::NoFocus);
        energy_2->setStyleSheet(QLatin1String("QDoubleSpinBox\n"
"{\n"
"	border:1px solid #242424;\n"
"}\n"
" \n"
"QDoubleSpinBox::up-button,QDoubleSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));
        energy_2->setDecimals(9);
        energy_2->setMinimum(-1e+09);
        energy_2->setMaximum(1e+09);

        verticalLayout_6->addWidget(energy_2);


        gridLayout_10->addLayout(verticalLayout_6, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_37 = new QLabel(frame_7);
        label_37->setObjectName(QStringLiteral("label_37"));
        sizePolicy3.setHeightForWidth(label_37->sizePolicy().hasHeightForWidth());
        label_37->setSizePolicy(sizePolicy3);

        horizontalLayout_28->addWidget(label_37);

        ua_max_2 = new QDoubleSpinBox(frame_7);
        ua_max_2->setObjectName(QStringLiteral("ua_max_2"));
        sizePolicy2.setHeightForWidth(ua_max_2->sizePolicy().hasHeightForWidth());
        ua_max_2->setSizePolicy(sizePolicy2);
        ua_max_2->setDecimals(5);
        ua_max_2->setMinimum(0);
        ua_max_2->setMaximum(999);
        ua_max_2->setValue(50);

        horizontalLayout_28->addWidget(ua_max_2);


        verticalLayout_4->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        label_38 = new QLabel(frame_7);
        label_38->setObjectName(QStringLiteral("label_38"));
        sizePolicy3.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy3);

        horizontalLayout_29->addWidget(label_38);

        ia_max_2 = new QDoubleSpinBox(frame_7);
        ia_max_2->setObjectName(QStringLiteral("ia_max_2"));
        sizePolicy2.setHeightForWidth(ia_max_2->sizePolicy().hasHeightForWidth());
        ia_max_2->setSizePolicy(sizePolicy2);
        ia_max_2->setDecimals(5);
        ia_max_2->setMinimum(0);
        ia_max_2->setMaximum(999);
        ia_max_2->setValue(5);

        horizontalLayout_29->addWidget(ia_max_2);


        verticalLayout_4->addLayout(horizontalLayout_29);


        gridLayout_10->addLayout(verticalLayout_4, 0, 2, 1, 1);


        gridLayout_7->addWidget(frame_7, 0, 1, 1, 1);

        frame_10 = new QFrame(tab_2);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        sizePolicy3.setHeightForWidth(frame_10->sizePolicy().hasHeightForWidth());
        frame_10->setSizePolicy(sizePolicy3);
        frame_10->setMinimumSize(QSize(0, 0));
        frame_10->setMaximumSize(QSize(16777215, 16777215));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame_10);
        gridLayout_9->setSpacing(2);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(2, 2, 2, 2);
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setSpacing(2);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        stopOutput_2 = new QPushButton(frame_10);
        stopOutput_2->setObjectName(QStringLiteral("stopOutput_2"));
        sizePolicy2.setHeightForWidth(stopOutput_2->sizePolicy().hasHeightForWidth());
        stopOutput_2->setSizePolicy(sizePolicy2);
        stopOutput_2->setMinimumSize(QSize(0, 0));

        gridLayout_14->addWidget(stopOutput_2, 1, 2, 1, 1);

        startOutput_2 = new QPushButton(frame_10);
        startOutput_2->setObjectName(QStringLiteral("startOutput_2"));
        sizePolicy2.setHeightForWidth(startOutput_2->sizePolicy().hasHeightForWidth());
        startOutput_2->setSizePolicy(sizePolicy2);
        startOutput_2->setMinimumSize(QSize(0, 0));

        gridLayout_14->addWidget(startOutput_2, 0, 2, 1, 1);

        configPipe = new QPushButton(frame_10);
        configPipe->setObjectName(QStringLiteral("configPipe"));
        sizePolicy2.setHeightForWidth(configPipe->sizePolicy().hasHeightForWidth());
        configPipe->setSizePolicy(sizePolicy2);
        configPipe->setMinimumSize(QSize(0, 0));

        gridLayout_14->addWidget(configPipe, 1, 1, 1, 1);

        btRemove_2 = new QPushButton(frame_10);
        btRemove_2->setObjectName(QStringLiteral("btRemove_2"));
        sizePolicy2.setHeightForWidth(btRemove_2->sizePolicy().hasHeightForWidth());
        btRemove_2->setSizePolicy(sizePolicy2);
        btRemove_2->setMinimumSize(QSize(0, 0));

        gridLayout_14->addWidget(btRemove_2, 1, 0, 1, 1);

        btAdd_2 = new QPushButton(frame_10);
        btAdd_2->setObjectName(QStringLiteral("btAdd_2"));
        sizePolicy2.setHeightForWidth(btAdd_2->sizePolicy().hasHeightForWidth());
        btAdd_2->setSizePolicy(sizePolicy2);
        btAdd_2->setMinimumSize(QSize(0, 0));

        gridLayout_14->addWidget(btAdd_2, 0, 0, 1, 1);

        overlayWave = new QPushButton(frame_10);
        overlayWave->setObjectName(QStringLiteral("overlayWave"));
        sizePolicy2.setHeightForWidth(overlayWave->sizePolicy().hasHeightForWidth());
        overlayWave->setSizePolicy(sizePolicy2);
        overlayWave->setMinimumSize(QSize(0, 0));

        gridLayout_14->addWidget(overlayWave, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_14, 1, 0, 1, 1);

        scrollArea = new QScrollArea(frame_10);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(16777215, 200));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgb(120, 170, 220);"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 364, 83));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_9->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_7->addWidget(frame_10, 0, 0, 2, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_11->addWidget(tabWidget, 1, 0, 1, 1);

        scene = new QTableView(wave_reout_ZJ);
        scene->setObjectName(QStringLiteral("scene"));
        sizePolicy1.setHeightForWidth(scene->sizePolicy().hasHeightForWidth());
        scene->setSizePolicy(sizePolicy1);
        scene->setMinimumSize(QSize(0, 150));
        scene->setMaximumSize(QSize(16777215, 150));

        gridLayout_11->addWidget(scene, 2, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(wave_reout_ZJ);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(wave_reout_ZJ);
    } // setupUi

    void retranslateUi(QWidget *wave_reout_ZJ)
    {
        wave_reout_ZJ->setWindowTitle(QApplication::translate("wave_reout_ZJ", "Form", 0));
        btAdd->setText(QApplication::translate("wave_reout_ZJ", "\345\234\272\346\231\257\345\257\274\345\205\245", 0));
        btRemove->setText(QApplication::translate("wave_reout_ZJ", "\345\234\272\346\231\257\345\210\240\351\231\244", 0));
        stopOutput->setText(QApplication::translate("wave_reout_ZJ", "\345\201\234\346\255\242\345\233\236\346\224\276", 0));
        startOutput->setText(QApplication::translate("wave_reout_ZJ", "\345\220\257\345\212\250\345\233\236\346\224\276", 0));
        label_3->setText(QApplication::translate("wave_reout_ZJ", "\347\273\210\347\202\271", 0));
        label_2->setText(QApplication::translate("wave_reout_ZJ", "\350\265\267\347\202\271", 0));
        btViewWave->setText(QApplication::translate("wave_reout_ZJ", "\346\263\242\345\275\242\351\242\204\350\247\210", 0));
        eleRev->setText(QApplication::translate("wave_reout_ZJ", "  \347\224\265\346\265\201\345\217\215\347\233\270", 0));
        label_23->setText(QApplication::translate("wave_reout_ZJ", "\350\275\254\346\215\242\345\220\216\351\207\207\346\240\267\347\216\207", 0));
        sample->setSuffix(QApplication::translate("wave_reout_ZJ", "k", 0));
        label_9->setText(QApplication::translate("wave_reout_ZJ", " \346\217\222\345\200\274\347\256\227\346\263\225", 0));
        insertMode->clear();
        insertMode->insertItems(0, QStringList()
         << QApplication::translate("wave_reout_ZJ", "\346\213\211\346\240\274\346\234\227\346\227\245-3\351\230\266", 0)
         << QApplication::translate("wave_reout_ZJ", "\347\272\277\346\200\247", 0)
        );
        label->setText(QApplication::translate("wave_reout_ZJ", "  \345\263\260\345\200\274", 0));
        label_35->setText(QApplication::translate("wave_reout_ZJ", "UA", 0));
        label_36->setText(QApplication::translate("wave_reout_ZJ", "IA", 0));
        label_4->setText(QApplication::translate("wave_reout_ZJ", "\350\276\223\345\207\272\347\233\270", 0));
        output_mode->clear();
        output_mode->insertItems(0, QStringList()
         << QApplication::translate("wave_reout_ZJ", "A\347\233\270", 0)
         << QApplication::translate("wave_reout_ZJ", "\344\270\211\347\233\270\345\271\266\350\201\224", 0)
        );
        label_45->setText(QApplication::translate("wave_reout_ZJ", "\347\220\206\350\256\272\347\224\265\350\203\275", 0));
        energy->setSuffix(QApplication::translate("wave_reout_ZJ", "kWh", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("wave_reout_ZJ", "CSV\346\240\274\345\274\217", 0));
        eleRev_2->setText(QApplication::translate("wave_reout_ZJ", "  \347\224\265\346\265\201\345\217\215\347\233\270", 0));
        label_10->setText(QApplication::translate("wave_reout_ZJ", " \346\217\222\345\200\274\347\256\227\346\263\225", 0));
        insertMode_2->clear();
        insertMode_2->insertItems(0, QStringList()
         << QApplication::translate("wave_reout_ZJ", "\346\213\211\346\240\274\346\234\227\346\227\245-3\351\230\266", 0)
         << QApplication::translate("wave_reout_ZJ", "\347\272\277\346\200\247", 0)
        );
        label_24->setText(QApplication::translate("wave_reout_ZJ", "\350\275\254\346\215\242\345\220\216\351\207\207\346\240\267\347\216\207", 0));
        sample_2->setSuffix(QApplication::translate("wave_reout_ZJ", "k", 0));
        label_8->setText(QApplication::translate("wave_reout_ZJ", "\347\273\210\347\202\271", 0));
        label_7->setText(QApplication::translate("wave_reout_ZJ", "\350\265\267\347\202\271", 0));
        btViewWave_2->setText(QApplication::translate("wave_reout_ZJ", "\346\263\242\345\275\242\351\242\204\350\247\210", 0));
        label_6->setText(QApplication::translate("wave_reout_ZJ", "\350\276\223\345\207\272\347\233\270", 0));
        output_mode_2->clear();
        output_mode_2->insertItems(0, QStringList()
         << QApplication::translate("wave_reout_ZJ", "A\347\233\270", 0)
         << QApplication::translate("wave_reout_ZJ", "\344\270\211\347\233\270\345\271\266\350\201\224", 0)
        );
        label_46->setText(QApplication::translate("wave_reout_ZJ", "\347\220\206\350\256\272\347\224\265\350\203\275", 0));
        energy_2->setSuffix(QApplication::translate("wave_reout_ZJ", "kWh", 0));
        label_5->setText(QApplication::translate("wave_reout_ZJ", "  \345\263\260\345\200\274", 0));
        label_37->setText(QApplication::translate("wave_reout_ZJ", "UA", 0));
        label_38->setText(QApplication::translate("wave_reout_ZJ", "IA", 0));
        stopOutput_2->setText(QApplication::translate("wave_reout_ZJ", "\345\201\234\346\255\242\345\233\236\346\224\276", 0));
        startOutput_2->setText(QApplication::translate("wave_reout_ZJ", "\345\220\257\345\212\250\345\233\236\346\224\276", 0));
        configPipe->setText(QApplication::translate("wave_reout_ZJ", "\351\200\232\351\201\223\351\205\215\347\275\256", 0));
        btRemove_2->setText(QApplication::translate("wave_reout_ZJ", "\345\234\272\346\231\257\345\210\240\351\231\244", 0));
        btAdd_2->setText(QApplication::translate("wave_reout_ZJ", "\345\234\272\346\231\257\345\257\274\345\205\245", 0));
        overlayWave->setText(QApplication::translate("wave_reout_ZJ", "\347\224\265\346\265\201\345\217\240\345\212\240", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("wave_reout_ZJ", "Comtrade\346\240\274\345\274\217", 0));
    } // retranslateUi

};

namespace Ui {
    class wave_reout_ZJ: public Ui_wave_reout_ZJ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVE_REOUT_ZJ_H
