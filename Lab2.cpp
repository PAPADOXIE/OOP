#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Player{
    //Private variables
    const int player_number = 0;
    static int number_of_players;
    int number_of_matches, *scores;
    char *status;
    
    //Private functions
    int number_of_innings(){
        int innings = 0;
        
        for(int i=0; i<number_of_matches; i++){
            if(status[i]=='O'){
                innings++;
            }
        }
        return innings;
    }
    
    public:
    //Constructor
    Player(){}
    
    Player(int number_of_matches):player_number(++number_of_players){
        this->number_of_matches =  number_of_matches;
        scores = (int*) calloc(number_of_matches, number_of_matches * sizeof(int));
        status = (char*) calloc(number_of_matches, number_of_matches * sizeof(char));
    }
    
    //Setters
    void set_scores(){
       for(int i=0; i<number_of_matches; i++){
           cin>>scores[i];
           cin>>status[i];
       } 
    }  
    
    //Getters
    static int num_players(){return number_of_players;}
    
    //Misc
    void player_average(){
        int total = 0, average;
        for(int i=0; i<number_of_matches;i++){
            total+=scores[i];
        }
        average = total/number_of_innings();
        cout<<"Average: "<<average<<endl;
    }
    
    //Display
    void dis_player(){
        cout<<"Player "<<player_number
            <<" has played "<<number_of_matches
            <<" matches and "<<number_of_innings()<<" innings"
            <<endl;
        
        cout<<"Scores:";
        for(int i=0; i<number_of_matches; i++){
            cout<<" "<<scores[i];
        }
        cout<<endl;
    }
    
    //Destructor
    ~Player(){
        number_of_players--;
        free(scores);
        free(status);
        scores = NULL;
        status = NULL;
        number_of_matches = -1;
    }
    
}; int Player::number_of_players = 0;

void menu(Player **players, int op){
    int player, matches;
    switch(op){
        case 1:
            cin>>player;
            players[player-1]->player_average();
            break;
        
        case 2:
            cin>>player;
            players[player-1]->dis_player();
            break;
            
        case 3:
            cout<<"Number of Players: "<<Player::num_players()<<endl;
            break;
            
        case 4:
            cin>>player;
            players[player-1]->player_average();
            break;   
            
        case 5:
            cin>>player;
            players[player-1]->~Player();
            break;
        
        case 6:
            cin>>player>>matches;
            players[player-1] = new Player(matches);
            break;
        
        case 7:
            cin>>player;
            players[player-1]->set_scores();
            break;
    }
}

int main(void){
    Player **players = (Player**) malloc(3* sizeof(Player*));
    int matches, ops, op;
    
    for(int i=0; i<3; i++){
        cin>>matches;
        players[i] = new Player(matches);
    }
    
    cin>>ops;
    for(int i=0; i<ops; i++){
        cin>>op;
        menu(players, op);
    }
    
    
    return 0;
}
