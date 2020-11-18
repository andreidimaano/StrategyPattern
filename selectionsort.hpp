#ifndef __SELECTION__SORT_HPP__
#define __SELECTION__SORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class Container;
class Sort;

class SelectionSort: public Sort {
    public:
        /* Constructors */
        SelectionSort(): Sort() {}

        /* Pure Virtual Functions */
        virtual void sort(Container* container) {
            unsigned i, j, min_index;
            for (i= 0; i < container->size(); i++) {
                min_index = i;
                for (j = i + 1; j < container->size(); j++){
                        if (container->at(j)->evaluate() < container->at(min_index)->evaluate()) {
                            min_index = j;
                        }
                }
                container->swap(min_index, i);
            }
        }
};

#endif //__SORT_HPP__
