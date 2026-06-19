//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_RESEARCHER_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_RESEARCHER_H
#include <string>


class Researcher {
private:
    std::string name;
    std::string position;
public:
    Researcher(const std::string& name,const std::string& position);
    std::string getName() const;
    std::string getPosition() const;
};



#endif //RESEARCHGRANTPROPOSALSOOPEXAM_RESEARCHER_H
