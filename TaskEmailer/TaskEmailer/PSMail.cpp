#include "PSMail.h"

#include <iostream>


PSMail::PSMail()
{
}


QString PSMail::CreateHeader(QDate date, QString name, QString comments)
{
    QString header =    "# Made By PowerShell Email Generator\n"
                        "# --------------------------------------------------------------------------------------\n"
                        "# Name: " + name + "\n"
                        "# Created: " + date.toString("dddd, MMMM dd, yyyy") + "\n"
                        "# Comments:" + comments + "\n"
                        "# --------------------------------------------------------------------------------------\n"
                        "# PowerShell Email Generator\n"
                        "# Copyright (C) 2021 Frank Pereny\n"
                        "# https://github.com/fjpereny/PowerShell-Email-Generator\n"
                        "#\n"
                        "# This program is free software: you can redistribute it and/or modify it under the\n"
                        "# terms of the GNU General Public License as published by the Free Software\n"
                        "# Foundation, either version 3 of the License, or (at your option) any later version.\n"
                        "\n"
                        "# This program is distributed in the hope that it will be useful, but WITHOUT ANY\n"
                        "# WARRANTY without even the implied warranty of MERCHANTABILITY or FITNESS\n"
                        "# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n"
                        "# --------------------------------------------------------------------------------------\n"
                        "\n"
                        "\n"
                        "Add-Type -assembly \"Microsoft.Office.Interop.Outlook\"\n"
                        "$Outlook = New-Object -comObject Outlook.Application\n";
    return header;
}


QString PSMail::CreateMail(QStringList toEmailList,
                               QStringList ccEmailList,
                               QStringList bccEMailList,
                               QString subject,
                               QString body,
                               QStringList attachmentList)
{
    QString mail;
    mail += "# ------------------------ EMAIL BEGIN ------------------------\n"
            "$Mail = $Outlook.CreateItem(0)\n";
    mail += "$Mail.To(\"" + toEmailList.join("\",\"") + "\")\n";
    mail += "$Mail.Cc(\"" + ccEmailList.join("\",\"") + "\")\n";
    mail += "$Mail.Bcc(\"" + bccEMailList.join("\",\"") + "\")\n";
    mail += "\n";
    mail += "$Mail.Subject(\"" + subject + "\")\n";
    mail += "\n";
    mail += "$body = \"" + body + "\"\n";
    mail += "$Mail.Body($body)\n";
    mail += "\n";
    mail += "$Mail.Attachments.Add(\"" + attachmentList.join("\",\"") + "\")\n";
    mail += "\n";
    mail += "$Mail.Send()\n";
    mail += "# ------------------------ EMAIL END --------------------------\n";

    return mail;
}

