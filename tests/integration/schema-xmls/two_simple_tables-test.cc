// test using two_simple_tables.xml as input
#include "../schema-xmls.h"

#define SRC_XML_FILE ":/two_simple_tables.xml"
#define SRC_SQL_FILE ":/two_simple_tables.xml.sql"

TEST(two_simple_tables, tryme) {
    TMP_FILE;
    EXPECT_TRUE(SchemaXmlsHelper::executeSchemaFile (
        s_database, QLatin1String(SRC_SQL_FILE)));

    QStringList tables (db.tables());
    ASSERT_EQ(tables.count(), 2);

    for (int i = 0; i < 2; ++i) {
        QSqlQuery query (QString("SELECT * FROM %1;").arg (tables.at (i)));
        EXPECT_FALSE(query.next());

        QSqlRecord rec = query.record();
        ASSERT_EQ(rec.count(), 1);
        EXPECT_EQ(rec.fieldName (0), QLatin1String ("id"));

        ColumnInfoMap coldata =
                SchemaXmlsHelper::columnInfo (tables.at (i));
        EXPECT_EQ(coldata.count(), 1);
        const ColumnInfo & colid = coldata.value("id");

        EXPECT_TRUE(colid.type.contains("INTEGER"));
        EXPECT_TRUE(colid.type.contains("AUTO_INCREMENT"));
        EXPECT_FALSE(colid.notnull);
        EXPECT_TRUE(colid.dflt_value.isEmpty());
        EXPECT_FALSE(colid.pk);
    }
}
