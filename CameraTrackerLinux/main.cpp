#include "TrackerGUI.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    TrackerGUI w;
    w.setWindowTitle("Camera Tracker");
	QIcon icon("../Images/target.png");
	w.setWindowIcon(icon);
    w.show();
    return a.exec();
}