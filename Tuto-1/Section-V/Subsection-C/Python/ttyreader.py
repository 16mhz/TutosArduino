#!/usr/bin/python3
# -*- coding: utf-8 -*-

import serial
import subprocess
import time

KEY_VALUES = ['Q', 'S', 'D', 'F', 'Return']
KEY_DOWN = [0, 0, 0, 0, 0]
KEYS_NB = 5

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=10)

while True:
	try:
		line = ser.readline().strip()
		value = int(line)

		# On boucle pour lire l'état de chaque bouton.
		for i in range(KEYS_NB):
			# On effectue un ET binaire pour connaitre l'état du bouton.
			down = (value & 2**i)
			# On récupère la touche correspondante au numéro du bouton.
			key = KEY_VALUES[i]
			if (down and not KEY_DOWN[i]):
				# Dans le cas où l'état du bouton a changé depuis la dernière
				# vérification et que le bouton est enfoncé (down = 1), on
				# appelle un sous-processus pour simuler l'appui sur la touche.
				subprocess.call(["xdotool", "keydown", key])
				# On sauvegarde l'état courant
				KEY_DOWN[i] = 1
			elif (not down and KEY_DOWN[i]):
				# Si l'état du bouton a changé et que le bouton n'est pas
				# enfoncé, on simule le relâchement de la touche.
				subprocess.call(["xdotool", "keyup", key])
				# On sauvegarde l'état courant
				KEY_DOWN[i] = 0
	except Exception:
		pass

ser.close();
