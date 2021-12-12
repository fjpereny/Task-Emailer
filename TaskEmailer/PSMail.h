#ifndef POWERSHELL_H
#define POWERSHELL_H

#include <QDate>
#include <QString>

class PSMail
{
public:
    PSMail();

    static QString CreateHeader(QDate date, QString name, QString comments);

    static QString CreateMail(QStringList toEmailList,
                                   QStringList ccEmailList,
                                   QStringList bccEMailList,
                                   QString subject,
                                   QString body,
                                   QStringList attachmentList);

};

#endif // POWERSHELL_H
