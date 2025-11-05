#include <iostream>
using namespace std;

constexpr unsigned int CIRCULAR_QUEUE_SIZE = 5;

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

    CircularQueue() : _data(allocator_type().allocate(CIRCULAR_QUEUE_SIZE)), _front(0), _rear(0) { PRINT_DEBUG_DATA(); }

    CircularQueue(value_type* initial_data) : CircularQueue() {}

    ~CircularQueue() { allocator_type().deallocate(_data, CIRCULAR_QUEUE_SIZE); }

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
        for (size_type i = 0; i < CIRCULAR_QUEUE_SIZE; ++i) {
            stream << "[" << i << "]:" << queue._data + i * sizeof(value_type) << " ";
        }

        return stream;
    }
};