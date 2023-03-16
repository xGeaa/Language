
#include <iostream>
#include <string>
#include "Bigram.h"

Bigram::Bigram(const std::string& text){
        if (text.length() == 2){
            _text = text;
        } else{
            _text = "__";
        }
    }
Bigram::Bigram(char first, char second){
        _text [0] = first;
        _text [1] = second;
    }
    
std::string Bigram::getText() const{
        return _text;
    }
    
std::string Bigram::toString() const{
        return _text;
    }

const char& Bigram::at(int index) const{
    return _text[index];
    }
     
char& Bigram::at(int index){
    return _text[index];
    }
 

bool isValidCharacter(char character, const std::string& validCharacters){
    for(int i = 0; i<validCharacters.length(); i++){
        if(character == validCharacters[i])
            return true;
    }
    return false;
}

void toUpper(Bigram &bigram){
    const int diff_ascii = 'a' - 'A', diff_ascii_esp = 'à' - 'À';
    
    for(int i=0; i<2; i++){
        if(bigram.at(i) >= 'a' && bigram.at(i) <= 'z'){
            bigram.at(i) -= diff_ascii;  
        } else {
            if (bigram.at(i) >= 'à' && bigram.at(i) <= 'ü'){
               bigram.at(i) -= diff_ascii_esp;
            }
        }
    }
}



