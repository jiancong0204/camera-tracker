#include "TrackerGUI.h"
#include "ui_TrackerGUI.h"

TrackerGUI::TrackerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrackerGUI)
{
    ui->setupUi(this);
}

TrackerGUI::~TrackerGUI()
{
    delete ui;
}
