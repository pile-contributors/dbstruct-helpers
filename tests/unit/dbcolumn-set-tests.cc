#include <gtest/gtest.h>
#include <dbstruct/dbstruct.h>
#include <dbstruct/dbcolumn.h>

class TestColumnSetters : public ::testing::Test {

public:

    TestColumnSetters () : inst_() {}

    virtual ~TestColumnSetters () {}

    void SetUp(){
        //inst_ = new DbStruct();
    }
    void TearDown(){
        //delete inst_;
    }
    DbColumn inst_;
};

TEST_F(TestColumnSetters, initial_state) {
    EXPECT_FALSE(inst_.isVirtual ());
    EXPECT_TRUE(inst_.columnName ().isEmpty());
    EXPECT_TRUE(inst_.columnLabel ().isEmpty());
    EXPECT_EQ(inst_.columnId (), dbstruct::UNDEFINED);
    EXPECT_EQ(inst_.columnRealId (), dbstruct::UNDEFINED);
    EXPECT_EQ(inst_.columnLength (), dbstruct::UNDEFINED);
    EXPECT_EQ(inst_.columnType (), DbDataType::DTY_INVALID);
    EXPECT_TRUE(inst_.allowNulls());
    EXPECT_FALSE(inst_.readOnly());
}

TEST_F(TestColumnSetters, name) {
    QString s_name ("name");
    inst_.setColumnName (s_name);
    EXPECT_FALSE(inst_.columnName ().isEmpty());
    EXPECT_FALSE(inst_.columnLabel ().isEmpty());
    EXPECT_EQ(inst_.columnName (), s_name);
    EXPECT_EQ(inst_.columnLabel (), s_name);
}

TEST_F(TestColumnSetters, label) {
    QString s_label ("label");
    inst_.setColumnLabel (s_label);
    EXPECT_TRUE(inst_.columnName ().isEmpty());
    EXPECT_FALSE(inst_.columnLabel ().isEmpty());
    EXPECT_EQ(inst_.columnLabel (), s_label);

    QString s_name ("name");
    inst_.setColumnName (s_name);
    EXPECT_FALSE(inst_.columnName ().isEmpty());
    EXPECT_FALSE(inst_.columnLabel ().isEmpty());
    EXPECT_EQ(inst_.columnName (), s_name);
    EXPECT_EQ(inst_.columnLabel (), s_label);

    inst_.setColumnLabel (QString());
    EXPECT_TRUE(inst_.columnLabel ().isEmpty());
    EXPECT_FALSE(inst_.columnName ().isEmpty());

    inst_.setColumnName (s_name);
    EXPECT_FALSE(inst_.columnName ().isEmpty());
    EXPECT_FALSE(inst_.columnLabel ().isEmpty());
    EXPECT_EQ(inst_.columnName (), s_name);
    EXPECT_EQ(inst_.columnLabel (), s_name);
}

TEST_F(TestColumnSetters, id) {
    int new_id = 15;
    inst_.setColumnId (new_id);
    EXPECT_EQ(inst_.columnId (), new_id);
    EXPECT_EQ(inst_.columnRealId (), dbstruct::UNDEFINED);

    ++new_id;
    inst_.setColumnId (new_id);
    EXPECT_EQ(inst_.columnId (), new_id);
    EXPECT_EQ(inst_.columnRealId (), dbstruct::UNDEFINED);

    new_id = dbstruct::UNDEFINED;
    inst_.setColumnId (new_id);
    EXPECT_EQ(inst_.columnId (), new_id);
    EXPECT_EQ(inst_.columnRealId (), dbstruct::UNDEFINED);
}

TEST_F(TestColumnSetters, real_id) {
    int new_id = 15;
    inst_.setColumnRealId (new_id);
    EXPECT_EQ(inst_.columnRealId (), new_id);
    EXPECT_EQ(inst_.columnId (), dbstruct::UNDEFINED);

    ++new_id;
    inst_.setColumnRealId (new_id);
    EXPECT_EQ(inst_.columnRealId (), new_id);
    EXPECT_EQ(inst_.columnId (), dbstruct::UNDEFINED);

    new_id = dbstruct::UNDEFINED;
    inst_.setColumnRealId (new_id);
    EXPECT_EQ(inst_.columnRealId (), new_id);
    EXPECT_EQ(inst_.columnId (), dbstruct::UNDEFINED);
}

TEST_F(TestColumnSetters, nulls) {
    inst_.setAllowNulls (true);
    EXPECT_TRUE(inst_.allowNulls());

    inst_.setAllowNulls (false);
    EXPECT_FALSE(inst_.allowNulls());

    inst_.setAllowNulls (true);
    EXPECT_TRUE(inst_.allowNulls());
}

TEST_F(TestColumnSetters, read_only) {
    inst_.setReadOnly (true);
    EXPECT_TRUE(inst_.readOnly ());

    inst_.setReadOnly (false);
    EXPECT_FALSE(inst_.readOnly ());

    inst_.setReadOnly (true);
    EXPECT_TRUE(inst_.readOnly ());
}

