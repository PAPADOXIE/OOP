#include <iostream>
#include <cstdarg>
#include <cstdlib>

struct Set{
    int *data, size, max_size, *universal, universal_size; //In order: Set Members, Current Size, Maximum Size

    void init(const int SIZE){ //Initialize the set with given max value
        data = (int*) malloc(SIZE * sizeof(int)); //Used malloc because realloc is easier than copying the whole set over
        max_size = SIZE;
        size = 0;
        universal_size = 0;
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

    bool add(const int argc, ...){ //Add new elements to set
        bool added = false;
        va_list elements;
        va_start(elements, argc);
        int temp;
        
        for(int i=0; i<argc; i++){
            temp = va_arg(elements, int);
            if(size<max_size && !is_exist(temp)){
                data[size++] = temp;
                added = true;
            }
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
            union_set.add(1, set.data[i]);
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
        if(size>new_size) size = new_size;
        max_size = new_size;
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

    void build_universal(int argc, ...){ //Build the universal set in which the current set resides
        va_list sets;
        va_start(sets, argc);
        Set temp;
        universal = (int*) malloc(0 * sizeof(int)); //Just to return a pointer we can use in realloc

        for(int i=0; i<argc; i++){
            temp = va_arg(sets, Set);
            universal = (int*) realloc(universal, (universal_size+temp.size) * sizeof(int));

            for(int i=0; i<temp.size; i++){
                if(!is_exist(true, temp.data[i])){
                    universal[universal_size++] = temp.data[i];
                }
            }
        }
    }

    bool is_subset(const Set &set){ // Check to see whether external set is a subset of internal set or not
        for(int i=0; i<set.size; i++){
            if(!is_exist(set.data[i])) return false;
        }
        return true;
    }

    bool is_proper_subset (const Set &set){ //Check to see whether external set is a proper subset of internal set or not
        if(is_subset(set) && size>set.size) return true;
        else return false;
    }

    void _delete(){ //Unallocates set arrays from memory
        free(data);
        if(universal_size!=0){
            free(universal);
        }
    }

};

int main(){ //Main function
    Set set1, set2, set3; //Create sets
    set1.init(5); set2.init(5); set3.init(8); //Initialize sets

    //*Test Adding to Sets
    //First argument for add should be number of elements to add
    std::cout<<"Set1, Set2, Set3 in Order"<<std::endl;
    set1.add(3, 1, 4, 16); set1.print();
    set2.add(5, 1, 2, 4, 8, 16); set2.print();
    set3.add(8, 3, 2, 6, 5, 4, 4, 7, 8); set3.print();
    std::cout<<std::endl;
    
    //*Test Union of Sets
    std::cout<<"Union of Set1 and Set3"<<std::endl;
    Set Union = set1._union(set3); Union.print();
    std::cout<<std::endl;

    //*Test Intersection of Sets
    std::cout<<"Intersection of Set1 and Set3"<<std::endl;
    Set Intersection = set1.intersection(set3); Intersection.print();
    std::cout<<std::endl;

    //*Test Difference of Sets
    std::cout<<"Difference of Set3 and Set1"<<std::endl;
    Set Difference = set3.difference(set1); Difference.print();
    std::cout<<std::endl;

    //*Test Resizing of Sets
    std::cout<<"Set3 after Resizing"<<std::endl;
    set3.resize(5); set3.print();
    std::cout<<std::endl;
    
    //*Test Complement of Sets
    std::cout<<"Complement of Set1 with a Universal Set consisting of Set1, Set2 and Set3"<<std::endl;
    set1.build_universal(2, set2, set3); //Build the Universal Set in the structure for Set1
    Set Complement = set1.complement(); Complement.print();
    std::cout<<std::endl;

    //*Test Whether a Set is a Subset of Another or Not
    std::cout<<"Checking if Set1 is a Subset of Set2"<<std::endl;
    std::cout<<set2.is_subset(set1)<<std::endl;
    std::cout<<std::endl;

    //*Test Whether a Set is a Proper Subset of Another or Not
    std::cout<<"Checking if Set1 is a Proper Subset of Set2"<<std::endl;
    std::cout<<set2.is_proper_subset(set1)<<std::endl;
    std::cout<<std::endl;

    //Delete Sets
    set1._delete(); set2._delete(); set3._delete(); Union._delete(); Intersection._delete(); Difference._delete(); Complement._delete();
    return 0;
}