# D - Knapsack 1
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_d](https://atcoder.jp/contests/dp/tasks/dp_d)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][j]` como el **valor máximo** de los ítems que Taro puede llevar considerando la capacidad de la mochila.
   - En el estado `dp[i][j]`, se almacena el costo máximo `i` con las transiciones permitidas, almacenando el peso actual (`j`) que tiene la maleta.
  
2. **Transición**: 
   - Para calcular `dp[i][j]`, se toma el máximo valor del resultado al considerar el peso restante al agregar el i-ésimo ítem. Por lo tanto, definimos las transiciones usando un bucle que itera desde el peso actual del objeto hasta la capacidad total de la maleta:
     - `for j = curWeight to w: dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i].second] + v[i].first );`
   - Este proceso se repetirá para cada ítem en la maleta. El orden es importante, por lo que se deben organizar según el valor de cada ítem, de manera que se prioricen los más valiosos.

3. **Inicialización**:
   - `dp[0][0] = 0`: La maleta tendrá un valor de 0 si no tiene ningún ítem.
   - `dp[i][j] = dp[i-1][j]`: Antes de la transición el valor que tendrá la maleta será el valor mismo que tenía antes de considerar el ítem actual. De esa manera si no es posible agregar más elementos conservamos el máximo valor posible para esa configuración de peso/valor.
   
4. **Estado Final**: 
   - La respuesta se encuentra en `dp[n-1][w]`, el valor máximo considerando la capacidad de la maleta.

## Análisis de Complejidad
- **Tiempo**: `O(N*W)`, Ya que se calculan los valores para cada ítem considerando el peso restante que queda en la maleta.
- **Espacio**: `O(N*W)`, Ya que se usa un vector `dp` de tamaño `N*W`. De esta forma almacenamos para cada ítem todos los pesos a los que puede llegar para encontrar el máximo valor.
