#include "src/widget/tree_widget.h"

TreeWidget::TreeWidget(QTreeWidget* parent) : QTreeWidget(parent)
{
    this->setHeaderHidden(true);

    m_itemCount = 0;

    QTreeWidgetItem* searchItem = new QTreeWidgetItem(this, QStringList(tr("Searching")));
    searchItem->setIcon(0, QIcon(":/branch.svg"));
    addItem(searchItem, tr("A Star search"));
    addItem(searchItem, tr("Breadth First Search"));//traversal
    addItem(searchItem, tr("Depth First Search"));

    QTreeWidgetItem* sortintItem = new QTreeWidgetItem(this, QStringList(tr("Sorting")));
    sortintItem->setIcon(0, QIcon(":/branch.svg"));
    addItem(sortintItem, tr("Insertion Sort"));
    addItem(sortintItem, tr("Merge Sort"));
    addItem(sortintItem, tr("Heap Sort"));
    addItem(sortintItem, tr("Selection Sort"));
}

void TreeWidget::addItem(QTreeWidgetItem* parentItem, const QString & text)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(parentItem, QStringList(text));
    item->setIcon(0, QIcon(":/tab.svg"));
    parentItem->addChild(item);

    m_itemCount++;
    m_map[parentItem] = AlgoFlag(m_itemCount);
}
