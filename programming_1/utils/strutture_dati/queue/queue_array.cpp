#include <iostream>

using namespace std;

struct queue
{
    int DIM;
    int head;
    int tail;
    int values[10];
};

void print(queue queue);
void enqueue(int value, queue& queue);
int dequeue(queue& queue);
int top(queue& queue);
bool my_is_empty(queue queue);
bool is_full(queue queue);

void print(queue queue)
{
    for (int i = 0; i < queue.DIM; i++)
    {
        cout << queue.values[i] << " ";
    }
    cout << endl;
}

void enqueue(int value, queue& queue)
{
    if (my_is_empty(queue))
    {
        queue.values[queue.head] = value;
        queue.tail++;
    }
    else
    {
        if (is_full(queue))
        {
            cout << "errore, la coda è piena" << endl;
        }
        else
        {
            queue.values[queue.tail] = value;
            queue.tail++;
        }
    }
}

int dequeue(queue& queue)
{
    if (my_is_empty(queue))
    {
        cout << "errore, la code è vuota" << endl;
    }
    else
    {
        int return_value = queue.values[queue.head];

        for (int i = 0; i < queue.DIM-1; i++)
        {
            queue.values[i] = queue.values[i+1];
        }
        
        queue.tail--;

        return return_value;
    }
}

int top(queue& queue)
{
    if (my_is_empty(queue))
    {
        cout << "errore, la code è vuota" << endl;
    }
    else
    {
        return queue.values[queue.head];
    }
}

bool my_is_empty(queue queue)
{
    return(queue.head == queue.tail);
}

bool is_full(queue queue)
{
    return(queue.DIM == queue.tail);
}