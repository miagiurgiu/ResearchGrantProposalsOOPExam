//
// Created by Maria on 19/06/2026.
//

#include "researcher.h"

Researcher::Researcher(const std::string &name, const std::string &position):name{name},position{position} {
}

std::string Researcher::getName() const {
    return name;
}

std::string Researcher::getPosition() const {
    return position;
}
