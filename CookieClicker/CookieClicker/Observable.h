#pragma once
#include <vector>
#include <functional>


class Observable
{
public:
    void addObserver(std::function<void()> func) {
        observers_.push_back(func);
    }

    void notifyObservers() {
        for (auto& observer : observers_) {
            observer();
        }
    }

private:
    std::vector<std::function<void()>> observers_;
};

