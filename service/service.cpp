//
// Created by Maria on 19/06/2026.
//

#include "service.h"

Service::Service(Repository &repo):repo{repo} {
}

std::vector<Idea> Service::getIdeas() const {
    return repo.getIdeas();
}

std::vector<Researcher> Service::getResearchers() const {
    return repo.getResearchers();
}
