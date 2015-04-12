#Arduino Room Control 

Arduino trabajando como servidor para el control del cuarto 

-Modo de funcionamiento- 

Es necesario abrir los puertos de tu modem . 
En mi caso tengo telmex en concreto el modelo Echolife HG520c 

por lo tando adjunto los pasos para abrir los puertos 

1.- Entrar en la parte de Firewall 
2.- Seleccionar permitir aplicaciones individuales 
3.- Agregar en ip Interna/local la ip que se le asigno al modulo de Ethernet debe ser una ip interna dentro del rango de ip que proporciona tu modem 
Ejem.. 192.168.1.X 
4.- Agregar en los puertos de inicio y fin local el puerto que asignaste en el Sketch por ejemplo yo asigne el puerto 8081 

Eso seria todo para la parte del router 
Estos modelos cuentan con una caracteristica muy curiosa y es que para que funcione debidamente necesitas activa el  ip nat loopback , se realiza de la siguiente manera : 

1.- Arbir tu consola 
2.- escribir por Telnet 192.168.1.254 (dependiendo de la direccion de tu modem , lo que es lo mismo la puerta de enlace )
3.-Introducir tu contraseña que usas para entrar a tu modem por lo general es la webkey 
4.-escribir "ip nat loopback on" (sin las comillas ) 

Listo ya se puede entrar a tu servidor Arduino desde cualquier parte , por ejemplo seria algo como 192.168.1.X:8081 

-Actualizaciones- 

