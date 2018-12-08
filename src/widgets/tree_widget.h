#ifndef TREE_WIDGET_H
#define TREE_WIDGET_H

#include "../config.h"
#include <QTreeWidget>
#include <QMouseEvent>

class TreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    TreeWidget(QTreeWidget* parent = nullptr);
};

#endif /* TREE_WIDGET_H */
