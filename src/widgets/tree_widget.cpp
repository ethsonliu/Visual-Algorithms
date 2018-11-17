#include "tree_widget.h"

TreeWidget::TreeWidget(QTreeWidget* parent) : QTreeWidget(parent)
{
    this->setHeaderHidden(true);
    this->setMouseTracking(true);

    QTreeWidgetItem* searchItem = new QTreeWidgetItem(this, QStringList(tr("Searching")));
    QTreeWidgetItem* aStarItem = new QTreeWidgetItem(searchItem, QStringList(tr("A Star search")));
    QTreeWidgetItem* bfsItem = new QTreeWidgetItem(searchItem, QStringList(tr("Breadth First Search")));//traversal
    QTreeWidgetItem* dfsItem = new QTreeWidgetItem(searchItem, QStringList(tr("Depth First Search")));
    searchItem->addChild(aStarItem);
    searchItem->addChild(bfsItem);
    searchItem->addChild(dfsItem);
    QTreeWidgetItem* sortintItem = new QTreeWidgetItem(this, QStringList(tr("Sorting")));
    QTreeWidgetItem* insertionSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Insertion Sort")));
    QTreeWidgetItem* mergeSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Merge Sort")));
    QTreeWidgetItem* heapSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Heap Sort")));
    QTreeWidgetItem* selectionSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Selection Sort")));
    sortintItem->addChild(insertionSortItem);
    sortintItem->addChild(mergeSortItem);
    sortintItem->addChild(heapSortItem);
    sortintItem->addChild(selectionSortItem);
}

void TreeWidget::mouseMoveEvent(QMouseEvent* event)
{
    static QTreeWidgetItem* preItem = nullptr;

    QFont font;
    QTreeWidgetItem* item = this->itemAt(event->pos());

    if (preItem)
    {
        font.setUnderline(false);
        preItem->setData(0, Qt::FontRole, font);
    }

    if (item)
    {
        this->setCursor(Qt::PointingHandCursor);
        preItem = item;
        font.setUnderline(true);
        item->setData(0, Qt::FontRole, font);
    }
    else
    {
        this->setCursor(Qt::ArrowCursor);
    }

    QTreeWidget::mouseMoveEvent(event);
}
