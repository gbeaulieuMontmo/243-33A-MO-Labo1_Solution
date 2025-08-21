/**************************************************************/
// Date de création du programme: 2 avril 2025
// Date de la dernière modification: 4 avril 2025
// Nom du programmeur principal: Guillaume Beaulieu
//
// But du programme: solution des exercices du laboratoire 1 du 
// cours de programmation 243-33A-MO Microcontrôleur 2. Chaque
// exercices est implémenté dans une fonction distincte. Il suffit
// d'appeler la fonction dans le loop() pour exécuter l'exercice.
//
// Version: 1.0
/**************************************************************/

#include <Arduino.h>

void manipulation1() {
  Serial.println("Bonjour le monde!");  
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  manipulation1();
  delay(1000);
}
