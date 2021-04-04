#include <iostream>
#include <stdlib.h>
#include "array.h"
#include "../Timer/timer.cpp"

using namespace std;

Array::Array()
{
    this->array = new int[0];
    this->size = 0;
}

Array::~Array()
{
    return;
}

void Array::addElement(int value)
{
    Timer timer;
    size++;
    array = (int *)realloc(array, size * sizeof(int));
    array[size - 1] = value;
}

void Array::printArray()
{
    Timer timer;
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Array::deleteElement(int value)
{
    Timer timer;
    int position = -1;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            position = i;
    }

    if (position == -1)
        return;

    for (int i = position; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
    array = (int *)realloc(array, size * sizeof(int));
}