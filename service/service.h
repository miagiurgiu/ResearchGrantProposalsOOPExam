//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_SERVICE_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_SERVICE_H

#include "../repo/repository.h"
#include <vector>
#include <string>
#include "../domain/Subject.h"

class Service:public Subject {
private:
    Repository& repo;
public:
    Service(Repository& repo);
    std::vector<Idea> getIdeas() const;
    std::vector<Researcher> getResearchers() const;
    std::vector<Idea> getSortedIdeas() const;
    std::vector<Idea> getAcceptedIdeas() const;
    void addIdea(const std::string& title,const std::string& description,const std::string& status,const std::string& creator, int duration);
    void acceptIdea(const std::string& title, const Researcher& researcher);
    void saveToFile(const std::string& filename);
};



#endif //RESEARCHGRANTPROPOSALSOOPEXAM_SERVICE_H
