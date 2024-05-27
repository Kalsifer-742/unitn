#include <iostream>

using namespace std;

struct queue
{
    int DIM;
    int head;
    int tail;
};

struct priority_queue
{
    int values[10];
    queue high_priority;
    queue low_priority;
};

void enqueue(int value, priority_queue& queue, int priority);
int dequeue(priority_queue& queue);
int top(priority_queue& queue);
bool my_is_empty(queue queue);
bool is_full(queue queue);
void print(priority_queue queue);

void enqueue(int value, priority_queue& queue, int priority)
{
    if(!priority)
    {
        if (my_is_empty(queue.high_priority))
        {
            queue.values[queue.high_priority.head] = value;
            queue.high_priority.tail++;
        }
        else
        {
            if (is_full(queue.high_priority))
            {
                cout << "errore, la coda a priorità max è piena" << endl;
            }
            else
            {
                queue.values[queue.high_priority.tail] = value;
                queue.high_priority.tail++;
            }
        }
    }
    else
    {
        if (my_is_empty(queue.low_priority))
        {
            queue.values[queue.low_priority.head] = value;
            queue.low_priority.tail++;
        }
        else
        {
            if (is_full(queue.low_priority))
            {
                cout << "errore, la coda a priorità min è piena" << endl;
            }
            else
            {
                queue.values[queue.low_priority.tail] = value;
                queue.low_priority.tail++;
            }
        }
    }
}

int dequeue(priority_queue& queue)
{
    int return_value;
    if (!my_is_empty(queue.high_priority))
    {
        return_value = queue.values[queue.high_priority.head];

        for (int i = 0; i < queue.high_priority.DIM-1; i++)
        {
            queue.values[i] = queue.values[i+1];
        }

        queue.high_priority.tail--;
    }
    else if(!my_is_empty(queue.low_priority))
    {
        return_value = queue.values[queue.low_priority.head];

        for (int i = queue.low_priority.head; i < (queue.low_priority.head + queue.low_priority.DIM-1); i++)
        {
            queue.values[i] = queue.values[i+1];
        }

        queue.low_priority.tail--;
    }
    else
    {
        cout << "errore, la coda è vuota" << endl;
        return -1;
    }
    return return_value;
}

int top(priority_queue& queue)
{
    int return_value;
    if (!my_is_empty(queue.high_priority))
    {
        return_value = queue.values[queue.high_priority.head];
    }
    else if(!my_is_empty(queue.low_priority))
    {
        return_value = queue.values[queue.low_priority.head];
    }
    else
    {
        cout << "errore, la coda è vuota" << endl;
        return -1;
    }
    return return_value;
}

bool my_is_empty(queue queue)
{
    return(queue.head == queue.tail);
}

bool is_full(queue queue)
{
    return(queue.DIM == queue.tail);
}

void print(priority_queue queue)
{
    if (!my_is_empty(queue.high_priority))
    {
        cout << "0 priority: ";
        for (int i = queue.high_priority.head; i < queue.high_priority.DIM; i++)
        {
            cout << queue.values[i] << " ";
        }
        cout << endl;
    }
    if (!my_is_empty(queue.low_priority))
    {
        cout << "1 priority: ";
        for (int i = queue.low_priority.head; i < (queue.low_priority.head + queue.low_priority.DIM); i++)
        {
            cout << queue.values[i] << " ";
        }
        cout << endl;
    }
}