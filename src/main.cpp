#include "circular-queue.hpp"

int main() {
    CircularQueue<char> default_object;

    int good_value_for_parameterized_object[5] = {11563, 1531, -105, 465, 6540};

    CircularQueue<int> parameterized_object_1 = CircularQueue<int>(good_value_for_parameterized_object, 5);

    CircularQueue<int> parameterized_object_2 =
        CircularQueue<int>(good_value_for_parameterized_object, good_value_for_parameterized_object,
                           good_value_for_parameterized_object + 5);

    CircularQueue<int> parameterized_object_3 = parameterized_object_2;

    default_object.PRINT_DEBUG_DATA();
    parameterized_object_1.PRINT_DEBUG_DATA();
    parameterized_object_2.PRINT_DEBUG_DATA();
    parameterized_object_3.PRINT_DEBUG_DATA();

    return 0;
}