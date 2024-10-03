# B - Frog 2
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_b](https://atcoder.jp/contests/dp/tasks/dp_b)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i]` como el **costo mínimo** de llegar desde la roca `0` (primera) hasta la roca `i`.
   - En el estado `dp[i]`, queremos almacenar el costo total mínimo de alcanzar la roca `i` con las transiciones permitidas.
  
2. **Transición**: 
   - Para calcular `dp[i]`, la rana puede llegar desde `dp[i+1]`, `dp[i+2]` ... `dp[i+k]`, por lo tanto, definimos las transiciones como un bucle que itera de 1 hasta k:
     - `for j = 1 to k: dp[i] = min(dp[i], abs(v[i] - v[i+j]) + f(i+j))`
   - El primer término representa el costo minimo acumulado entra saltar desde la roca actual (`i`) hasta la j-esima roca, mientras que el segundo término considera todas las iteraciones de saltar desde la roca actual a la k-esima (`i+k`).

3. **Inicialización**:
   - `dp[0] = 0`: No hay costo en la primera roca, ya que empezamos desde ahí.
   - `dp[1] = abs(v[1] - v[j])`: El costo mínimo para llegar a la j-esima roca es el valor absoluto de la diferencia de alturas entre la primera y la j-esima roca.
   
4. **Estado Final**: 
   - La respuesta se encuentra en `dp[0]`, el costo mínimo que se necesita para ir de la roca 0 hasta la última roca (`n-1`).

## Análisis de Complejidad
- **Tiempo**: `O(N*K)`, ya que se calculan los valores para cada roca k veces, hay que considerar todos los saltos.
- **Espacio**: `O(N)`, ya que estamos usando un vector `dp` de tamaño `N` para almacenar los resultados intermedios.
