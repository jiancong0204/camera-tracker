#pragma once
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMainWindow>

class GUI : public QDialog
{
    Q_OBJECT

public:
    GUI(QWidget *parent = 0);
    ~GUI() {};


private:
    QPushButton     *initialize;         //< Push button for initialization
    QPushButton     *startTracking;      //< Push button for starting tracking 
    QPushButton     *moveAbsolute;       //< Push button for moving absolute
    QPushButton     *moveRelative;       //< Push button for moving relative
    QPushButton     *poseEstimation;     //< Push button for pose estimation
    QLineEdit       *azimuth_value;      //< Line editor for azimuth angle
    QLineEdit       *elevation_value;    //< Line editor for elevation angle
    QLabel          *azimuth;            //< Label for azimuth
    QLabel          *elevation;          //< Label for elevation
    QLabel          *translation;        //< Label for translation vector
    QLabel          *rotation;           //< Label for rotation vector
    QLabel          *translation_x;
    QLabel          *translation_y;
    QLabel          *translation_z;

    void initializeGUI();

    //void initializeSlots();

};