# M - Candies 
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_m](https://atcoder.jp/contests/dp/tasks/dp_m)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][j]` como **el número de posibilidades** de repartir `j` dulces entre los primeros `i` niños.
   
2. **Transición**: 
    - Para calcular `dp[i][j]`, necesitamos calcular las formas de repartir `j` dulces entre los primeros `i` niños. Esto se puede dividir en una sumatoria con dos partes:
      - Las formas de repartir `j` dulces entre `i-1` niños
      - Las formas de repartir `j-1` dulces entre los primeros `i` niños

    - Esta implementación se hace con el prefix porque necesitamos la acumulación en cada resultado:
       - `prfx[i][j] = (prfx[i-1][j] + prfx[i][j-1]) % M;`

    - Sin embargo, es posible que, al calcular `prfx[i][j]`, estemos contando combinaciones en las que el i-ésimo niño recibe más dulces de los permitidos según su capacidad `v[i]`. Si le damos más de `v[i]` dulces, esas combinaciones no son válidas y deben ser excluidas.

    - Para manejar esto, debemos restar las combinaciones que exceden la capacidad máxima de dulces que el `i-ésimo` niño puede recibir. Es decir, si `j` (el número de dulces distribuidos) es mayor a `v[i]`, las combinaciones que se obtienen al darle más de `v[i]` dulces al `i-ésimo` niño deben ser eliminadas de `prfx[i][j]`.
         - `if(j-v[i]-1>= 0 ) prfx[i][j] = (prfx[i][j] - prfx[i-1][j-v[i]-1] + M) % M;`

3. **Inicialización**:
   - `prfx[0][j] = 1`. Solo hay una forma de repartir `j` dulces entre `0` niños.
   - `prfx[i][0] = 1`. Solo hay una forma de repartir `0` dulces entre `i` niños. 

4. **Estado Final**: 
   - `prfx[n-1][k]`. Las formas de repartir `k` dulces entre los primeros `n-1` niños.

## Análisis de Complejidad
- **Tiempo**: `O(n*k)`, ya que necesitamos recorrer para los primeros `n` niños todos los dulces entre `0 y k` que se pueden repartir
- **Espacio**: `O(n*k)`, ya que se usa un vector `dp` de tamaño `N*n`. Que almacena la combinación de los dulces que se pueden repartir para cada índice del arreglo.


