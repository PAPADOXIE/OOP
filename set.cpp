#include <iostream>
#include <cstdarg>

struct Set{
    int *data, size, max_size, *universal, universal_size; //In order: Set Members, Current Size, Maximum Size

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

    bool is_exist(bool is_universal, const int ELEMENT){ //Check if an element exists in the universal set or not
        for(int i=0; i<universal_size; i++){
            if(ELEMENT==universal[i]) return true;
        }
        return false;
    }

    bool add(const int ELEMENT, ...){ //Add new elements to set
        bool added = false;
        va_list elements;
        va_start(elements, ELEMENT);
        int temp = ELEMENT;
        
        while(!temp==NULL){
            if(size<max_size && !is_exist(temp)){
            data[size++] = temp;
            added = true;
            }
            temp = va_arg(elements, int);
        }
        return added;
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

    Set intersection(const Set &set){ //Create a new set from 2 given set which contains same elements from both sets
        Set intersection_set;

        if(set.size > size) intersection_set.init(size);
        else intersection_set.init(set.size);

        for(int i=0; i<set.size; i++){
            if(is_exist(set.data[i])){
                intersection_set.data[intersection_set.size++] = set.data[i];
            }
        }
        return intersection_set;
    }

    Set difference(const Set &set){ //Create a new set which holds only the values exclusive to current set
        Set difference_set;
        Set intersected = intersection(set);
        difference_set.init(size);
        
        for(int i=0; i<size; i++){
            if(!intersected.is_exist(data[i])){
                difference_set.data[difference_set.size++] = data[i];
            }
        }

        return difference_set;
    }

    void resize(const int new_size){ //Increase or decrease size of set
        data = (int*) realloc(data, new_size * sizeof(int));
    }

    Set complement(){ //Takes complement of set with the universal set
        Set complement_set;
        complement_set.init(universal_size);
        for(int i=0; i<universal_size; i++){
            if(!is_exist(universal[i])){
                complement_set.data[complement_set.size++] = universal[i];
            }
        }
        return complement_set;
    }

    void build_universal(Set &set, ...){ //Build the universal set in which the current set resides
        va_list sets;
        va_start(sets, set);
        Set temp = set;

        while(!&temp==NULL){
            universal = (int*) realloc(universal, temp.size * sizeof(int));

            for(int i=0; i<temp.size; i++){
                if(!is_exist(true, temp.data[i])){
                    universal[universal_size++] = temp.data[i];
                }
                temp = va_arg(sets, Set);
            }
        }
    }

    bool is_subset(const Set &set){ //TODO
        return false;
    }

    bool isProperSubset (const Set &set){ //TODO
        return false;
    }

    void _delete(){ //Unallocates set arrays from memory
        free(data);
        free(universal);
    }

};

int main(){ //Main function
    Set set1, set2, set3; //Create sets
    set1.init(5); set2.init(5); set3.init(8); //Initialize sets

    //*Test Adding to Sets
    set1.add(1,2,4,8,16);
    set1.print();


    set1._delete(); set1._delete(); set3._delete();
    return 0;
}