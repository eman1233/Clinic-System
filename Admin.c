/**
*\brief           : Implementation funcation in admin mode
*
*\file            : Admin.c
*
*\author          : Eman Megahed
*
*\date            : 3/1/2022
*
*\version         : 1.0.0
*
*\pre             :LinkedList.h std_types.h Admin.h Admin_config.h
*
*\deprecated      : This file implementation of prototype of funcations in Admin.h
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "LinkedList.h"
#include "Admin.h"
#include "Admin_config.h"
#include "main.h"
/**
*@addtogroup globalVariable
*
*@{
*/
/**
*\b Description : i is variable is increasing when adding new patient with new id
*
*/
int i;
/**
*\b Description : pos is variable to search id exist or not
*
*/
int pos;

/**
*\b Description : SlotsArr is an array object from Slot to make it is easy for admin to select suitable reservation for patient
*
*/
Slot SlotsArr[5];

/**
*\b Description : SlotReserve is an array object from SlotReserve_t this array consist 5 element from struct objects for each slot
*
*/
SlotReserve_t  SlotReserve[5]={{0,Available,"2 pm to 2:30 pm"},
                               {0,Available,"2:30 pm to 3 pm"},
                               {0,Available,"3 pm to 3:30 pm"},
                               {0,Available,"4 pm to 4:30 pm"},
                               {0,Available,"4:30 pm to 5 pm"}};

/**
*@}
*/

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
Error_t Admin_AddNewDataPatient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
{
   /**assign this variable to Defult which no error*/
    Error_t ErrorHappen=No_Error;

    /**if NewData assign to null*/
    if(NameOfPatient == NULL || GenderOfPatient == NULL || IdOfPatient == NULL || AgeOfPatient == NULL)
    {
        /**ErrorHappen will assign to error is PointerEqualNull*/
        ErrorHappen=PointerEqualNull;
    }

    /** else */
    else
    {
       /**this output to indicate the admin enter patient name*/
      printf("Enter Name =");

      /**Input name of patient which admin entered*/
      scanf("%s",&(*NameOfPatient));

      /**this output to indicate the admin enter patient age*/
      printf("Enter Age =");

      /**Input age of patient which admin entered*/
      scanf("%d",&(*AgeOfPatient));

      /**this output to indicate the admin enter patient gender*/
      printf("Enter Gender =");

      /**Input gender of patient which admin entered*/
      scanf("%s",&(*GenderOfPatient));

      /**this output to indicate the admin enter patient id*/
      printf("Enter Id =");

      /**Input id of patient which admin entered*/
      scanf("%d",&(*IdOfPatient));

      /**make new object NewData from NewData_t contain Data entered from admin and put it into NewData elements*/
      NewData_t NewData={.NewName=NameOfPatient,.NewAge=*AgeOfPatient,.NewGender=GenderOfPatient,.NewId=*IdOfPatient};

      /**if i assign to zero this is the first patient enter to system*/
      if(i==0)
      {
            /**add new data to new patient and using LinkedList_AddNode method to add new patient*/
            LinkedList_AddNode(&NewData);

            /**this output to indicate this patient not exist*/
            printf("############ID Not existed############\n");
      }
      /**else if this not the first patient*/
      else
      {
          /**take the positon of this person id and check of this id exist or not*/
          pos=LinkedList_SearchNode(*IdOfPatient);

          /**Infinite loop until break from it if new id entered*/
          while(1)
          {
                /**check of the IDNotExist*/
                if(pos==IDNotExist)
                {
                    /**this output to indicate this patient not exist*/
                    printf("############ID Not existed############\n");

                    /**assign new id of patient to NewId element of NewData object*/
                    NewData.NewId=*IdOfPatient;

                    /**add new data to new patient and using LinkedList_AddNode method to add new patient*/
                    LinkedList_AddNode(&NewData);

                    /**this window  will be terminated*/
                    break;
                }

                /**if this id existed*/
                else
                {
                    /**this output to indicate this patient exist*/
                    printf("##############ID existed#################\n");

                    /**make position not exist*/
                    pos=IDNotExist;

                    /**this output to indicate enter another id because the input id exist*/
                    printf("Please Enter another ID :");

                    /**Input id of patient which admin entered*/
                    scanf("%d",&(*IdOfPatient));

                    /**assign new id of patient to NewId element of NewData object*/
                    NewData.NewId=*IdOfPatient;
                 }
                 /**increase counter of patient entered */
                 i++;

            }
       }
       /**increase counter of patient entered */
       i++;
    }

    /**return which error happen*/
    return ErrorHappen;
}

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

Error_t Admin_EditPaient(u8 *NameOfPatient,u8 *GenderOfPatient,u16 *IdOfPatient,u8 *AgeOfPatient)
{
    /**assign this variable to Defult which no error*/
    Error_t ErrorHappen=No_Error;

    /**if NewData assign to null*/
    if(NameOfPatient == NULL || GenderOfPatient == NULL || IdOfPatient == NULL || AgeOfPatient == NULL)
    {
        /**ErrorHappen will assign to error is PointerEqualNull*/
        ErrorHappen=PointerEqualNull;
    }

    /** else */
    else
    {
        /**this output indicate to admin enter patient id which admin need to edit*/
        printf("Enter ID Which you want to Edit:");

        /**Input id of patient which admin edited*/
        scanf("%d",IdOfPatient);

        /**make new object NewData from NewData_t contain Data edit from admin and put it into NewData elements*/
        NewData_t NewData={.NewName=NameOfPatient,.NewAge=*AgeOfPatient,.NewGender=GenderOfPatient};

        /**take the positon of this person id and check of this id exist or not*/
        pos=LinkedList_SearchNode(*IdOfPatient);

        /**check of the IDNotExist*/
        if(pos == IDNotExist)
        {
            /**Indicate this id not exist*/
            printf("############ID Not existed############\n");

        }

        /**if this id existed*/
        else
        {

            /**Indicate this id exist*/
            printf("##############ID existed#################\n");

            /**Indicate to admin to enter new name of patient*/
            printf("Enter New Name =");

            /**Input name of patient which admin edit*/
            scanf("%s",NameOfPatient);

            /**Indicate to admin to enter new age of patient*/
            printf("Enter New Age =");

            /**Input age of patient which admin edit*/
            scanf("%d",AgeOfPatient);

            /**Indicate to admin to enter new gender of patient*/
            printf("Enter New Gender =");

            /**Input gender of patient which admin edit*/
            scanf("%s",GenderOfPatient);

            /**edit new data to new patient and using LinkedList_EditNode method to edit new patient*/
            LinkedList_EditNode(&NewData);

            /**indicate to admin patient id which data edited*/
            printf("You Edit %d this patient\n",*IdOfPatient);
        }
    }

    /**return which error happen*/
    return ErrorHappen;
}

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


Error_t Admin_ReserveASlotWithDoctor(u8 *IdOfPatient,Slot SlotReservation)
{
    /**assign this variable to Defult which no error*/
    Error_t ErrorHappen=No_Error;

    /**if IdOfPatient assign to null*/
    if(IdOfPatient==NULL)
    {
        /**ErrorHappen will assign to error is PointerEqualNull*/
        ErrorHappen=PointerEqualNull;
    }

    /**if SlotReservation greater than NumOfSlots*/
    else if(SlotReservation>NumOfSlots)
    {

        /**ErrorHappen will assign to error is ErrorInSlotNum*/
        ErrorHappen=ErrorInSlotNum;
    }

    /**If no error*/
    else
    {

        /**This output indicate to admin Available Slot*/
        printf("Available Slot:\n");

        /**Loop until Slots finish*/
        for(int i=0;i<=NumOfSlots;i++)
        {

            /**if this slot not reserved*/
            if(SlotReserve[i].SlotExisting==Available)
            {

                /**this out put sring of avaiable slot*/
                printf("%d-%s\n",i,SlotReserve[i].Time);
            }

            /**else this slot reserved*/
            else
            {

                /**ignore this value in this iteration*/
                continue;
            }
        }

        /**this output show to admin to enter  time which paticent want*/
        printf("Enter Time which patient want:");

        /**Input slot which patient want*/
        scanf("%d",&SlotReservation);

        /**this output show to admin to enter  patient id*/
        printf("Enter Patient ID who want to reserve:");

        /**Input id of patient which admin entered*/
        scanf("%d",IdOfPatient);

        /**take the positon of this person id and check of this id exist or not*/
        pos=LinkedList_SearchNode(*IdOfPatient);

        /**check of the IDNotExist*/
        if(pos == IDNotExist)
        {
            /**Indicate this id not exist*/
            printf("############ID Not existed############\n");
        }

        /**check of the IDExist*/
        else
        {
            /**Indicate this id exist*/
            printf("##############ID existed#################\n");

            /**make this slot not available which patient reserved*/
            SlotReserve[SlotReservation].SlotExisting=NotAvailable;

            /**put this IdOfPatient in this SlotReserve[SlotReservation].id*/
            SlotReserve[SlotReservation].id=(*IdOfPatient);

            /**Indicate id reserved*/
            printf("%d\n",SlotReserve[SlotReservation].id);

            /**Indicate time slot reserved*/
            printf("%s\n",SlotReserve[SlotReservation].Time);

            /**Put this slot in in  SlotsArr[*IdOfPatient]*/
            SlotsArr[*IdOfPatient]=SlotReservation;
        }

    }

    /**return which error happen*/
    return ErrorHappen;

}

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

Error_t Admin_CancleReservation(u8 *IdOfPatient)
{
    /**assign this variable to Defult which no error*/
    Error_t ErrorHappen=No_Error;

    /**if IdOfPatient assign to null*/
    if(IdOfPatient==NULL)
    {
        /**ErrorHappen will assign to error is PointerEqualNull*/
        ErrorHappen=PointerEqualNull;
    }

    /**If no error*/
    else
    {
        /**This output indicate to admin to enter patient id who want to cancle Reservation*/
        printf("Enter Patient ID who want to Cancle Reseravation:");

        /**Input id of patient which admin entered*/
        scanf("%d",IdOfPatient);

        /**take the positon of this person id and check of this id exist or not*/
        pos=LinkedList_SearchNode(*IdOfPatient);

        /**check of the IDNotExist*/
        if(pos == IDNotExist)
        {
            /**Indicate this id not exist*/
            printf("############ID Not existed############\n");
        }

        /**check of the IDExist*/
        else
        {
            /**Indicate this id exist*/
            printf("##############ID existed#################\n");

            /**Return id available again*/
            SlotReserve[SlotsArr[*IdOfPatient]].id=(*IdOfPatient);

            /**Put time slot which cancled avaliable again*/
            SlotReserve[SlotsArr[*IdOfPatient]].SlotExisting=Available;

            /**Indicate id cancled*/
            printf("%d\n",SlotReserve[SlotsArr[*IdOfPatient]].id);

            /**Indicate slots cancled*/
            printf("%s\n",SlotReserve[SlotsArr[*IdOfPatient]].Time);
        }
    }

    /**return which error happen*/
    return ErrorHappen;
}

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

void Admin_EnterPassWord(void)
{
    /**declare static array of char contain MaxNumOfNameChar element is called NameOfPatient*/
    static char NameOfPatient[MaxNumOfNameChar];

    /**declare static array of char contain MaxNumOfGenderChar element is called GenderOfPatient*/
    static char GenderOfPatient[MaxNumOfGenderChar];

    /**declare static element of int is called IdOfPatient*/
    static int IdOfPatient=0;

    /**declare static element of int is called AgeOfPatient*/
    static int AgeOfPatient=0;

    /**declare element of NewData_t is called NewData*/
    NewData_t NewData;

    /**declare static element of Patient is called FeatureChoose*/
    static Patient FeatureChoose;

    /**declare static element of Slot is called SlotReservation*/
    static Slot SlotReservation;


    /**declare element of u8 is called LoopCounter*/
    u8 LoopCounter=0;

    /**declare element of u32 is called PasswordEntered*/
    u32 PasswordEntered;

    /**this output indicate to admin to enter Password*/
    printf("Enter Password :");

    /**Enter Password from admin*/
    scanf("%d",&PasswordEntered);

    /**Check PasswordEntered not equal normal Password */
    if(PasswordEntered!=NormalPassword)
    {
        /**Loop until LoopCounter less than NumOfTrial*/
        while(LoopCounter<NumOfTrial)
        {
           /**this output indicate to admin to this Password false*/
           printf("Password false\n");

           /**this output indicate to admin to Enter passward when is false*/
           printf("Enter Password again:");

           /**Enter Password again from admin when is false*/
           scanf("%d",&PasswordEntered);

           /**check if PasswordEntered  equal to NormalPassword*/
           if(PasswordEntered==NormalPassword)
           {
               /**this output indicate to admin to passward correct*/
               printf("Password Ok\n");

               /**Infinite loop terminate when admin wants to exist*/
               while(1)
               {
                  /**this output indicate to admin to show options to admin*/
                  printf("Feature you Need:\n1-To Add New Patient\n2-To Edit Patient Existed\n3-To Reserve slot with doctor\n4-T Cancel Reservation For Patient\n5-To Exit\n");

                  /**this output indicate to admin to Enter suitable feature*/
                  printf("Enter Feature:");

                  /**Input from admin to choose feature which ho want*/
                  scanf("%d",&FeatureChoose);

                  /**check if FeatureChoose equal to AddNewPatientRecord*/
                  if(FeatureChoose==AddNewPatientRecord)
                  {
                     /**this output indicate to admin to add new patient*/
                     printf("You are in Add New patient\n");

                     /**call Admin_AddNewDataPatient fun to add new patient with new data*/
                     Admin_AddNewDataPatient(NameOfPatient,GenderOfPatient,&IdOfPatient,&AgeOfPatient);
                  }

                  /**check if FeatureChoose equal to EditPatientRecord*/
                  if(FeatureChoose==EditPatientRecord)
                  {
                    /**this output indicate to admin to edit patient record*/
                     printf("You are in Edit patient record\n");

                     /**call Admin_EditPaient fun to edit exist patient with new data*/
                     Admin_EditPaient(NameOfPatient,GenderOfPatient,&IdOfPatient,&AgeOfPatient);
                  }

                  /**check if FeatureChoose equal to ReserveSlot*/
                  if(FeatureChoose==ReserveSlot)
                  {
                      /**this output indicate to admin to reserve slot to id*/
                      printf("You are in Reserve a slot with the doctor\n");

                      /**call Admin_ReserveASlotWithDoctor fun to reserve slot to exist Id Of Patient*/
                      Admin_ReserveASlotWithDoctor(&IdOfPatient,SlotReservation);
                  }

                  /**check if FeatureChoose equal to CancleReservation*/
                  if(FeatureChoose==CancleReservation)
                  {
                      /**this output indicate to admin to cancel reservation*/
                      printf("You are in Cancel reservation\n");

                      /**call Admin_CancleReservation fun to Cancle Reservation to exist Id Of Patient*/
                      Admin_CancleReservation(&IdOfPatient);
                  }

                  /**check if FeatureChoose equal to Admin_Exit*/
                  if(FeatureChoose==Admin_Exit)
                  {
                      /**this output indicate to admin you exist from this window*/
                      printf("You are exit\n");

                      /**This window will terminated*/
                      break;
                  }
               }
               /**This window will terminated when admin enter new password okay*/
               break;
           }

           /**increament counter if password false*/
           LoopCounter++;
        }

        /**check if LoopCounter equal to NumOfTrial*/
        if(LoopCounter==NumOfTrial)
        {
            /**This indicate to admin you have no trails to enter password more*/
            printf("You can not Enter More\n");
        }
    }
    else
    {
         /**This indicate to admin entering password ok*/
        printf("Password Ok\n");
        while(1)
        {
            /**this output indicate to admin to show options to admin*/
            printf("Feature you Need:\n1-To Add New Patient\n2-To Edit Patient Existed\n3-To Reserve slot with doctor\n4-T Cancel Reservation For Patient\n5-To Exit\n");

            /**this output indicate to admin to Enter suitable feature*/
            printf("Enter Feature:");

            /**Input from admin to choose feature which ho want*/
            scanf("%d",&FeatureChoose);

            /**check if FeatureChoose equal to AddNewPatientRecord*/
            if(FeatureChoose==AddNewPatientRecord)
            {
                /**this output indicate to admin to add new patient*/
                printf("You are in Add New patient\n");

                /**call Admin_AddNewDataPatient fun to add new patient with new data*/
                Admin_AddNewDataPatient(NameOfPatient,GenderOfPatient,&IdOfPatient,&AgeOfPatient);
            }

            /**check if FeatureChoose equal to EditPatientRecord*/
            if(FeatureChoose==EditPatientRecord)
            {
                /**this output indicate to admin to edit patient record*/
                printf("You are in Edit patient record\n");

                /**call Admin_EditPaient fun to edit exist patient with new data*/
                Admin_EditPaient(NameOfPatient,GenderOfPatient,&IdOfPatient,&AgeOfPatient);
            }

            /**check if FeatureChoose equal to ReserveSlot*/
            if(FeatureChoose==ReserveSlot)
            {
                /**this output indicate to admin to reserve slot to id*/
                printf("You are in Reserve a slot with the doctor\n");

                /**call Admin_ReserveASlotWithDoctor fun to reserve slot to exist Id Of Patient*/
                Admin_ReserveASlotWithDoctor(&IdOfPatient,SlotReservation);
            }

            /**check if FeatureChoose equal to CancleReservation*/
            if(FeatureChoose==CancleReservation)
            {
                /**this output indicate to admin to cancel reservation*/
                printf("You are in Cancel reservation\n");

                /**call Admin_CancleReservation fun to Cancle Reservation to exist Id Of Patient*/
                Admin_CancleReservation(&IdOfPatient);
            }

            /**check if FeatureChoose equal to Admin_Exit*/
            if(FeatureChoose==Admin_Exit)
            {
                /**this output indicate to admin you exist from this window*/
                printf("You are exit\n");

                /**This window will terminated*/
                break;
            }
        }
    }
}



