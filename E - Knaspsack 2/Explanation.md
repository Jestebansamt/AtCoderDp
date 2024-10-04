# E - Knapsack 2
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_e](https://atcoder.jp/contests/dp/tasks/dp_e)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][j]` como el **máximo valor** hasta el `i-esimo` ítem, tomando los más livianos.
   - En el estado `dp[i][j]`, se almacena el peso mínimo `i` con las transiciones permitidas, para encontrar el máximo valor `j`.
   
2. **Transición**: 
   - Para calcular `dp[i][j]`, necesitamos conocer el mínimo peso (`i`) con el que podemos llegar al mayor valor (`j`). Por lo tanto, teniendo en cuenta los constraints del problema, definimos las transiciones usando un bucle que itera sobre todos los valores posibles a los que podemos llegar:
     - `dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i].second] + v[i].first);`
   - Este proceso se repetirá para cada ítem en la maleta. El orden es importante, por lo que se deben organizar según el peso de cada ítem.

3. **Inicialización**:
   - `dp[0][0] = 0`: La maleta está vacía.
   - `dp[i][j] = dp[i-1][j]`: Antes de la transición el valor que tendrá la maleta será el mismo valor que tenía antes de considerar el ítem actual. De esa manera si no es posible agregar más elementos conservamos el mínimo peso posible para el valor (`j`).
   
4. **Estado Final**: 
   - Para el estado final, la respuesta será el mayor valor que se almaceno en la `dp` que respete la capacidad de la maleta.

## Análisis de Complejidad
- **Tiempo**: `O(N*n)`. Ya que se calculan todos los valores posibles a los que puede llegar cada ítem.
- **Espacio**: `O(N*n)`. Ya que se usa un vector `dp` de tamaño `N*n`. Para almacenar los valores a los que puede llegar cada ítem.


