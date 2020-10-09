#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LINE_LENGTH 500
#define NUMBER_OF_ARGUMENTS 2
#include <stdlib.h>

bool doesStringStartWith(char *string, char *pattern){
    /*
 Full credit to: Seyed for this beautiful helper function
  */
    if(strlen(pattern)==0){
        return true;
    }
    return(*string == *pattern) && doesStringStartWith(string+1, pattern+1);
}

bool doesStringContainPattern(char *string, char *pattern){
    /*
Full credit to: Seyed for this beautiful recursive function
 */
    int num=0;
    if(strlen(pattern)==0){
        return true;
    }
    while(*string){
        if (doesStringStartWith(string++,pattern)){
            return true;
        }
    }
    return false;
}



void readFile(char *argv[]) {
    char *fileName = argv[1];
    char *word = argv[2];
    int num_lines = 1;
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        perror("File not found");
    }
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
            if (doesStringContainPattern(line, word)) {
                printf("\nFound at line: %d", num_lines);
            }
            num_lines++;

        }

        fclose(file);
    }





void findIndex(char *argv[]) {
    char *fileName = argv[1];
    char *word= argv[2];

    int len_word = strlen(word);
    int char_matched = 0;
    int num_counted = 1;

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("File not found");
    }
    char character;
    while ((character = fgetc(file)) != EOF) {
        if (char_matched == len_word) {
            printf("Character: %d", num_counted-len_word);
            break;
        }

        while(character == *word) {
            char_matched++;
            word++;
        }
        num_counted++;
    }
fclose(file);
}






int main(int argc, char *argv[]) {
    printf("Name of the program %s\n", argv[0]);
    char *fileName = argv[1];
    char *wordToFind = argv[2];

    if(argc !=(NUMBER_OF_ARGUMENTS+1)){
        perror("Need exactly 2 arguments");
        exit(1);
    }

    findIndex(argv);
    readFile(argv);

}
