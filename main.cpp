#include <iostream>
#include <cmath>
#include <windows.h>

//------------------------------------------------------------------------------
int getLevel(int index)
{
    if (index == 0) return 0;
    // level = floor(log2(index + 1))
    return static_cast<int>(std::log2(index + 1));
}
//------------------------------------------------------------------------------
void print_pyramid_node(int index, int value, int parent_index, int parent_value) {
    int level = getLevel(index);
    if (index == 0) {
        std::cout << level << " root " << value << std::endl;
    } else {
        std::string child_type = (index % 2 == 1) ? "left" : "right";
        std::cout << level << " " << child_type << "(" << parent_value << ") " << value << std::endl;
    }
}
//------------------------------------------------------------------------------
void print_pyramid(int* arr, int size)
{
    std::cout << "Пирамида:" << std::endl;
    if (size == 0) return;

    print_pyramid_node(0, arr[0], 0, 0);

    for (int i = 1; i < size; i++) {
        int parent_index = (i - 1) / 2;
        print_pyramid_node(i, arr[i], parent_index, arr[parent_index]);
    }
}
//------------------------------------------------------------------------------
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
//------------------------------------------------------------------------------
int main()
{
    // Тест 1
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Исходный массив: ";
    printArray(arr1, size1);
    print_pyramid(arr1, size1);
    std::cout << std::endl;

    // Тест 2
    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Исходный массив: ";
    printArray(arr2, size2);
    print_pyramid(arr2, size2);
    std::cout << std::endl;

    // Тест 3
    int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Исходный массив: ";
    printArray(arr3, size3);
    print_pyramid(arr3, size3);

    return 0;
}
//------------------------------------------------------------------------------
