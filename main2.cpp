#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

int main(int argc, char **argv){
    int i, j;
    int match = 1;   
    for(i = 1; i < argc; i++){
        Stack s;
        match = 1; 
        
        cout << "Checking " << argv[i] << " ... ";
        
        for(j = 0; j < strlen(argv[i]); j++){
            char c = argv[i][j];
            
            if(c == '{' || c == '['){
                s.push(c);
            }
            else if(c == '}' || c == ']'){
                int open = s.pop(); 
                
                if(open == -1){ 
                    cout << "Incorrect: Too many closed parenthesis" << endl;
                    match = 0;
                    break;
                }
                
                if((c == '}' && open != '{') || (c == ']' && open != '[')){
                    cout << "Incorrect: Mismatch detected" << endl;
                    match = 0;
                    break;
                }
            }
        }
        
        if(match == 1){
            if(s.getSize() > 0){
                cout << "Incorrect: Too many open parenthesis" << endl;
            }
            else {
                cout << "Correct" << endl;
            }
        }
    }
    
    return 0;
}