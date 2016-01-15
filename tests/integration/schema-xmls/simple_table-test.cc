// test using simple_table.xml as input
#include "../schema-xmls.h"

#define SRC_XML_FILE ":/simple_table.xml"
#define SRC_SQL_FILE ":/simple_table.xml.sql"

#include <QDebug>

TEST(simple_table, tryme) {
    TMP_FILE;
    EXPECT_TRUE(SchemaXmlsHelper::executeSchemaFile (
        s_database, QLatin1String(SRC_SQL_FILE)));

    QStringList tables (db.tables());
    ASSERT_EQ(tables.count(), 1);

    QSqlQuery query(QString("SELECT * FROM %1;").arg(tables.at(0)));
    EXPECT_FALSE(query.next());

    QSqlRecord rec = query.record();
    ASSERT_EQ(rec.count(), 1);
    EXPECT_EQ(rec.fieldName (0), QLatin1String ("id"));

    ColumnInfoMap coldata =
            SchemaXmlsHelper::columnInfo (tables.at(0));
    EXPECT_EQ(coldata.count(), 1);
    const ColumnInfo & colid = coldata.value("id");

    EXPECT_TRUE(colid.type.contains("INTEGER"));
    EXPECT_TRUE(colid.type.contains("AUTO_INCREMENT"));
    EXPECT_FALSE(colid.notnull);
    EXPECT_TRUE(colid.dflt_value.isEmpty());
    EXPECT_FALSE(colid.pk);
}
