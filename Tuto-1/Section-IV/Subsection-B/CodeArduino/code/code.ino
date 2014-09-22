const int NOMBRE_BOUTONS = 2;

// On définit les broches pour les deux boutons
const int BROCHE_BOUTONS[] = {2, 3};

// Initialisation des états des boutons
int etatBoutons[] = {0, 0};

void setup() {
  // Initialisation de la transmission via le port série à 9600 bauds
  Serial.begin(9600);
  
  // Sélection du mode "entrée" pour chaque broche 
  for (int i = 0; i < NOMBRE_BOUTONS; i++) {
    pinMode(BROCHE_BOUTONS[i], INPUT);
  }
}

void loop(){
  // Lecture de l'état des boutons
  for (int i = 0; i < NOMBRE_BOUTONS; i++) {
    etatBoutons[i] = digitalRead(BROCHE_BOUTONS[i]);
    
    // On transmet le texte générique...
    Serial.print("Bouton ");
    Serial.print(i);
    
    // ... puis on transmet uniquement l'état qui nous intéresse
    if (etatBoutons[i] == HIGH) {
      Serial.println(" appuye");
    } 
    else {
      Serial.println(" relache");
    }
  }
  
  // On patiente une seconde (1000 ms) pour avoir un affichage lisible
  delay(1000);
}
