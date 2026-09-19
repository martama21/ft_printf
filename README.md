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

## Funcionamiento interno

Como ya se ha dicho, la función _printf_ al igual que esta versión _ft_printf_ reciben como argumento una cadena de formato. Esta cadena de formato puede incluir especidifcadores de formato, que en el caso de esta versión de la función son: **cspdiuxX%** como ya se ha visto en el punto anterior. 

**Por cada especificador de formato que aparezca en la cadena, la función espera recibir un argumento del tipo de ese especificador**. El caso del especificador _%_ es el único que no espera recibir un argumento adicional.

Por tanto, esta función **puede recibir un número variable de argumentos**, lo que se conoce como función **variádica**.

Para acceder a esos argumentos se hace uso de la librería de C _stdarg.h_ y las macros: _va_start_, _va_arg_, _va_copy_ y _va_end_, que son las que permiten recorrer esos argumentos adicionales.

<u>**Idea clave de _ft_printf_: Recorrer la cadena de formato, detectar cuando aparece _%_ y decidir que tipo de argumento se tiene que extraer con _va_arg_.**</u>

Refrescando un poco el punto anterior y a modo de entender mejor este, esto sería lo que esperaría recibir como argumento la función según el especificador de formato que se encuentre en la cadena de formato:

- Especificador **%c**: espera recibir un argumento de tipo _int_ cuyo valor representa un carácter (_char_).

- Especificador **%s**: espera recibir un argumento de tipo _char *_, es decir, una cadena terminada con el carácter de terminación (_\0_).

- Especificador **%p**: espera recibir un argumento de tipo _void *_ (puntero genérico) y muestra su dirección de memoria en formato hexadecimal.

- Especificadores **%d** y **%i**: esperan recibir un argumento de tipo _int_.

- Especificador **%u**: espera recibir un argumento de tipo _unsigned int_ y lo imprime como un número decimal sin signo.

- Especificador **%x**: espera recibir un argumento de tipo _unsigned int_ y lo imprime en base hexadecimal utilizando letras minúsculas.

- Especificador **%X**: espera recibir un argumento de tipo _unsigned int_ y lo imprime en base hexadecimal utilizando letras mayúsculas.

- Especificador **%%**: no espera recibir ningún argumento adicional, simplemente imprime un carácter _%_.

---

#### Ahora bien, **¿qué ocurre o qué debería ocurrir si lo que recibimos no es lo que espera recibir ese especificador de formato? O, ¿qué ocurre si directamente se espera extraer un argumento adicional, pero no se le ha pasado nada?**

Tanto si los argumentos no coinciden con los especificadores de formato, como si faltan argumentos, el comportamiento es **indefinido**, pudiéndose producir así errores en algunos casos.

Un caso en el que no ocurrirán errores, será cuando el número de argumentos adicionales sea mayor que el número de argumentos adicionales que se espera recibir, en ese caso esos argumentos de más se ignorarán y no ocurrirá nada.

Todo esto significa, que el programador de esta versión _ft_printf_ **no tiene que protegerse** contra estos casos, y que por tanto, es **responsabilidad de quien llama a la función usar correctamente el formato**.

---

#### va_start, va_arg, va_copy y va_end

Ya se ha mencionado brevemente que para acceder a los argumentos adicionales que se le pasan a la función se han utilizado las macros _va_start_, _va_arg_, _va_copy_ y _va_end_. En esta secciñon se explicará un poco más en detalle para qué sirve cada una y para ello se explicará también el tipo _va_list_, necesario para el funcionamiento de la función. 

**(Paréntesis: ¿Qué es una macro?)**

- **_va_list_** no es ni una función ni una macro, es el tipo que representa la lista de argumentos variables.

- **_va_start_** se utiliza para inicializar la lista de argumentos variables. Prepara la variable de tipo _va_list_ para empezar a leer los argumentos que vienen detrás de _format_.

- **_va_arg_** extrae el siguiente argumento de la lista y lo trata como el tipo que se le especifique. Se le pasará un tipo u otro en función del especificador de formato que nos encontremos.

- **_va_copy_** crea una copia independiente de una lista de argumentos, así si se quiere crear una copia de _va_list_, se podrá crear con esta macro, y podremos tratar a esa nueva lista de manera independiente a la original. En este código no se ha hecho uso de esta macro.

- **_va_end_** libera y termina el uso de la lista. Siempre que se haga uso de _va_start_ hay que hacer uso de _va_end_.

Para el funcionamiento de _ft_printf_ se recorre el argumento _format_ y se va imprimiendo su contenido hasta encontrar un espeficador de formato, en ese momento se crea una variable de tipo _va_list_ y en función de cual sea el especificador se le pide a _va_arg_ que extraiga de la lista de argumentos adicionales ese tipo, una vez extraido, se imprime y se sigue recorriendo la lista repitiendo este proceso, hasta que se llega al carácter de terminación del argumento _format_ y se hace un _va_end_ en caso de que se hubiera hecho un _va_start_ y el programa acaba.


## Instrucciones
- :::
	:::
- Creación de archivo ejecutable
	Después de haber hecho el make y haber creado la librería estática _libftprintf.a_ y la _libft.a_ (dentro del directorio _libft/_), podemos crear el ejecutable mediante el siguiente comando: **cc -Wall -Wextra -Werror -g libftprintf.a libft/libft.a**. De esta manera se nos generará un ejecutable, llamado por defecto _a.out_, para ejecutarlo simplemente usaríamos el comando **./a.out**.

## Recursos

Para la creación de este proyecto, se ha utilizado en gran medida la información proporcionada por el comando man. También ha sido de gran utilidad la consulta de la web stack overflow donde se encuentran preguntas similares a las que han ido surguiendo a la hora de crear esta versión de _printf_.
