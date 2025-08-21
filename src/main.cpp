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

// Manipulation 3: Convertir des degrés Celsius en Fahrenheit et afficher un message 
// selon la température.
void manipulation3() {
  float celsius = 25.0;
  float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  Serial.print(celsius);
  Serial.print(" °C = ");
  Serial.print(fahrenheit);
  Serial.println(" °F");

  if (celsius <= -15.0) {
    Serial.println("Il fait froid! N'oublie pas ta tuque!");
  } else if (celsius > -15.0 && celsius < 5.0) {
    Serial.println("Il fait froid! Ca prend un manteau d'hiver.");
  } else if (celsius >= 5.0 && celsius < 15.0) {
    Serial.println("Il commence à faire chaud.");
  } else {
    Serial.println("Il fait chaud aujourd'hui!");
    Serial.println("Vive le soleil :)");
  }
}

// Manipulation 4: Calculer la TVQ, la TPS et le montant total à partir d'un montant
// avant taxes entré par l'utilisateur via le moniteur série. Afficher les résultats
// et offrir la possibilité de recommencer.
void manipulation4() {
  const float tauxTVQ = 0.09975;
  const float tauxTPS = 0.05;
  bool recommencer = true;

  while (recommencer) {
    Serial.println("Entrez le montant avant taxes: ");
    while (Serial.available() == 0) {}
    float montant = Serial.parseFloat();
    float montantTVQ = montant * tauxTVQ;
    float montantTPS = montant * tauxTPS;
    float montantTotal = montant + montantTVQ + montantTPS;
    Serial.print("Montant avant taxes: ");
    Serial.println(montant, 2);
    Serial.print("Montant de la TVQ (9.975%): ");
    Serial.println(montantTVQ, 2);
    Serial.print("Montant de la TPS (5%): ");
    Serial.println(montantTPS, 2);
    Serial.print("Montant total (avant taxes + TVQ + TPS): ");
    Serial.println(montantTotal, 2);
    Serial.println("--------------------------------------------------");

    Serial.println("Voulez-vous recommencer? (o/n)");
    recommencer = false;
    while (true) {
      while (Serial.available() == 0) {}
      char reponse = Serial.read();
      while (Serial.available()) Serial.read(); // Nettoyer le buffer
      if (reponse == 'o' || reponse == 'O') {
        recommencer = true;
        break;
      } else if (reponse == 'n' || reponse == 'N') {
        Serial.println("Fin du programme.");
        break;
      } else {
        Serial.println("Réponse invalide. Veuillez entrer 'o' pour oui ou 'n' pour non.");
      }
    }
  }
}

void manipulation5() {
  int min, max;
  Serial.println("Entrez la valeur minimale: ");
  while (Serial.available() == 0) {}  
  min = Serial.parseInt();
  Serial.println("Entrez la valeur maximale: ");
  while (Serial.available() == 0) {}
  max = Serial.parseInt();
  Serial.print("Les nombres pairs entre ");
  Serial.print(min);
  Serial.print(" et ");
  Serial.print(max);
  Serial.println(" sont: ");
  for(int i = min; i <= max; i++) {
    if(i % 2 == 0) {
      Serial.print(i);
      Serial.print(" ");
    } 
  }
  Serial.println();
  Serial.print("Les nombres impairs entre ");
  Serial.print(min);
  Serial.print(" et ");
  Serial.print(max);
  Serial.println(" sont: ");
  for(int i = min; i <= max; i++) {
    if(i % 2 != 0) {
      Serial.print(i);
      Serial.print(" ");
    } 
  }
}

// Configuration du uC
void setup() {
  Serial.begin(9600);
}

// Boucle principale
void loop() {
  //manipulation1();
  // manipulation2();
  // manipulation3();
   manipulation4();
  delay(1000);
}
