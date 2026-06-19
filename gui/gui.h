//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_GUI_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_GUI_H

#include <QWidget>
#include "IdeasModel.h"
#include "service/service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(Service& service,const Researcher& researcher,QWidget *parent = nullptr);
    ~GUI() override;


private:
    Ui::GUI *ui;
    Service& service;
    Researcher researcher;
    IdeasModel* model;
    void connectSignalsAndSlots();
    void populateList();
    void addIdea();
    void update();
};


#endif //RESEARCHGRANTPROPOSALSOOPEXAM_GUI_H
