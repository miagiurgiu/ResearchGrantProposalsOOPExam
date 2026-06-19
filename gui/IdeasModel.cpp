//
// Created by Maria on 19/06/2026.
//

#include "IdeasModel.h"

IdeasModel::IdeasModel(const std::vector<Idea> &ideas, QObject *parent):QAbstractTableModel{parent},ideas{ideas}{
}

int IdeasModel::rowCount(const QModelIndex &parent) const {
    return ideas.size();
}

int IdeasModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant IdeasModel::data(const QModelIndex &index, int role) const {
    if (role!=Qt::DisplayRole)
        return QVariant{};
    const auto& i=ideas[index.row()];
    if (index.column()==0)
        return QString::fromStdString(i.getTitle());
    if (index.column()==1)
        return QString::fromStdString(i.getDescription());
    if (index.column()==2)
        return QString::fromStdString(i.getStatus());
    if (index.column()==3)
        return QString::fromStdString(i.getCreator());
    if (index.column()==4)
        return i.getDuration();
    return QVariant{};
}

QVariant IdeasModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant{};
    if (section == 0) return "Title";
    if (section == 1) return "Description";
    if (section == 2) return "Status";
    if (section == 3) return "Creator";
    if (section == 4) return "Duration";
    return QVariant{};
}

void IdeasModel::updateData(const std::vector<Idea>& newIdeas) {
    beginResetModel();
    ideas = newIdeas;
    endResetModel();
}
