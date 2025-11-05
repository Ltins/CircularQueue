#include <iostream>
using namespace std;

constexpr unsigned int CIRCULAR_QUEUE_MAXIMUM_CAPACITY = 5;

// TODO: return 'this' pointer where needed
template <class T, class Allocator = allocator<T>>
class CircularQueue {
    int _front_index, _rear_index;
    T* _data;

   public:
    using value_type = T;
    using allocator_type = Allocator;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    CircularQueue() : _front_index(-1), _rear_index(-1) {
        _data = allocator_type().allocate(CIRCULAR_QUEUE_MAXIMUM_CAPACITY);
    }

    // NOTE: Remember that copy( ) uses [x, y) range and not [x, y]
    CircularQueue(const value_type* data, const value_type* first_element, const value_type* last_element)
        : CircularQueue() {
        const auto number_of_elements = last_element - first_element;

        if (number_of_elements > CIRCULAR_QUEUE_MAXIMUM_CAPACITY) {
            throw overflow_error("Number of elements is bigger than maximum capacity!");
        }

        copy(first_element, last_element, _data);
        _front_index = 0;
        _rear_index = number_of_elements - 1;
    }

    CircularQueue(const value_type* data, const size_type& number_of_elements) : CircularQueue() {
        if (number_of_elements > CIRCULAR_QUEUE_MAXIMUM_CAPACITY) {
            throw overflow_error("Number of elements is bigger than maximum capacity!");
        }

        _rear_index = number_of_elements - 1;
        _front_index = 0;

        const auto last_element_pointer = data + number_of_elements;
        copy(data, last_element_pointer, _data);
    }

    ~CircularQueue() { allocator_type().deallocate(_data, CIRCULAR_QUEUE_MAXIMUM_CAPACITY); }

    CircularQueue(const CircularQueue& other) : _front_index(other._front_index), _rear_index(other._rear_index) {
        _data = allocator_type().allocate(CIRCULAR_QUEUE_MAXIMUM_CAPACITY);
        copy(other._data + _front_index, other._data + _rear_index + 1, _data);
    }

    bool empty() const { return _front_index == -1; }

    bool full() const { return size() == CIRCULAR_QUEUE_MAXIMUM_CAPACITY; }

    size_type size() const { return empty() ? 0 : _rear_index - _front_index + 1; }

    void clear() { _rear_index = _front_index = -1; }

    // TODO: rewrite function behavior and get rid of "friend"
    friend ostream& operator<<(ostream& stream, const CircularQueue<value_type>& queue) {
        if (!queue.empty()) {
            for (auto i = queue._front_index; i <= queue._rear_index; ++i) {
                stream << "[" << i << "]:" << queue._data[i] << " ";
            }
        }

        return stream;
    }

    void enqueue(const value_type& value) {
        if (full()) {
            dequeue();
        }

        if (_rear_index + 1 >= CIRCULAR_QUEUE_MAXIMUM_CAPACITY) {
            shift_queue();
        }

        push_back(value);
    }

    value_type dequeue() {
        if (empty()) {
            underflow_error("CircularQueue Underflow!\n");
        }

        auto return_value = _data[_front_index];
        ++_front_index;

        if (_front_index > _rear_index) {
            _front_index = _rear_index = -1;
        }

        return return_value;
    }

    // TODO: consider removing debug functions
#ifndef NDEBUG
    void PRINT_DEBUG_DATA() const {
        static unsigned long long debug_index = 0;

        cout << "Debug index -> " << debug_index << endl;
        cout << "Data -> " << *this << endl;
        cout << "Front index -> " << _front_index << endl;
        cout << "Rear index -> " << _rear_index << endl;
        cout << "Is empty -> " << empty() << endl;
        cout << "Is full -> " << full() << endl;
        cout << "Size -> " << size() << endl;
        cout << endl;

        ++debug_index;
    }

   private:
    void push_back(const value_type& value) {
        if (empty()) {
            _front_index = 0;
        }

        ++_rear_index;
        _data[_rear_index] = value;
    }

    void shift_queue() {
        if (empty() || _front_index == 0) {
            return;
        }

        const auto queue_size = size();

        for (auto i = 0; i < queue_size; ++i) {
            _data[i] = _data[_front_index + i];
        }

        _front_index = 0;
        _rear_index = queue_size - 1;
    }
#elif
    void PRINT_DEBUG_DATA() {}
#endif
};