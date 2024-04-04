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
        std::cout << "Categoría: " << nombre << ", Cantidad de equipos asociados: " << cantidadEquipos << std::endl;
        std::cout << "Equipos asociados:" << std::endl;
        for (const auto& equipo : equiposAsociados) {
            std::cout << "Código: " << equipo->getCodigo() << ", Nombre: " << equipo->getNombre() << std::endl;
        }
    }
}

void Categoria::agregarCategoriaOrdenado(std::string nombre) {
    // Crear una nueva categoría con el nombre proporcionado
    Categoria nuevaCategoria(nombre);

    // Agregar la nueva categoría a la lista de categorías
    listaCategorias.push_back(nuevaCategoria);

    // Ordenar la lista de categorías alfabéticamente por nombre
    listaCategorias.sort([](const Categoria& a, const Categoria& b) {
        return a.getNombre() < b.getNombre();
        });
}

void Categoria::removerCategoria(std::string nombre) {
    // Buscar la categoría con el nombre proporcionado en la lista de categorías
    auto it = std::find_if(listaCategorias.begin(), listaCategorias.end(),
        [&](const Categoria& categoria) {
            return categoria.getNombre() == nombre;
        });

    if (it != listaCategorias.end()) {
        // Eliminar la categoría si se encontró
        listaCategorias.erase(it);
        std::cout << "La categoría '" << nombre << "' ha sido eliminada." << std::endl;
    }
    else {
        std::cout << "No se encontró una categoría con el nombre '" << nombre << "'." << std::endl;
    }
}

Categoria Categoria::consultarCategoria(std::string nombre) {
    // Buscar la categoría con el nombre proporcionado en la lista de categorías
    auto it = std::find_if(listaCategorias.begin(), listaCategorias.end(),
        [&](const Categoria& categoria) {
            return categoria.getNombre() == nombre;
        });

    if (it != listaCategorias.end()) {
        // Devolver la categoría si se encontró
        return *it;
    }
    else {
        // Puedes devolver una categoría predeterminada o lanzar una excepción
        // dependiendo de tus necesidades. Aquí, devolvemos una categoría vacía.
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
        // Modificar el nombre de la categoría
        it->setNombre(nuevoNombre);
        std::cout << "La categoría '" << nombreAnterior << "' ha sido modificada a '" << nuevoNombre << "'." << std::endl;
    }
    else {
        std::cout << "No se encontró una categoría con el nombre '" << nombreAnterior << "'." << std::endl;
    }
}

void Categoria::mostrarCatalogoCategorias() {
    std::cout << "Catálogo de Categorías:" << std::endl;
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
//        // Agregar el equipo a la categoría
//        it->agregarEquipo(equipo);
//        std::cout << "El equipo ha sido agregado a la categoría '" << nombreCategoria << "'." << std::endl;
//    }
//    else {
//        std::cout << "No se encontró una categoría con el nombre '" << nombreCategoria << "'." << std::endl;
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
//        // Retirar el equipo de la categoría
//        it->retirarEquipo(equipo);
//        std::cout << "El equipo ha sido retirado de la categoría '" << nombreCategoria << "'." << std::endl;
//    }
//    else {
//        std::cout << "No se encontró una categoría con el nombre '" << nombreCategoria << "'." << std::endl;
//    }
//}

Categoria::~Categoria() {}

