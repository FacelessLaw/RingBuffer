#ifndef __RING_BUFFER_HPP__
#define __RING_BUFFER_HPP__

#include "ra_iterator.hpp"

template<class C>
class RingBuffer
{
    size_t _capacity;
    size_t _size;
    unsigned _begin;
    unsigned _end;
    C *buffer;
public:
    RingBuffer(const size_t &capacity): _capacity(capacity) {
        _size = 0;
        _begin = 0;
        _end = -1;
        buffer = new C[_capacity + 1];
    }

    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }
    bool empty() const { return _size == 0; }

    RAIterator<C> begin() const { return RAIterator<C>(&buffer[0]); }
    RAIterator<C> end() const { return RAIterator<C>(&buffer[_capacity]); }

    void resize(const size_t &capacity) {
        size_t old_size = _size < capacity ? _size : capacity;
        C *new_buffer = new C[capacity + 1];

        for (size_t i = 0; i < old_size; ++i) {
            new_buffer[i] = buffer[(_begin + i) % _capacity];
        }
        _capacity = capacity;
        _size = old_size;
        _begin = 0;
        _end = _size - 1;
        delete[] buffer;
        buffer = new_buffer;
    }

    void push_back(const C &val) {
        if (_size == _capacity) {
            ++_begin;
            _begin %= _capacity; 
        }
        _size = std::min(_size + 1, _capacity);
        buffer[++_end % _capacity] = val;
        _end %= _capacity;
    }

    void push_front(const C &val) {
        if (_size < _capacity) {
            _size = std::min(_size + 1, _capacity);
            if (_begin > 0) {
                --_begin;
            } else {
                _begin = _capacity - 1;
            }
        }
        buffer[_begin] = val;
    }

    void pop_back() {
        if (_size == 0)
            return;
        --_size;
        buffer[_end] = C();
        if (_end > 0) {
            --_end;
        } else {
            _end = _capacity - 1;
        }

        if (_size == 0) {
            _begin = 0;
            _end = -1;
        }
    }

    void pop_front() {
        if (_size == 0)
            return;
        --_size;
        buffer[_begin++] = C();
        _begin %= _capacity;

        if (_size == 0) {
            _begin = 0;
            _end = -1;
        }
    }

    C& operator[](const int &ind) { return buffer[(_begin + ind) % _capacity]; }

    ~RingBuffer() {
        delete[] buffer;
    }
};


#endif