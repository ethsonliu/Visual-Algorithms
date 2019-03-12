#ifndef VISUAL_ALGORITHMS_WIDGET_TREE_WIDGET_H
#define VISUAL_ALGORITHMS_WIDGET_TREE_WIDGET_H

#include "src/config.h"

#include <QTreeWidget>

#include <QMouseEvent>
#include <QMap>

enum AlgoFlag
{
    aStar,
    breadthFirstSearch,
    depthFirstSearch
};

class TreeWidget : public QTreeWidget
{

public:

    TreeWidget(QTreeWidget* parent = nullptr);

    inline int itemCount() const { return m_itemCount; }
    inline AlgoFlag indexByItem(QTreeWidgetItem* item) const { return m_map[item]; }


private:

    int                              m_itemCount;
    QMap<QTreeWidgetItem*, AlgoFlag> m_map;

    void addItem(QTreeWidgetItem* parentItem, const QString & text);

};

#endif // VISUAL_ALGORITHMS_WIDGET_TREE_WIDGET_H
