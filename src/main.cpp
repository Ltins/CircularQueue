#include "circular-queue.hpp"

int main() {
    CircularQueue<char> default_object;

    std::string oleg_string = "dsadsa";
    CircularQueue<char> parameterized_object = CircularQueue<char>(oleg_string.data());

    return 0;
}