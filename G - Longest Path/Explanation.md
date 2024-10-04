# G - Longest Path
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_g](https://atcoder.jp/contests/dp/tasks/dp_g)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i]` como el **máximo recorrido** que podemos hacer desde el nodo `i`.
   
2. **Transición**: 
    - Para calcular `dp[i]`, necesitamos conocer la máxima longitud a la que podemos llegar considerando los nodos adyacentes más uno (el nodo actual): 
    - `  for a in v[i] : dp[i] = max(dp[i], f(a)+1);`

3. **Inicialización**:
   - Para todos los valores que no tengan un padre la respuesta será la máxima longitud de sus hijos, por este motivo se usa el arreglo mask.

4. **Estado Final**: 
   - La respuesta será el nodo que tenga la máxima longitud, entre todos los nodos que no tienen un padre.

## Análisis de Complejidad
- **Tiempo**: `O(n)`, Ya que se calculan la máxima longitud 1 vez.
- **Espacio**: `O(n)`, Ya que se usa un vector `dp` de tamaño `n`. Que almacena la máxima longitud de cada nodo.


