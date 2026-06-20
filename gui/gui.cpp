//
// Created by Maria on 19/06/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>
#include <QPushButton>


GUI::GUI(Service& service,const Researcher& researcher,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},researcher{researcher} {
    ui->setupUi(this);
    service.registerObserver(this);
    ui->ideasTableView->setSelectionBehavior(QAbstractItemView::SelectRows); // HINT(*)
    this->setWindowTitle(QString::fromStdString(researcher.getName()));
    ui->positionLabel->setText(QString::fromStdString(researcher.getPosition()));
    // MODEL
    model=new IdeasModel{service.getSortedIdeas(),this};
    ui->ideasTableView->setModel(model);
    connectSignalsAndSlots();
}

GUI::~GUI() {
    service.unregisterObserver(this);
    delete ui;
}

void GUI::connectSignalsAndSlots() {
    connect(ui->addButton,&QPushButton::clicked,this,&GUI::addIdea);
    connect(ui->acceptButton,&QPushButton::clicked,this,&GUI::acceptIdea);
}

void GUI::populateList() {
    update();
}
//yes
void GUI::addIdea() {
    std::string title=ui->titleLineEdit->text().toStdString();
    std::string description=ui->descriptionLineEdit->text().toStdString();
    int duration=ui->durationLineEdit->text().toInt();
    try {
        service.addIdea(title,description,"proposed",researcher.getName(),duration);
        update();
        ui->titleLineEdit->clear();
        ui->descriptionLineEdit->clear();
        ui->durationLineEdit->clear();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this,"ERROR",e.what());
    }
}

void GUI::update() {
    model->updateData(service.getSortedIdeas());
}

void GUI::acceptIdea() {
    auto indexes=ui->ideasTableView->selectionModel()->selectedIndexes();
    if (indexes.empty())
        return;
    int row=indexes[0].row();
    auto ideas=service.getSortedIdeas();
    Idea selectedIdea=ideas[row];
    try {
        service.acceptIdea(selectedIdea.getTitle(),researcher);
        update();
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this,"ERROR",e.what());
    }
}
