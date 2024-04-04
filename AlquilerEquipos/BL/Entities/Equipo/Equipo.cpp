#include "Equipo.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//Implementacion de constructores con parametros

Equipo::Equipo() {
}

Equipo::Equipo(std::string codigo, std::string nombre, int anio, float nivelPh, std::string descripcion)
    : codigo(codigo), nombre(nombre), anio(anio), nivelPh(nivelPh), descripcion(descripcion)  {
}

Equipo::Equipo(std::string codigo) : codigo(codigo) {
}

Equipo::~Equipo() {
}

// Inicializaci�n de la variable est�tica
std::list<Equipo> Equipo::listaEquipos;
std::list<Equipo> Equipo::listaRemovidos;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Funcionalidades
Equipo Equipo::agregarEquipo(std::string codigo, std::string nombre, int anio, float nivelPh, std::string descripcion) {

    Equipo equipoLoad(codigo, nombre, anio, nivelPh, descripcion);
    

    bool equipoRepetido = false;

    // Validar si el equipo ya existe
    for (const Equipo& equipo : Equipo::listaEquipos) {
        if (equipo.getCodigo() == equipoLoad.codigo) {
            equipoRepetido = true;
            break;
        }
    }

    if (equipoRepetido) {
        std::cout << "Error: El equipo con codigo " << codigo << " ya existe." << std::endl;
        std::cout << " " << std::endl;
    }
    else {
        // Crear el objeto Equipo y agregarlo a la lista
        Equipo equipo(codigo, nombre, anio, nivelPh, descripcion);
        Equipo::listaEquipos.push_back(equipo);

        // Ordenar los equipos en forma ascendente por codigo
        Equipo::listaEquipos.sort([](const Equipo& a, const Equipo& b) {
            return a.getCodigo() < b.getCodigo();
        });

        std::cout << "El equipo ha sido agregado correctamente." << std::endl;
        std::cout << " " << std::endl;
    }
    return equipoLoad;
}

Equipo Equipo::retirarEquipo(std::string codigo)
{
    // Retirar equipo
    // Buscar el equipo con el c�digo proporcionado en la listaEquipos
    auto eqp = std::find_if(listaEquipos.begin(), listaEquipos.end(),
        [&](const Equipo& equipo) {
        return equipo.getCodigo() == codigo;
        });

    if (eqp != listaEquipos.end()) {
        // Agregar el equipo a la lista listaRemovidos
        listaRemovidos.push_back(*eqp);

        // Eliminar el equipo de la listaEquipos
        listaEquipos.erase(eqp);

        std::cout << "El equipo con el codigo: " << codigo << " ha sido retirado." << std::endl;
        std::cout << " " << std::endl;
    }
    else {
        std::cout << "No se encontro un equipo con el codigo proporcionado." << std::endl;
        std::cout << " " << std::endl;
    }

    return Equipo();
}

Equipo Equipo::consultarEquipo(std::string codigo) 
{
    // Consultar equipo
    if (listaEquipos.empty()) {
        std::cout << "La lista de equipos esta vacia." << std::endl;
        std::cout << " " << std::endl;
    }
    else {
        // Buscar el equipo con el c�digo proporcionado
        auto it = std::find_if(listaEquipos.begin(), listaEquipos.end(), 
            [&](const Equipo& equipo) {
            return equipo.getCodigo() == codigo;
        });

        if (it != listaEquipos.end()) {
            // Mostrar informaci�n del equipo seleccionado
            std::cout << "Informacion del equipo:" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "Codigo: " << it->getCodigo() << std::endl;
            std::cout << "Nombre: " << it->getNombre() << std::endl;
            std::cout << "Anio: " << it->getAnio() << std::endl;
            std::cout << "Nivel de pH: " << it->getNivelPh() << std::endl;
            std::cout << "Descripcion: " << it->getDescripcion() << std::endl;
            std::cout << " " << std::endl;
        }
        else {
            std::cout << "No se encontro un equipo con el codigo ingresado." << std::endl;
            std::cout << " " << std::endl;
        }
    }
    return Equipo();
}

Equipo Equipo::modificarEquipo(std::string codigo) 
{
    // Modificar equipo
    if (listaEquipos.empty()) {
        std::cout << "No se han agregado equipos aun." << std::endl;
        std::cout << " " << std::endl;
    }
    else {
        bool equipoEncontrado = false;
        for (Equipo& equipo : listaEquipos) {
            if (equipo.getCodigo() == codigo) {

                std::string nuevoNombre, nuevaDescripcion;
                int nuevoAnio;
                float nuevoNivelPh;

                std::cout << "Ingrese los nuevos datos del equipo: " << std::endl;
                std::cout << " " << std::endl;
                
                std::cout << "Nuevo nombre del equipo: \n";
                std::cin.ignore(); // Limpiar el buffer del teclado antes de leer el nombre
                std::getline(std::cin, nuevoNombre);
                std::cout << "Nuevo anio del equipo: \n";
                std::cin >> nuevoAnio;
                std::cout << "Nuevo nivel de pH del equipo: \n";
                std::cin >> nuevoNivelPh;
                std::cout << "Nueva descripcion del equipo: \n";
                std::cin.ignore(); // Limpiar el buffer del teclado antes de leer la descripci�n
                std::getline(std::cin, nuevaDescripcion);

                // Modificar los datos del equipo
                equipo.setNombre(nuevoNombre);
                equipo.setAnio(nuevoAnio);
                equipo.setNivelPh(nuevoNivelPh);
                equipo.setDescripcion(nuevaDescripcion);

                std::cout << "El equipo ha sido modificado correctamente." << std::endl;
                std::cout << " " << std::endl;

                equipoEncontrado = true;
                break;
            }
        }

        if (!equipoEncontrado) {
            std::cout << "No se encontro un equipo con el codigo proporcionado.\n" << std::endl;
            std::cout << " " << std::endl;
        }
    }
    return Equipo();
}

/********************************LISTADOS COMPLETOS*********************************/
//Funcion para la condicion de la lista ordenada por nombre y priorizar el a�o en nombres repetidos
bool compararPorNombreYAnio(const Equipo& equipo1, const Equipo& equipo2) {
    if (equipo1.getNombre() == equipo2.getNombre()) {
        return equipo1.getAnio() < equipo2.getAnio();
    }
    return equipo1.getNombre() < equipo2.getNombre();
}

/*Listado por el nombre en ascendente y descendente, si los nombre son iguales lo debe priorizar por a�o*/
std::list<Equipo> Equipo::listarNombreASC()
{
    // Listar cat�logo completo por nombre (ascendente)
    if (listaEquipos.empty()) {
        std::cout << "No se han agregado equipos aun." << std::endl;
    }   
    else {
        // Ordenar equipos por nombre en forma ascendente
        listaEquipos.sort(compararPorNombreYAnio);

        // Mostrar cat�logo completo en forma ascendente por nombre
        std::cout << "Catalogo completo (ascendente por nombre):" << std::endl;
        for (const auto& equipo : listaEquipos) {

            std::cout << "Codigo: " << equipo.getCodigo() << std::endl;
            std::cout << ", Nombre: " << equipo.getNombre() << std::endl;
            std::cout << ", Anio: " << equipo.getAnio() << std::endl;
            std::cout << ", Nivel de ph: " << equipo.getNivelPh() << std::endl;
            std::cout << ", Desccripcion: " << equipo.getDescripcion() << std::endl;    
            std::cout << " " << std::endl;
        }
    }
    return listaEquipos;
}
std::list<Equipo> Equipo::listarNombreDESC()
{
    // Listar cat�logo completo por nombre (descendente)
    if (listaEquipos.empty()) {
        std::cout << "No se han agregado equipos aun." << std::endl;
    }
    else {
        // Ordenar equipos por nombre en forma ascendente
        listaEquipos.sort(compararPorNombreYAnio);

        //Invertir el orden de la lista para hacerla descendente
        listaEquipos.reverse();

        // Mostrar cat�logo completo en forma ascendente por nombre
        std::cout << "Catalogo completo (descendente por nombre):" << std::endl;
        for (const auto& equipo : listaEquipos) {

            std::cout << "Codigo: " << equipo.getCodigo() << std::endl;
            std::cout << ", Nombre: " << equipo.getNombre() << std::endl;
            std::cout << ", Anio: " << equipo.getAnio() << std::endl;
            std::cout << ", Nivel de ph: " << equipo.getNivelPh() << std::endl;
            std::cout << ", Desccripcion: " << equipo.getDescripcion() << std::endl;
            std::cout << " " << std::endl;
        }
    }
    return listaEquipos;
}

/*Metodo para listar una hilera especifica, la hilera se refiere a un caracter especifico.*/
std::list<Equipo> Equipo::listarHilera(const std::string& hilera)
{
    std::list<Equipo> equiposConDescripcion;

    for (const auto& equipo : Equipo::listaEquipos) {
        if (equipo.getDescripcion().find(hilera) != std::string::npos) {
            equiposConDescripcion.push_back(equipo);
        }
    }

    // Mostrar los equipos que coinciden con la hilera
    if (equiposConDescripcion.empty()) {
        std::cout << "No se encontraron equipos con la descripci�n deseada." << std::endl;
    }
    else {
        std::cout << "Equipos con descripcion que contiene \"" << hilera << "\": \n" << std::endl;
        for (const auto& equipo : equiposConDescripcion) {
            std::cout << "Codigo: " << equipo.getCodigo() << std::endl;
            std::cout << "Nombre: " << equipo.getNombre() << std::endl;
            std::cout << "Anio: " << equipo.getAnio() << std::endl;
            std::cout << "Nivel de ph: " << equipo.getNivelPh() << std::endl;
            std::cout << "Descripcion: " << equipo.getDescripcion() << "\n" << std::endl;
            std::cout << " " << std::endl;
        }
    }
    return equiposConDescripcion;
}

bool compararPorCodigo(const Equipo& equipo1, const Equipo& equipo2) {
    return equipo1.getCodigo() < equipo2.getCodigo();
}
/*Listado por el c�digo en ascendente y descendente, si los nombre son iguales lo debe priorizar por a�o*/
std::list<Equipo> Equipo::listarCodigoASC()
{
    // Listar cat�logo completo por codigo (ascendente)
    if (listaEquipos.empty()) {
        std::cout << "No se han agregado equipos aun." << std::endl;
    }
    else {
        // Ordenar equipos por nombre en forma ascendente
        listaEquipos.sort(compararPorCodigo);

        // Mostrar cat�logo completo en forma ascendente por nombre
        std::cout << "Catalogo completo (ascendente por codigo):" << std::endl;
        for (const auto& equipo : listaEquipos) {

            std::cout << "Codigo: " << equipo.getCodigo() << std::endl;
            std::cout << " Nombre: " << equipo.getNombre() << std::endl;
            std::cout << " Anio: " << equipo.getAnio() << std::endl;
            std::cout << " Nivel de ph: " << equipo.getNivelPh() << std::endl;
            std::cout << " Desccripcion: " << equipo.getDescripcion() << std::endl;
            std::cout << " " << std::endl;
        }
    }
    return listaEquipos;
}
std::list<Equipo> Equipo::listarCodigoDESC()
{
    // Listar cat�logo completo por codigo (descendente)
    if (listaEquipos.empty()) {
        std::cout << "No se han agregado equipos aun." << std::endl;
    }
    else {
        // Ordenar equipos por nombre en forma ascendente
        listaEquipos.sort(compararPorCodigo);

        //Invertir el orden de la lista para hacerla descendente
        listaEquipos.reverse();

        // Mostrar cat�logo completo en forma ascendente por nombre
        std::cout << "Catalogo completo (descendente por codigo):" << std::endl;
        for (const auto& equipo : listaEquipos) {

            std::cout << " Codigo: " << equipo.getCodigo() << std::endl;
            std::cout << " Nombre: " << equipo.getNombre() << std::endl;
            std::cout << " Anio: " << equipo.getAnio() << std::endl;
            std::cout << " Nivel de ph: " << equipo.getNivelPh() << std::endl;
            std::cout << " Desccripcion: " << equipo.getDescripcion() << std::endl;
            std::cout << " " << std::endl;
        }
    }
    return listaEquipos;
}

/*Debe listar los equipos en un rango de a�os*/
std::list<Equipo> Equipo::listarPorAnio(int anioInicio, int anioFin)
{
    if (listaEquipos.empty()) {
        std::cout << "No se han agregado equipos aun." << std::endl;
    }
    else {
        // Filtrar equipos que est�n dentro del rango de a�os especificado
        std::list<Equipo> equiposEnRango;

        std::copy_if(listaEquipos.begin(), listaEquipos.end(), std::back_inserter(equiposEnRango),
            [&](const Equipo& equipo) {
                int anioEquipo = equipo.getAnio();
                return anioEquipo >= anioInicio && anioEquipo <= anioFin;
            });

        // Mostrar cat�logo completo en forma descendente por a�o en el rango de a�os especificado
        std::cout << "Catalogo completo en el rango de a�os [" << anioInicio << ", " << anioFin << "]:" << std::endl;
        for (const auto& equipo : equiposEnRango) {
            std::cout << "Codigo: " << equipo.getCodigo() << std::endl;
            std::cout << ", Nombre: " << equipo.getNombre() << std::endl;
            std::cout << ", Anio: " << equipo.getAnio() << std::endl;
            std::cout << ", Nivel de ph: " << equipo.getNivelPh() << std::endl;
            std::cout << ", Descripcion: " << equipo.getDescripcion() << std::endl;
            std::cout << " " << std::endl;
        }

        // Devolver la lista de equipos en el rango de a�os
        return equiposEnRango;
    }

    // Si no hay equipos, devolver lista vac�a
    return std::list<Equipo>();
}

//std::list<Equipo> Equipo::listarAcidez(float nivelPhMin, float nivelPhMax) {
//    std::list<Equipo> equiposEnRango;
//    return equiposEnRango;
//}


