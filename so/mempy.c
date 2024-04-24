#include <Python.h>
#include "lib/ll.h" 
#include <stdio.h>

static PyObject *py_create_node(PyObject *self, PyObject *args){
    char *key ;
    char *data ;

    if(!PyArg_ParseTuple(args, "ss", &key, &data)){
        return NULL ;
    }

    Node *node = create_node(key, data) ;
    return PyCapsule_New(node, NULL, NULL) ;
}

static PyObject *py_insert(PyObject *self, PyObject *args){
    char *key ;
    char *data ;
    PyObject *node_capsule ;

    if(!PyArg_ParseTuple(args, "Oss", &node_capsule, &key, &data)){
        return NULL ;
    }

    Node *node = PyCapsule_GetPointer(node_capsule, NULL) ;
    Node *last_node = insert_value(&node, key, data) ;
    return PyCapsule_New(last_node, NULL, NULL) ;
}

static PyObject *py_display_all(PyObject *self, PyObject *args){
    PyObject *head_capsule ;
    

    if(!PyArg_ParseTuple(args, "O", &head_capsule)){
        return NULL ;
    }

    Node *node = PyCapsule_GetPointer(head_capsule, NULL) ;
    display(node) ;
    Py_RETURN_NONE ;
}

static PyObject *py_clear_all(PyObject *self, PyObject *args){
    PyObject *head_capsule ;
    

    if(!PyArg_ParseTuple(args, "O", &head_capsule)){
        return NULL ;
    }

    Node *node = PyCapsule_GetPointer(head_capsule, NULL) ;
    free_mem(node) ;
    Py_RETURN_NONE ;
}


static PyMethodDef methods[] = {
    {"create_node", py_create_node, METH_VARARGS, "Create new node"},
    {"insert_node", py_insert, METH_VARARGS, "Insert value as next node"},
    {"display", py_display_all, METH_VARARGS, "Display all nodes"},
    {"free", py_clear_all, METH_VARARGS, "GC"},
    {NULL, NULL, 0, NULL}
} ; 

static struct PyModuleDef modules = {
    PyModuleDef_HEAD_INIT,
    "mempy",
    "A simple module in C for mem db",
    -1,
    methods
} ;


PyMODINIT_FUNC PyInit_mempy(void){
    return PyModule_Create(&modules) ;
}
