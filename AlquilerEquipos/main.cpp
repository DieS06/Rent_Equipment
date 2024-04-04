#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include "BL/Entities/Equipo/Equipo.h"
#include "BL/Entities/Categoria/Categoria.h"
#include "BL/Entities/Equipo/Equipo.cpp"
#include "BL/Entities/Categoria/Categoria.cpp"
#include <map>

struct contrasena {
    std::string contra;
};

void mostrarMenu(Equipo& equipo, Categoria& categoria);

int inicio(Equipo& equipo, Categoria& categoria) {
    std::map<std::string, contrasena> bdAdmin;
    bdAdmin["admin"] = { "1qazxsw2" };

    std::string nombreUsuario;
    std::cout << "Ingrese su nombre de usuario: ";
    std::cin >> nombreUsuario;

    if (bdAdmin.find(nombreUsuario) != bdAdmin.end()) {
        std::string contra;
        std::cout << "Ingrese su contrasena: ";
        std::cin >> contra;

        if (contra == bdAdmin[nombreUsuario].contra) {
            std::cout << "" << std::endl;
            std::cout << "Inicio de sesion exitoso. Bienvenido, " << nombreUsuario << "!" << std::endl;
            mostrarMenu(equipo, categoria);
        }
        else {
            std::cout << "Contrasena incorrecta. Inicio de sesion fallido." << std::endl;
        }
    }
    else {
        std::cout << "Usuario no encontrado. Inicio de sesion fallido." << std::endl;
    }

    return 0;
}


void mostrarMenu(Equipo& equipo, Categoria& categoria) {

    int opcion = -1;

    while (opcion != 0) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Agregar equipo." << std::endl;
        std::cout << "2. Retirar equipo." << std::endl;
        std::cout << "3. Consultar equipo." << std::endl;
        std::cout << "4. Modificar equipo." << std::endl;
        std::cout << "5. Listado de equipos en forma ascendente por nombre." << std::endl;
        std::cout << "6. Listado de equipos en forma descendente por nombre." << std::endl;
        std::cout << "7. Listado de equipos por descripcion con una hilera especifica. No funciona" << std::endl;
        std::cout << "8. Listado de equipos en forma ascendente por codigo." << std::endl;
        std::cout << "9. Listado de equipos en forma descendente por codigo." << std::endl;
        std::cout << "10. Listado de equipos por rango de anios." << std::endl;
        std::cout << "11. Listado de equipos por rango de acidez." << std::endl;//FALTA ERROR RARO
        std::cout << "12. Agregar categoria.." << std::endl;
        std::cout << "13. Eliminar categoria." << std::endl;
        std::cout << "14. Consultar categoria." << std::endl;
        std::cout << "15. Modificar categoria." << std::endl;
        std::cout << "16. Listado de catalogo por categorias." << std::endl;
        std::cout << "17. Agregar equipo a categoria. No funciona" << std::endl;
        std::cout << "18. Retirar equipo de categoria. No funciona" << std::endl;
        std::cout << "0. Salir \n" << std::endl;
        std::cout << "Ingrese la opcion que desea seleccionar: \n";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
        {
            std::string codigo, nombre, descripcion;
            int anio;
            float nivelPh;

            bool equipoRepetido = false;

            std::cout << "Ingrese el codigo del equipo: \n";
            std::cin >> codigo;
            std::cout << "Ingrese el nombre del equipo: \n";
            std::cin.ignore(); // Limpiar el buffer del teclado antes de leer el nombre
            std::getline(std::cin, nombre);
            std::cout << "Ingrese el anio del equipo: \n";
            std::cin >> anio;
            std::cout << "Ingrese el nivel de pH del equipo: \n";
            std::cin >> nivelPh;
            std::cout << "Ingrese la descripcion del equipo: \n";
            std::cin.ignore(); // Limpiar el buffer del teclado antes de leer la descripción
            std::getline(std::cin, descripcion);
            std::cout << " " << std::endl;
            equipo.agregarEquipo(codigo, nombre, anio, nivelPh, descripcion);

        }
        break;
        case 2:
        {
            // Declaración de variables
            std::string codigo;

            // Aquí pedimos el código del equipo a retirar
            std::cout << "Ingrese el codigo del equipo que desea retirar: \n";
            std::cin >> codigo;

            // Llamamos a la función retirarEquipo con el código ingresado
            equipo.retirarEquipo(codigo);
        }
        break;
        case 3:
        {
            // Declaración de variables
            std::string codigo;

            std::cout << "Ingrese el codigo del equipo que desea consultar: \n";
            std::cin >> codigo;

            // Llamado de la función consultarEquipo
            equipo.consultarEquipo(codigo);
        }
        break;
        case 4:
        {
            // Declaración de variables
            std::string codigo;

            std::cout << "Ingrese el codigo del equipo que desea modificar: \n";
            std::cin >> codigo;

            equipo.modificarEquipo(codigo);
        }
        break;
        case 5:
            equipo.listarNombreASC();
            break;
        case 6:
            equipo.listarNombreDESC();
            break;
        case 7: 
        {
            std::string hilera;
            std::cout << "Ingrese la hilera que desea buscar en las descripciones: \n";
            std::cin >> hilera;
            
            equipo.listarHilera(hilera);
        }
            break;
        case 8:
            equipo.listarCodigoASC();
            break;
        case 9:
            equipo.listarCodigoDESC();
            break;
        case 10:
        {
            // Declaración de variables
            int anioInicio, anioFin;

            std::cout << "Ingrese el anio de inicio para el rango: \n";
            std::cin >> anioInicio;
            std::cout << "Ingrese el anio del final para el rango: \n";
            std::cin >> anioFin;

            equipo.listarPorAnio(anioInicio, anioFin);
        }
        break;
        case 11:
        {
            //// Declaración de variables
            //float nivelphmin, nivelphmax;

            //std::cout << "Ingrese la acidez minima para el rango: \n";
            //std::cin >> nivelphmin;
            //std::cout << "Ingrese la acidez maxima para el rango: \n";
            //std::cin >> nivelphmax;

            //equipo.listarAcidez(nivelphmin, nivelphmax);
        }
            break;
        case 12:
        {
            std::string nombreCategoria;
            std::cout << "Ingrese el nombre de la categoría: ";
            std::cin >> nombreCategoria;
            categoria.agregarCategoriaOrdenado(nombreCategoria);
        }
            break;
        case 13:
        {
            std::string nombreCategoria;
            std::cout << "Ingrese el nombre de la categoría a eliminar: ";
            std::cin >> nombreCategoria;
            categoria.removerCategoria(nombreCategoria);
        }
        break;
        case 14:
        {
            std::string nombreCategoria;
            std::cout << "Ingrese el nombre de la categoría a consultar: ";
            std::cin >> nombreCategoria;
            Categoria categoriaConsultada = categoria.consultarCategoria(nombreCategoria);
            if (categoriaConsultada.getNombre() != "") {
                std::cout << "Nombre: " << categoriaConsultada.getNombre() << ", Cantidad de equipos asociados: " << categoriaConsultada.getCantidadEquipos() << std::endl;
                std::cout << "Equipos asociados:" << std::endl;
                std::list<Equipo*> equipos = categoriaConsultada.listarEquipos();
                for (const auto& equipo : equipos) {
                    std::cout << "Código: " << equipo->getCodigo() << ", Nombre: " << equipo->getNombre() << std::endl;
                }
            }
            else {
                std::cout << "La categoría no existe." << std::endl;
            }
        }
        break;
        case 15:
        {
            std::string nombreCategoriaModificar;
            std::cout << "Ingrese el nombre de la categoría a modificar: ";
            std::cin >> nombreCategoriaModificar;
            categoria.modificarCategoria(nombreCategoriaModificar);
        }
        break;
        case 16:
        {
            categoria.mostrarCatalogoCategorias();
        }
        break;
        case 17:
        {
           /* std::string nombreCategoriaAgregarEquipo;
            std::string codigoEquipo;
            Equipo eqp = equipo.consultarEquipo(codigoEquipo);

            std::cout << "Ingrese el nombre de la categoría: ";
            std::cin >> nombreCategoriaAgregarEquipo;
            std::cout << "Ingrese el código del equipo a agregar: ";
            std::cin >> codigoEquipo;
            categoria.agregarEquipoACategoria(nombreCategoriaAgregarEquipo, eqp);*/
        }
        break;
        case 18:
        {
           /* std::string nombreCategoriaAgregarEquipo;
            std::string codigoEquipo;
            Equipo eqp = equipo.consultarEquipo(codigoEquipo);

            std::cout << "Ingrese el nombre de la categoría: ";
            std::cin >> nombreCategoriaAgregarEquipo;
            std::cout << "Ingrese el código del equipo a agregar: ";
            std::cin >> codigoEquipo;
            categoria.agregarEquipoACategoria(nombreCategoriaAgregarEquipo, eqp);*/
        }
        break;
        case 0:
            std::cout << "¡Gracias por usar nuestra aplicación! " << std::endl;
            break;
        default:
            std::cout << "Opción inválida" << std::endl;
            break;
        }
    }
}

int main() {
    Equipo equipo;
    Categoria categoria;
    inicio(equipo, categoria);
    return 0;
};

