#include "header_1.h"
#include "header_2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    person *p1 = malloc(sizeof(person));
    p1->age = 22;
    p1->name = malloc(sizeof(char) * 256);
    strcpy(p1->name, "Aimable Nkurikiyimana");

    printf("\n =======    Person 1     ========\n");
    printf(" Name: %s\n", p1->name);
    printf(" Age: %d\n", p1->age);
    printf(" =======    End     ========\n");

    // new person
    person_details *p2 = malloc(sizeof(person_details));
    p2->name_age = malloc(sizeof(person));
    p2->name_age->name = malloc(sizeof(char) * 256);
    strcpy(p2->name_age->name, "Jean Luc Nkurikiye");
    p2->name_age->age = 23;
    p2->height = 180;
    p2->sex = 'M';

    // Dispaly person details;
    printf("\n\n =======    Person 1     ========\n");
    printf(" Name: %s\n", p2->name_age->name);
    printf(" Age: %d\n", p2->name_age->age);
    printf(" Height: %d\n", p2->height);
    printf(" Sex: %c\n", p2->sex);
    printf(" =======    End          ========\n\n");

    // Free stuff.
    free(p1->name);
    free(p1);

    free(p2->name_age->name);
    free(p2->name_age);
    free(p2);

    return 0;
}
