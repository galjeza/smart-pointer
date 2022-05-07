//
// Created by galje on 5/7/2022.
//

#ifndef NALOGA0902_SMARTPOINTER_H
#define NALOGA0902_SMARTPOINTER_H

#include "ReferenceCounter.h"

template<typename T>
class SmartPointer {
private:
    T *pObject;
    ReferenceCounter *counter;
public:
    explicit SmartPointer(T *pObject) : pObject(pObject), counter(new ReferenceCounter()) {
        (*counter)++;
    };

    ~SmartPointer() {
        if (--(*counter) == 0) {
            delete counter;
            delete pObject;
        }
    };

    T &operator*() { return *pObject; }
    T &operator->() { return pObject; }


    SmartPointer(SmartPointer<T> &sp) {
        pObject = sp.pObject;
        counter = sp.counter;
        (*counter)++;
    }

    SmartPointer<T> &operator=(const SmartPointer<T> &other) {
        if (this != &other) {
            if (--(*counter) == 0) {
                delete pObject;
                delete counter;
            }
            pObject = other.pObject;
            counter = other.counter;
            (*counter)++;
        }
        return *this;
    }

    unsigned int useCount() const { return counter->getCount(); };
};


#endif //NALOGA0902_SMARTPOINTER_H
