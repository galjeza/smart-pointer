//
// Created by galje on 5/7/2022.
//

#ifndef NALOGA0902_REFERENCECOUNTER_H
#define NALOGA0902_REFERENCECOUNTER_H

#include <ostream>

class ReferenceCounter {
private:
    unsigned int count;
public:
    ReferenceCounter():count(0){};
    unsigned int operator--() {count--;return count;}
    unsigned int operator++(int dummy) {count++;return count;}
    int getCount()const{return count;};
    friend std::ostream& operator<<(std::ostream& os,const ReferenceCounter& counter){
        os << "Counter Value : " << counter.count<< std::endl;return os;}
    };


#endif //NALOGA0902_REFERENCECOUNTER_H
