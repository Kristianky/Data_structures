#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>

template <class T>
class Array
{
private:
    T *data;
    int size;
    int length;

public:
    Array(int size = 1, int length = 0) : size{size}, length{length}
    {
        data = new T[size];
    }
    ~Array() { delete[] data; }
    void display_array() const;
    void insert_element(T element);
    void insert_element(T element, int index); // Forward declaration
    void add_element(T element);
    void delete_element(int index);
    int linear_search(T element) const;
    int binary_search(T element) const;
    T get_element(int index) const;
    void set(int index, T value);
    int max() const;
    int min() const;
    int total() const;
    float avg() const;
    void swap();
    void Shift_Left();
    void Shift_Right();
    void Rotate_Left();
    bool Check_Sorted();
    void Sorting_Positive_Negative();
    Array *Merge(Array &arr2);
    Array *Union(Array &arr2);
    Array *Intrersection(Array &arr2);
    Array *Diffrence(Array &arr2);
    int Get_Size() { return size; }
    int Get_Length() { return length; }
    void Set_Size(int temp) { size = temp; }
    void Set_Length(int temp) { length = temp; }
    int Finding_Missing_Element();
    void Fill_Data(T element);
};

template <class T>
void Array<T>::display_array() const
{
    std::cout << "Array elements: ";
    for (int i = 0; i < length; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
template <class T>
void Array<T>::insert_element(T element)
{
    while (length < size)
    {
        std::cout << "Enter element to insert: ";
        std::cin >> element;
        data[length] = element;
        length++;
    }
}
template <class T>
void Array<T>::insert_element(T element, int index)
{
    if (length >= size)
    {
        T arr_temp[size];
        for (int i = 0; i < length; ++i)
        {
            arr_temp[i] = data[i];
        }
        size += 1;
        delete[] data;  // Free allocated memory
        data = nullptr; // Set to nullptr to avoid dangling pointer
        data = new int[size];
        for (int i = 0; i < length; ++i)
        {
            data[i] = arr_temp[i];
        }
    }
    for (int i = length; i > index; --i)
    {
        data[i] = data[i - 1];
    }
    data[index] = element;
    length++;
}
template <class T>
void Array<T>::add_element(T element)
{
    if (length < size)
    {
        data[length] = element;
        length++;
    }
    else
    {
        T arr_temp[size];
        for (int i = 0; i < length; ++i)
        {
            arr_temp[i] = data[i];
        }
        size += 1;
        delete[] data;  // Free allocated memory
        data = nullptr; // Set to nullptr to avoid dangling pointer
        data = new T[size];
        for (int i = 0; i < length; ++i)
        {
            data[i] = arr_temp[i];
        }
        data[length] = element;
        length++;
    }
}
template <class T>
void Array<T>::delete_element(int index)
{
    if (index < 0 || index >= length)
    {
        std::cout << "Index out of bounds." << std::endl;
        return;
    }
    for (int i = index; i < length - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    length--;
}
template <class T>
int Array<T>::linear_search(T element) const
{
    for (int i{0}; i < length; ++i)
    {
        if (data[i] == element)
        {
            return i; // Mmozme pouzit swap (arr.data[i], arr.data[0]);) // Swap with first element (move to head), alebo swap(arr.data[i], arr.data[i-1])(transposition); // Swap with previous element pre zlepsenie casu
        }
        std::cout << "Element not found." << std::endl;
        return -1;
    }
    std::cout << "Element not found." << std::endl;
    return -1;
}
template <class T>
int Array<T>::binary_search(T element) const
{
    int Left{0};
    int right{length};
    while (Left <= right)
    {
        int mid = ((Left + right) / 2);
        if (data[mid] == element)
        {
            return mid; // Element is in midlle
        }
        else if (data[mid] < element)
        {
            Left = mid + 1; // Element is in right half
        }
        else
        {
            right = mid - 1; // Element is in left half
        }
    }
    return -1; // Element not found
}
template <class T>
T Array<T>::get_element(int index) const
{
    if (index < 0 || index > length)
    {
        std::cout << "Index out of bounds." << std::endl;
        return -1; // Return an invalid value or handle error appropriately
    }
    return data[index]; // Return the element at the specified index
}
template <class T>
void Array<T>::set(int index, T value)
{
    if (index < 0 || index > length)
    {
        std::cout << "Index out of bounds." << std::endl;
        return; // Handle error appropriately
    }
    data[index] = value; // Set the value at the specified index
}
template <class T>
int Array<T>::max() const
{
    if (length == 0)
    {
        std::cout << "Array is empty." << std::endl;
        return -1; // Handle empty array case
    }
    T max_value = data[0];
    for (int i = 1; i < length; ++i)
    {
        if (data[i] > max_value)
        {
            max_value = data[i];
        }
    }
    return max_value; // Return the maximum value found in the array
}
template <class T>
int Array<T>::min() const
{
    if (length == 0)
    {
        std::cout << "Array is empty." << std::endl;
        return -1; // Handle empty array case
    }
    T min_value = data[0];
    for (int i = 1; i < length; ++i)
    {
        if (data[i] < min_value)
        {
            min_value = data[i];
        }
    }
    return min_value; // Return the minimum value found in the array
}
template <class T>
int Array<T>::total() const
{
    T sum{};
    for (int i = 0; i < length; ++i)
    {
        sum += data[i];
    }
    return sum; // Return the total sum of the array elements
}
template <class T>
void Array<T>::swap()
{
    int j{length - 1};
    for (int i{0}; i < j; i++, j--)
    {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp; // Swap elements at positions i and j
    }
}
template <class T>
float Array<T>::avg() const
{
    if (length == 0)
    {
        std::cout << "Array is empty." << std::endl;
        return 0.0f; // Handle empty array case
    }
    return static_cast<float>(total()) / length; // Calculate and return the average
}
template <class T>
void Array<T>::Shift_Left()
{
    if (length == 0)
    {
        std::cout << "Array is empty." << std::endl;
        return; // Handle empty array case
    }
    for (int i = 0; i < length - 1; ++i)
    {
        data[i] = data[i + 1]; // Shift elements to the left
    }
}
template <class T>
void Array<T>::Shift_Right()
{
    if (length == 0)
    {
        std::cout << "Array is empty." << std::endl;
        return; // Handle empty array case
    }
    for (int i = length - 1; i > 0; --i)
    {
        data[i] = data[i - 1]; // Shift elements to the right
    }
}
template <class T>
void Array<T>::Rotate_Left()
{
    if (length == 0)
    {
        std::cout << "Array is empty." << std::endl;
    }
    T first = data[0]; // Store the first element
    for (int i{0}; i < length - 1; ++i)
    {
        Shift_Left();             // Shift elements to the left
        data[length - 1] = first; // Place the first element at the end
    }
}
template <class T>
bool Array<T>::Check_Sorted()
{
    for (int i = 0; i < length - 1; ++i)
    {
        if (data[i] > data[i + 1])
        {
            return false; // If any element is greater than the next, the array is not sorted
        }
    }
    return true; // If no such element is found, the array is sorted
}
template <class T>
void Array<T>::Sorting_Positive_Negative()
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (data[i] < 0)
        {
            i++;
        }
        while (data[j] <= 0)
        {
            j--;
        }
        if (i < j)
        {
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp; // Swap positive and negative elements
        }
    }
}
template <class T>
Array<T> *Array<T>::Merge(Array &arr2)
{
    Array *merged = new Array;
    merged->Set_Size(size + arr2.Get_Size());
    merged->data = new T[merged->size];
    merged->length = 0;
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2.length)
    {
        if (data[i] < arr2.data[j])
        {
            merged->data[k++] = data[i++];
        }
        else
        {
            merged->data[k++] = arr2.data[j++];
        }
    }
    for (; i < length; ++i)
    {
        merged->data[k++] = data[i]; // Copy remaining elements from arr1
    }
    for (; j < arr2.length; ++j)
    {
        merged->data[k++] = arr2.data[j]; // Copy remaining elements from arr2
    }
    merged->length = k; // Set the length of the merged array
    return merged;      // Return the merged array
}
template <class T>
Array<T> *Array<T>::Union(Array &arr2)
{
    Array *merged = new Array;
    merged->Set_Size(size + arr2.Get_Size());
    merged->data = new T[merged->size];
    merged->length = 0;
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2.length)
    {
        if (data[i] < arr2.data[j])
        {
            merged->data[k++] = data[i++];
        }
        else if (arr2.data[j] < data[i])
        {
            merged->data[k++] = arr2.data[j++];
        }
        else
        {
            merged->data[k++] = arr2.data[j++];
            i++;
        }
    }
    for (; i < length; ++i)
    {
        merged->data[k++] = data[i]; // Copy remaining elements from arr1
    }
    for (; j < arr2.length; ++j)
    {
        merged->data[k++] = arr2.data[j]; // Copy remaining elements from arr2
    }
    merged->length = k; // Set the length of the merged array
    return merged;      // Return the merged array
}
template <class T>
Array<T> *Array<T>::Intrersection(Array &arr2)
{
    Array *merged = new Array;
    merged->Set_Size(size + arr2.Get_Size());
    merged->data = new T[merged->size];
    merged->length = 0;
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2.length)
    {
        if (data[i] < arr2.data[j])
        {
            i++;
        }
        else if (arr2.data[j] < data[i])
        {
            j++;
        }
        else if (data[i] == arr2.data[j])
        {
            merged->data[k++] = arr2.data[j++];
            i++;
        }
    }
    for (; i < length; ++i)
    {
        merged->data[k++] = data[i]; // Copy remaining elements from arr1
    }
    for (; j < arr2.length; ++j)
    {
        merged->data[k++] = arr2.data[j]; // Copy remaining elements from arr2
    }
    merged->length = k; // Set the length of the merged array
    return merged;      // Return the merged array
}
template <class T>
Array<T> *Array<T>::Diffrence(Array &arr2)
{
    Array *merged = new Array;
    merged->Set_Size(size + arr2.Get_Size());
    merged->data = new T[merged->size];
    merged->length = 0;
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2.length)
    {
        if (data[i] < arr2.data[j])
        {
            merged->data[k++] = data[i++];
        }
        else if (arr2.data[j] < data[i])
        {
            j++;
        }
        else if (data[i] == arr2.data[j])
        {
            i++;
        }
    }
    for (; i < length; ++i)
    {
        merged->data[k++] = data[i]; // Copy remaining elements from arr1
    }
    for (; j < arr2.length; ++j)
    {
        merged->data[k++] = arr2.data[j]; // Copy remaining elements from arr2
    }
    merged->length = k; // Set the length of the merged array
    return merged;      // Return the merged array
}
template <class T>
int Array<T>::Finding_Missing_Element()
{
    int difrence = data[0];
    for (int i{}; i < length + 1; i++)
    {
        if (difrence != data[i] - i)
        {
            return i + difrence;
        }
    }
    return -1;
}
template <class T>
void Array<T>::Fill_Data(T element)
{
    for (int i{0};i < size;i++){
        data[i] = element;
        element++;
        length++;
    }
}
#endif