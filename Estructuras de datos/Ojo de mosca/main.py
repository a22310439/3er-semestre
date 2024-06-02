import pygame
import time
import update
import render
import gameLoop

pygame.init()

# Configuración de la ventana
width, height = 800, 800
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Ojo de Mosca Dinamica")

# Colores
black = (0, 0, 0)
white = (255, 255, 255)

# gameLoop
gameLoop.gameLoop(width, height, window, black, white, update, render, time)
