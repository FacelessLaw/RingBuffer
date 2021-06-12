#include <algorithm>
#include <iostream>
#include <vector>

#include "ra_iterator.hpp"
#include "ring_buffer.hpp"

void print_buffer(RingBuffer<int> &r) {
    for (int i = 0; i < r.capacity(); ++i) {
        std::cout << r[i] << ' ';
    }
    std::cout <<std::endl;
}

int main()
{
    RingBuffer<int> r(5);
    std::cout << "Starting with empty ring buffer of integers with capacity = 5";
    std::cout << std::endl;
    std::cout << "Type 0 to show the commands";
    std::cout << std::endl;


    bool is_interrupted = false;
    while (!is_interrupted) {
        int curr_command;
        std::cin >> curr_command;
        if (curr_command == -1) {
            is_interrupted = true;
        } else if (curr_command == 0) {
            std::cout << "Type -1 to interrupt";
            std::cout << std::endl;
            std::cout << "Type 0 to show the commands";
            std::cout << std::endl;
            std::cout << "Type 1 <integer_value> to push back your integer value";
            std::cout << std::endl;
            std::cout << "Type 2 <integer_value> to push front your integer value";
            std::cout << std::endl;
            std::cout << "Type 3 to pop back";
            std::cout << std::endl;
            std::cout << "Type 4 to pop front";
            std::cout << std::endl;
            std::cout << "Type 5 <integer_value> to get buffer's [<integer_value>]";
            std::cout << std::endl;
            std::cout << "Type 6 <integer_value> to change capacity to your integer value";
            std::cout << std::endl;
            std::cout << "Type 7 to use stl sort function";
            std::cout << std::endl;
            std::cout << "Type 8 to call begin()";
            std::cout << std::endl;
            std::cout << "Type 9 to call end()";
            std::cout << std::endl;
        } else if (curr_command == 1) {
            int val;
            std::cin >> val;
            r.push_back(val);
        } else if (curr_command == 2) {
            int val;
            std::cin >> val;
            r.push_front(val);
        } else if (curr_command == 3) {
            r.pop_back();
        } else if (curr_command == 4) {
            r.pop_front();
        } else if (curr_command == 5) {
            int ind;
            std::cin >> ind;
            if (ind < 0 || r.capacity() <= ind) {
                std::cout << "Note that there is 0 indexation and index is less than capacity";
                std::cout << std::endl;
            } else {
                std::cout << r[ind] << std::endl;
            }
        } else if (curr_command == 6) {
            int cp;
            std::cin >> cp;
            if (cp < 0) {
                std::cout << "Note that capacity >= 0";
                std::cout << std::endl;
            } else {
                r.resize(cp);
            }
        } else if (curr_command == 7) {
            RAIterator<int> first = r.begin();
            RAIterator<int> last = r.end();
            std::sort(first, last);
            std::cout << std::endl;
        } else if (curr_command == 8) {
            std::cout << (*r.begin());
            std::cout << std::endl;
        } else if (curr_command == 9) {
            std::cout << (*r.end());
            std::cout << std::endl;
        }
        print_buffer(r);
    }

    return 0;
}