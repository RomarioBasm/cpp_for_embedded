#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main(){

    stringstream inputElement;  
    
    string inputString;     /* get the current line of input */
    string word;            /* get the word of the line      */
    string extension;       /* get the extension of the file */
    string strSize;         /* get the size of the file      */

    int caseNum = 0;        /* the number of the test cases  */
    int *inputs;            /* the number of the inputs in each test case */

    /* the size of the file. */
    int music_length    = 0;
    int images_length   = 0;
    int movies_length   = 0;
    int other_length    = 0;
    
    /* pointer to save the length of the files in each test case */
    int *music_lengths ;
    int *images_lengths; 
    int *movies_lengths; 
    int *other_lengths ; 

    int fileSize = 0;
    std::size_t found;
    int first_input = 1;
    int index = 0;
    
    /* 
    * get the first line in the inputs, 
    * the number of the test cases, and 
    * the number of line in each test case.
    */
    
    while(true){
      
        /* first input in the line, that represent the number of the test cases */
        if(first_input){
            first_input = 0;        /* change the state of the flag */
            cin>>caseNum;
            inputs = new int[caseNum];

            music_lengths = new int[caseNum];
            images_lengths= new int[caseNum]; 
            movies_lengths= new int[caseNum]; 
            other_lengths = new int[caseNum]; 
            index=0; 
        }
        else{
            cin>>inputs[index];
            index++;
        }
        if(cin.peek() =='\n'){
            break;
        }
    }

    cin.ignore();   /* to flush the buffer of the input stream */
    
    /*
    * get the length of the differnt files in each test case,
    * by getting the extension of the file, 
    * and the size of each file, 
    * then, determine this file is in which category.
    * (music, image, movies or other).
    */
    for(int i=0;i<caseNum;i++){
        music_length  = 0;
        images_length = 0;
        movies_length = 0;
        other_length  = 0;

        for(int j=0;j<(inputs[i]);j++){
            getline(cin, inputString); /* get a line of input from the user */
            
            /* pursing the input to get the extension */
            stringstream inputElement(inputString);
            inputElement>>word; 
            found = word.find_last_of('.');
            extension = word.substr(found+1);
            
            /* pursing the input to get the size of the file */
            inputElement>>word;
            int size = word.length() - 1;
            strSize = "";
            
            for(int i=0;i<size;i++){
                strSize += word[i];
            }
            fileSize = stoi(strSize); /* change the type of the size from string to int */
            
            /* checking the category of the file */
            if(extension == "mp3" ||extension == "acc"||extension == "flac"){
                music_length += fileSize;
            }
            else if(extension == "jpg" || extension == "bmp"||extension == "gif"){
                images_length += fileSize;
            }
            else if(extension == "mp4" ||extension == "avi"||extension == "mkv"){
                movies_length += fileSize;
            }
            else{
                other_length += fileSize;
            }
        }
        
        /* saving the length of the files */
        music_lengths[i] = music_length; 
        images_lengths[i]= images_length;
        movies_lengths[i]= movies_length;
        other_lengths[i] = other_length;
    }
    
    /* printing out the result */
    for(int i=0;i<caseNum;i++){
        std::cout<<"music "<<music_lengths[i];
        std::cout<<"b images "<<images_lengths[i];
        std::cout<<"b movies "<<movies_lengths[i];
        std::cout<<"b other "<<other_lengths[i]<<"b"<<endl;
    }
    return 0;
}