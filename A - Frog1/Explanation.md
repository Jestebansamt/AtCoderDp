# A - Frog 1
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_a](https://atcoder.jp/contests/dp/tasks/dp_a)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i]` como el **costo mínimo** de llegar desde la roca `0` (primera) hasta la roca `i`.
   - En el estado `dp[i]`, queremos almacenar el costo total mínimo de alcanzar la roca `i` con las transiciones permitidas.
  
2. **Transición**: 
   - Para calcular `dp[i]`, la rana puede llegar desde `dp[i+1]` o `dp[i+2]`:
     - `dp[i] = min(dp[i+1] + abs(v[i]-v[i+1]), dp[i+1] + abs(v[i]-v[i+2]);`
   - El primer término representa el costo de saltar a la siguiente roca (`i+1`), mientras que el segundo término considera saltar desde la roca actual a dos rocas más (`i+2`).

3. **Inicialización**:
   - `dp[0] = 0`: No hay costo en la primera roca, ya que empezamos desde ahí.
   - `dp[i] = abs(v[i] - v[i+1])`: El costo mínimo para llegar a la siguiente roca es el valor absoluto de la diferencia de alturas entre la primera y la segunda roca.
   
4. **Estado Final**: 
   - La respuesta se encuentra en `dp[0]`, el costo mínimo que se necesita para ir de la roca 0 hasta la última roca (`n-1`).

## Análisis de Complejidad
- **Tiempo**: `O(N)`, ya que se calculan los valores para cada roca una sola vez.
- **Espacio**: `O(N)`, ya que estamos usando un vector `dp` de tamaño `N` para almacenar los resultados intermedios.
