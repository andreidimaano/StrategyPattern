#ifndef __BUBBLE__SORT_HPP__
#define __BUBBLE__SORT_HPP__

#include "container.hpp"
#include "sort.hpp"
class Container;
class Sort;

class BubbleSort: public Sort {
	public:
		/* Constructors */
		BubbleSort() : Sort() { };
	
		/* Pure Virtual Functions */
		virtual void sort(Container* container) {
			unsigned i, j;
			for(i = 0; i < container->size() - 1; i++) {
				for(j = 0; j < container->size() - i - 1; j++){
					if(container->at(j)->evaluate() > container->at(j + 1)->evaluate()) {
						container->swap(j, j + 1);
					}
				}
			}
		}
};

#endif //__SORT_HPP__
