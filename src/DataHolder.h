//
// Created by Trebing, Peter on 06.09.19.
//

#ifndef GOOGLETEST_TEST_DATAHOLDER_H
#define GOOGLETEST_TEST_DATAHOLDER_H

class QueueInterface {
public:
    virtual ~QueueInterface() { ; }

    virtual void enqueue(int data) = 0;

    virtual int dequeue() = 0;
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

#endif //GOOGLETEST_TEST_DATAHOLDER_H
