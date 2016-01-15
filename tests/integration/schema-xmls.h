/**
 * \file tests/integration/example_01.cc
 * \brief GUI example using a text-only standard model
 *
 * The example does not use the list delegate (GroupListDelegate).
 */
#ifndef GUARD_SCHEMA_XMLS_H
#define GUARD_SCHEMA_XMLS_H

#include <gtest/gtest.h>
#include <QString>
#include <QTemporaryFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QMap>

#define TMP_FILE \
    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE"); \
    QTemporaryFile dbtemp; \
    ASSERT_TRUE(dbtemp.open()); \
    QString s_database (dbtemp.fileName ())

struct ColumnInfo {
    QString cid;
    QString name;
    QString type;
    bool notnull;
    QString dflt_value;
    bool pk;
};

typedef QMap<QString, ColumnInfo> ColumnInfoMap;

class SchemaXmlsHelper {
public:
    static bool
    executeSchemaFile (
            const QString & database_path,
            const QString & file_path);

    static ColumnInfoMap
    columnInfo (
            const QString & s_table_name);
};

#endif // GUARD_SCHEMA_XMLS_H
