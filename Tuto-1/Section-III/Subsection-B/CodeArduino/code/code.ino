// Numéro de la broche sur laquelle est branché le bouton
const int buttonPin = 2;
// Initialisation de l'état du bouton
int buttonState = 0;

void setup() {
  // Initialisation de la transmission via le port série à 9600 bauds
  Serial.begin(9600);
  // Sélection du mode "entrée" de la broche 
  pinMode(buttonPin, INPUT);     
}

void loop(){
  // Lecture de l'état du bouton
  buttonState = digitalRead(buttonPin);

  // On teste si le bouton est enfoncé (low)
  if (buttonState == LOW) {
    // On écrit le message sur le port série
    Serial.println("Bouton appuye");
  } 
  else {
    Serial.println("Bouton relache");
  }
}
