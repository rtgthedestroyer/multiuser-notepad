//the notes.c file
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>



#define FILENAME "notes.txt""
#define MAX_LINE 1024

void usage(const char *prog){
    fprintf(stderr, "Usage:\n"
            " %s add \"your note\"\n"
            " %s list\n",
            prog, prog);
    exit(1);
}
///////////////////////////////////////////////////////////

void add_note(const char *text){
    //write to the note
    int fd = open(FILENAME,O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    
    if(fd<0){ perror("open to add"); exit(1); } //error

    //write the text
    size_t len = strlen(text);
    if (write(fd,text,len)!= (ssize_t)len){
        perror("write note");
        close(fd);
        exit(1);
    }

    //newline
    if (write(fd, "\n",1)!=1){
        perror("write new line");
        close(fd);
        exit(1);
    }

    close(fd);
    printf("note added\n");

}









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
