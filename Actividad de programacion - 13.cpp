/*************************************************************

NOMBRE: Roberto perez Zamora
FECHA: 15/04/24
PROGRAMA: Actividad de programacion - 13.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION: Pedir al usuario una palabra o frase
Debe contar el número de vocales, consonantes y espacios
Debe determinar si es una palabra palíndromo 
Convertir palabra o frase a Mayúsculas y minúsculas
Solicitar otra palabra o frase y que se concatene con la anterior

*************************************************************/

// Incluir bibliotecas necesarias
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Función para contar el número de vocales, consonantes y espacios
void contarCaracteres(const std::string& palabra, int& vocales, int& consonantes, int& espacios) {
    vocales = consonantes = espacios = 0;
    
    // Recorrer cada caracter de la palabra
    for (char c : palabra) {
        if (std::isalpha(c)) {
            c = std::tolower(c);
            // Contar vocales y consonantes
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        } else if (c == ' ') {
            espacios++;
        }
    }
}

// Función para determinar si una palabra es palíndromo
bool esPalindromo(const std::string& palabra) {
    std::string reversa = palabra;
    std::reverse(reversa.begin(), reversa.end());
    return palabra == reversa;
}

// Función para verificar si una palabra contiene solo letras
bool contieneSoloLetras(const std::string& palabra) {
    for (char c : palabra) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

// Función principal
int main() {
    std::string palabra;
    int vocales, consonantes, espacios;
    
    // Pedir al usuario una palabra o frase
    std::cout << "Ingrese una palabra o frase: ";
    std::getline(std::cin, palabra);
    
    // Verificar si la palabra contiene solo letras
    while (!contieneSoloLetras(palabra)) {
        std::cout << "La palabra o frase debe contener solo letras" << std::endl;
        std::cout << "Ingrese una palabra o frase: ";
        std::getline(std::cin, palabra);
    }

    // Solicitar informacion que sea valida
    while (palabra.empty()) {
        std::cout << "La palabra o frase no puede estar vacia" << std::endl;
        std::cout << "Ingrese una palabra o frase: ";
        std::getline(std::cin, palabra);
    }
    
    // Contar el numero de vocales, consonantes y espacios
    contarCaracteres(palabra, vocales, consonantes, espacios);
    std::cout << "Vocales: " << vocales << std::endl;
    std::cout << "Consonantes: " << consonantes << std::endl;
    std::cout << "Espacios: " << espacios << std::endl;
    
    // Determinar si es una palabra palíndromo
    if (esPalindromo(palabra)) {
        std::cout << "La palabra o frase es un palindromo" << std::endl;
    } else {
        std::cout << "La palabra o frase no es un palindromo" << std::endl;
    }
    
    // Convertir la palabra o frase a mayúsculas y minúsculas
    std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
    std::cout << "En mayusculas: " << palabra << std::endl;
    std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
    std::cout << "En minusculas: " << palabra << std::endl;
    
    // Solicitar otra palabra o frase y concatenarla con la anterior
    std::string otraPalabra;
    std::cout << "Ingresa otra palabra o frase: ";
    std::getline(std::cin, otraPalabra);
    palabra += " " + otraPalabra;
    std::cout << "Palabra o frase concatenada: " << palabra << std::endl;
    
    // Mostrar la iformación de la palabra o frase
    contarCaracteres(palabra, vocales, consonantes, espacios);
    std::cout << "Vocales: " << vocales << std::endl;
    std::cout << "Consonantes: " << consonantes << std::endl;
    std::cout << "Espacios: " << espacios << std::endl;

    // Regresar 0
    return 0;
}
