#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include <vector>
#include "container.hpp"
#include <iostream>
#include <algorithm>

class VectorContainer: public Container{
    private:
        std::vector<Base*> elements;

    public:
        /* Constructors */
        VectorContainer() : Container() { };
        VectorContainer(Sort* function) : Container(function) { };

        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element){
            elements.push_back(element);
        }
        // iterate through trees and output the expressions (use stringify())
        virtual void print() {
            for(Base* element: elements){
                std::cout << element->stringify();
            }
        }
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort(){
            this->sort_function->sort(this);
        }

        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j){
            std::swap(elements.at(i), elements.at(j));
        }
        // get top ptr of tree at index i
        virtual Base* at(int i){
            return this->elements.at(i);
        }
        // return container size
        virtual int size(){
            return this->elements.size();
        }


};

#endif
