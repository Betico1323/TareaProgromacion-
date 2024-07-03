#include <iostream>
#include <cmath>

using namespace std;

struct Dot {
    float x;
    float y;
    float z;
    
    Dot(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

// Funciones para 2D
float distancia2D(const Dot& a, const Dot& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

Dot suma2D(const Dot& a, const Dot& b) {
    return Dot(a.x + b.x, a.y + b.y, 0);
}

Dot sumaVectores2D(const Dot vectores[], int n) {
    float x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        x += vectores[i].x;
        y += vectores[i].y;
    }
    return Dot(x, y, 0);
}

float productoEscalar2D(const Dot& a, const Dot& b) {
    return a.x * b.x + a.y * b.y;
}

// Funciones para 3D
float distancia3D(const Dot& a, const Dot& b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

Dot suma3D(const Dot& a, const Dot& b) {
    return Dot(a.x + b.x, a.y + b.y, a.z + b.z);
}

Dot sumaVectores3D(const Dot vectores[], int n) {
    float x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        x += vectores[i].x;
        y += vectores[i].y;
        z += vectores[i].z;
    }
    return Dot(x, y, z);
}

float productoEscalar3D(const Dot& a, const Dot& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Dot productoCruz(const Dot& a, const Dot& b) {
    return Dot(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

void imprimirVector2D(const Dot& vec) {
    cout << "u = " << vec.x << "i + " << vec.y << "j";
    if (vec.x != 0 && vec.y != 0) {
        cout << " (en el plano XY)";
    } else if (vec.x != 0) {
        cout << " (en el eje X)";
    } else if (vec.y != 0) {
        cout << " (en el eje Y)";
    }
    cout << endl;
}

void imprimirVector3D(const Dot& vec) {
    cout << "u = " << vec.x << "i + " << vec.y << "j + " << vec.z << "k";
    if (vec.x != 0 && vec.y != 0 && vec.z != 0) {
        cout << " (en el espacio XYZ)";
    } else if (vec.x != 0 && vec.y != 0) {
        cout << " (en el plano XY)";
    } else if (vec.x != 0 && vec.z != 0) {
        cout << " (en el plano XZ)";
    } else if (vec.y != 0 && vec.z != 0) {
        cout << " (en el plano YZ)";
    } else if (vec.x != 0) {
        cout << " (en el eje X)";
    } else if (vec.y != 0) {
        cout << " (en el eje Y)";
    } else if (vec.z != 0) {
        cout << " (en el eje Z)";
    }
    cout << endl;
}

Dot resolverSistemaDeFuerzas2D(const Dot fuerzas[], int n) {
    return sumaVectores2D(fuerzas, n);
}

Dot resolverSistemaDeFuerzas3D(const Dot fuerzas[], int n) {
    return sumaVectores3D(fuerzas, n);
}

int main() {
    // Funciones en 2D
    // Editar aqui las posiciones x, y
    int cero = 0.0;
    Dot p1(15.0, 20.0, cero);
    Dot p2(8.0, 9.0, cero);

    cout << "Distancia entre p1 y p2 en 2D: " << distancia2D(p1, p2) << endl;

    Dot sumaPuntos2D = suma2D(p1, p2);
    cout << "Suma de p1 y p2 en 2D: ";
    imprimirVector2D(sumaPuntos2D);

    const int n = 3;
    Dot vectores2D[n] = {p1, p2, Dot(7.0, 8.0, cero)};
    Dot sumaVectoresResult2D = sumaVectores2D(vectores2D, n);
    cout << "Suma de un arreglo de vectores en 2D: ";
    imprimirVector2D(sumaVectoresResult2D);

    float escalar2D = productoEscalar2D(p1, p2);
    cout << "Producto escalar de p1 y p2 en 2D: " << escalar2D << endl;

    Dot resultadoSistemaFuerzas2D = resolverSistemaDeFuerzas2D(vectores2D, n);
    cout << "Resultado del sistema de fuerzas en 2D: ";
    imprimirVector2D(resultadoSistemaFuerzas2D);

    cout << endl << endl;

    // Funciones en 3D
    // Editar aqui las posiciones x, y, z

    Dot p3(10.0, 3.0, 21.0);
    Dot p4(6.0, 4.0, 15.0);

    cout << "Distancia entre p3 y p4 en 3D: " << distancia3D(p3, p4) << endl;

    Dot sumaPuntos3D = suma3D(p3, p4);
    cout << "Suma de p3 y p4 en 3D: ";
    imprimirVector3D(sumaPuntos3D);

    Dot vectores3D[n] = {p3, p4, Dot(7.0, 8.0, 9.0)};
    Dot sumaVectoresResult3D = sumaVectores3D(vectores3D, n);
    cout << "Suma de un arreglo de vectores en 3D: ";
    imprimirVector3D(sumaVectoresResult3D);

    float escalar3D = productoEscalar3D(p3, p4);
    cout << "Producto escalar de p3 y p4 en 3D: " << escalar3D << endl;

    Dot cruz = productoCruz(p3, p4);
    cout << "Producto cruz de p3 y p4 en 3D: ";
    imprimirVector3D(cruz);

    Dot resultadoSistemaFuerzas3D = resolverSistemaDeFuerzas3D(vectores3D, n);
    cout << "Resultado del sistema de fuerzas en 3D: ";
    imprimirVector3D(resultadoSistemaFuerzas3D);

    return 0;
}
