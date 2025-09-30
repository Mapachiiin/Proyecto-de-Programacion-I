```mermaid
flowchart LR
  %% Grupos
  subgraph UI_Consola [UI / Consola]
    Menu[Menu]
  end

  subgraph Logica [Logica de Negocio]
    Control[Control]
    Quemados[Quemados - seed]
  end

  subgraph Dominio [Dominio]
    Sucursal[Sucursal]
    Cliente[Cliente]
    Instructor[Instructor]
    ClaseGrupal[ClaseGrupal]
    Rutina[Rutina]
    ReporteMedicion[ReporteMedicion]
    Ejercicios[Ejercicios]
    Ejercicio[Ejercicio]
  end

  %% Flujo principal
  Menu --> Control
  Quemados --> Control

  Control --> Sucursal
  Sucursal --> Cliente
  Sucursal --> Instructor
  Sucursal --> ClaseGrupal

  Cliente --> Instructor
  Cliente --> Rutina
  Cliente --> ReporteMedicion

  ClaseGrupal --> Instructor
  ClaseGrupal --> Sucursal

  Rutina --> Ejercicios
  Ejercicios --> Ejercicio

  %% Estilos por grupo
  classDef ui fill:#E3F2FD,stroke:#64B5F6,stroke-width:1px;
  classDef logic fill:#E8F5E9,stroke:#81C784,stroke-width:1px;
  classDef domain fill:#FFF3E0,stroke:#FFB74D,stroke-width:1px;

  class Menu ui;
  class Control,Quemados logic;
  class Sucursal,Cliente,Instructor,ClaseGrupal,Rutina,ReporteMedicion,Ejercicios,Ejercicio domain;
```

Notas rápidas:
- Menu dirige las acciones del usuario hacia Control.
- Quemados carga datos de ejemplo en Control.
- Control orquesta Sucursal y sus entidades relacionadas (Cliente, Instructor, ClaseGrupal).
- Cliente referencia a su Instructor, a una Rutina y a sus ReporteMedicion.
- ClaseGrupal se asocia a Instructor y Sucursal.
- Rutina agrega Ejercicios/Ejercicio.

---

## 2) UML de Clases (Mermaid)

```mermaid
classDiagram
  direction LR

  namespace UI {
    class Menu {
      - control_ : Control*
      + quemados() void
    }
  }

  namespace Logic {
    class Control {
      - sucursales_ : Sucursal**
      - numSucursales_ : int
      - capSucursales_ : int
      + Control()
      + ~Control()
      + agregarSucursal(codi: string, tel: int, prov: string, cant: string, corr: string, capCli: int, capIns: int) void
      + eliminarSucursal(codigo: string) void
      + listarSucursales() void
      + gestionarSucursal(codigo: string) void
      + menuGestionarClientes(sucu: Sucursal*) void
      + agregarCliente(sucu: Sucursal*) void
      + gestionarCliente(sucu: Sucursal*) void
      + eliminarCliente(sucu: Sucursal*) void
      + menuGestionarInstructores(sucu: Sucursal*) void
      + agregarInstructor(sucu: Sucursal*) void
      + gestionarInstructor(sucu: Sucursal*) void
      + eliminarInstructor(sucu: Sucursal*) void
      + menuGestionarClasesGrupales(sucu: Sucursal*) void
      + agregarClaseGrupal(sucu: Sucursal*) void
      + gestionarClaseGrupalSi(sucu: Sucursal*) void
      + eliminarClaseGrupal(sucu: Sucursal*) void
      + buscarSucursal(codigo: string) Sucursal*
    }

    class Quemados {
      - control_ : Control*
      + Quemados(con: Control*)
      + IngreDatosQuemados() void
    }
  }

  namespace Domain {
    class Sucursal {
      - cod : string
      - provi : string
      - canton : string
      - correo : string
      - telef : int
      - numClientes_ : int
      - capClientes_ : int
      - numInstructores_ : int
      - capInstruc_ : int
      - numClasesGrups_ : int
      - capClasesGrupales_ : int
      + getCod() string
      + getProvi() string
      + getCanton() string
      + getCorreo() string
      + getTelef() int
      + getNumClientes() int
      + getCapClientes() int
      + getNumInstructores() int
      + getCapClasesGrupales() int
      + buscarCliente(cedula: int) Cliente*
      + buscarInstructor(cedula: int) Instructor*
      + buscarClaseGrupal(cod: int) ClaseGrupal*
      + getClaseGrupalPorIndice(indice: int) ClaseGrupal*
      + agregarCliente(cliente: Cliente*) void
      + agregarInstructor(instructor: Instructor*) void
      + agregarClaseGrupal(clase: ClaseGrupal*) void
      + eliminarCliente(cedula: int) void
      + eliminarInstructor(cedula: int) void
      + eliminarClaseGrupal(codClase: int) void
      + listarInstructores() void
      + listarClientes() void
      + listarClasesGrupales() void
      + listarClientesDeInstructor(inst: Instructor*) void
      + listarClasesGrupalesCliente(cli: Cliente*) void
      + listarClientesPorIMC() void
      + toString() string
    }

    class Cliente {
      - name_ : string
      - ced_ : int
      - telf_ : int
      - correo : string
      - fechaNac_ : string
      - sexo_ : char
      - fechaIns_ : string
      - inscritos_ : int
      - instAsig_ : Instructor*
      - ruti_ : Rutina*
      - reportes_ : ReporteMedicion*[10]
      - numReportes_ : int
      + getCorreo() string
      + getFechaNac() string
      + getSexo() char
      + getFechaIns() string
      + getInscritos() int
      + getInstructor() Instructor*
      + getRutina() Rutina*
      + getNumReportes() int
      + setName(name: string) void
      + setCed(ced: int) void
      + setTelf(telf: int) void
      + setCorreo(corr: string) void
      + setFechaNac(fN: string) void
      + setSexo(mf: char) void
      + setFechaIns(fI: string) void
      + setInscritos(ins: int) void
      + setIntructor(ins: Instructor*) void
      + asignarRutina(ruti: Rutina*) void
      + agregarReporte(rep: ReporteMedicion) void
      + listarReportes() void
      + getReportePorIndice(indice: int) ReporteMedicion*
      + toString() string
    }

    class Instructor {
      - numCed_ : int
      - nombre_ : string
      - telef_ : int
      - correo : string
      - fechaNac : string
      - espeIns : string[]
      - numEspecialidades : int
      + setNumCed(nC: int) void
      + setNombre(nom: string) void
      + setTelef(tel: int) void
      + setCorreo(corr: string) void
      + setFechaNac(fN: int) void
      + getCed() int
      + getNombre() string
      + getTelef() int
      + getCorreo() string
      + getFechaNac() string
      + getNumEspecialidades() int
      + getEspecialidadPrinci() string
      + tieneEspecialidad(esp: string) bool
      + tieneEspecialidadInt(esp: int) bool
      + toString() string
    }

    class ClaseGrupal {
      - codClase_ : int
      - cupoMax_ : int
      - ocupados_ : int
      - horario_ : string
      - insAsig_ : Instructor*
      - sucAsig_ : Sucursal*
      + toString() string
    }

    class Rutina
    class Ejercicio
    class Ejercicios
    class ReporteMedicion {
      + toString() string
    }
  }

  %% Relaciones
  Control --> Sucursal
  Sucursal --> Cliente
  Sucursal --> Instructor
  Sucursal --> ClaseGrupal
  Cliente --> Instructor
  Cliente --> Rutina
  Cliente --> ReporteMedicion
  ClaseGrupal --> Instructor
  ClaseGrupal --> Sucursal
  Menu --> Control
  Quemados --> Control
  Rutina --> Ejercicio
  Rutina --> Ejercicios
```

---
