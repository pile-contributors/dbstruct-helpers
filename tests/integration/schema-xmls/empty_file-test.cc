#include "../schema-xmls.h"

#define SRC_XML_FILE ":/empty_file.xml"
#define SRC_SQL_FILE ":/empty_file.xml.sql"

TEST(empty_file, tryme) {
    TMP_FILE;
    EXPECT_TRUE(SchemaXmlsHelper::executeSchemaFile (
                s_database, QLatin1String(SRC_SQL_FILE)));
    QStringList tables (db.tables());
    EXPECT_EQ(tables.count(), 0);
}
