//
// Created by Trebing, Peter on 06.09.19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

class QueueInterface {
public:
    virtual ~QueueInterface() { ; }

    virtual void enqueue(int data) = 0;

    virtual int dequeue() = 0;
};

class MockQueue : public QueueInterface {
public:
    MOCK_METHOD0(dequeue, int());
    MOCK_METHOD1(enqueue, void(int
            data));
};

class DataHolder {
public:
    DataHolder(QueueInterface *queue) : queue(queue) { ; }

    void addData(int data) {
        queue->enqueue(data);
    }

    int getData() {
        return queue->dequeue();
    }

protected:
    QueueInterface *queue;
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