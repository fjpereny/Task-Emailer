#include "spreadsheettable.h"

#include <QKeyEvent>
#include <iostream>

SpreadsheetTable::SpreadsheetTable(QWidget *parent,
                                   int rows,
                                   int cols,
                                   int load_row_size,
                                   int low_col_size)
    : QTableWidget(parent)
    , headers(new QStringList)
{
    setRowCount(rows);
}

SpreadsheetTable::~SpreadsheetTable()
{

}

void SpreadsheetTable::keyPressEvent(QKeyEvent *event)
{    
    if (event->modifiers() == Qt::Key_Control && event->key() == Qt::Key_A)
    {

    }

    if (event->key() == Qt::Key_Return)
    {
        setCurrentCell(currentIndex().row() + 1, currentIndex().column());
    }

    if (event->key() == Qt::Key_Delete)
    {
        QModelIndexList selectedIndexes = this->selectionModel()->selectedIndexes();
        for (QModelIndex index : selectedIndexes)
        {
            QTableWidgetItem *item;
            if ((item = this->itemFromIndex(index)))
                item->setText("");

        }
        clearSelection();
        repaint();
    }

    if (event->key() == Qt::Key_Escape)
    {
        this->selectionModel()->clearSelection();
    }

    else
        QTableWidget::keyPressEvent(event);

}


void SpreadsheetTable::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    double percent_from_end_row = (double)currentRow() / (double)rowCount();
    if (percent_from_end_row > 0.90)
        add_visible_rows();
}


void SpreadsheetTable::add_visible_rows()
{
    setRowCount(rowCount() + 100);
}

