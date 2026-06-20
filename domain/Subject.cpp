//
// Created by Maria on 20/06/2026.
//

#include "Subject.h"

void Subject::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void Subject::unregisterObserver(Observer *observer) {
    observers.erase(std::remove(observers.begin(),observers.end(),observer),observers.end());
}

void Subject::notify() {
    for (auto o:observers) {
        o->update();
    }
}
