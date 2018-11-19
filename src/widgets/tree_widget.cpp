#include "tree_widget.h"

TreeWidget::TreeWidget(QTreeWidget* parent) : QTreeWidget(parent)
{
    this->setHeaderHidden(true);

    QTreeWidgetItem* searchItem = new QTreeWidgetItem(this, QStringList(tr("Searching")));
    searchItem->setIcon(0, QIcon(":/images/branch.svg"));
    QTreeWidgetItem* aStarItem = new QTreeWidgetItem(searchItem, QStringList(tr("A Star search")));
    aStarItem->setIcon(0, QIcon(":/images/tab.svg"));
    QTreeWidgetItem* bfsItem = new QTreeWidgetItem(searchItem, QStringList(tr("Breadth First Search")));//traversal
    bfsItem->setIcon(0, QIcon(":/images/tab.svg"));
    QTreeWidgetItem* dfsItem = new QTreeWidgetItem(searchItem, QStringList(tr("Depth First Search")));
    dfsItem->setIcon(0, QIcon(":/images/tab.svg"));
    searchItem->addChild(aStarItem);
    searchItem->addChild(bfsItem);
    searchItem->addChild(dfsItem);

    QTreeWidgetItem* sortintItem = new QTreeWidgetItem(this, QStringList(tr("Sorting")));
    sortintItem->setIcon(0, QIcon(":/images/branch.svg"));
    QTreeWidgetItem* insertionSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Insertion Sort")));
    insertionSortItem->setIcon(0, QIcon(":/images/tab.svg"));
    QTreeWidgetItem* mergeSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Merge Sort")));
    mergeSortItem->setIcon(0, QIcon(":/images/tab.svg"));
    QTreeWidgetItem* heapSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Heap Sort")));
    heapSortItem->setIcon(0, QIcon(":/images/tab.svg"));
    QTreeWidgetItem* selectionSortItem = new QTreeWidgetItem(sortintItem, QStringList(tr("Selection Sort")));
    selectionSortItem->setIcon(0, QIcon(":/images/tab.svg"));
    sortintItem->addChild(insertionSortItem);
    sortintItem->addChild(mergeSortItem);
    sortintItem->addChild(heapSortItem);
    sortintItem->addChild(selectionSortItem);

    QTreeWidgetItem* testItem = new QTreeWidgetItem(this, QStringList(tr("Origin")));
    testItem->setIcon(0, QIcon(":/images/branch.svg"));
    QTreeWidgetItem* test1Item = new QTreeWidgetItem(testItem, QStringList(tr("Ubuntu 18.04 x64 Origin")));
    test1Item->setIcon(0, QIcon(":/images/tab.svg"));
    QTreeWidgetItem* test2Item = new QTreeWidgetItem(testItem, QStringList(tr("Ubuntu 14.04 x64 Origin")));
    test2Item->setIcon(0, QIcon(":/images/tab.svg"));
    testItem->addChild(test1Item);
    testItem->addChild(test2Item);
}
