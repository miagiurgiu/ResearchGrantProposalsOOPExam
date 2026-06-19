//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_SERVICE_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_SERVICE_H

#include "../repo/repository.h"
#include <vector>
#include <string>

class Service {
private:
    Repository& repo;
public:
    Service(Repository& repo);
    std::vector<Idea> getIdeas() const;
    std::vector<Researcher> getResearchers() const;
    std::vector<Idea> getSortedIdeas() const;
    void addIdea(const std::string& title,const std::string& description,const std::string& status,const std::string& creator, int duration);
};



#endif //RESEARCHGRANTPROPOSALSOOPEXAM_SERVICE_H
