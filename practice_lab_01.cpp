#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

class List{
    
    private: //!PRIVATE
    char *elements;
    int size, num_elements;
    
    //Misc
    void construct(int size){ //Helper function for constructor
        this->size = size;
        elements = (char*) malloc(this->size * sizeof(char));
    }
    
    void copy(const List& list){ //Helper function for copy constructor
        int max = list.size;
        construct(max);
        memcpy(elements, list.elements, size);
        num_elements = max;
    }
    
    int is_exist(const char ELEMENT){ //Check if an element exists in the list or not
        for(int i=0; i<num_elements; i++){
            if(ELEMENT==elements[i]) return i;
        }
        return -1;
    }

    public: //!PUBLIC
    //Constructors
    List(int size = 5){ //One Parameter
        construct(size);
        num_elements = 0;
    }
    List(int size, const char array[]){ //Two Parameters
        construct(size);
        memcpy(elements, array, size);
        num_elements = size;
    }
      
    List(const List& list){ //Copy Constructor
        copy(list);
    }   
    List operator = (const List& list){ //Assignment Operator
        copy(list);
        return *this;
    }
    
    //Operators
    List operator += (const List& list){ //Add elements of second List to first one
        int index = size - 1;
        size = size + list.size;
        num_elements = size;
        elements = (char*) realloc(elements, size * sizeof(char));

        for(int i=0; i<list.size; i++){
            elements[index++] = list.elements[i];
        }

        return *this;
    }

    List operator += (const char element){ //Add an element to the list

        if(num_elements == size){
            size++;
            elements = (char*) realloc(elements, size * sizeof(char));
        }
        elements[num_elements++] = element;

        return *this;
    }

    List operator -= (const List& list){ //Remove elements of second list in first list
        int index, decrement = 0;

        for(int i=0; i<list.size; i++){
            index = is_exist(list.elements[i]);

            if(index != -1){
                decrement++;

                for(int j=index; j<size-1; j++){
                    elements[j] = elements[j+1];
                }
            }
        }

        num_elements = num_elements - decrement;
        shrink(decrement);
        return *this;
    }
    
    List operator + (const List& list){ //Add elements of 2 lists into one
        List newlist(*this);
        newlist += list;
        return newlist;
    }

    List operator - (const List& list){ //Add elements of first list except the ones in the second list
        List newlist(*this);
        newlist -= list;
        return newlist;
    }

    friend ostream& operator << (ostream& out, const List& list){ //Print list

        if(list.num_elements == 0 || list.size == 0){
            out << "EMPTY LIST" << endl;

        }else{ 
            out << list.elements[0];
            for(int i=1; i<list.num_elements; i++){
                out << " " << list.elements[i];
            }
            out << endl;
        }

        return out;
    }

    //Misc
    void shrink(int decrement){
        size = size - decrement;
        elements = (char*) realloc(elements, size * sizeof(char));
    }
    
    //Destructor
    ~List(){
        free(elements);
    }
    
};

void menu(List** strings, int op){

    int i, i2, i3, i_param;
    char* c_param;

    switch(op){
        case 1:
            cin >> i;
            strings[i] = new List();
            break;
        
        case 2:
            cin >> i >> i_param;
            c_param = (char*) malloc(i_param * sizeof(char));
            for(int j=0; j<i_param; j++){
                cin >> c_param[j];
            }
            strings[i] = new List(i_param, c_param);
            free(c_param);
            break;

        case 3:
            cin >> i >> i_param;
            strings[i] = strings[i_param];
            break;

        case 4:
            cin >> i >> i2;
            strings[i] = strings[i2];
            break;

        case 5:
            cin >> i;
            strings[i]->~List();
            break;

        case 6:
            cin >> i >> i2;
            *strings[i] += *strings[i2];
            break;

        case 7:
            cin >> i >> i2;
            *strings[i] -= *strings[i2];
            break;

        case 8:
            cin >> i >> i2 >> i3;
            *strings[i3] = *strings[i] + *strings[i2];
            break;

        case 9:
            cin >> i >> i2 >> i3;
            *strings[i3] = *strings[i] - *strings[i2];
            break;

        case 10:
            cin >> i;
            cout << strings[i];
            break;
        
        case 11:
            cin >> i >> *c_param;
            strings[i] += *c_param;
            break;
    }

}

int main(){

    int ops, op;
    List** strings = (List**) malloc(2 * sizeof(List*));  
    memset(strings, NULL, sizeof(strings));

    cin >> ops;

    for(int i=0; i<ops; i++){
        menu(strings, op);
    }

    return 0;
}