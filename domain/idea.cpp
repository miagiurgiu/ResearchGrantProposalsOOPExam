//
// Created by Maria on 19/06/2026.
//

#include "idea.h"

Idea::Idea(const std::string &title, const std::string &description, const std::string &status,
    const std::string &creator, int duration):title{title}, description{description},status{status},creator{creator},duration{duration}{
}

std::string Idea::getTitle() const {
    return title;
}

std::string Idea::getDescription() const {
    return description;
}

std::string Idea::getStatus() const {
    return status;
}

std::string Idea::getCreator() const {
    return creator;
}

int Idea::getDuration() const {
    return duration;
}

std::string Idea::toString() const {
    return title+","+description+","+status+","+creator+","+std::to_string(duration);
}

std::string Idea::toStringNoDescription() const {
    return title+","+status+","+creator+","+std::to_string(duration);
}

void Idea::setStatus(const std::string &newStatus) {
    this->status=newStatus;
}
