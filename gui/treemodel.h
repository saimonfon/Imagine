
 #ifndef TREEMODEL_H
 #define TREEMODEL_H

 #include <QAbstractItemModel>
 #include <QModelIndex>
 #include <QVariant>
 #include "../grammaire/Parser.h"

 class TreeItem;

 class TreeModel : public QAbstractItemModel
 {
     Q_OBJECT

 public:
     TreeModel(Parser* p, QObject *parent = 0);
     ~TreeModel();

     QVariant data(const QModelIndex &index, int role) const;
     Qt::ItemFlags flags(const QModelIndex &index) const;
     QVariant headerData(int section, Qt::Orientation orientation,
                         int role = Qt::DisplayRole) const;
     QModelIndex index(int row, int column,
                       const QModelIndex &parent = QModelIndex()) const;
     QModelIndex parent(const QModelIndex &index) const;
     int rowCount(const QModelIndex &parent = QModelIndex()) const;
     int columnCount(const QModelIndex &parent = QModelIndex()) const;
	TreeItem* item(const QModelIndex &index);

 private:
     void setupModelData(Parser* p, TreeItem *parent);

     TreeItem *rootItem;
 };

 #endif