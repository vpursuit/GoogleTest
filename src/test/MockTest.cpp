//
// Created by Trebing, Peter on 06.09.19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../DataHolder.h"

class MockQueue : public QueueInterface {
public:
    MOCK_METHOD0(dequeue, int());
    MOCK_METHOD1(enqueue, void(int
            data));
};

TEST(MockTests, CanAddData) {
    MockQueue myMockObj;
    DataHolder dh(&myMockObj);

    EXPECT_CALL(myMockObj, enqueue(testing::_));

    dh.addData(1);
}

TEST(MockTests, CanAddAndGetData) {
    MockQueue myMockObj;
    DataHolder dh(&myMockObj);

    EXPECT_CALL(myMockObj, enqueue(1));
    EXPECT_CALL(myMockObj, dequeue()).WillOnce(testing::Return(1));

    dh.addData(1);
    int data = dh.getData();

    ASSERT_EQ(1, data);
}