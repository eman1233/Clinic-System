/**
*\brief           : This file has variables to admin and protoype of Admin funcation
*
*\file            : Admin.h
*
*\author          : Eman Megahed
*
*\date            : 3/1/2022
*
*\version         : 1.0.0
*
*\pre             :First initialize the system.
*
*\deprecated      : This file has variables to admin and protoype of Admin funcation
*
*/

#ifndef __Admin_h__
#define __Admin_h__
#include "std_types.h"

/**
*\struct Node_t Admin.h "C:\Users\CRIZMA123\Desktop\C_Project\PatientData_t.h"
*
*\b Name           :    PatientData_t
*
*\b Type           :    Struct
*
*\b Range          :    None
*
*\b Discription    :    This is the type of the data structure including the configuration set required for
*                       initializing patient data record
*/
typedef struct
{
  u8 *PatientName;                /**< patient Name element*/
  u8 PatientAge;                  /**< patient Age element*/
  u8 *PatientGender;              /**< patient Gender element*/
  u16 PatientId;                  /**< patient Gender Id*/
}PatientData_t;

/**
*
*\b Name           :    Patient
*
*\b Type           :    Enum
*
*\b Range          :
*                       AddNewPatientRecord
*
*                       EditPatientRecord
*
*                       ReserveSlot
*
*                       CancleReservation
*
*                       Admin_Exit
*
*\b Discription    :    Allow Selections of different Admin optiens
*
*/

typedef enum
{
    AddNewPatientRecord=1,        /**<Add New Patient Record Mode*/
    EditPatientRecord=2,           /**<Edit Patient Record Mode*/
    ReserveSlot=3,                 /**<Reserve Slot Mode*/
    CancleReservation=4,           /**<Cancle Reservation Mode*/
    Admin_Exit=5                    /**<Admin Exit Mode*/

}Patient;

/**
*
*\b Name           :    Slot
*
*\b Type           :    Enum
*
*\b Range          :
*                       _2pmTo2_30pm
*
*                       _2_30pmTo3pm
*
*                       _3pmTo3_30pm
*
*                       _4pmTo4_30pm
*
*                       _4_30pmTo5pm
*
*\b Discription    :    Allow Selections of different Slot optiens
*/

typedef enum
{
    _2pmTo2_30pm=0,            /**<2    pm : 2.30 pm */
    _2_30pmTo3pm=1,            /**<2.30 pm : 3 pm*/
    _3pmTo3_30pm=2,            /**<3    pm : 3.30 pm*/
    _4pmTo4_30pm=3,            /**<4    pm : 4.30 pm*/
    _4_30pmTo5pm=4             /**<4.30 pm : 5 pm*/
}Slot;

typedef enum
{
    NotAvailable=0,
    Available=1
}SlotAvailabilty;
typedef struct
{
    u8 id;
    SlotAvailabilty SlotExisting;
    u8 Time[15];

}SlotReserve_t;

/**
*   @name                   : Admin_AddNewDataPatient
*
*   \b Syntax               : void Admin_AddNewDataPatient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
*
*   \b Sync/Async           : Synchronous
*
*   \b Reentrancy           : Non Reentrant
*
*   @param [in]             : *NameOfPatient
*
*   @param [in]             : *GenderOfPatient
*
*   @param [in]             : *IdOfPatient
*
*   @param [in]             : *AgeOfPatient
*
*   @param [out]            : ErrorHappen
*
*   @return                 : ErrorHappen
*
*   @pre                    : void LinkedList_AddNode(NewData_t *NewData)
*
*   @pre                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @post                   : void Admin_EnterPassWord(void)
*
*   \b Description          : Add New Data Patient In admin mode
*
*   @see                    : void LinkedList_AddNode(NewData_t *NewData)
*
*   @see                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @see                    : void Admin_EnterPassWord(void)
*
*/

Error_t Admin_AddNewDataPatient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient);


/**
*   @name                   :  Admin_EditPaient
*
*   \b Syntax               : void Admin_EditPaient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
*
*   \b Sync/Async           : Synchronous
*
*   \b Reentrancy           : Reentrant
*
*   @param [in]             : *NameOfPatient
*
*   @param [in]             : *GenderOfPatient
*
*   @param [in]             : *IdOfPatient
*
*   @param [in]             : *AgeOfPatient
*
*   @param [out]            : ErrorHappen
*
*   @return                 : ErrorHappen
*
*   @pre                    : void LinkedList_EditNode(NewData_t *NewData)
*
*   @pre                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @post                   : void Admin_EnterPassWord(void)
*
*   \b Description          : Edit Data Patient In admin mode
*
*   @see                    : void LinkedList_EditNode(NewData_t *NewData)
*
*   @see                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @see                    : void Admin_EnterPassWord(void)
*
*/

Error_t Admin_EditPaient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient);

/**
*   @name                   :  Admin_ReserveASlotWithDoctor
*
*   \b Syntax               : void Admin_ReserveASlotWithDoctor(u8 *IdOfPatient,Slot SlotReservation)
*
*   \b Sync/Async           : Synchronous
*
*   \b Reentrancy           : Reentrant
*
*   @param [in]             : *IdOfPatient
*
*   @param [out]            : ErrorHappen
*
*   @return                 : ErrorHappen
*
*   @pre                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @post                   : void Admin_EnterPassWord(void)
*
*   \b Description          : Reserve slot with doctor In admin mode
*
*   @see                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @see                    : void Admin_EnterPassWord(void)
*
*/
Error_t Admin_ReserveASlotWithDoctor(u8 *IdOfPatient,Slot SlotReservation);

/**
*   @name                   : Admin_CancleReservation
*
*   \b Syntax               : void Admin_CancleReservation(u8 *IdOfPatient)
*
*   \b Sync/Async           : Synchronous
*
*   \b Reentrancy           : Reentrant
*
*   @param [in]             : *IdOfPatient
*
*   @param [out]            : ErrorHappen
*
*   @return                 : ErrorHappen
*
*   @pre                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @pre                    : void LnkedList_DelateNode(u8 pos)
*
*   @post                   : void Admin_EnterPassWord(void)
*
*   \b Description          : Edit Data Patient In admin mode
*
*   @see                    : int LinkedList_SearchNode(u8 IDsearch)
*
*   @see                    : void LnkedList_DelateNode(u8 pos)
*
*   @see                    : void Admin_EnterPassWord(void)
*
*/

Error_t Admin_CancleReservation(u8 *IdOfPatient);

/**
*   @name                   : Admin_EnterPassWord
*
*   \b Syntax               : void Admin_EnterPassWord(void)
*
*   \b Sync/Async           : Synchronous
*
*   \b Reentrancy           : Reentrant
*
*   @param [in]             : None
*
*   @param [out]            : None
*
*   @return                 : None
*
*   @pre                    : void Admin_AddNewDataPatient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
*
*   @pre                    : void Admin_EditPaient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
*
*   @pre                    : void Admin_ReserveASlotWithDoctor(u8 *IdOfPatient,Slot SlotReservation)
*
*   @pre                    : void Admin_CancleReservation(u8 *IdOfPatient)
*
*   @post                   : int main(void)
*
*   \b Description          : Edit Data Patient In admin mode
*
*   @see                    : void Admin_AddNewDataPatient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
*
*   @see                    : void Admin_EditPaient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
*
*   @see                    : void Admin_ReserveASlotWithDoctor(u8 *IdOfPatient,Slot SlotReservation)
*
*   @see                    : void Admin_CancleReservation(u8 *IdOfPatient)
*
*   @see                   : int main(void)
*
*/

void Admin_EnterPassWord(void);
#endif // __Admin_h__
