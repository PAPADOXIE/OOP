#include <iostream>
#include <cstdarg>
#include <cstdlib>

struct Bag{
    int *data, size, max_size;

    void init(const int SIZE){ //Initialize the bag with given max value
        data = (int*) malloc(SIZE * sizeof(int)); //Used malloc because realloc is easier than copying the whole bag over
        max_size = SIZE;
        size = 0;
    }

    bool is_exist(const int ELEMENT){ //Check if an element exists in the bag or not
        for(int i=0; i<size; i++){
            if(ELEMENT==data[i]) return true;
        }
        return false;
    }

    bool add(const int argc, ...){ //Add new elements to bag
        bool added = false;
        va_list elements;
        va_start(elements, argc);
        int temp;
        
        for(int i=0; i<argc; i++){
            temp = va_arg(elements, int);
            if(size<max_size){
                data[size++] = temp;
                added = true;
            }
        }
        return added;
    } 

    void print(){ //Output the contents of the bag
        std::cout<<"{";
        for(int i=0; i<size; i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<'\b'<<"}"<<std::endl;
    }     

    Bag merge(const Bag &bag){ //Add elements of two bags together
        Bag merged;
        merged.init(size + bag.size);

        for(int i=0; i<size; i++) merged.add(1, data[i]);
        for(int i=0; i<bag.size; i++) merged.add(1, bag.data[i]);

        return merged;       
    }

    int index_of(const int ELEMENT){ //Return index of element if it exists otherwise return -1
        for(int i=0; i<size; i++){
            if(ELEMENT==data[i]) return i;
        }
        return -1;
    }

    void resize(const int new_size){ //Increase or decrease size of bag
        data = (int*) realloc(data, new_size * sizeof(int));
        if(size>new_size) size = new_size;
        max_size = new_size;
    }

    bool has(const Bag &bag){ //Check if current bag has all elements of other bag
        for(int i=0; i<bag.size; i++){
            if(!is_exist(bag.data[i])) return false;
        }
        return true;
    }
};

int main(){
    
}