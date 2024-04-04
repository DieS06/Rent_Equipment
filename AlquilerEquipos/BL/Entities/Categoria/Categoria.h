// Categoria.h

#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <list>

class Equipo; // Declaración previa de la clase Equipo para evitar dependencia circular

class Categoria {
private:
    std::string nombre;
    int cantidadEquipos;
    std::list<Equipo*> equiposAsociados; // Lista de punteros a objetos de tipo Equipo

public:
    Categoria();
    Categoria(std::string nombre);

    static std::list<Categoria> listaCategorias;

    // Getters y setters
    std::string getNombre() const;
    int getCantidadEquipos() const;
    void setNombre(std::string nombre);
    void setCantidadEquipos(int cantidadEquipos);

    // Funciones relacionadas con la lista de equipos asociados
    void agregarEquipo(Equipo* equipo);
    void retirarEquipo(Equipo* equipo);
    std::list<Equipo*> listarEquipos();

    // Resto de las funcionalidades solicitadas para la clase Categoria
    void agregarCategoriaOrdenado(std::string nombre);
    void removerCategoria(std::string nombre);
    Categoria consultarCategoria(std::string nombre);
    void listarTodasCategorias();
    void modificarCategoria(std::string nombreAnterior);
    void mostrarCatalogoCategorias();
    /*void agregarEquipoACategoria(std::string nombreCategoria, Equipo* equipo);
    void retirarEquipoDeCategoria(std::string nombreCategoria, Equipo* equipo);*/

    // Destructor
    ~Categoria();
};

#endif