/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Alejandro Gea Martinez
 *
 * Created on 2 de febrero de 2023, 12:23
 */


/**
 * This program reads a text (without spaces) with a undefined number of 
 * characters and a text with two characters (bigram). It finds the bigrams 
 * contained in the first text, storing them in an array of Bigram. 
 * After that, the bigrams of the array are shown in the standard output. 
 * Then it converts to uppercase the bigrams in the array that are equals to the 
 * bigram of the second text. Finally the bigrams of the array are shown again 
 * in the standard output. 
 * Running example:
 * > language0 < data/SimpleText.txt
 */

#include "Bigram.h"


void toLowerText(std::string &text){
    const int diff_ascii = 'a' - 'A', diff_ascii_esp = 'à' - 'À';
    
    for (int i=0; i<text.length(); i++){ 
        if (text[i] >= 'A' && text[i] <= 'Z'){
            text[i] += diff_ascii;
        } else{
            if(text[i] >= 'À' && text[i] <= 'Ü'){
                text[i] += diff_ascii_esp;
            }
        }
    }
}


int main(int argc, char* argv[]) {
    // This string contains the list of characters that are considered as
    // valid within a word. The rest of characters are considered as
    // separators
    const std::string validCharacters = "abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";

    // Read a text
    std::string text, comparation;

    std::cin >> text;
    toLowerText(text);
   
    // Read a bigram (text with two characters)

    std::cin >> comparation;
    toLowerText(comparation);
    
    std::cout << std::endl;
    
    for(int i=0; i<comparation.length(); i++){
        if(comparation.length() > 2){
            std::cout << "Numero de caracteres de comparacion excedido.";
            return 0;
        }
        if(isValidCharacter(comparation[i], validCharacters) == false){
            std::cout << "Caracteres invalidos en la comparacion.";
            return 0;
        }
    }

    Bigram bigram(comparation);

    // Find the bigrams in text and put them in an array of Bigrams

    const int MAX_array = 1000;
    int utiles = 0, semejanzas = 0;

    Bigram bigrams_text [MAX_array];

    for (int i = 0; i < text.length() - 1; i++) {
        if (isValidCharacter(text[i], validCharacters) && isValidCharacter(text[i+1], validCharacters)) {
            bigrams_text[i].at(0) = text[i];
            bigrams_text[i].at(1) = text[i+1];
        }
        utiles++;
    }

    // Show the bigrams stored in the array

    for (int i = 0; i < utiles; i++) {
        std::cout << bigrams_text[i].getText() << "     ";
      
    }
    
    std::cout << std::endl << std::endl;
    
    // Convert to uppercase the bigrams in the array that are equals to input bigram

    for (int i = 0; i < utiles; i++) {
        if (bigrams_text[i].getText() == comparation) {
            toUpper(bigrams_text[i]);
            semejanzas++;
        }
    }

    // Show again the bigrams stored in the array

    std::cout << "Hay un total de: " << semejanzas << " ocurrencias." << std::endl;
    for (int i = 0; i < utiles; i++) {
        std::cout << bigrams_text[i].getText() << "     ";
    }
}



