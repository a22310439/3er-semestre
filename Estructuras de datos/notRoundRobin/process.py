import math
import time
import random
import multiprocessing

# Función para calcular las líneas de un ojo de mosca
def calcEyeLines(x, y, size, numVertex):
    # Calcular los vértices
    vertex = []
    for i in range(numVertex):
        angle = 2 * math.pi * i / numVertex
        vertexX = x + size * math.cos(angle)
        vertexY = y + size * math.sin(angle)
        vertex.append((vertexX, vertexY))

    # Crear las líneas
    lines = []
    for start in vertex:
        for end in vertex:
            if start != end:
                midX = (start[0] + end[0]) / 2
                midY = (start[1] + end[1]) / 2
                if not (abs(midX - x) < 1e-6 and abs(midY - y) < 1e-6): # Control para evitar líneas que pasan por el centro del círculo
                    lines.append((start, end))
    return lines

# Función que representa un proceso independiente
def eyeProcess(queue, x, y, size, numVertex, barrier):
    # Calcular las líneas del ojo de mosca
    lines = calcEyeLines(x, y, size, numVertex)
    queue.put((x, y, size, lines))
    barrier.wait()

def process(queue, barrier, numProcess, pos, size, vertex):
    procesos = []   # Arreglo que es donde van a estar los procesos
    for i in range(numProcess):
        p = multiprocessing.Process(target=eyeProcess, args=(queue, pos[i][0], pos[i][1], size[i], vertex[i], barrier))
        procesos.append(p)
        p.start()
    
    # Esperar a que todos los procesos terminen de colocar las líneas en la cola
    barrier.wait()
    
    # Recoger las líneas de la cola y las posiciones
    eyeLines = []
    posAndSize = []
    while not queue.empty():
        x, y, size, lines = queue.get()
        eyeLines.append(lines)
        posAndSize.append((x, y, size))
    
    return eyeLines, posAndSize
