/********************************************************************************
** Form generated from reading UI file 'TrackerGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKERGUI_H
#define UI_TRACKERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrackerGUI
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *streaming;
    QVBoxLayout *verticalLayout;
    QPushButton *initialization;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *trackingModePin;
    QPushButton *trackingMode;
    QFrame *line;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QPushButton *moveNegative_x;
    QLineEdit *displacement_x;
    QPushButton *movePositive_x;
    QPushButton *goto_x;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QPushButton *moveNegative_y;
    QLineEdit *displacement_y;
    QPushButton *movePositive_y;
    QPushButton *goto_y;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QPushButton *cameraPoseEstimate;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *translation_x;
    QLabel *translation_y;
    QLabel *translation_z;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *rotation_x;
    QLabel *rotation_y;
    QLabel *rotation_z;
    QFrame *line_3;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLabel *barcode;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLabel *qrcode;
    QFrame *line_4;
    QLabel *warning;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrackerGUI)
    {
        if (TrackerGUI->objectName().isEmpty())
            TrackerGUI->setObjectName(QStringLiteral("TrackerGUI"));
        TrackerGUI->resize(1190, 760);
        centralWidget = new QWidget(TrackerGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(16);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        streaming = new QLabel(centralWidget);
        streaming->setObjectName(QStringLiteral("streaming"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(streaming->sizePolicy().hasHeightForWidth());
        streaming->setSizePolicy(sizePolicy);
        streaming->setMinimumSize(QSize(860, 620));
        streaming->setMaximumSize(QSize(860, 620));

        horizontalLayout_6->addWidget(streaming);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        initialization = new QPushButton(centralWidget);
        initialization->setObjectName(QStringLiteral("initialization"));
        initialization->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(initialization->sizePolicy().hasHeightForWidth());
        initialization->setSizePolicy(sizePolicy1);
        initialization->setMinimumSize(QSize(228, 25));
        initialization->setMaximumSize(QSize(5000, 25));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        initialization->setFont(font);
        initialization->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(initialization);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        trackingModePin = new QLineEdit(centralWidget);
        trackingModePin->setObjectName(QStringLiteral("trackingModePin"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(trackingModePin->sizePolicy().hasHeightForWidth());
        trackingModePin->setSizePolicy(sizePolicy2);
        trackingModePin->setMinimumSize(QSize(86, 22));
        trackingModePin->setMaximumSize(QSize(86, 22));
        trackingModePin->setFont(font);

        horizontalLayout_7->addWidget(trackingModePin);

        trackingMode = new QPushButton(centralWidget);
        trackingMode->setObjectName(QStringLiteral("trackingMode"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(trackingMode->sizePolicy().hasHeightForWidth());
        trackingMode->setSizePolicy(sizePolicy3);
        trackingMode->setMinimumSize(QSize(138, 25));
        trackingMode->setMaximumSize(QSize(50000, 25));
        trackingMode->setFont(font);
        trackingMode->setCursor(QCursor(Qt::PointingHandCursor));
        trackingMode->setMouseTracking(false);

        horizontalLayout_7->addWidget(trackingMode);


        verticalLayout->addLayout(horizontalLayout_7);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(228, 25));
        label->setMaximumSize(QSize(5000, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(60, 25));
        label_3->setMaximumSize(QSize(60, 25));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        moveNegative_x = new QPushButton(centralWidget);
        moveNegative_x->setObjectName(QStringLiteral("moveNegative_x"));
        sizePolicy2.setHeightForWidth(moveNegative_x->sizePolicy().hasHeightForWidth());
        moveNegative_x->setSizePolicy(sizePolicy2);
        moveNegative_x->setMinimumSize(QSize(40, 25));
        moveNegative_x->setMaximumSize(QSize(40, 25));
        moveNegative_x->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(moveNegative_x, 0, Qt::AlignLeft);

        displacement_x = new QLineEdit(centralWidget);
        displacement_x->setObjectName(QStringLiteral("displacement_x"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(10);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(displacement_x->sizePolicy().hasHeightForWidth());
        displacement_x->setSizePolicy(sizePolicy4);
        displacement_x->setMinimumSize(QSize(80, 22));
        displacement_x->setMaximumSize(QSize(5000, 22));
        displacement_x->setFont(font);

        horizontalLayout_2->addWidget(displacement_x);

        movePositive_x = new QPushButton(centralWidget);
        movePositive_x->setObjectName(QStringLiteral("movePositive_x"));
        sizePolicy2.setHeightForWidth(movePositive_x->sizePolicy().hasHeightForWidth());
        movePositive_x->setSizePolicy(sizePolicy2);
        movePositive_x->setMinimumSize(QSize(40, 25));
        movePositive_x->setMaximumSize(QSize(40, 25));
        movePositive_x->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(movePositive_x, 0, Qt::AlignRight);

        goto_x = new QPushButton(centralWidget);
        goto_x->setObjectName(QStringLiteral("goto_x"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(goto_x->sizePolicy().hasHeightForWidth());
        goto_x->setSizePolicy(sizePolicy5);
        goto_x->setMinimumSize(QSize(62, 25));
        goto_x->setMaximumSize(QSize(62, 25));
        goto_x->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(goto_x);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(60, 25));
        label_4->setMaximumSize(QSize(60, 25));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        moveNegative_y = new QPushButton(centralWidget);
        moveNegative_y->setObjectName(QStringLiteral("moveNegative_y"));
        sizePolicy2.setHeightForWidth(moveNegative_y->sizePolicy().hasHeightForWidth());
        moveNegative_y->setSizePolicy(sizePolicy2);
        moveNegative_y->setMinimumSize(QSize(40, 25));
        moveNegative_y->setMaximumSize(QSize(40, 25));
        moveNegative_y->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(moveNegative_y, 0, Qt::AlignLeft);

        displacement_y = new QLineEdit(centralWidget);
        displacement_y->setObjectName(QStringLiteral("displacement_y"));
        sizePolicy4.setHeightForWidth(displacement_y->sizePolicy().hasHeightForWidth());
        displacement_y->setSizePolicy(sizePolicy4);
        displacement_y->setMinimumSize(QSize(80, 22));
        displacement_y->setMaximumSize(QSize(5000, 22));
        displacement_y->setFont(font);

        horizontalLayout->addWidget(displacement_y);

        movePositive_y = new QPushButton(centralWidget);
        movePositive_y->setObjectName(QStringLiteral("movePositive_y"));
        sizePolicy2.setHeightForWidth(movePositive_y->sizePolicy().hasHeightForWidth());
        movePositive_y->setSizePolicy(sizePolicy2);
        movePositive_y->setMinimumSize(QSize(30, 25));
        movePositive_y->setMaximumSize(QSize(40, 25));
        movePositive_y->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(movePositive_y, 0, Qt::AlignRight);

        goto_y = new QPushButton(centralWidget);
        goto_y->setObjectName(QStringLiteral("goto_y"));
        sizePolicy5.setHeightForWidth(goto_y->sizePolicy().hasHeightForWidth());
        goto_y->setSizePolicy(sizePolicy5);
        goto_y->setMinimumSize(QSize(62, 25));
        goto_y->setMaximumSize(QSize(62, 25));
        goto_y->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(goto_y);


        verticalLayout->addLayout(horizontalLayout);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(228, 0));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(90, 25));
        label_2->setMaximumSize(QSize(90, 25));
        label_2->setFont(font1);

        horizontalLayout_8->addWidget(label_2);

        cameraPoseEstimate = new QPushButton(centralWidget);
        cameraPoseEstimate->setObjectName(QStringLiteral("cameraPoseEstimate"));
        cameraPoseEstimate->setMinimumSize(QSize(100, 25));
        cameraPoseEstimate->setMaximumSize(QSize(16777215, 25));
        cameraPoseEstimate->setFont(font);
        cameraPoseEstimate->setCursor(QCursor(Qt::PointingHandCursor));
        cameraPoseEstimate->setMouseTracking(true);

        horizontalLayout_8->addWidget(cameraPoseEstimate);


        verticalLayout->addLayout(horizontalLayout_8);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(228, 25));
        label_5->setMaximumSize(QSize(5000, 25));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        translation_x = new QLabel(centralWidget);
        translation_x->setObjectName(QStringLiteral("translation_x"));
        sizePolicy5.setHeightForWidth(translation_x->sizePolicy().hasHeightForWidth());
        translation_x->setSizePolicy(sizePolicy5);
        translation_x->setMinimumSize(QSize(70, 15));
        translation_x->setMaximumSize(QSize(1500, 15));
        translation_x->setFont(font);
        translation_x->setFocusPolicy(Qt::NoFocus);
        translation_x->setFrameShadow(QFrame::Plain);
        translation_x->setTextFormat(Qt::AutoText);
        translation_x->setWordWrap(false);

        horizontalLayout_3->addWidget(translation_x);

        translation_y = new QLabel(centralWidget);
        translation_y->setObjectName(QStringLiteral("translation_y"));
        sizePolicy5.setHeightForWidth(translation_y->sizePolicy().hasHeightForWidth());
        translation_y->setSizePolicy(sizePolicy5);
        translation_y->setMinimumSize(QSize(70, 15));
        translation_y->setMaximumSize(QSize(1500, 15));
        translation_y->setFont(font);
        translation_y->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(translation_y);

        translation_z = new QLabel(centralWidget);
        translation_z->setObjectName(QStringLiteral("translation_z"));
        sizePolicy5.setHeightForWidth(translation_z->sizePolicy().hasHeightForWidth());
        translation_z->setSizePolicy(sizePolicy5);
        translation_z->setMinimumSize(QSize(70, 15));
        translation_z->setMaximumSize(QSize(1500, 15));
        translation_z->setFont(font);
        translation_z->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(translation_z);


        verticalLayout->addLayout(horizontalLayout_3);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(228, 25));
        label_6->setMaximumSize(QSize(16777215, 25));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        rotation_x = new QLabel(centralWidget);
        rotation_x->setObjectName(QStringLiteral("rotation_x"));
        rotation_x->setMinimumSize(QSize(70, 15));
        rotation_x->setMaximumSize(QSize(16777215, 15));
        rotation_x->setFont(font);

        horizontalLayout_5->addWidget(rotation_x);

        rotation_y = new QLabel(centralWidget);
        rotation_y->setObjectName(QStringLiteral("rotation_y"));
        rotation_y->setMinimumSize(QSize(70, 15));
        rotation_y->setMaximumSize(QSize(16777215, 15));
        rotation_y->setFont(font);

        horizontalLayout_5->addWidget(rotation_y);

        rotation_z = new QLabel(centralWidget);
        rotation_z->setObjectName(QStringLiteral("rotation_z"));
        rotation_z->setMinimumSize(QSize(70, 15));
        rotation_z->setMaximumSize(QSize(16777215, 15));
        rotation_z->setFont(font);

        horizontalLayout_5->addWidget(rotation_z);


        verticalLayout->addLayout(horizontalLayout_5);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setMinimumSize(QSize(228, 0));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(110, 25));
        label_7->setMaximumSize(QSize(110, 25));
        label_7->setFont(font1);

        verticalLayout->addWidget(label_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(70, 25));
        label_9->setMaximumSize(QSize(70, 25));
        QFont font2;
        font2.setFamily(QStringLiteral("Nimbus Roman No9 L"));
        label_9->setFont(font2);

        horizontalLayout_9->addWidget(label_9);

        barcode = new QLabel(centralWidget);
        barcode->setObjectName(QStringLiteral("barcode"));
        barcode->setMinimumSize(QSize(0, 15));
        barcode->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_9->addWidget(barcode);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(50, 25));
        label_10->setMaximumSize(QSize(70, 25));
        label_10->setFont(font2);

        horizontalLayout_10->addWidget(label_10, 0, Qt::AlignVCenter);

        qrcode = new QLabel(centralWidget);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setMinimumSize(QSize(0, 15));
        qrcode->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_10->addWidget(qrcode);


        verticalLayout->addLayout(horizontalLayout_10);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        warning = new QLabel(centralWidget);
        warning->setObjectName(QStringLiteral("warning"));
        sizePolicy.setHeightForWidth(warning->sizePolicy().hasHeightForWidth());
        warning->setSizePolicy(sizePolicy);
        warning->setMinimumSize(QSize(228, 200));
        warning->setMaximumSize(QSize(5000, 5000));
        QFont font3;
        font3.setFamily(QStringLiteral("Times New Roman"));
        font3.setPointSize(12);
        warning->setFont(font3);

        verticalLayout->addWidget(warning);


        horizontalLayout_6->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        TrackerGUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TrackerGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1190, 22));
        TrackerGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrackerGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TrackerGUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TrackerGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TrackerGUI->setStatusBar(statusBar);

        retranslateUi(TrackerGUI);

        QMetaObject::connectSlotsByName(TrackerGUI);
    } // setupUi

    void retranslateUi(QMainWindow *TrackerGUI)
    {
        TrackerGUI->setWindowTitle(QApplication::translate("TrackerGUI", "GUI", 0));
        streaming->setText(QApplication::translate("TrackerGUI", "TextLabel", 0));
        initialization->setText(QApplication::translate("TrackerGUI", "Initialization", 0));
        trackingModePin->setText(QApplication::translate("TrackerGUI", "WZL", 0));
        trackingMode->setText(QApplication::translate("TrackerGUI", "Tracking", 0));
        label->setText(QApplication::translate("TrackerGUI", "Rotation", 0));
        label_3->setText(QApplication::translate("TrackerGUI", "Elevation:", 0));
        moveNegative_x->setText(QApplication::translate("TrackerGUI", "\342\206\220", 0));
        movePositive_x->setText(QApplication::translate("TrackerGUI", "\342\206\222", 0));
        goto_x->setText(QApplication::translate("TrackerGUI", "GoTo", 0));
        label_4->setText(QApplication::translate("TrackerGUI", "Azimuth:", 0));
        moveNegative_y->setText(QApplication::translate("TrackerGUI", "\342\206\220", 0));
        movePositive_y->setText(QApplication::translate("TrackerGUI", "\342\206\222", 0));
        goto_y->setText(QApplication::translate("TrackerGUI", "GoTo", 0));
        label_2->setText(QApplication::translate("TrackerGUI", "Camera Pose", 0));
        cameraPoseEstimate->setText(QApplication::translate("TrackerGUI", "Estimate", 0));
        label_5->setText(QApplication::translate("TrackerGUI", "Translation Vector [mm]:", 0));
        translation_x->setText(QApplication::translate("TrackerGUI", "0.00", 0));
        translation_y->setText(QApplication::translate("TrackerGUI", "0.00", 0));
        translation_z->setText(QApplication::translate("TrackerGUI", "0.00", 0));
        label_6->setText(QApplication::translate("TrackerGUI", "Rotation Vector [rad]:", 0));
        rotation_x->setText(QApplication::translate("TrackerGUI", "0.00", 0));
        rotation_y->setText(QApplication::translate("TrackerGUI", "0.00", 0));
        rotation_z->setText(QApplication::translate("TrackerGUI", "0.00", 0));
        label_7->setText(QApplication::translate("TrackerGUI", "Code Scanning", 0));
        label_9->setText(QApplication::translate("TrackerGUI", "Barcode:", 0));
        barcode->setText(QString());
        label_10->setText(QApplication::translate("TrackerGUI", "QR-Code:", 0));
        qrcode->setText(QString());
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TrackerGUI: public Ui_TrackerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKERGUI_H
