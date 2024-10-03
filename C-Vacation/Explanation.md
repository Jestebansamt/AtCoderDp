# C - Vacation
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_c](https://atcoder.jp/contests/dp/tasks/dp_c)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][last]` como el **costo máximo** de puntos desde el día `0` (primero) hasta el `i` día, considerando la última actividad realizada.
   - En el estado `dp[i][last]`, queremos almacenar el costo total máximo `i` con las transiciones permitidas, sin repetir dos actividades consecutivas.
  
2. **Transición**: 
   - Para calcular `dp[i][last]`, Taro puede tomar las dos actividades restantes `(last+1)%3` o `(last+2)%3`, por lo tanto definimos las transiciones como:
     - `dp[i][last] = max(f(i+1,(last+1)%3), f(i+1,(last+2)%3))+v[i][last]`
   - El primer y el segundo término representan el costo de ir a las dos actividades restantes.

3. **Inicialización**:
   - `dp[0] = max(dp[0,0],dp[0,1]),dp[0,2])`: Para conocer el máximo puntaje se tienen que las tres actividades.
   - `dp[i][last] += v[i][last]`: El máximo costo de cada transición será la sumatoria de las llamadas recursivas.
   
4. **Estado Final**: 
   - La respuesta se encuentra en `max(dp[0,0],dp[0,1]),dp[0,2])`. El costo máximo entre escoger una de las tres tareas.

## Análisis de Complejidad
- **Tiempo**: `O(N*3)`, ya que se calculan los valores para cada tarea 1 vez.
- **Espacio**: `O(N*3)`, ya que estamos usando un vector `dp` de tamaño `N*3` para almacenar los resultados intermedios.
