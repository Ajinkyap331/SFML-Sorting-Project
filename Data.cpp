#include "sort.h"

sf::RenderWindow window(sf::VideoMode(1200, 600), "Hello From SFML");

vector<int> arr = {117, 221, 128, 19, 468, 384, 123, 398, 457, 437, 337, 85, 496, 46, 448, 458, 233, 436, 55, 55, 372, 224, 393, 436, 194, 356, 495, 311, 159, 240, 41, 316, 401, 244, 343, 330, 123, 445, 68, 372, 341, 19, 226, 216, 372, 394, 237, 306, 254, 96, 449, 319, 95, 76, 124, 258, 214, 251, 81, 134, 250, 199, 456, 8, 436, 447, 161, 58, 48, 25, 292, 57, 397, 238, 434, 227, 144, 81, 357, 345, 60, 213, 53, 490, 66, 494, 74, 166, 31, 233, 148, 273, 444, 42, 124, 391, 327, 500, 46, 52};

sf::RectangleShape getData(int i, int seen)
{
    sf::RectangleShape line(sf::Vector2f(arr[i], 5.f));
    line.setPosition(i * 10, 600);
    line.rotate(270.f);
    if (seen == i)
        line.setFillColor(sf::Color(0, 100, 0));
    return line;
}

void bubbleSort()
{
    int i, j;
    for (i = 0; i < arr.size() - 1; i++)
        for (j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            window.clear();
            for (int k = 0; k < arr.size(); k++)
                window.draw(getData(k, j + 1));
            window.display();
            this_thread::sleep_for(chrono::milliseconds(10));
        }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int low, int high)
{
    window.clear();
    for (int k = 0; k < arr.size(); k++)
        window.draw(getData(k, low));
    window.display();
    this_thread::sleep_for(chrono::milliseconds(100));
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
