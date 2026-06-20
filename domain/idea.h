//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_IDEA_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_IDEA_H
#include <string>


class Idea {
private:
    std::string title;
    std::string description;
    std::string status;
    std::string creator;
    int duration;
public:
    Idea(const std::string& title,const std::string& description,const std::string& status, const std::string& creator, int duration);
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getStatus() const;
    std::string getCreator() const;
    int getDuration() const;
    std::string toString() const;
    std::string toStringNoDescription() const;
    std::string toStringBrackets() const;
    void setStatus(const std::string& newStatus);
};



#endif //RESEARCHGRANTPROPOSALSOOPEXAM_IDEA_H
