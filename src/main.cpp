#include "circular-queue.hpp"

int main() {
    int good_value_for_parameterized_object[5] = {11563, 1531, -105, 465, 6540};

    CircularQueue<int> parameterized_object_1 = CircularQueue<int>(good_value_for_parameterized_object, 5);

    CircularQueue<int> parameterized_object_2 = parameterized_object_1;

    return 0;
}