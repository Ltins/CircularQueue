#include "circular-queue.hpp"

int main() {
    int good_value_for_parameterized_object[5] = {11563, 1531, -105, 465, 6540};

    CircularQueue<int> parameterized_object_1 = CircularQueue<int>(good_value_for_parameterized_object, 5);
    parameterized_object_1.PRINT_DEBUG_DATA();

    CircularQueue<int> parameterized_object_2 =
        CircularQueue<int>(good_value_for_parameterized_object, good_value_for_parameterized_object,
                           good_value_for_parameterized_object + 5);
    parameterized_object_2.PRINT_DEBUG_DATA();

    CircularQueue<int> parameterized_object_3 = parameterized_object_2;
    parameterized_object_3.PRINT_DEBUG_DATA();

    CircularQueue<int> default_object;
    default_object.PRINT_DEBUG_DATA();

    default_object.enqueue(1);
    default_object.enqueue(2);
    default_object.enqueue(3);
    default_object.enqueue(4);
    default_object.enqueue(5);
    default_object.PRINT_DEBUG_DATA();

    default_object.dequeue();
    default_object.dequeue();
    default_object.PRINT_DEBUG_DATA();

    default_object.enqueue(6);
    default_object.PRINT_DEBUG_DATA();

    default_object.dequeue();
    default_object.PRINT_DEBUG_DATA();

    return 0;
}