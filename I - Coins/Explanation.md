# I - Coins 
**Fuente**: [https://atcoder.jp/contests/dp/tasks/dp_i](https://atcoder.jp/contests/dp/tasks/dp_i)

## Enfoque y Solución
1. **Definición del Estado**: 
   - Definimos `dp[i][j]` como la **la probabilidad** de obtener exactamente `j` monedas `Tail` con las primeras `i` monedas.  
   
2. **Transición**: 
    - Para calcular `dp[i][j]`, tenemos dos opciones:
       - Contar la `i-ésima` moneda como `Head` y calcular `dp[i + 1][j]` (la probabilidad de obtener `j Tails` entre las primeras `i+1` monedas), con probabilidad `v[i][0]`. 
       - Contar la `i-ésima` moneda como `Tail` y calcular `dp[i + 1][j + 1]` (la probabilidad de obtener `j+1 Tails` entre las primeras `i+1` monedas), con probabilidad `v[i][1]`.
    - Luego sumamos las dos probabilidades para tener:
       -`dp[i][j] = (f(i+1,j) * v[i][0]) + ((f(i+1,j+1) * v[i][1])) ;`
    - En `v[i][0]` almacenamos la probabilidad de monedas `Head` mientras que en `v[i][1]` almacenamos la probabilidad de las monedas `Tail`.

3. **Inicialización**:
   - Cuando hemos procesado todas las monedas la probabilidad de tener más de la mitad de las monedas como `Head` es 1.
   - `(Tail > n/2) dp[i][j] = 0`. Sí la cantidad de `Tail` es mayor que la mitad de  la longitud del arreglo la probabilidad de tener una combinacion valida es `0`.

4. **Estado Final**: 
   - El valor que retorne la funcion `f(0,0)` que nos asegura que la probabilidad de tener mas `Head` que `Tail`.
## Análisis de Complejidad
- **Tiempo**: `O(n*n)`, Ya que se calcula para cada moneda revisando si se toma o no se toma la moneda actual
- **Espacio**: `O(n*n)`, Ya que se usa un vector `dp` de tamaño `N*N`. Que almacena la combinacion de monedas que se tomaron o no se tomaron para cada moneda.


