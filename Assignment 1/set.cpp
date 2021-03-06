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
        list.num_elements;
        construct(list.num_elements);
        memcpy(elements, list.elements, size);
        num_elements = list.num_elements;
    }
    
    bool is_exist(const char ELEMENT){ //Check if an element exists in the list or not
        for(int i=0; i<num_elements; i++){
            if(ELEMENT==elements[i]) return true;
        }
        return false;
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
        int index = size;
        size = num_elements + list.size;
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

    List operator -= (List& list){ //Remove elements of second list in first list
        
        List newlist(num_elements);
    
            for(int i=0; i<num_elements; i++){
                if(!list.is_exist(elements[i])){
                    newlist.elements[newlist.num_elements++] = elements[i];
                }
            }
        
        size = newlist.size;
        num_elements = newlist.num_elements;
        memcpy(elements, newlist.elements, num_elements);
        
        return *this;
    }
    
    List operator + (const List& list){ //Add elements of 2 lists into one
        List newlist(*this);
        newlist += list;
        return newlist;
    }

    List operator - (List& list){ //Add elements of first list except the ones in the second list
        List newlist(num_elements);
        
        for(int i=0; i<num_elements; i++){
            if(!list.is_exist(elements[i])){
                newlist.elements[newlist.num_elements++] = elements[i];
            }
        }
        
        return newlist;
    }

    friend ostream& operator << (ostream& out, const List& list){ //Print list

        if(list.num_elements == 0){
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
        num_elements = num_elements - decrement;
        elements = (char*) realloc(elements, num_elements * sizeof(char));
    }
    
    //Destructor
    ~List(){
        free(elements);
    }
    
};

void menu(List** strings, int op){

    int i, i2, i3, i_param;
    char* c_param;
    char c;

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
            strings[i] = new List(*strings[i_param]);
            break;

        case 4:
            cin >> i >> i2;
            *strings[i] = *strings[i2];
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
            cin >> i >> i2;
            cout << *strings[i] + *strings[i2];
            break;

        case 9:
            cin >> i >> i2;
            cout << *strings[i] - *strings[i2];
            break;

        case 10:
            cin >> i;
            if(strings[i]==NULL){
                cout << "NO OBJECT" << endl;
            }else cout << *strings[i];
            break;
        
        case 11:
            cin >> i >> c;
            *strings[i] += c;
            break;
    }

}

int main(){

    int ops, op;
    int num_lists = 2;
    List** strings = (List**) malloc(num_lists * sizeof(List*));  
    
    for(int i=0; i<num_lists; i++){
        *strings = NULL;
    }

    cin >> ops;

    for(int i=0; i<ops; i++){
        cin >> op;
        menu(strings, op);
    }

    return 0;
}
