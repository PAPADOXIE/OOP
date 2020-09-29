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

int main(){//Main Function
    Bag bag1, bag2, bag3; //Create Bags
    bag1.init(5); bag2.init(5); bag3.init(8); //Initialize Bags

    //*Test Adding to Bags
    //First argument for add should be number of elements to add
    std::cout<<"Bag1, Bag2, Bag3 in Order"<<std::endl;
    bag1.add(3, 1, 4, 16); bag1.print();
    bag2.add(5, 1, 3, 4, 8, 16); bag2.print();
    bag3.add(8, 3, 2, 6, 5, 4, 4, 7, 8); bag3.print();
    std::cout<<std::endl;

    //*Test Merging of Bags
    std::cout<<"Merger of Bag1 and Bag2"<<std::endl;
    Bag merged = bag1.merge(bag2); merged.print();
    std::cout<<std::endl;

    //*Test Resizing of Bags
    std::cout<<"Bag3 after Resizing"<<std::endl;
    bag3.resize(5); bag3.print();
    std::cout<<std::endl;

    //*Test Whether one Bag Has All of the Contents of Another Bag
    std::cout<<"Checking if Bag2 has all the contents of Bag1"<<std::endl;
    std::cout<<bag2.has(bag1)<<std::endl;
    std::cout<<std::endl;
    return 0;
}