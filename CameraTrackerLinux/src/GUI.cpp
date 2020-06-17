#include "GUI.h"

GUI::GUI(QWidget *parent) : QDialog(parent)
{
    initializeGUI(); // Layout of the UI
    //initializeSlots();
    setWindowTitle("Camera Tracker - WZL");
}

void GUI::initializeGUI()
{
    initialize = new QPushButton(tr("Initialize Tracker"));
    startTracking = new QPushButton(tr("Start Tracking"));
    QVBoxLayout *VLay1=new QVBoxLayout;
    VLay1->addStretch();
    VLay1->addWidget(initialize);
    VLay1->addWidget(startTracking);
    setLayout(VLay1); 
}