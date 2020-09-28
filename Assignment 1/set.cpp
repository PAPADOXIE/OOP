#include <iostream>

struct Set{
    int *data, size, max_size; //In order: Set Members, Current Size, Maximum Size

    void init(const int SIZE){ //Initialize the set with given max value
        data = (int*) malloc(SIZE * sizeof(int)); //Used malloc because realloc is easier than copying the whole set over
        max_size = SIZE;
        size = 0;
    }

    bool is_exist(const int ELEMENT){ //Check if an element exists in the set or not
        for(int i=0; i<size; i++){
            if(ELEMENT==data[i]) return true;
        }
        return false;
    }

    bool add(const int ELEMENT){ //Add new element to set
        if(size<max_size && !is_exist(ELEMENT)){
            data[size++] = ELEMENT;
            return true;
        }
        return false;
    }

    void print(){ //Output the contents of the set
        std::cout<<"{";
        for(int i=0; i<size; i++){
            std::cout<<data[i]<<" ";
        }
        std::cout<<'\b'<<"}"<<std::endl;
    }

    Set _union(const Set &set){ //Create a new set from 2 given sets which contains all elements from both sets
        Set union_set;
        union_set.init(size + set.size);

        for(int i=0; i<size; i++){
            union_set.data[union_set.size++] = data[i];
        }
        for(int i=0; i<set.size; i++){
            union_set.add(set.data[i]);
        }

        return union_set;
    }

    Set intersection(const Set &set){ //TODO Create a new set from 2 given set which contains same elements from both sets

    }

    Set difference(const Set &set){ //TODO

    }

    void resize(const int new_size){ //Increase or decrease size of set
        data = (int*) realloc(data, new_size * sizeof(int));
    }

    Set complement(){ //TODO

    }

    bool is_subset(const Set &set){ //TODO

    }

    bool isProperSubset (const Set &set){ //TODO

    }

    void _delete(){ //Unallocates set from memory
        free(data);
    }

};

int main(int argc, char *argv[]){ //Main function

}