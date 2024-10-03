# A - Frog 1
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_d](https://atcoder.jp/contests/dp/tasks/dp_d)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][j]` como el **valor maximo** de los items que Taro puede llevar a casa desde el día considerando la capacidad de la mochila.
   - En el estado `dp[i][j]`, queremos almacenar el costo total maximo `i` con las transiciones permitidas, almacenando el peso actual (`i`) que tiene la maleta.
  
2. **Transición**: 
   - Para calcular `dp[i][j]`, se tomará el maximo valor segun todas las posibles combinaciones de pesos que se puedan hacer con el peso restante, por lo tanto definimos las transiciones como un bucle que itera del peso actual del objeto hasta la diferencia con la capacidad total de la maleta:
     - `for j = curWeight to w: dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i].second] + v[i].first );`
   - Se hara este proceso para cada item de la maleta, el orden es importante por lo que se tendrán que organizar segun el valor de cada item, de esta manera se pueden priorizar los items mas valiosos.

3. **Inicialización**:
   - `dp[0][0] = 0`: La maleta sin peso ni items tendra un valor de 0
   - `dp[i][j] = dp[i-1][j]`: Antes de la transición el valor que tendra la maleta con el peso j será igual al valor que tenia sin considerar el item actual. De esa manera si no es posible agregar mas elemetnos conservamos el maximo valor posible para esa configuracion de peso/valor.
   
4. **Estado Final**: 
   - La respuesta se encuentra en `dp[n-1][w]`, el valor maximo considerando la capacidad de la maleta.

## Análisis de Complejidad
- **Tiempo**: `O(N*W)`, Ya que se calculan los valores para cada item considerando el peso restante que queda en la maleta.
- **Espacio**: `O(N*W)`, Ya que estamos usando un vector `dp` de tamaño `N*W`. De esta forma almacenamos para cada item todos los pesos a los que puede llegar para encontrar el maximo valor.
