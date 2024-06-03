import pygame

def render(screen, eyeLines, posAndSize, index):
    # Rellenar la pantalla de blanco
    screen.fill((255, 255, 255))
    
    # Dibujar los círculos en la pantalla principal
    for x, y, size in posAndSize:
        pygame.draw.circle(screen, (0, 0, 0), (x, y), size, 1)
    
    # Dibujar las líneas de manera intercalada
    for i, lines in enumerate(eyeLines):
        for j in range(index[i]):
            start, end = lines[j]
            pygame.draw.line(screen, (0, 0, 0), start, end, 1)
    
    pygame.display.flip()