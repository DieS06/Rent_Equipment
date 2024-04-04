#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <list>

class Equipo {
private:
    //Atributos
    std::string codigo;
    std::string nombre;
    int anio;
    float nivelPh;
    std::string descripcion;

public:
    // Constructores
    Equipo();   
    Equipo(std::string codigo, std::string nombre, int anio, float nivelPh,
        std::string descripcion);
    Equipo(std::string codigo);

    //Destructor
    ~Equipo();

    // Lista para almacenar los equipos agregados
    static std::list<Equipo> listaEquipos;
    static std::list<Equipo> listaRemovidos;

    // GETTERS
    std::string getCodigo() const {return codigo;}
    std::string getNombre() const {return nombre;}
    int getAnio() const {return anio;}
    float getNivelPh() const {return nivelPh;}
    std::string getDescripcion() const {return descripcion;}

    // SETTERS
    void setNombre(std::string nombre) {this->nombre = nombre;}
    void setAnio(int anio) {this->anio = anio;}
    void setNivelPh(float nivelPh) {this->nivelPh = nivelPh;}
    void setDescripcion(std::string descripcion) {this->descripcion = descripcion;}

    /*METODOS SINGULARES*/
    Equipo agregarEquipo(std::string codigo, std::string nombre, int anio, float nivelPh, std::string descripcion);
    Equipo retirarEquipo(std::string codigo);
    Equipo consultarEquipo(std::string codigo);
    Equipo modificarEquipo(std::string codigo);

    /*LISTADOS COMPLETOS*/

    /*Listado por el nombre en ascendente y descendente,
    si los nombre son iguales lo debe priorizar por año*/
    std::list<Equipo> listarNombreASC();
    std::list<Equipo> listarNombreDESC();

    /*Metodo para listar una hilera especifica,
    la hilera se refiere a un caracter especifico.*/
    std::list<Equipo> listarHilera(const std::string& hilera);

    /*Listado por el código en ascendente y descendente,
    si los nombre son iguales lo debe priorizar por año*/
    std::list<Equipo> listarCodigoASC();
    std::list<Equipo> listarCodigoDESC();

    /*Debe listar los equipos en un rango de años*/
    std::list<Equipo> listarPorAnio(int anioInicio, int anioFin);

    /*std::list<Equipo> listarAcidez(float nivelPhMin, float nivelPhMax);*/
};



#endif
