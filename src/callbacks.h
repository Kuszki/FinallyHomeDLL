/*********************************************

    FinallyHome DLL "callback" module headers

    copyright: KuszkiDevGroup

    license: GNU GPL v2

*********************************************/

#ifndef _FINALLYHOMESERVERDLL_CALLBACK_H
#define _FINALLYHOMESERVERDLL_CALLBACK_H

/*! \brief Funkcja wątku nasłuchiwania.
 *  \param [in] pvArgs Argumenty.
 *  \return Kod błędu.
 *
 *  Odpowiada za nasłuchiwanie połączeń.
 */ DWORD WINAPI ThreadProc(LPVOID pvArgs);

/*! \brief Pakiet danych.
 *
 *  Struktura odpowiadająca za przechowywanie danych potrzebnych do nawiązania komunikacji.
 */ typedef struct {

	 unsigned char cDev; //!< Identyfikator urządzenia.
	 unsigned char cSet; //!< Stan urządzenia.

} DATA_PACK, *LPDATA_PACK;

#endif
