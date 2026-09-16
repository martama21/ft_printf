_Este proyecto ha sido creado como parte del currículo de 42 por mmarina-_

## Descripción
El objetivo de este proyecto es crear una librería en C formada por diferentes funciones de propósito general para su uso en diferentes programas futuros.
Las funciones incluidas van desde nuestra propia versión de funciones de _libc_, hasta funciones para el manero de listas, pasando por funciones que o bien no son de la librería _libc_ o bien lo son pero con alguna modificación.

## Instrucciones
- Compilación de los ficheros *.c del proyecto:

    El proyecto cuenta con un archivo _Makefile_ destinado a la compilación de todos los ficheros fuente del propio proyecto.
    Para la compilación utilizamos el comando **make** que internamente utiliza el compilador _cc_ seguido de los flags _-Wall -Wextra -Werror_ y crea los ficheros objeto **.o** correspondientes a cada fichero fuente **.c**. Al usar este comando sólo se realizará la compilación de los archivos fuente de los cuales no se tuviera un fichero objeto o de aquellos cuyo fichero objeto fuera posterior al propio fichero fuente, es decir, que hubieran sido modificados.
    Una vez se tienen todos los ficheros objeto empaquetamos estos mediante el programa _ar_ que crea la biblioteca estática _libft.a_.

- Borrado de los ficheros *.o del proyecto:

    El archivo _Makefile_ cuenta con las reglas _clean_ y _fclean_ que se encargan de eliminar todos los archivos objetos que encuentran en el directorio. Para utilizarlos usaremos el comando **make** seguido de **clean** o **fclean**.

- Borrado de la biblioteca estática _libft.s_:

    La regla **fclean** además de borrar todos los ficheros objetos como acabamos de ver, también elimina la biblioteca estática _libft.a_.

Este proyecto solo cuenta con _funciones_, es decir, no hay ningún _programa_ en él que podamos ejecutar, pero en caso de que se añadiera algún programa en un futuro, detallamos los pasos a seguir para su ejecución:

- Creación del archivo ejecutable//Ejecución del programa:

    Una vez tenemos la biblioteca _libft.a_ con todos los ficheros objeto del proyecto, podemos ejecutar el programa utilizando el comando **cc -Wall -Wextra -Werror -g libft.a** esto creará el ejecutable _a.out_. 
    _a.out_ es el nombre por defecto que el compilador usa para darle nombre al ejecutable, ya que con el comando que hemos usado no le estamos indicando ningún nombre de salida. Si quisiéramos un nombre concreto de ejecutable, tendríamos que añadir al final del comando la opción **-o** seguida de un espacio y el nombre que quisiéramos darle a nuestro ejecutable.

- Ejecutar el programa:
    
    A partir de nuestro ejecutable podemos ejecutar un programa mediante el comando **./** seguido del nombre del ejecutable.

## Funciones
El archivo libft.h está compuesto por el prototipo de las funciones más relevantes incluidas en este proyecto. A continuación pasamos a describir brevemente las funciones obligatorias del proyecto libft.

|Funciones|
|------------|
| **int	ft_isalpha(int c);** <br> Retorna 1 en caso de que el caracter que se le pasa sea una letra y 0 en caso contrario |
|**int	ft_isdigit(int c);** <br> Retorna 1 en caso de que el caracter que se le pasa sea un dígito y 0 en caso contrario|
|**int ft_isalnum(int c);** <br> Retorna 1 en caso de que el cararter que se le pasa sea una letra o un dígito y 0 en caso contrario|
|**int	ft_isascii(int c)** <br> Retorna 1 en caso de que el caracter que se le pasa forme parte de los caracteres de ASCII y 0 en caso contrario. <font color="red">No sé si habría que comprobar que el caracter fuera un "unsigned char" de 7 bits</font>|
|**int	ft_isprint(int c);** <br> Retorna 1 en caso de que el caracter que se le pasa sea un caracter imprimible (incluido el SPACE) y 0 en caso contrario|
|**size_t	ft_strlen(const char \*s);** <br> Devuelve la longitud de una string, sin contar el caracter '\0' final|
|**void	\*ft_memset(void \*s, int c, size_t n);** <br> Al pasarle un bufer con 'n' bytes reservados los rellena con el caracter que se le pase. <font color="red">No sé si hay que controlar que el tamaño del bufer que se le pasa tiene que ser de n bytes</font>|
|**void ft_bzero(void \*s, size_t n);** <br> Rellena 'n' bytes de memoria con '\0' comenzando por la localización a la que apunta el puntero que se le pasa. <font color="red">No sé si hay que controlar que el tamaño del bufer que se le pasa tiene que ser de n bytes</font>|
|**void	\*ft_memcpy(void \*dest, const void \*src, size_t n);** <br> Copia 'n' bytes de _src_ en _dest_. Si hay overlap el resultado puede no ser el esperado|
|**void	\*ft_memmove(void \*dest, const void \*src, size_t n);** <br> Copia 'n' bytes de _src_ en _dest_ usando como si hubiéramos usado un buffer temporal para hacer la copia de uno a otro. Soporta overlap|
|**size_t	ft_strlcpy(char \*dest, const char \*src, size_t size);**  <br> Copia size bytes de la cadena _src_ en _dest_ incluyendo el caracter de terminación y lo hace sin comprobar que _dest_ tenga espacio suficiente para almacenar los _size_ bytes, por lo que puede causar overflow.|
|**size_t ft_strlcat (char \*dest, const char \*src, size_t size);** <br> Añade al final de la cadena _dest_ _ft\_strlen(dest)- size_ bytes. En caso de que _size_ sea menor o igual que la longitud de _dest_ no añade ningún caracter a _dest_ y devuelve _size + ft\_strlen(src)_. En caso de que _size_ sea mayor que la longitud de la cadena _dest_ añade _ft\_strlen(dest)- size_ bytes al final de _dest_ entre ellos el carater de terminación, y devuelve el tamaño de _dest_ original más el tamaño de _src_. Habrá overflow si _size_ es mayor que la memoria reservada para _dest_.|
|**int	ft_toupper(int c);** <br> Si el caracter que se le pasa es una letra minúscula, devuelve su mayúscula, en otro caso, devuelve el caracter introducido.|
|**int	ft_tolower(int c);** <br> Si el caracter que se le pasa es una letra mayúscula, devuelve si minúscula, en otro caso, devuelve el caracter introducido.|
|**char	\*ft_strchr(const char \*s, int c);** <br> Busca en la cadena el caracter que se le pasa y devuelve el puntero a la primera vez que aparece ese caracter dentro de la cadena, o NULL si no aparece en toda la cadena. El catacter terminación '\0' es considerado parte del string y por tanto, contempla el caso en que el caracter a buscar sea este, devolviendo en ese caso un puntero no nulo.|
|**char \*ft_strrchr(const char \*s, int c);** <br> Busca en la cadena el caracter que se le pasa desde el final, y en este caso devuelve un puntero a la última aparición de ese caracter dentro de la cadena, y en caso de que no aparezca devuelve un puntero a NULL. El caracter de terminación también forma parte del string y contempla el caso de buscarle.|
|**int ft_strncmp(const char \*s1, const char \*s2, size_t n);** <br> Compara como máximo _n_ caracteres de las dos cadenas. Devuelve **0** en caso de que sean iguales, **un número negativo** en caso de que _s1_ sea menor que _s2_ y **un número positivo** en caso de que _s1_ sea mayor que _s2_.|
|**void \*ft_memchr(const void \*s, int c, size_t n);** <br> Busca en los primeros _n_ bytes de _s_ si aparece el carcter que se le pasa. En caso de que aparezca devuelve un puntero a esa primera aparición y NULL en caso de que no aparezca en los _n_ primeros bytes. A diferencia de funciones como **ft_strchr** que comparaba los chars de la string que se le pasaba y paraba cuando la string acababa, aquí **no se comprueba la string** se comprueban n posiciones de memoria, empezando desde la dirección a la que apunta _s_, es decir, que si _n_ fuese mayor que _ft\_strlen(s)_, nuestra función pasaría el caracter de terminación y seguiría comparando, si no ha encontrado el caracter a buscar, hasta haber comparado _n_ bytes. Podrá ocurrir por tanto, que accedamos a posiciones de memoria no reservadas y que se produzca un _segmentation falut_.|
|**int ft_memcmp(const void \*s1, const void \*s2, size_t n);** <br> Compara como máximo _n_ bytes desde la dirección a la que apunta _s1_ y la dirección a la que apunta _s2_. Devuelve **0** en caso de que los _n_ bytes sean iguales; **un número negativo** en caso de encontrarse un byte menor en _s1_ y **un número positivo** en caso de encontrarse un byte mayor en _s1_. Puede provocar un _segmentation fault_ en caso de que accedamos a partes de la memoria que no teníamos reservada.|
|**char \*ft_strnstr(const char \*big, const char \*little, size_t len);** <br> Devuelve la primera aparición de la subcadena _little_ en la cadena _big_, si esta aparece en los _len_ primeros bytes. Si la cadena _little_ está vacía, devuelve el puntero a _big_. Si la cadena _little_ no aparece dentro de los _len_ primeros bytes de _big_ devuelve NULL.|
|**int ft_atoi(const char \*nptr);** <br> Convierte un string en un entero|
|**void \*ft_calloc(size_t nmemb, size_t size);** <br> Reserva memoria dinámica mediante _malloc_ e inicializa la memoria reservada a cero. En caso de fallo en la reserva de memoria devuelve NULL, en caso contrario devuelve el prunterio a la memoria reservada. <font color="red">No sé si tengo que tener el cuenta SIZE_MAX.</font>|
|**char \*ft_strdup(const char \*s);** <br> Duplica el string que le pasamos y nos devuelve el string resultante. Para ello reserva memoria dinámica con malloc.|
|**char \*ft_substr(char const \*s, unsigned int start, size_t len);** <br> Reserva memoria con _malloc_ y devuelve una subcadena de caracteres de la cadena _s_. La subcadena comienta en el índice _start_ y tiene una longitud máxima de _len_.|
|**char \*ft_strjoin(char const \*s1, char const \*s2);** <br> Reserva memoria con malloc y devuelve una nueva cadena de caracteres, formada por la concatenación de _s1_ y _s2_.|
|**char \*ft_strtrim(char const \*s1, char const \*set);** <br> Reserva memoria con _malloc_ y devuelve una copia de _s1_ con los caracteres de _set_ eliminados al principio y al final.|
|**char \*\*ft_split(char const \*s, char c);** <br>Reserva memoria utilizando _malloc_ y devuelve un array de cadenas obtenido al dividir la cadena 's' en subcadenas utilizando el carácter 'c' como delimitador.<br>Cada cadena del arreglo devuelto se reserva de manera independiente.<br>El arreglo de punteros también se reserva dinámicamente.<br>El arreglo devuelto debe terminar con un puntero a NULL.|
|**char \*ft_itoa(int n);** <br> Reserva memoria con _malloc_y devuelve una cadena que represente el valor del número entero recibido como argumento. Debe ser capaz de manejar números negativos.<br> AÚN NO ESTÁ LISTO|
|**char \*ft_strmapi(char const \*s, char (\*f)(unsigned int, char));**<br> Aplica la función _f_ a cada carácter de la cadena _s_, pasando su índice como primer argumento y el propio carácter como segundo argumento. Se crea una nueva cadena utilizando _malloc_ para almacenar los resultados de las sucesivas aplicaciones de _f_.|
|**void ft_striteri(char \*s, void (\*f)(unsigned int, char\*));**<br> Aplica la función _f_ a cada carácter de la string _s_, pasando como parámetros el índice de cada carácter dentro de _s_ y la dirección del propio carácter, que puede modificarse si es necesario.|
|**void ft_putchar_fd(char c, int fd);**<br>Envía el carácter _c_ al descriptor de archivo especificado.|
|**void ft_putstr_fd(char \*s, int fd);**<br>Envía la cadena _s_ al descriptor de archivo especificado.|
|**void ft_putendl_fd(char \*s, int fd);**<br>Envía la cadena _s_ al descriptor de archivo dado, seguido de un salto de línea.|
|**void ft_putnbr_fd(int n, int fd);**<br>Escribe el número _n_ en el descriptor de archivo dado|
|**t_list \*ft_lstnew(void \*content);**<br>Reserva memoria con _malloc_ y devuelve un nuevo nodo. La variable _content_ se inicializa con el contenido del parámetro _content_. Mientras que la variable _next_ se inicializa con _NULL_.|
|**void ft_lstadd_front(t_list \*\*lst, t_list \*new);**<br>Añade el nodo _new_ al principio de la lista _lst_.|
|**int ft_lstsize(t_list \*lst);**<br>Cuenta el número de nodos de una lista.|
|**t_list \*ft_lstlast(t_list \*lst);**<br>Devuelve el último nodo de la lista.|
|**void ft_lstadd_back(t_list \*\*lst, t_list \*new);**<br>Añade el nodo _new_al final de la lista _lst_.|
|**void ft_lstdelone(t_list \*lst, void (\*del)(void\*));**<br>Recibe como parámetro un nodo _lst_ y libera la memoria del contenido utilizando la función _del_ dada como parámetro. También libera el nodo en sí mismo, pero no libera el siguiente nodo.|
|**void ft_lstclear(t_list \*\*lst, void (\*del)(void\*));**<br>Elimina y libera el nodo _lst_ dado y todos los consecutivos del mismo, utilizando la función _del_ y _free_. Al final, el puntero a la lista debe ser NULL.|
|**void ft_lstiter(t_list \*lst, void (\*f)(void \*));**<br>Itera la lista _lst_ y aplica la función _f_ en el contenido de cada nodo.|
|**t_list \*ft_lstmap(t_list \*lst, void \*(\*f)(void \*), void (\*del)(void \*));**<br>Itera la lista _lst_ y aplica la función _f_ al contenido de cada nodo. Crea una lista resultante de aplicar sucesivamente la función _f_ a cada nodo. La función _del_ se utiliza para eliminar el contenido de un nodo si es necesario.|

## Recursos
Para la creación de este proyecto, hemos utilizado en gran medida la información proporcionada por el comando _man_. También ha sido de gran utilidad la consulta de la web _stack overflow_ donde hemos encontrado preguntas y respuestas similares a las que teníamos con algunas funciones del proyecto.