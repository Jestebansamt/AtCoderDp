# H - Grid 1
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_h](https://atcoder.jp/contests/dp/tasks/dp_h)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][j]` como el **número de caminos** que hay para llegar a esa casilla siempre y cuando sea una transición valida.
   
2. **Transición**: 
    - Para calcular `dp[i][j]`, necesitamos sumar el número de caminos que hay en las dos casillas adyacentes validas `dp[i-1][j]`, `dp[i][j-1]` siempre y cuando no sean `#`: 
        - `dp[i][j]+= dp[i-1][j]%MOD;`
        - `dp[i][j]+= dp[i][j-1]%MOD;`

3. **Inicialización**:
   - `dp[0][i] = 1` y `dp[i][0] = 1;`. Porque solo hay una forma de llegar a ellos, ya sea por la izquierda (para `dp[0][i]`) o por arriba (para `dp[i][0]`). Sin embargo, si hay algún `#` en el camino, el valor será cero de ahí en adelante, porque no hay ningún camino valido que conduzca a esa casilla. 

4. **Estado Final**: 
   - El valor que haya en la casilla final `dp[n-1][m-1]`

## Análisis de Complejidad
- **Tiempo**: `O(n*n)`, Ya que se calcula el número de formas de llegar a una casilla 1 vez por cada casilla.
- **Espacio**: `O(n*n)`, ya que se usa un vector `dp` de tamaño `n`. Que almacena el número de formas de llegar a cada casilla.


