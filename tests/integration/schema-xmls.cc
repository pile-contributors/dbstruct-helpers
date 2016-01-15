/**
 * \file tests/integration/example_01.cc
 * \brief GUI example using a text-only standard model
 *
 * The example does not use the list delegate (GroupListDelegate).
 */

#include "schema-xmls.h"
#include "../testhelpers.h"
#include <QDir>
#include <QFile>
#include <QSqlQuery>
#include <QTextStream>
#include <QSqlError>
#include <QDebug>

bool SchemaXmlsHelper::executeSchemaFile (
        const QString & database_path, const QString &file_path)
{
    QFile f (QDir().absoluteFilePath (file_path));
    Q_ASSERT (f.exists());
    Q_ASSERT (f.open(QIODevice::ReadOnly));
    QTextStream in (&f);
    QString statevv = in.readAll();
    statevv = statevv.replace (QLatin1String ("\r"), QString ());
    QStringList statements = statevv.split ("\n");
    f.close();

    QSqlDatabase db = QSqlDatabase::database ();
    db.setDatabaseName (database_path);
    bool ok = db.open();

    QString s_exec;
    foreach(const QString & line, statements) {
        if (line.startsWith("--")) continue;
        s_exec.append (line);
        s_exec.append (" ");
    }
    s_exec = s_exec.trimmed();

    bool b_ret = true;
    statements = s_exec.split (";", QString::SkipEmptyParts);
    foreach(const QString & statement, statements) {
        QSqlQuery query (statement, db);
        bool b_this = query.exec();
        b_ret = b_ret & b_this;
        if (!b_this) {
            QString s_error = query.lastError().text();
            qDebug () << s_error;
        }
    }
    return b_ret;
}

ColumnInfoMap SchemaXmlsHelper::columnInfo (
        const QString &s_table_name)
{
    ColumnInfoMap result;
    QSqlQuery query2 (QString("PRAGMA table_info(%1)").arg (s_table_name));
    while (query2.next()) {
        ColumnInfo cinf;
        QSqlRecord rec = query2.record();
        cinf.cid = rec.value("cid").toString ();
        cinf.name = rec.value("name").toString ();
        cinf.type = rec.value("type").toString ();
        cinf.notnull = rec.value("notnull").toBool ();
        cinf.dflt_value = rec.value("dflt_value").toString ();
        cinf.pk = rec.value("pk").toBool ();

        result.insert (cinf.name, cinf);
    }
    return result;
}
