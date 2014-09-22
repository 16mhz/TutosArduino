#!/usr/bin/python3
# -*- coding: utf-8 -*-

import serial

# Lecture du port ttyACM0 à une vitesse de 9600 symboles par seconde
# et avec un timeout à 10 secondes
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=10)

# Boucle infinie de lecture
while True:
	# On met l'instruction de lecture dans un try / except pour éviter les
	# plantages trop secs
	try:
		# On lit la ligne et on enlève le ou les caractère(s) de fin de ligne
		line = ser.readline().strip()
		# On affiche ce que l'on a lu
		print(line)
	# Dans le cas d'une exception, on ne fait rien
	except Exception:
		pass

# On n'oublie pas de libérer le port
ser.close();
