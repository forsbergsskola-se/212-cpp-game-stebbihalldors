#pragma once
#include "Observable.h"
#include <iostream>
class MyObservable :
    public Observable
{
public:
    void doSomething() {
        // do something here...
        std::cout << "Observable Event Raised!\n";
        notifyObservers();
    }
};

