#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
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
        num_args++;  //allocate one more space for num_args
        printf("num_args: %d\n\n", (num_args));
        //now I need to create an array to store all my arguments like argv

        //char *argumentv[num_args]; //lets hope this works trying to store arguments in an array

        char *arguments[num_args];
        arguments[0] = strtok(dup, " ");  //I should see if I can store it in an aray of pointers instead of just one        
        
        for (int i = 1; i < num_args; i++)
            arguments[i] = strtok(NULL, " ");
        
        

        //this below for loops simpleu just prints out the value
        
        for(int i = 0; i<num_args; i++){
            printf("args[%d]: %s\n", i, arguments[i]);
        }
        
        num_args = 0;
        
        //free allocated memory
        //free(dup);
    }

    return 0;
}

/*
    if argument count is 2
        go into batch mode
        read file
        while file not end
            pass line to function
    else if argument count is 1
        go into interactive mode
        do
            print prompt
            read line from user
            pass line to function
        while (true)
    else
        error message 
*/
