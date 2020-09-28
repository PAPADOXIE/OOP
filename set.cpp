#include <iostream>
using namespace std;

struct Set{
    int *data, size, max_size; //In order: Set Members, Current Size, Maximum Size

    void init(const int SIZE){ //Initialize the set with given max value
        *data = (int*) malloc(SIZE * sizeof(int)); //Used malloc because realloc is easier than copying the whole set over
        max_size = SIZE;
        size = 0;
    }

    bool is_exist(){ //TODO Check if an element exists in the set or not

    }

    bool add(const int ELEMENT){ //TODO Add new element to set
        
    }

    void print(){ //TODO Output the contents of the set

    }

    Set _union(const Set &set){ //TODO Create a new set from 2 given sets which contains all elements from both sets

    }

    Set intersection(const Set &set){

    }

    Set difference(const Set &set){

    }

    void resize(const int newSize){

    }

};

int main(int argc, char *argv[]){

}