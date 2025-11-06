#include <algorithm>

#include "circular-queue.hpp"

int main() {
    int good_value_for_parameterized_object[5] = {11563, 1531, -105, 465, 6540};

    CircularQueue<int> parameterized_object_1 = CircularQueue<int>(good_value_for_parameterized_object, 5);
    parameterized_object_1.PRINT_DEBUG_DATA();  // 0
    cout << endl;

    CircularQueue<int> parameterized_object_2 =
        CircularQueue<int>(good_value_for_parameterized_object, good_value_for_parameterized_object,
                           good_value_for_parameterized_object + 5);
    parameterized_object_2.PRINT_DEBUG_DATA();  // 1
    cout << endl;

    CircularQueue<int> parameterized_object_3 = parameterized_object_2;
    parameterized_object_3.PRINT_DEBUG_DATA();  // 2
    cout << endl;

    CircularQueue<int> default_object;
    default_object.PRINT_DEBUG_DATA();  // 3
    cout << endl;

    default_object.enqueue(1);
    default_object.enqueue(2);
    default_object.enqueue(3);
    default_object.enqueue(4);
    default_object.enqueue(5);
    default_object.PRINT_DEBUG_DATA();  // 4
    cout << endl;

    default_object.enqueue(6);
    default_object.PRINT_DEBUG_DATA();  // 5
    cout << endl;

    default_object.dequeue();
    default_object.dequeue();
    default_object.PRINT_DEBUG_DATA();  // 6
    cout << endl;

    default_object.enqueue(7);
    default_object.PRINT_DEBUG_DATA();  // 7
    cout << endl;

    default_object.dequeue();
    default_object.PRINT_DEBUG_DATA();  // 8
    cout << endl;

    default_object.enqueue(8);
    default_object.enqueue(9);
    reverse(default_object.begin(), default_object.end());
    default_object.PRINT_DEBUG_DATA();  // 9
    cout << endl;

    const auto count_condition = [](const auto& value) { return value % 2 == 0; };
    const auto count_result = count_if(default_object.begin(), default_object.end(), count_condition);
    default_object.PRINT_DEBUG_DATA();  // 10
    cout << "count(% 2 == 0) result: " << count_result << endl;
    cout << endl;

    const auto at_result = default_object.at(2);
    default_object.PRINT_DEBUG_DATA();  // 11
    cout << "at(2) result: " << at_result << endl;
    cout << endl;

    default_object.clear();
    default_object.PRINT_DEBUG_DATA();  // 12
    cout << endl;

    return 0;
}