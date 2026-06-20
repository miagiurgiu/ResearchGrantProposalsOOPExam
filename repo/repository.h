//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_REPOSITORY_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_REPOSITORY_H
#include "idea.h"
#include "researcher.h"
#include <vector>

class Repository {
private:
    std::string ideasFile;
    std::string researchersFile;
    std::vector<Idea> ideas;
    std::vector<Researcher> researchers;
    std::vector<Idea> acceptedIdeas;
public:
    Repository(const std::string& ideasFile, const std::string& researchersFile);
    std::vector<Idea> getIdeas() const;
    std::vector<Researcher> getResearchers() const;
    std::vector<Idea> getAcceptedIdeas() const;
    void loadIdeas();
    void loadResearchers();
    void save();
    void addIdea(const Idea& idea);
    void acceptIdea(const std::string& title);
    void saveToFile(const std::string& filename);
};



#endif //RESEARCHGRANTPROPOSALSOOPEXAM_REPOSITORY_H
