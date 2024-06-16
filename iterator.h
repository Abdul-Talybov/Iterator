#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

template<typename T>
class Iterator {
private:
    Node<T>* slider;
    std::vector<int> primes;

    bool is_prime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int sum_primes() {
        int sum = 0;
        for (int prime : primes) {
            sum += prime;
        }
        return sum;
    }

    void move_to_next() {
        while (slider != nullptr) {
            int temp = slider->data.publication_year;
            slider->data.publication_year -= sum_primes();
            if (is_prime(temp)) {
                primes.push_back(temp);
            }
            slider = slider->next;
        }
    }

public:
    Iterator(Node<T>* start) : slider(start) {
        move_to_next();
    }

    Iterator& operator++() {
        if (slider != nullptr) {
            move_to_next();
        }
        return *this;
    }

    T operator*() {
        return slider->data;
    }

    bool operator==(const Iterator& it) {
        return slider == it.slider;
    }

    bool operator!=(const Iterator& it) {
        return !(*this == it);
    }
};
