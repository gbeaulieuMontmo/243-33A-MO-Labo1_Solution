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

// Manipulation 1: Afficher "Bonjour le monde!" dans le moniteur série.
void manipulation1() {
  Serial.println("Bonjour le monde!");  
}

// Manipulation 2: Convertir des pouces en centimètres et afficher le résultat.
void manipulation2() {
  float pouces = 12.0;
  float cm = pouces * 2.54;
  Serial.print(pouces);
  Serial.print(" pouces = ");
  Serial.print(cm);
  Serial.println(" cm");
}

// Configuration du uC
void setup() {
  Serial.begin(9600);
}

// Boucle principale
void loop() {
  manipulation1();
  // manipulation2();
  delay(1000);
}
