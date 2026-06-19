//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_GUI_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_GUI_H

#include <QWidget>

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
    void connectSignalsAndSlots();
    void populateList();
};


#endif //RESEARCHGRANTPROPOSALSOOPEXAM_GUI_H
