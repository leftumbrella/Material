#include "mainscenes.h"
#include "ui_mainscenes.h"

MainScenes::MainScenes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScenes)
{
    ui->setupUi(this);
}

MainScenes::~MainScenes()
{
    delete ui;
}

