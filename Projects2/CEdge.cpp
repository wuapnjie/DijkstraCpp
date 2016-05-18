//
// Created by snowbean on 16-5-10.
//

#include "CEdge.h"

int CEdge::getCap() {
    return capacity;
}

int CEdge::getHead() {
    return head;
}

int CEdge::getTail() {
    return tail;
}

int CEdge::getWeight() {
    return weight;
}

CEdge::CEdge(CEdge &x) {
    this->weight = x.weight;
    this->head = x.head;
    this->tail = x.tail;
    this->capacity = x.capacity;
}

CEdge::CEdge(int a, int b, int c) {
    this->head = a;
    this->tail = b;
    this->weight = c;
}

CEdge::CEdge(int a, int b, int c, int d) {
    this->head = a;
    this->tail = b;
    this->weight = c;
    this->capacity = d;
}

CEdge::~CEdge() {
}

bool CEdge::operator<(CEdge &x) {
    return this->weight < x.weight;
}

CEdge::CEdge(int a, int b) {
    this->head = a;
    this->tail = b;
}

double CEdge::getRate() {
    return this->rate;
}


CEdge::CEdge(int a, int b, int c, int d, double e) {
    this->head = a;
    this->tail = b;
    this->weight = c;
    this->capacity = d;
    this->rate = e;
}




