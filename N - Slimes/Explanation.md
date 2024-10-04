# N  - Slimes 
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_n](https://atcoder.jp/contests/dp/tasks/dp_n)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[l][r]` como el **mínimo costo** de repartir unir todos los slimes desde el índice `l` hasta el índice `r`.
   
2. **Transición**: 
    - Para calcular `dp[l][r]`, necesitamos calcular el mínimo costo de dividir el rango en dos. Por lo que las transiciones se van a calcular en un bucle que itera desde `l` hasta `r` (inclusivo) para determinar que división es mas optima:
      - `for j = l to r : dp[l][r] = min(dp[l][r], f(l,j) + f(j+1,r) + prfx[r] - prfx[l-1]);`
    - Se implementa el prefix para no tener que calcular los rangos varias veces.

3. **Inicialización**:
   - `f(l,j) + f(j+1,r) + prfx[r] - prfx[l-1])`. El costo que tiene unir un rango necesariamente tiene que incluir la suma de todos sus elementos, independiente al orden que se decida hacer.
   - `prfx[i][0] = 1`. Solo hay una forma de repartir `0` dulces entre `i` niños. 

4. **Estado Final**: 
   - `dp[0][n-1]`. El costo mínimo de dividir el arreglo completo.

## Análisis de Complejidad
- **Tiempo**: `O(n**3)`, ya que para cada elemento del arreglo vamos a tener que revisar las combinaciones del rango.
- **Espacio**: `O(n*2)`, ya que se usa un vector `dp` de tamaño `n*n`. Que almacena el mínimo costo de dividir cada sección.


