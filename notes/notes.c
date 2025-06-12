//the notes.c file
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>



#define FILENAME "notes.txt""
#define MAX_LINE 1024










//main 
int main(int argc, char *argv[]){
    
    //check if theres at least a single arguement
    if(argc<2){
        usage(argv[0]);
    }
    
    //add to the note
    if(strcmp(argv[1],"add")==0){
        //if there is no input to add
        if (argc!=3){ 
            usage(argv[0]); 
        }
        add_note(argv[2]); //add 
        
        //list command
    }   else if (strcmp(argv[1], "list")==0){
            list_notes();
    }   else {
            
        usage(argv[0]);

    }
        return 0;

}
