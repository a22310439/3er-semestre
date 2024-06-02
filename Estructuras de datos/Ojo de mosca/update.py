import pygame
import time

def update(center, radius, n_vertices, last_change_time, vertex_change_interval, 
           radius_change_interval, move_speed, width, height):
    current_time = time.time()
    keys = pygame.key.get_pressed()
    
    # Cambiar el radio con un intervalo de tiempo
    if current_time - last_change_time > radius_change_interval:
        if keys[pygame.K_q]:  # Disminuir el radio
            radius -= 5
            if radius < 5:  # Asegurarse de que el radio no sea negativo o cero
                radius = 5
            last_change_time = current_time  # Reiniciar el temporizador
        if keys[pygame.K_e]:  # Aumentar el radio
            # Para el tamaño del círculo
            if (center[0] + radius + 5 <= width and center[0] - radius - 5 >= 0 and
                center[1] + radius + 5 <= height and center[1] - radius - 5 >= 0):
                radius += 5
            last_change_time = current_time  # Reiniciar el temporizador
    
    # Cambiar el número de vértices con un intervalo de tiempo
    if current_time - last_change_time > vertex_change_interval:
        if keys[pygame.K_f]:  # Disminuir el número de vértices
            n_vertices -= 1
            if n_vertices < 3:  # Asegurarse de que el número de vértices no sea menor que 3
                n_vertices = 3
            last_change_time = current_time  # Reiniciar el temporizador
        if keys[pygame.K_r]:  # Aumentar el número de vértices
            n_vertices += 1
            last_change_time = current_time  # Reiniciar el temporizador
        if keys[pygame.K_w]:  # Mover hacia arriba
            center[1] -= move_speed
        if keys[pygame.K_s]:  # Mover hacia abajo
            center[1] += move_speed
        if keys[pygame.K_a]:  # Mover hacia la izquierda
            center[0] -= move_speed
        if keys[pygame.K_d]:  # Mover hacia la derecha
            center[0] += move_speed
    
    # Limitar el espacio a la ventana
    if center[0] - radius < 0:
        center[0] = radius
    if center[0] + radius > width:
        center[0] = width - radius
    if center[1] - radius < 0:
        center[1] = radius
    if center[1] + radius > height:
        center[1] = height - radius
    
    return radius, n_vertices, last_change_time