#include "TrackerGUI.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    TrackerGUI w;
    w.show();
    return a.exec();

    return 0;
}