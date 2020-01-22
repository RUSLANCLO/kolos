#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Person{
    char *surname;
    char *forename;
}Person;

typedef struct Person *ptrToPerson;

int readForenameFromUser(ptrToPerson person_pointer);
int readSurnameFromUser(ptrToPerson person_pointer);

int main(void){
    ptrToPerson person_pointer = (ptrToPerson)malloc(sizeof(ptrToPerson));
    if (!person_pointer)
        return 1;
    printf("Enter forename:\n");
    readForenameFromUser(person_pointer);
    printf("Enter surname:\n");
    readSurnameFromUser(person_pointer);

    printf("%p \t %p \t %p \n", person_pointer, person_pointer->forename, person_pointer->surname);

    printf("Person \t %s \t %s\n", person_pointer->forename, person_pointer->surname);

    free(person_pointer->surname);
    free(person_pointer->forename);
    free(person_pointer);
    return 0;

}

int readForenameFromUser(ptrToPerson person_pointer){
    char inputted_char[1] = {'\0'};
    int size = 1;
    while (inputted_char[0] != '\n'){
        inputted_char[0] = (char)getchar();
        person_pointer->forename = realloc(person_pointer->forename, size);
        if (!person_pointer->forename)
            return 1;
        person_pointer->forename = strncat(person_pointer->forename, inputted_char, 1);
        size++;

    }
    return 0;
}


int readSurnameFromUser(ptrToPerson person_pointer){
    char inputted_char[1] = {'\0'};
    int size = 1;
    while (inputted_char[0] != '\n'){
        inputted_char[0] = (char)getchar();
        person_pointer->surname = realloc(person_pointer->surname, size);
        if (!person_pointer->surname)
            return 1;
        person_pointer->surname = strncat(person_pointer->surname, inputted_char, 1);
        size++;

    }
    return 0;
}