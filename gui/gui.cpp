//
// Created by Maria on 19/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(Service& service,const Researcher& researcher,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},researcher{researcher} {
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(researcher.getName()));
    ui->positionLabel->setText(QString::fromStdString(researcher.getPosition()));
    connectSignalsAndSlots();
}

GUI::~GUI() {
    delete ui;
}

void GUI::connectSignalsAndSlots() {
    return;
}

void GUI::populateList() {
    return;
}
