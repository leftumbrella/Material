#ifndef MAINSCENES_H
#define MAINSCENES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScenes; }
QT_END_NAMESPACE

class MainScenes : public QWidget
{
    Q_OBJECT

public:
    MainScenes(QWidget *parent = nullptr);
    ~MainScenes();

private:
    Ui::MainScenes *ui;
};
#endif // MAINSCENES_H
