#ifndef __RA_ITERATOR_HPP__
#define __RA_ITERATOR_HPP__

template<typename ValueType>
class RAIterator: public std::iterator<std::random_access_iterator_tag, ValueType>
{
    ValueType *p;
public:
    RAIterator(): p(nullptr) {}
    RAIterator(ValueType *_p): p(_p) {}
    RAIterator(const RAIterator &src): p(src.p) {}
    typename RAIterator::reference operator*() const { return *p; }
    typename RAIterator::pointer operator->() const { return p; }
    typename RAIterator::reference operator[](typename RAIterator::difference_type i) const {
        return p[i];
    }

    RAIterator& operator=(const RAIterator &other) {
        p = other.p;
        return *this;
    }
    bool operator==(const RAIterator &other) const { return p == other.p; };
    bool operator!=(const RAIterator &other) const { return p != other.p; };
    bool operator<(const RAIterator &other) const { return p < other.p; };
    bool operator>(const RAIterator &other) const { return p > other.p; };
    bool operator<=(const RAIterator &other) const { return p <= other.p; };
    bool operator>=(const RAIterator &other) const { return p >= other.p; };

    RAIterator& operator++() {
        ++p;
        return *this;
    }
    RAIterator& operator--() {
        --p;
        return *this;
    }
    RAIterator& operator+=(typename RAIterator::difference_type n) {
        p += n;
        return *this;
    }
    RAIterator operator+(typename RAIterator::difference_type n) const {
        return RAIterator(p + n);
    }
    RAIterator& operator-=(typename RAIterator::difference_type n) {
        p -= n;
        return *this;
    }
    RAIterator operator-(typename RAIterator::difference_type n) const {
        return RAIterator(p - n);
    }
    friend inline RAIterator operator+(
        typename RAIterator::difference_type l,
        const RAIterator& r
    ) { return RAIterator(l + r.p); }
    friend inline RAIterator operator-(
        typename RAIterator::difference_type l,
        const RAIterator& r
    ) { return RAIterator(l - r.p); }
};

template<typename ValueType>
typename RAIterator<ValueType>::difference_type operator-(
    const RAIterator<ValueType>& l,
    const RAIterator<ValueType>& r
) { return *l - *r; }

#endif