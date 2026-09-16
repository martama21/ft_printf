_Este proyecto ha sido creado como parte del currículo de 42 por mmarina-._

## Descripción

En este proyecto se trata de replicar el funcionamiento de la función original de _stdio_ **printf**, que se encarga de imprimir un mensaje por pantalla utilizando una cadena de formato que se le pasa como argumento.
En este caso, solo se implmentan las siguientes conversiones:
- **%c**
	
	Imprime un sólo caracter.
	<font color="red">No sé si en caso de no pasarle ningún argumento debería de controlar el posible error. ¿¿¿Este posible error podría ser un segmentation fault por caso de acceder a partes de la memoria a las que no puedo acceder??.</font>

- **%s**
	
	Imprime una cadena de caracteres como se define por defecto en C, es decir, teniendo en cuenta que la cadena acaba en el carácter nulo (**\0**). Por tanto, si la cadena pasada como argumento, no acaba en el carácter nulo, la función _ft_printf_ seguirá intentando imprimir caracteres que no se le han pasado, pudiendo dar errores en tiempo de ejecución, que no se van a controlar en esta versión de la función, ya que da por echo que la cadena acabará con el carácter nulo.

	<font color="red">DUDITA: Esta conversión hace uso de otra función que es _ft_strdup_ que a su vez hace uso de las funciones _malloc_ y _free_. ¿¿PARA ESTE CASO TENGO QUE CONTROLAR DE ALGUNA MANERA LOS MALLOCS Y FREES???</font>

- **%p**

	Al utilizar este formato, se le pasa como argumento un puntero **void \***, y la función en este caso imprimirá la dirección a la que apunta ese puntero en formato hexadecimal. En caso de que el puntero sea a _NULL_ se imprimirá _(nil)_.

- **%d**

	Imprime un número **decimal** (en base 10).

- **%i**

	Imprime un **entero** en base 10.

- **%u**

	Imprime un número decimal (base 10) sin signo. La función original, en caso de que sea un número negativo lo que se le pasa como argumento devuelve el número resultante de la operación 2³32 + [número negativo pasado por argumento] y es lo que imprime. Para hacer lo mismo en esta versión se ha realizado una versión de la función ft_itoa, en este caso ft_uitoa, que se utiliza cuando el numero que se le pasa es negativo, y trabaja con tipos _long int_ en lugar de _int_.

- **%x**

	Imprime un número hexadecimal en minúsculas.

- **%X**

	Imprime un número hexadecimal en mayúsculas.

- **%%**

	Imprime el símbolo de porcentaje.

	


La función original _printf_ da un error de compilación cuando no coincide el número de conversiones con el número de parámetros que se le pasan como argumentos. Esta réplica de la función no gestiona errores en tiempo de compilación, por lo que ejecutará el programa aunque no coincidan las conversiones con el número de argumentos pasados, para ese caso el comportamiento de esta función será indefinido, por lo que se podrán producir errores en tiempo de ejecución.

## Instrucciones
- :::
	:::
- Creación de archivo ejecutable
	Después de haber hecho el make y haber creado la librería estática _libftprintf.a_ y la _libft.a_ (dentro del directorio _libft/_), podemos crear el ejecutable mediante el siguiente comando: **cc -Wall -Wextra -Werror -g libftprintf.a libft/libft.a**. De esta manera se nos generará un ejecutable, llamado por defecto _a.out_, para ejecutarlo simplemente usaríamos el comando **./a.out**.

## Recursos

Para la creación de este proyecto, se ha utilizado en gran medida la información proporcionada por el comando man. También ha sido de gran utilidad la consulta de la web stack overflow donde se encuentran preguntas similares a las que han ido surguiendo a la hora de crear esta versión de _printf_.
