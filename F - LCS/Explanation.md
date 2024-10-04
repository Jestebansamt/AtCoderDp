# F - LCS
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_f](https://atcoder.jp/contests/dp/tasks/dp_f)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][j]` como la **maxima longitud** del string que se puede formar con los dos arreglos.
   - En el estado `dp[i][j]`, `i` representa los caracteres del primer string y `j` los del segundo.
   
2. **Transición**: 
   - Para calcular `dp[i][j]`, necesitamos concer la maxima longitud a la que podemos llegar considerando los primeros `i` y `j` caracteres. Se presentan dos casos:
     - Los caracteres `i` y `j` son iguales entonces la longitud del string final aumenta en 1  
         - `dp[i][j] = dp[i-1][j-1]+1;` 
     - Los caracteres son diferentes, entonces el valor del string final no cambia. Sin embargo necesitamos almacenar la mayor longitud obtenida hasta el momento:
         - `dp[i][j] = max(dp[i-1][j], dp[i][j-1]);`

3. **Inicialización**:
   - `dp[0][0] = 0`: No se puede generar un string sin letras.
   - `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`: Antes de la transición la maxima longitud a la que podemos llegar, será la maxima almacenada.
        - Será `dp[i][j-1]` en el caso de que haya una nueva letra `j` que sea igual a `i`.
        - Será `dp[i][j-1]` ya que es la mayor longitud almacenada hasta ese momento.
   
4. **Estado Final**: 
   - Para el estado final, se tendra que reconstruir el string recorriendolo desde `dp[n][m]` hasta `dp[0][0]` agregando el caracter `i` del primer string cuando `i == j`. De otra manera se recorrera la matriz siguiendo las longitudes mas grandes

## Análisis de Complejidad
- **Tiempo**: `O(n*m)`, Ya que se calculan la maxima longitud para cada `i` caracter `j` veces.
- **Espacio**: `O(n*m)`, Ya que se usa un vector `dp` de tamaño `n*m`. Que almacena las longitudes optimas hasta cada letra.
