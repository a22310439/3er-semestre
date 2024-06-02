import pygame

def gameLoop(width, height, window, black, white, update, render, time):
    # Centro y radio del círculo
    center = [width // 2, height // 2]
    radius = 300

    # Número de vértices iniciales
    n_vertices = 5

    # Velocidad de movimiento
    move_speed = 1

    # Intervalo de tiempo para cambiar el número de vértices y el radio
    vertex_change_interval = 0.01
    radius_change_interval = 0.01

    last_change_time = time.time()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        radius, n_vertices, last_change_time = update.update(
            center, radius, n_vertices, last_change_time, vertex_change_interval, 
            radius_change_interval, move_speed, width, height
        )
        render.render(window, center, radius, n_vertices, white, black)

    pygame.quit()