import pygame
import multiprocessing
import time
import process
import render

def gameLoop():

    # Configuración del programa en general
    pygame.init()
    screen = pygame.display.set_mode((800, 600))
    pygame.display.set_caption("Ojos de Mosca")

    numProcess = 4
    pos = [(200, 150), (600, 150), (200, 450), (600, 450)]
    size = [100, 100, 100, 100] # Un arreglo para hacer posible el cambio de tamaño de los ojos de mosca
    vertex = [8, 12, 16, 20]  # Diferente número de vértices para cada ojo de mosca

    # Crear la barrera para sincronizar los procesos
    barrier = multiprocessing.Barrier(numProcess + 1)
    
    # Crear la cola para comunicación
    queue = multiprocessing.Queue()
    
    # Procesar las líneas y posiciones
    eyeLines, posAndSize = process.process(queue, barrier, numProcess, pos, size, vertex)

    # Crear un array compartido para el índice de línea actual
    index = multiprocessing.Array('i', [0] * numProcess)

    running = True
    startTime = time.time()
    totalTime = 10  # Tiempo total en segundos para que cada proceso dibuje todas sus líneas
    waitTimes = [totalTime / len(lines) for lines in eyeLines]

    # Bucle principal
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        currentTime = time.time()
        elapsedTime = currentTime - startTime

        for i, (lines, wait_time) in enumerate(zip(eyeLines, waitTimes)):
            while index[i] < len(lines) and elapsedTime >= index[i] * wait_time:
                index[i] += 1

        render.render(screen, eyeLines, posAndSize, index)

        if all(index >= len(lines) for index, lines in zip(index, eyeLines)):
            break

    # Mantener la ventana abierta hasta que el usuario la cierre
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

    pygame.quit()
