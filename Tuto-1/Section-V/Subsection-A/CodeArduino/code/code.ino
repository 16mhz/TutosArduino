const int NOMBRE_BOUTONS = 5;

// On définit les broches pour les deux boutons
const int BROCHE_BOUTONS[] = {2, 3, 4, 5, 6};

// Initialisation des états des boutons
int etatBoutons[] = {0, 0, 0, 0, 0};
byte valeursBoutons = B0;

void setup() {
  // Initialisation de la transmission via le port série à 9600 bauds
  Serial.begin(9600);
  
  // Sélection du mode "entrée" pour chaque broche 
  for (int i = 0; i < NOMBRE_BOUTONS; i++) {
    pinMode(BROCHE_BOUTONS[i], INPUT);
  }
}

void loop() {
  // Initialisation du byte de stockage à 0 (aucun boutons appuyés)
  valeursBoutons = B0;
  for (int i = 0; i < NOMBRE_BOUTONS; i++) {
    etatBoutons[i] =  digitalRead(BROCHE_BOUTONS[i]);

    // Si le bouton est appuyé, on sauvegarde son état
	if (etatBoutons[i] == HIGH) {
	  // On décale à gauche le bit à 1 autant de fois que nécessaire en fonction du numéro du bouton
	  byte valeur = 1 << i;
	  // On utilise l'opérateur |= pour effectuer un OU binaire puis une affectation
	  valeursBoutons |= valeur;
	}
  }
  Serial.println(valeursBoutons);
  delay(100);
}

