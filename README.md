
## TP2: Uso de Interfaces

<details>
<summary><b>Información acerca de proyecto</b></summary>
  
* **Autores:**
    * Pojmaevich Mirko (mirkopoj@gmail.com) 
    * Torletti Lara (lara.a.torletti@gmail.com)

* **Materia:**
    Arquitectura de Software - B5647

* **Profesor:**
    Martín Morixe
  
* Universidad Nacional de Río Negro - Sede Andina - Ingeniería Electrónica
</details>

<details>

<summary><b>Objetivo de proyecto</b></summary>

* Diseñar e implementar un programa con el patrón de diseño estructural Decorator:
  * Un restaurante de comidas rápidas ofrece 3 combos (Básio, Familiar y Especial). Cada uno tiene características diferentes (cantidad, porciones y salsas). Pero se puede aumentar el pedido mediante adicionales (Tomate, Papas Fritas, Carne, Queso).
  * Crear un sistema de pedido que permita seleccionar el ombo y adicionales. El sistema deberá informar el pedido del usuario y valor total.
    
![ConsignaUML](/consigna/UML_Consigna.png)

 </details>
 
<details>
  
<summary><b>Instrucciones de uso</b></summary>

* Haga:
 ```{bash}
git clone https://github.com/Arquitectura-de-Software-UNRN-2024/TP4-Patron-Disenno-Decorator.git
make
```
* Los ejecutables luego de hacer make, se encontrarán en bin/.
* para correr el Sistema de Gestión de Pedidos main:
 ```{bash}
#Para correr el sistema de gestión de pedidos
bin/main
# en donde las opciones son:
# Se mostrará un menú inicial con las opciones de los 3 combos y una opción [SALIR] del menú.
# Para seleccionar alguna opción deberá presionar la tecla [ENTER].
# Si presiona algún combo, se mostrará el submenú para agregar adicionales.
# Usted podrá agregar todos los adicionales que quiera con tan solo presionar [ENTER] en el adicional.
# Para terminar el pedido y ver la descripción y valor total deberá presionar la opción [No deseo agregar más adicionales].
```

</details>

<details>
  
<summary><b>Pruebas de programa funcionando</b></summary>

### Menú Bienvenido al sistema de pedidos
  <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/menu_bienvenido.png alt="Menú de Bienvenida y selección de combo" width="500px">
  </p>
  </div>

### SubMenú Adicionales
  <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/menu_adicionales.png alt="Menú de selección de adicionales" width="500px">
  </p>
  </div>

### Fin de programa
  <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/salida_del_programa.png alt="Salida del programa" width="500px">
  </p>
  </div>

</details>

> [!WARNING]
> Correr los test depende de Criterion. [Ver más sobre criterion](https://criterion.readthedocs.io/en/master/intro.html)

