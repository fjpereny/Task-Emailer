#ifndef SPREADSHEETTABLE_H
#define SPREADSHEETTABLE_H

#include <QTableWidget>

class SpreadsheetTable : public QTableWidget
{
public:
    SpreadsheetTable(QWidget *parent = nullptr,
                     int rows = 100,
                     int cols = 100,
                     int load_row_size = 100,
                     int load_col_size = 100);

    ~SpreadsheetTable();

    QStringList *headers = new QStringList();

private slots:
    void keyPressEvent(QKeyEvent *event);
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void add_visible_rows();

private:

};

#endif // SPREADSHEETTABLE_H
