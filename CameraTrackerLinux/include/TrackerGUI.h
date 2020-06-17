#ifndef TRACKERGUI_H
#define TRACKERGUI_H

#include <QMainWindow>
#include <QApplication>

namespace Ui {
class TrackerGUI;
}

class TrackerGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrackerGUI(QWidget *parent = 0);
    ~TrackerGUI();

private:
    Ui::TrackerGUI *ui;
};

#endif // TRACKERGUI_H
