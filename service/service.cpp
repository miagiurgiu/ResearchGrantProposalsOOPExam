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

std::vector<Idea> Service::getSortedIdeas() const {
    auto ideas=repo.getIdeas(); // copy
    std::sort(ideas.begin(),ideas.end(),[](const Idea& a, const Idea& b) {
        return a.getDuration()<b.getDuration();
    });
    return ideas;
}

void Service::addIdea(const std::string &title, const std::string &description, const std::string &status,
    const std::string &creator, int duration) {
    if (title.empty())
        throw std::runtime_error("title is empty");
    if (duration!=1 && duration !=2 && duration !=3)
        throw std::runtime_error("invalid duration");
    Idea newIdea{title,description,status,creator,duration};
    repo.addIdea(newIdea);
}

void Service::acceptIdea(const std::string &title, const Researcher &researcher) {
    if (researcher.getPosition()!="senior")
        throw std::runtime_error("only seniors can revise and accept");
    repo.acceptIdea(title);
    notify(); //OBSERVER
}
