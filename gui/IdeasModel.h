//
// Created by Maria on 19/06/2026.
//

#ifndef RESEARCHGRANTPROPOSALSOOPEXAM_IDEASMODEL_H
#define RESEARCHGRANTPROPOSALSOOPEXAM_IDEASMODEL_H
#include <qabstractitemmodel.h>
#include "idea.h"


class IdeasModel:public QAbstractTableModel {
private:
    std::vector<Idea> ideas;
public:
    IdeasModel(const std::vector<Idea>& ideas, QObject* parent=nullptr);
    int rowCount(const QModelIndex& parent=QModelIndex{}) const override;
    int columnCount(const QModelIndex& parent=QModelIndex{}) const override;
    QVariant data(const QModelIndex& index, int role=Qt::DisplayRole) const override;
    QVariant headerData(int section,Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    void updateData(const std::vector<Idea>& newIdeas);
    Qt::ItemFlags flags(const QModelIndex& index) const override;
};



#endif //RESEARCHGRANTPROPOSALSOOPEXAM_IDEASMODEL_H
