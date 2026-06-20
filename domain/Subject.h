//
// Created by Maria on 20/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_SUBJECT_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_SUBJECT_H
#include <vector>
#include <Observer.h>


class Subject {
private:
    std::vector<Observer*> observers;
public:
    Subject()=default;
    void registerObserver(Observer* observer);
    void unregisterObserver(Observer* observer);
    void notify();
};



#endif //RESEARCHGRANTPROPOSALSOOPEXAM_SUBJECT_H
