#pragma once
#include "Observable.h"
#include <iostream>
class ICookieListener
{
public:
    ICookieListener(Observable& observable) {
        observable.addObserver([this] {this->update(); });
    }
    virtual void update() {
        std::cout << "Observer was notified!\n";
    }
};

