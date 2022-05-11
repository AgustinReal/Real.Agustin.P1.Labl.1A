#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED



#endif // INPUTS_H_INCLUDED

/** \brief Esta funcion: Permite elgir entre 2 tipos de chars ingresadas por parametro
 *
 * \param charAValidar char*: Letra ingresada por el usuario.
 * \param mensaje[] char: Mensaje al usuario.
 * \param mensajeError[] char: Mensaje error al usuario.
 * \param opcionUno char: opcion letra 1.
 * \param opcionDos char: opcion letra 2.
 * \return int: 1 or -1: "1" if it was able to perform the function or "-1" if it was not able to perform the function.
 *
 */
int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos);
/**
 * @fn int ingresoEntero(int*, char*, char*, int, int)
 * @brief Allows you to request an integer "a number", give a message to the user with or without error and
 * also allows to give a range of number that can be entered from minimum or maximum.
 *
 * @param entero: Number that is entered and stored in this integer variable, to use it later.
 * @param mensaje: We ask something to the user.
 * @param mensajeError: What we ask the user to do, we tell him to re-enter it.
 * @param min: Is the minimum integer the user can enter.
 * @param max: This is the maximum integer the user can enter.
 * @return todoOk: 1 or -1: "1" if it was able to perform the function or "-1" if it was not able to perform the function.
 */
int ingresoEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
/**
 * @fn int ingresoFlotante(float*, char*, char*, float, float)
 * @brief
 *
 * @param flotante: Real number that is entered and stored in this float variable, to use it later.
 * @param mensaje: We ask something to the user.
 * @param mensajeError: What we ask the user we tell him to re-enter.
 * @param min: Is the minimum float the user can enter.
 * @param max: This is the floating maximum that the user can enter.
 * @return todoOk:1 or -1: "1" if it was able to perform the function or "-1" if it was not able to perform the function.
 */
int ingresoFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
/**
 * @fn int ingresoChar(char*, char*)
 * @brief This function: Allows us to verify that only letters can be entered.
 *
 * @param letra: This is what the user enters and we use it to verify by means of an if.
 * @param mensaje: This is the message we ask the user for.
 * @return todoOk: 1 or -1: "-1" if it was able to perform the function or "1" if it was not able to perform the function.
 */
int ingresoChar(char* letra, char* mensaje);
/**
 * @fn int ingresoCadena(char*, char*, char*, int)
 * @brief This function: Allows to request a string from the user, i.e. a string of chars,
 * which can be names, etc...
 *
 * @param cadena: It is the string of chars that is entered and saved in this variable string, to use it later.
 * @param mensaje: We ask the user to enter something.
 * @param mensajeError: We ask the user to re-enter something.
 * @param max: This is the maximum number of letters the user can input to the user.
 * @return todoOk: 1 or -1: "-1" if it was able to perform the function or "1" if it was not able to perform the function.
 */
int ingresoCadena(char* cadena, char* mensaje, char* mensajeError, int max);
/**
 * @fn int acomodarCadenaIngresada(char*)
 * @brief This function allows to accommodate an array of characters entered in an out-of-order way,
 * that is, with lowercase and uppercase letters randomly.
 *
 * @param cadena: It is the string of chars that is entered and saved in this variable string, to use it later.
 * @return todoOk: 1 or -1: "-1" if it was able to perform the function or "1" if it was not able to perform the function.
 */
int acomodarCadenaIngresada(char* cadena);
                            /**
 * @fn int validarSoloLetras(char*)
 * @brief This function allows to validate if what the user enters is an array of characters.
 *
 * @param cadena: It is the string of chars that is entered and saved in this variable string, to use it later.
 * @return todoOk: 1 or -1: "-1" if it was able to perform the function or "1" if it was not able to perform the function.
 */
int validarSoloLetras(char* cadena);
/**
 * @fn int ingresoLetrasNumeros(char*, char*, char*, int)
 * @brief This function allows you to randomly enter numbers and letters up to the maximum by assigning as a parameter.
 *
 * @param cadena: It is the string of chars that is entered and saved in this variable string and numbers, to use it later.
 * @param mensaje: We ask the user to enter something.
 * @param mensajeError: We ask the user to re-enter something.
 * @param max: This is the maximum number of letters the user can input to the user.
 * @return todoOk: 1 or -1: "-1" if it was able to perform the function or "1" if it was not able to perform the function.
 */
int ingresoLetrasNumeros(char* cadena, char* mensaje, char* mensajeError, int max);










































//Real Agustin 1°A, 11/5/2022
