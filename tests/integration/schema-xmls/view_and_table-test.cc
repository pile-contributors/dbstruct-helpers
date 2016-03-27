// test using view_and_table.xml as input
#include "../schema-xmls.h"

#define SRC_XML_FILE ":/view_and_table.xml"
#define SRC_SQL_FILE ":/view_and_table.xml.sql"

TEST(view_and_table, tryme) {
    TMP_FILE;
    SchemaXmlsHelper::executeSchemaFile (
        s_database, QLatin1String(SRC_SQL_FILE));

    QStringList tables (db.tables (QSql::Tables));
    ASSERT_EQ(tables.count(), 2);
    QStringList views (db.tables (QSql::Views));
    ASSERT_EQ(views.count(), 1);

    ColumnInfoMap coldata =
            SchemaXmlsHelper::columnInfo (tables.at(0));
    EXPECT_EQ(coldata.count(), 4);

    ColumnInfoMap coldatav =
            SchemaXmlsHelper::columnInfo (views.at(0));
    EXPECT_EQ(coldatav.count(), 4);
    foreach(const QString & sitr, coldata.keys()) {
        EXPECT_EQ(coldata[sitr].cid, coldatav[sitr].cid);
        EXPECT_EQ(coldata[sitr].name, coldatav[sitr].name);
        EXPECT_EQ(coldata[sitr].type, coldatav[sitr].type);
        //EXPECT_EQ(coldata[sitr].notnull, coldatav[sitr].notnull);
        //EXPECT_EQ(coldata[sitr].dflt_value, coldatav[sitr].dflt_value);
        //EXPECT_EQ(coldata[sitr].pk, coldatav[sitr].pk);
    }

}

