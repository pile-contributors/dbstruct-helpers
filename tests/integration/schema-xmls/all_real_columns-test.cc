// test using all_real_columns.xml as input
#include "../schema-xmls.h"

#define SRC_XML_FILE ":/all_real_columns.xml"
#define SRC_SQL_FILE ":/all_real_columns.xml.sql"

TEST(all_real_columns, tryme) {
    TMP_FILE;
    SchemaXmlsHelper::executeSchemaFile (
        s_database, QLatin1String(SRC_SQL_FILE));

    QStringList tables (db.tables());
    ASSERT_EQ(tables.count(), 1);

    ColumnInfoMap coldata =
            SchemaXmlsHelper::columnInfo (tables.at(0));
    EXPECT_EQ(coldata.count(), 27);

    const ColumnInfo & col_id = coldata.value("id");
    EXPECT_TRUE(col_id.type.contains("INTEGER"));
    EXPECT_TRUE(col_id.type.contains("AUTO_INCREMENT"));

    const ColumnInfo & col_bit = coldata.value("bit");
    EXPECT_TRUE(col_bit.type.contains("BOOLEAN"));

    const ColumnInfo & col_tristate = coldata.value("tristate");
    EXPECT_TRUE(col_tristate.type.contains("SMALLINT"));

    const ColumnInfo & col_int = coldata.value("int");
    EXPECT_TRUE(col_int.type.contains("INTEGER"));

    const ColumnInfo & col_bigint = coldata.value("bigint");
    EXPECT_TRUE(col_bigint.type.contains("BIGINT"));

    const ColumnInfo & col_smallint = coldata.value("smallint");
    EXPECT_TRUE(col_smallint.type.contains("SMALLINT"));

    const ColumnInfo & col_tinyint = coldata.value("tinyint");
    EXPECT_TRUE(col_tinyint.type.contains("SMALLINT"));

    const ColumnInfo & col_numeric = coldata.value("numeric");
    EXPECT_TRUE(col_numeric.type.contains("DECIMAL"));

    const ColumnInfo & col_decimal = coldata.value("decimal");
    EXPECT_TRUE(col_decimal.type.contains("DECIMAL"));

    const ColumnInfo & col_numericScale0 = coldata.value("numericScale0");
    EXPECT_TRUE(col_numericScale0.type.contains("DECIMAL"));

    const ColumnInfo & col_decimalScale0 = coldata.value("decimalScale0");
    EXPECT_TRUE(col_decimalScale0.type.contains("DECIMAL"));

    const ColumnInfo & col_money = coldata.value("money");
    EXPECT_TRUE(col_money.type.contains("DECIMAL"));

    const ColumnInfo & col_float = coldata.value("float");
    EXPECT_TRUE(col_float.type.contains("FLOAT"));

    const ColumnInfo & col_real = coldata.value("real");
    EXPECT_TRUE(col_real.type.contains("REAL"));

    const ColumnInfo & col_date = coldata.value("date");
    EXPECT_TRUE(col_date.type.contains("DATE"));

    const ColumnInfo & col_datetime = coldata.value("datetime");
    EXPECT_TRUE(col_datetime.type.contains("VARCHAR"));

    const ColumnInfo & col_time = coldata.value("time");
    EXPECT_TRUE(col_time.type.contains("TIME"));

    const ColumnInfo & col_char = coldata.value("char");
    EXPECT_TRUE(col_char.type.contains("CHARACTER"));

    const ColumnInfo & col_varchar = coldata.value("varchar");
    EXPECT_TRUE(col_varchar.type.contains("VARCHAR"));

    const ColumnInfo & col_text = coldata.value("text");
    EXPECT_TRUE(col_text.type.contains("VARCHAR"));

    const ColumnInfo & col_nchar = coldata.value("nchar");
    EXPECT_TRUE(col_nchar.type.contains("VARCHAR"));

    const ColumnInfo & col_nvarchar = coldata.value("nvarchar");
    EXPECT_TRUE(col_nvarchar.type.contains("VARCHAR"));

    const ColumnInfo & col_ntext = coldata.value("ntext");
    EXPECT_TRUE(col_ntext.type.contains("VARCHAR"));

    const ColumnInfo & col_binary = coldata.value("binary");
    EXPECT_TRUE(col_binary.type.contains("VARBINARY"));

    const ColumnInfo & col_varbinary = coldata.value("varbinary");
    EXPECT_TRUE(col_varbinary.type.contains("VARBINARY"));

    const ColumnInfo & col_image = coldata.value("image");
    EXPECT_TRUE(col_image.type.contains("VARBINARY"));

    const ColumnInfo & col_xml = coldata.value("xml");
    EXPECT_TRUE(col_xml.type.contains("VARCHAR"));

    // common for all
    foreach(const QString & colname, coldata.keys()) {
        const ColumnInfo & colid = coldata.value (colname);
        EXPECT_FALSE(colid.notnull);
        EXPECT_TRUE(colid.dflt_value.isEmpty());
        EXPECT_FALSE(colid.pk);
    }
}

