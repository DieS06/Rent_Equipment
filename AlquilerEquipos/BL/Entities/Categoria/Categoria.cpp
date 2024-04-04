// Categoria.cpp
#include <iostream>
#include "Categoria.h"

Categoria::Categoria() : cantidadEquipos(0) {}

Categoria::Categoria(std::string nombre) : nombre(nombre), cantidadEquipos(0) {}

std::list<Categoria> Categoria::listaCategorias;

void Categoria::agregarEquipo(Equipo* equipo) {
    equiposAsociados.push_back(equipo);
    cantidadEquipos++;
}

void Categoria::retirarEquipo(Equipo* equipo) {
    equiposAsociados.remove(equipo);
    cantidadEquipos--;
}

std::list<Equipo*> Categoria::listarEquipos() {
    return equiposAsociados;
}

std::string Categoria::getNombre() const {
    return nombre;
}

int Categoria::getCantidadEquipos() const {
    return cantidadEquipos;
}

void Categoria::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Categoria::setCantidadEquipos(int cantidadEquipos) {
    this->cantidadEquipos = cantidadEquipos;
}

void Categoria::listarTodasCategorias() {
    if (equiposAsociados.empty()) {
        std::cout << "No hay equipos asociados a esta categoria." << std::endl;
    }
    else {
        std::cout << "Categor�a: " << nombre << ", Cantidad de equipos asociados: " << cantidadEquipos << std::endl;
        std::cout << "Equipos asociados:" << std::endl;
        for (const auto& equipo : equiposAsociados) {
            std::cout << "C�digo: " << equipo->getCodigo() << ", Nombre: " << equipo->getNombre() << std::endl;
        }
    }
}

void Categoria::agregarCategoriaOrdenado(std::string nombre) {
    // Crear una nueva categor�a con el nombre proporcionado
    Categoria nuevaCategoria(nombre);

    // Agregar la nueva categor�a a la lista de categor�as
    listaCategorias.push_back(nuevaCategoria);

    // Ordenar la lista de categor�as alfab�ticamente por nombre
    listaCategorias.sort([](const Categoria& a, const Categoria& b) {
        return a.getNombre() < b.getNombre();
        });
}

void Categoria::removerCategoria(std::string nombre) {
    // Buscar la categor�a con el nombre proporcionado en la lista de categor�as
    auto it = std::find_if(listaCategorias.begin(), listaCategorias.end(),
        [&](const Categoria& categoria) {
            return categoria.getNombre() == nombre;
        });

    if (it != listaCategorias.end()) {
        // Eliminar la categor�a si se encontr�
        listaCategorias.erase(it);
        std::cout << "La categor�a '" << nombre << "' ha sido eliminada." << std::endl;
    }
    else {
        std::cout << "No se encontr� una categor�a con el nombre '" << nombre << "'." << std::endl;
    }
}

Categoria Categoria::consultarCategoria(std::string nombre) {
    // Buscar la categor�a con el nombre proporcionado en la lista de categor�as
    auto it = std::find_if(listaCategorias.begin(), listaCategorias.end(),
        [&](const Categoria& categoria) {
            return categoria.getNombre() == nombre;
        });

    if (it != listaCategorias.end()) {
        // Devolver la categor�a si se encontr�
        return *it;
    }
    else {
        // Puedes devolver una categor�a predeterminada o lanzar una excepci�n
        // dependiendo de tus necesidades. Aqu�, devolvemos una categor�a vac�a.
        return Categoria();
    }
}

void Categoria::modificarCategoria(std::string nombreAnterior) {
    std::string nuevoNombre;

    auto it = std::find_if(listaCategorias.begin(), listaCategorias.end(),
        [&](const Categoria& categoria) {
            return categoria.getNombre() == nombreAnterior;
        });

    if (it != listaCategorias.end()) {
        // Modificar el nombre de la categor�a
        it->setNombre(nuevoNombre);
        std::cout << "La categor�a '" << nombreAnterior << "' ha sido modificada a '" << nuevoNombre << "'." << std::endl;
    }
    else {
        std::cout << "No se encontr� una categor�a con el nombre '" << nombreAnterior << "'." << std::endl;
    }
}

void Categoria::mostrarCatalogoCategorias() {
    std::cout << "Cat�logo de Categor�as:" << std::endl;
    for (const auto& categoria : listaCategorias) {
        std::cout << "Nombre: " << categoria.getNombre() << ", Cantidad de equipos asociados: " << categoria.getCantidadEquipos() << std::endl;
    }
}

//void Categoria::agregarEquipoACategoria(std::string nombreCategoria, Equipo* equipo) {
//    auto it = std::find_if(listaCategorias.begin(), listaCategorias.end(),
//        [&](const Categoria& categoria) {
//            return categoria.getNombre() == nombreCategoria;
//        });
//
//    if (it != listaCategorias.end()) {
//        // Agregar el equipo a la categor�a
//        it->agregarEquipo(equipo);
//        std::cout << "El equipo ha sido agregado a la categor�a '" << nombreCategoria << "'." << std::endl;
//    }
//    else {
//        std::cout << "No se encontr� una categor�a con el nombre '" << nombreCategoria << "'." << std::endl;
//    }
//}
//
//void Categoria::retirarEquipoDeCategoria(std::string nombreCategoria, Equipo* equipo) {
//    auto it = std::find_if(listaCategorias.begin(), listaCategorias.end(),
//        [&](const Categoria& categoria) {
//            return categoria.getNombre() == nombreCategoria;
//        });
//
//    if (it != listaCategorias.end()) {
//        // Retirar el equipo de la categor�a
//        it->retirarEquipo(equipo);
//        std::cout << "El equipo ha sido retirado de la categor�a '" << nombreCategoria << "'." << std::endl;
//    }
//    else {
//        std::cout << "No se encontr� una categor�a con el nombre '" << nombreCategoria << "'." << std::endl;
//    }
//}

Categoria::~Categoria() {}

