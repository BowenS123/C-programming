#include <stdio.h>
#include <string.h>

//De opdracht is om de maanden alphabetisch te sorteren.

//De checker functie neemt 2 strings en geeft een -1 of 1 afhankelijk van welke eerder komt
/*
Vergeet niet dat wat hier gebruikt wordt een niveau van pointers is dat nog verondersteld wordt
te lukken, dit is wel echt die piek van hoe complex pointers dit vak mogen zijn.
*/
int checker(const char *str1, const char *str2) { //strings worden doorgegeven als pointers naar de eerste char
    //We gaan de characters van de string af tot een van de strings eindigt
    while (*str1 != '\0' && *str2 != '\0') { //*str geeft de inhoud van een pointer
        if (*str1 < *str2) {
            return -1; // str1 komt eerder.
        } else if (*str1 > *str2) {
            return 1;  // str1 komt later.
        }
        str1++; //De waarde van een string pointer verhogen geeft latere chars van de string
        str2++; //let op dat je de waarde niet voorbij u \0 verhoogt (garanderen we hier met de while loop)
    }

    //stel dat een string langer is dan de andere en dezelfde letters heeft (bv appel en appelboom)
    //dan gaat dit de kortere string eerst plaatsen. Voor maanden is dit niet echt nodig.
    if (*str1 == '\0' && *str2 != '\0') {
        return -1; 
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    }

    // Als beide strings identiek zijn geven we 0 terug
    return 0;
}

int main() {
    const char *months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    char *sorted[12];  //array om de gesorteerde maanden in bij te houden
    
    //eerst kopieren we alle maanden over naar sorted, je kan ook manueel sorted met waardes initialiseren
    for (int i = 0; i < 12; i++) {
        sorted[i] = months[i];
    }

    //dan maken we gebruik van de checker functie om alle maanden te sorteren.
    /*
    er zijn veel verschillende systemen voor hoe je kan sorten, dit is een van de kortere.
    De eerste loop gaat over alle maanden behalve de laatste.
    De tweede loop gaat over alle maanden die na je huidige maand komen.
    Binnen de tweede loop kijk je of u maand van loop 1 voor of na u huidige van loop 2 komt.
    Als u maand van loop 1 later komt wissel je hun positie in sorted om.

    Dit soort oefeningen gaan veel vlotter als je op papier voor uzelf uittekend hoe u loops zich
    gaan gedragern
    */
    for (int i = 0; i < 12 - 1; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (checker(sorted[i], sorted[j]) > 0) {
                
                char *temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    //en we printen uiteraard uit wat onze sorted uitendelijk is.
    printf("gesorteerde maanden:\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\n", sorted[i]);
    }

    return 0;
}
