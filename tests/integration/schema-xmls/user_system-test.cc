// test using user_system.xml as input
#include "../schema-xmls.h"

#define SRC_XML_FILE ":/user_system.xml"
#define SRC_SQL_FILE ":/user_system.xml.sql"

#define DECAL_TABL(tname, tlabel) \
    int table_ ## tname = tables.indexOf(tlabel); \
    ColumnInfoMap coldata_ ## tname = \
            SchemaXmlsHelper::columnInfo (tables.at (table_ ## tname)); \
    all_col_data.append (coldata_ ## tname)



TEST(user_system, tryme) {
    TMP_FILE;
    SchemaXmlsHelper::executeSchemaFile (
        s_database, QLatin1String(SRC_SQL_FILE));

    QList< ColumnInfoMap > all_col_data;

    QStringList tables (db.tables());
    ASSERT_EQ(tables.count(), 5);

    DECAL_TABL(acctok, "AccessToken");
    DECAL_TABL(acl, "ACL");
    DECAL_TABL(person, "Person");
    DECAL_TABL(role, "Role");
    DECAL_TABL(role_m, "RoleMapping");

    int i = 0;
    foreach (const ColumnInfoMap & cdata, all_col_data){
        if (i != table_acctok) {
            const ColumnInfo & col_id = cdata.value("id");
            EXPECT_TRUE(col_id.type.contains("INTEGER"));
            EXPECT_TRUE(col_id.type.contains("AUTO_INCREMENT"));
            EXPECT_FALSE(col_id.notnull);
            EXPECT_TRUE(col_id.dflt_value.isEmpty());
            EXPECT_TRUE(col_id.pk);
        }
        ++i;
    }

}

