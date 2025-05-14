# Laboratorio: Algoritmos de Dijkstra y Floyd-Warshall  
**Pontificia Universidad Javeriana – Estructuras de Datos**

Este laboratorio tiene como objetivo aplicar y comparar los algoritmos de Dijkstra y Floyd-Warshall para el cálculo de rutas más cortas en grafos ponderados.

## Descripción

Se implementaron dos programas en C++ que permiten:

- Calcular la ruta más corta desde un nodo origen a todos los demás usando el algoritmo de **Dijkstra**.
- Calcular las rutas más cortas entre todos los pares de nodos utilizando el algoritmo de **Floyd-Warshall**.

Ambos algoritmos trabajan sobre grafos representados mediante matrices de adyacencia.

## Estructura del Proyecto

- `dijkstra.cpp`: Implementación del algoritmo de Dijkstra.
- `floydWarshal.cpp`: Implementación del algoritmo de Floyd-Warshall.

## Instrucciones de Compilación

Para compilar los programas, utilizar los siguientes comandos desde la terminal:

```bash
g++ -o progDijkstra dijkstra.cpp
g++ -o progFloyd floydWarshal.cpp
```

Esto generará dos ejecutables: `progDijkstra` y `progFloyd`.

## Instrucciones de Ejecución

Una vez compilados, los programas se pueden ejecutar con:

```bash
./progDijkstra
./progFloyd
```

Asegúrate de tener los archivos de entrada necesarios (si aplica) en el mismo directorio o modifica el código fuente para adaptarlo a tus necesidades de entrada/salida.

## Requisitos

- Compilador compatible con C++ (g++)
- Sistema operativo compatible con ejecución de binarios (`Linux`, `WSL`, o `MacOS`)

## Créditos

Este laboratorio fue desarrollado como parte del curso de **Estructuras de Datos** en la **Pontificia Universidad Javeriana** por **Juan Esteban Bello Durango**.
