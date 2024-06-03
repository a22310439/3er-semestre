import pygame

def gameLoop(width, height, window, black, white, update, render, time):
    # Centro y radio del círculo
    center = [width / 2, height / 2]
    radius = 300

    # Número de vértices iniciales
    n_vertices = 5

    # Velocidad de movimiento
    movementSpeed = 1

    # Intervalo de tiempo para cambiar el número de vértices y el radio
    vertexInterval = 0.01
    radiusInterval = 0.01

    lastChangeTime = time.time()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        radius, n_vertices, lastChangeTime = update.update(
            center, radius, n_vertices, lastChangeTime, vertexInterval, 
            radiusInterval, movementSpeed, width, height
        )
        render.render(window, center, radius, n_vertices, white, black)

    pygame.quit()