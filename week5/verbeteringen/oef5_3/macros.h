#define SQUARE(x) ((x) * (x)) //macro functies altijd met veel haakjes om problemen te vermijden
#define SUM(x,y) (x+y)
#define NUMBER 666
#define LUCKY //we willen dat NUMBER 7 is, ifdef weghalen werkt ook
#ifdef LUCKY
#define NUMBER 7
#endif
