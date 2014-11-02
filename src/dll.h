/*********************************************

    FinallyHome DLL "main" module headers

    copyright: KuszkiDevGroup

    license: GNU GPL v2

*********************************************/

#ifndef _FINALLYHOMESERVERDLL_MAIN_H
#define _FINALLYHOMESERVERDLL_MAIN_H

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec (dllimport)
#endif

typedef unsigned (*CALLBACK_PROC)(unsigned uDev, unsigned uSet); //!< Prototyp funkcji zwrotnej.

/*! \brief Rozpoczyna nasłuchiwanie.
 *  \param [in] uPort Numer portu.
 *  \param [in, out] fProc Funkcja obsługi zdarzeń.
 *  \return Kod błędu.
 *
 *  Tworzy wątek nasłuchujący i otwiera połączanie na wybranym porcie.
 */ unsigned DLLIMPORT start_Listening(unsigned uPort, void* fProc);

/*! \brief Ustala stan urządzenia.
 *  \param [in] uDev Numer urządzenia.
 *  \param [in] uSet Stan urządzenia.
 *
 *  Ustawia podane urządzenia na wybrany stan.
 */ void DLLIMPORT set_State(unsigned uDev, unsigned uSet);

/*! \brief Pobiera stan urządzenia.
 *  \param [in] uDev Numer urządzenia.
 *
 *  Sprawdza stan wybranego urządzenia. Jego wartość zostanie odczytana w wątku słuchającym i przekazana do funkcji zwrotnej ustalonej w trakcie włączania nasłuchiwania.
 */ void DLLIMPORT get_State(unsigned uDev);

/*! \brief Kończy nasłuchiwanie.
 *
 *  Kończy wątek i zamyka port.
 */ void DLLIMPORT stop_Listening(void);

#endif
