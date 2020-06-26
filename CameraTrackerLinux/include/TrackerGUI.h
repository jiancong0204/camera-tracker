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

private slots:

    /**
     * @brief Slot for initialization
     * 
     */
    void initializationSlot();

    /**
     * @brief  Slot for moving in positive x
     * 
     */
	void movePositiveXSlot();

    /**
     * @brief Slot for moving in negative x
     * 
     */
	void moveNegativeXSlot();

    /**
     * @brief Slot for moving in positive y
     * 
     */
	void movePositiveYSlot();

    /**
     * @brief Slot for moving in negative y
     * 
     */
	void moveNegativeYSlot();

    /**
     * @brief Slot for absolute moving in x-direction
     * 
     */
	void gotoXSlot();

    /**
     * @brief Slot for absolute moving in y-direction
     * 
     */
	void gotoYSlot();

    /**
     * @brief Slot for pose estimation
     * 
     */
    void cameraPoseEstimationSlot();
};

#endif // TRACKERGUI_H
