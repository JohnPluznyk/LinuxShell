#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//what is a shell
//a shell simply is an interpreter
//it takes commands usally in specficed order e.g. in bash > cmd (args) file'
//how does are shell know where these commands are?
//it goes into the bin folder and searches for the command if the command is found it will execute the command on the file
//if the command is not found it will then return with an error
//the shell will also continusouly run until the user types exit or an error occurs

//search the file system sort the file system
void batchMode(){
    printf("Batch mode:\n");
}

int main(int argc, char *argv[]){
    printf("Hello welcome to the shell.\n");  //Weclome user to shell

    if(argc != 1){  //if more than one argument is entered run in batch mode
        batchMode();
        return 0;  //we can exit the program after bathc mode is executed b/c batch mode should only run once
    }

    //int boolean = 0;  //boolean variable to decide whether batch mode is acceptable or not
    char *input = NULL;  //take user input and store it in string literal
    size_t size = 0;
    ssize_t chars_read;
    //int num_args = 0;

    while(1){  //if no arguments are entered run in interactive mode
        int num_args = 0;  //holds number of arguments
        printf("grsh> ");  //prompts user
        chars_read = getline(&input, &size, stdin);  //stores characters read in char_read

        char *dup;
        dup = malloc(chars_read);  //duplicate array into a mutable array
        dup = input;

        printf("Input: %s\n", dup);  //debugging purpose

        for(int i = 0; i<strlen(dup); i++){  //for loop that keeps track of the amount of spaces in the input
            if(dup[i] == ' ')  //if we dont find white space add argument to an array of strings  //do i need to find how many spaces are first?
                num_args++;
        }
        num_args++;  //allocate one more space for the last word
        num_args++;  //allocate one more space for NULL
        printf("num_args: %d\n\n", (num_args));
        //now I need to create an array to store all my arguments like argv

        //char *argumentv[num_args]; //lets hope this works trying to store arguments in an array

        char *arguments[num_args];
        arguments[0] = strtok(dup, " ");  //I should see if I can store it in an aray of pointers instead of just one        
        
        for (int i = 1; i < num_args - 1; i++)  //fill array with arguments
            arguments[i] = strtok(NULL, " ");
        
        arguments[num_args - 1] = NULL;  //set last arguemnt to NULL

        //this below for loops simpleu just prints out the value
        
        for(int i = 0; i<num_args; i++){  //print out arguments
            printf("args[%d]: %s\n", i, arguments[i]);
        }
        

        //fork();//we want to fork the process and call execute
        //exec();

        pid_t p = fork();

        if(p<0){
            perror("fork fail");
            exit(1);
        }

        else if (p == 0){
            execvp(arguments[0], arguments);
        }
        sleep(1);
        printf("\n");
        printf("Hello World! process_id(%d)\n", getpid());
        
        //free allocated memory
        //free(dup);
        num_args = 0;
    }

    return 0;
}