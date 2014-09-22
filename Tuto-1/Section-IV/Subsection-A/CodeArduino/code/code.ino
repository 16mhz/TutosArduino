// On définit la broche correspondant à chaque bouton poussoir
const int brocheBouton1 = 2;
const int brocheBouton2 = 3;
// Initialisation de l'état du bouton
int etatBouton1 = 0;
int etatBouton2 = 0;

void setup() {
  // Initialisation de la transmission via le port série à 9600 bauds
  Serial.begin(9600);
  // Sélection du mode "entrée" pour chaque broche 
  pinMode(brocheBouton1, INPUT);
  pinMode(brocheBouton2, INPUT);
}

void loop(){
  // Lecture de l'état des boutons
  etatBouton1 = digitalRead(brocheBouton1);
  etatBouton2 = digitalRead(brocheBouton2);

  // Test de l'état du premier bouton
  if (etatBouton1 == HIGH) {
    // On écrit le message sur le port série
    Serial.println("Bouton 1 appuye");
  } 
  else {
    Serial.println("Bouton 1 relache");
  }
  
  // Test de l'état du second bouton
  if (etatBouton2 == HIGH) {
    // On écrit le message sur le port série
    Serial.println("Bouton 2 appuye");
  } 
  else {
    Serial.println("Bouton 2 relache");
  }
  
  // On patiente une seconde (1000 ms) pour avoir un affichage lisible
  delay(1000);
}
