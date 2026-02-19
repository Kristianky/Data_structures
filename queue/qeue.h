#ifndef _QEUE_H_
#define _QEUE_H_

template <typename T>
class queue
{
private:
    int Size, Rear;
    T *Data;

public:
    void Enqueue(T Data);
    T Deque();
    bool IsEmpty()
    {
        if (Rear == -1)
            return true;
        else
            return false;
    };
    bool IsFull()
    {
        if (Rear == Size - 1)
            return true;
        else
            return false;
    };
    T First() { return Data[0]; }
    T Lasts() { return Data[Rear]; }
};

#endif