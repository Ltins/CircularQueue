#include <iostream>
using namespace std;

constexpr unsigned int CIRCULAR_QUEUE_MAXIMUM_CAPACITY = 5;

// TODO: return 'this' pointer where needed
template <class T, class Allocator = allocator<T>>
class CircularQueue {
    unsigned int _front, _rear;
    T* _data;

   public:
    using value_type = T;
    using allocator_type = Allocator;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    CircularQueue() : _front(0), _rear(0) { _data = allocator_type().allocate(CIRCULAR_QUEUE_MAXIMUM_CAPACITY); }

    CircularQueue(const value_type* data, const value_type* first_element, const value_type* last_element)
        : CircularQueue() {
        const auto number_of_elements = last_element - first_element;

        if (number_of_elements > CIRCULAR_QUEUE_MAXIMUM_CAPACITY) {
            throw overflow_error("Number of elements is bigger than maximum capacity!");
        }

        copy(first_element, last_element, _data);
        _rear = number_of_elements - 1;
    }

    CircularQueue(const value_type* data, const size_type& number_of_elements) : CircularQueue() {
        if (number_of_elements > CIRCULAR_QUEUE_MAXIMUM_CAPACITY) {
            throw overflow_error("Number of elements is bigger than maximum capacity!");
        }

        _rear = number_of_elements - 1;

        const auto last_element_pointer = data + number_of_elements;
        copy(data, last_element_pointer, _data);
    }

    ~CircularQueue() { allocator_type().deallocate(_data, CIRCULAR_QUEUE_MAXIMUM_CAPACITY); }

    CircularQueue(const CircularQueue& other) : _front(other._front), _rear(other._rear) {
        _data = allocator_type().allocate(CIRCULAR_QUEUE_MAXIMUM_CAPACITY);
        copy(other._data + _front, other._data + _rear + 1, _data);
    }

    bool empty() { return _front == _rear; }
    bool full() { return _rear - _front == CIRCULAR_QUEUE_MAXIMUM_CAPACITY; }

    // TODO: consider removing debug functions
#ifndef NDEBUG
    void PRINT_DEBUG_DATA() {
        static unsigned long long debug_index = 0;

        cout << "Debug index -> " << debug_index << endl;
        cout << "Data -> " << *this << endl;
        cout << "Front pointer -> " << _front << endl;
        cout << "Rear pointer -> " << _rear << endl;
        cout << endl;

        ++debug_index;
    }
#elif
    void PRINT_DEBUG_DATA() {}
#endif

    // TODO: rewrite function behavior and get rid of "friend"
    friend ostream& operator<<(ostream& stream, const CircularQueue<value_type>& queue) {
        for (size_type i = 0; i < CIRCULAR_QUEUE_MAXIMUM_CAPACITY; ++i) {
            stream << "[" << i << "]:" << queue._data[i] << " ";
        }

        return stream;
    }
};