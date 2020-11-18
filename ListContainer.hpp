#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include <list>
#include "container.hpp"
#include <iterator>
#include <iostream>
#include <algorithm>

class ListContainer: public Container{
	private:
		std::list<Base*> elements;

	public:
		/* Constructors */
		ListContainer() : Container() { };
		ListContainer(Sort* function) : Container(function) { };
		
		/* Pure Virtual Functions */
		//push the top pointer of the tree into container
		virtual void add_element(Base* element) {
			elements.push_back(element);
			}

		// iterate through trees and output the expressions (use stringify())
		virtual void print() {
			for(std::list<Base*>::iterator it = elements.begin(); it != elements.end(); it++){
				std::cout << (*it)->stringify();
			}
		}

		// calls on the previously set sorting-algorithm. Checks if sort_function is not null, throws exception if otherwise
		virtual void sort() {
			if(!sort_function) {
				throw "sort function is not specified";
			}

			this->sort_function->sort(this);
		}

		/* Essentially the only functions needed to sort */
		//switch tree locations
		virtual void swap(int i , int j){
			std::list<Base*>::iterator iteratorI = elements.begin();
			std::advance(iteratorI, i);	

			std::list<Base*>::iterator iteratorJ = elements.begin();
			std::advance(iteratorJ, j);

			std::iter_swap(iteratorI, iteratorJ);
		}

		// get top ptr of three at index i
		virtual Base* at(int i){
			std::list<Base*>::iterator it = elements.begin();
			std::advance (it, i);
			return (*it);
		}

		// return container size
		virtual int size(){
			return this->elements.size();
		}

};

#endif
