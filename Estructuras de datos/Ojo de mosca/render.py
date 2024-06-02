import pygame
import math
import random

def render(surface, center, radius, n_vertices, white, black):
    # Limpiar la superficie
    surface.fill(white)

    # Calcular los vértices
    vertices = []
    for i in range(n_vertices):
        angle = 2 * math.pi * i / n_vertices
        x = center[0] + radius * math.cos(angle)
        y = center[1] + radius * math.sin(angle)
        vertices.append((int(x), (int(y))))

    # Dibujar el círculo sin relleno
    pygame.draw.circle(surface, black, center, radius, 1)

    # Dibujar las líneas entre los vértices, excepto las que pasan por el centro
    for i in range(n_vertices):
        for j in range(i + 1, n_vertices):
            # Verificar si los vértices no son opuestos
            if n_vertices % 2 == 0 and abs(i - j) == n_vertices // 2:
                continue
            pygame.draw.line(surface, (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)), vertices[i], vertices[j], 1)

    pygame.display.flip()
