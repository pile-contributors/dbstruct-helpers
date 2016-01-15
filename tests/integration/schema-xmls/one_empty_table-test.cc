// test using one_empty_table.xml as input
#include "../schema-xmls.h"

#define SRC_XML_FILE ":/one_empty_table.xml"
#define SRC_SQL_FILE ":/one_empty_table.xml.sql"

TEST(one_empty_table, tryme) {
    TMP_FILE;
    EXPECT_FALSE(SchemaXmlsHelper::executeSchemaFile (
                s_database, QLatin1String(SRC_SQL_FILE)));
    QStringList tables (db.tables());
    EXPECT_EQ(tables.count(), 0);
}
