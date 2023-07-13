#ifndef SISTEMA_H
#define SISTEMA_H

#include "Paciente.h"
#include <iostream>
#include <string>
#include <exception>

template <class T> class Nodo{
    public:
        T paciente;
        Nodo* esquerda;
        Nodo* direita;

        Nodo(const T& paciente);
};

class Sistema {
private:
    Nodo<Paciente>* raiz;

    template <class T>
    Nodo<T>* insereNodo(Nodo<T>* nodo, const Paciente& paciente) {
        if (nodo == nullptr) {
            return new Nodo<T>(paciente);
        }

        if (paciente.getNome() < nodo->paciente.getNome()) {
            nodo->esquerda = insereNodo(nodo->esquerda, paciente);
        } else if (paciente.getNome() > nodo->paciente.getNome()) {
            nodo->direita = insereNodo(nodo->direita, paciente);
        } else {
            throw std::runtime_error("Paciente já existente no sistema");
        }

        return nodo;
    }

    template <class T>
    Nodo<T>* buscaNodo(Nodo<T>* nodo, const std::string& nome) const {
        if (nodo == nullptr || nodo->paciente.getNome() == nome) {
            return nodo;
        }

        if (nome < nodo->paciente.getNome()) {
            return buscaNodo(nodo->esquerda, nome);
        } else {
            return buscaNodo(nodo->direita, nome);
        }
    }

    template <class T>
    void imprimeNodos(Nodo<T>* nodo, std::ostream& os) const {
        if (nodo != nullptr) {
            imprimeNodos(nodo->esquerda, os);
            nodo->paciente.imprime(os);
            os << std::endl;
            imprimeNodos(nodo->direita, os);
        }
    }

    template <class T>
    void destruir(Nodo<T>* nodo) {
        if (nodo != nullptr) {
            destruir(nodo->esquerda);
            destruir(nodo->direita);
            delete nodo;
        }
    }

public:
    Sistema() : raiz(nullptr) {}

    ~Sistema() {
        destruir(raiz);
    }

    void insere(const Paciente& paciente) {
        raiz = insereNodo(raiz, paciente);
    }

    const Paciente* busca(const std::string& nome) const {
        Nodo<Paciente>* nodo = buscaNodo(raiz, nome);
        if (nodo == nullptr) {
            throw std::runtime_error("Paciente não existe.");
        }
        return &(nodo->paciente);
    }

    void imprime(std::ostream& os) const {
        imprimeNodos(raiz, os);
    }
};

// Implementação das funções do template

template <class T>
Nodo<T>::Nodo(const T& paciente) : paciente(paciente), esquerda(nullptr), direita(nullptr) {}

#endif  // SISTEMA_H