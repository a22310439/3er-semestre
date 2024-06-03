import pygame
import time

def update(center, radius, n_vertices, lastChangeTime, vertexInterval, 
           radiusInterval, movementSpeed, width, height):
    currentTime = time.time()
    keys = pygame.key.get_pressed()
    
    # Cambiar el radio con un intervalo de tiempo
    if currentTime - lastChangeTime > radiusInterval:
        if keys[pygame.K_q]:    # Disminuir el radio
            radius -= 5
            if radius < 5:      # Bloquear el radio mínimo a 5
                radius = 5
            lastChangeTime = currentTime  # Reiniciar el temporizador
        if keys[pygame.K_e]:    # Aumentar el radio
            # Para el tamaño del círculo
            if (center[0] + radius + 5 <= width and center[0] - radius - 5 >= 0 and
                center[1] + radius + 5 <= height and center[1] - radius - 5 >= 0):
                radius += 5
            lastChangeTime = currentTime  # Reiniciar el temporizador
    
    # Cambiar el número de vértices con un intervalo de tiempo
    if currentTime - lastChangeTime > vertexInterval:
        if keys[pygame.K_f]:  # Disminuir el número de vértices
            n_vertices -= 1
            if n_vertices < 3:  # Asegurarse de que el número de vértices no sea menor que 3
                n_vertices = 3
            lastChangeTime = currentTime  # Reiniciar el temporizador
        if keys[pygame.K_r]:  # Aumentar el número de vértices
            n_vertices += 1
            lastChangeTime = currentTime  # Reiniciar el temporizador
        if keys[pygame.K_w]:  # Mover hacia arriba
            center[1] -= movementSpeed
        if keys[pygame.K_s]:  # Mover hacia abajo
            center[1] += movementSpeed
        if keys[pygame.K_a]:  # Mover hacia la izquierda
            center[0] -= movementSpeed
        if keys[pygame.K_d]:  # Mover hacia la derecha
            center[0] += movementSpeed
    
    # Limitar el espacio a la ventana
    if center[0] - radius < 0:
        center[0] = radius
    if center[0] + radius > width:
        center[0] = width - radius
    if center[1] - radius < 0:
        center[1] = radius
    if center[1] + radius > height:
        center[1] = height - radius
    
    return radius, n_vertices, lastChangeTime