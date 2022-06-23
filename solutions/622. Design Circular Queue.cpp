class MyCircularQueue {
private:
    int size, maxSize;
    int *queue;
    int front, rear;
public:
    MyCircularQueue(int k)
            : maxSize(k), size(0), front(0), rear(k-1) {
        queue = new int[k];
    }
    
    ~MyCircularQueue() {
        delete [] queue;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % maxSize;
        queue[rear] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % maxSize;
        --size;
        return true;
    }
    
    int Front() {
        return (isEmpty() ? -1 : queue[front]);
    }
    
    int Rear() {
        return (isEmpty() ? -1 : queue[rear]);
    }
