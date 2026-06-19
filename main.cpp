//
// Created by Maria on 19/06/2026.
//

#include "gui/gui.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    Repository repo{"../ideas.txt","../researchers.txt"};
    Service service{repo};
    std::vector<GUI*> windows;
    for (const auto& r:service.getResearchers()) {
        GUI* gui=new GUI{service,r};
        gui->show();
        windows.push_back(gui);
    }
    return app.exec();

}
