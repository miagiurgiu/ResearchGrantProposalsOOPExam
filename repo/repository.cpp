//
// Created by Maria on 19/06/2026.
//

#include "repository.h"
#include <fstream>
#include <sstream>

Repository::Repository(const std::string &ideasFile, const std::string &researchersFile):ideasFile{ideasFile}, researchersFile{researchersFile}{
    loadIdeas();
    loadResearchers();
}

std::vector<Idea> Repository::getIdeas() const {
    return ideas;
}

std::vector<Researcher> Repository::getResearchers() const {
    return researchers;
}

std::vector<Idea> Repository::getAcceptedIdeas() const {
    return acceptedIdeas;
}

void Repository::loadIdeas() {
    std::ifstream fin(ideasFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open file");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);

        std::string title,description,status,creator,durationString;

        std::getline(ss,title,',');
        std::getline(ss,description,',');
        std::getline(ss,status,',');
        std::getline(ss,creator,',');
        std::getline(ss,durationString,',');

        int duration=std::stoi(durationString);
        ideas.emplace_back(title,description,status,creator,duration);
    }
    fin.close();
}

void Repository::loadResearchers() {
    std::ifstream fin(researchersFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open file");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);

        std::string name,position;

        std::getline(ss,name,',');
        std::getline(ss,position,',');

        researchers.emplace_back(name,position);
    }
    fin.close();
}

void Repository::save() {
    std::ofstream fout(ideasFile);
    if (!fout.is_open())
        throw std::runtime_error("error");
    for (const auto& i:ideas) {
        fout<<i.toString()<<"\n";
    }
    fout.close();
}

void Repository::addIdea(const Idea &idea) {
    ideas.push_back(idea);
    save();
}

void Repository::acceptIdea(const std::string &title) {
    for (auto& i:ideas) {
        if (i.getTitle()==title) {
            if (i.getStatus()!="proposed")
                throw std::runtime_error("idea is not proposed");
            i.setStatus("accepted");
            save();
            return;
        }
    }
    throw std::runtime_error("idea not found");
}

void Repository::saveToFile(const std::string &filename) {
    std::ofstream fout(filename);
    if (!fout.is_open())
        throw std::runtime_error("error");
    std::vector<Idea> accepted;
    for (const auto& i:ideas) {
        if (i.getStatus()=="accepted")
            accepted.push_back(i);
    }
    std::sort(accepted.begin(),accepted.end(),[](const Idea& a,const Idea& b) {
        return a.getDuration()<b.getDuration();
    });
    for (const auto& i:accepted) {
        fout<<i.toStringBrackets()<<"\n";
    }
    fout.close();
}
