#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    //open file for reading

    if(argc == 1)
        return 0;
    
    int i = 1;
    while(i != argc){

        FILE *file = fopen(argv[i], "r");

        if(file == NULL){
            printf("my_cat: cannot open file\n");
            return 1;
        }
        
        while (feof(file) == 0){
            char c = fgetc(file);
            if(c == EOF)
                break;
            printf("%c", c);
        }
        
        fclose(file);
        //printf("\n");
        i++;
    }

    return 0;
}