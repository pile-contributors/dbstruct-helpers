#include <gtest/gtest.h>
#include <dbstruct/dbstruct.h>

class TestUsage : public ::testing::Test {

public:

    TestUsage () {}

    virtual ~TestUsage () {}

    void SetUp(){
        inst_ = new DbStruct();
    }
    void TearDown(){
        delete inst_;
    }
    DbStruct * inst_;
};

TEST_F(TestUsage, initial_state) {

}

