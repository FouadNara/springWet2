#include "recordsCompany.h"

RecordsCompany :: RecordsCompany()
{

}

RecordsCompany :: ~RecordsCompany()
{
    
}

StatusType RecordsCompany :: newMonth(int *records_stocks,int number_of_records)
{
    if( number_of_records < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    //to add : alloctaion error case

    return StatusType :: SUCCESS;
}

StatusType RecordsCompany :: addCostumer(int c_id,int phone)
{
    if(c_id < 0 || phone < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    // if c_id already exists
    {
        return StatusType :: ALREADY_EXISTS;
    }
    //to add : alloctaion error case
    return StatusType::SUCCESS;
}

Output_t<int> RecordsCompany :: getPhone(int c_id)
{
    if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    // to add: c_id does not exit already
    {
        return StatusType :: DOESNT_EXISTS;
    }
    int phone_number;

    return Output_t<int>(phone_number);
}

StatusType RecordsCompany :: makeMember(int c_id)
{
    if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }
    //to add : if c_id does not exit 
    {
        return StatusType :: DOESNT_EXISTS;
    }
    //to add : alloctaion error case
    return StatusType :: SUCCESS;
} 

Output_t<bool> RecordsCompany ::isMember(int c_id)
{
   if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    // to add: c_id does not exit already
    {
        return StatusType :: DOESNT_EXISTS;
    }
    bool is_member;

    return Output_t<bool>(is_member);
}

StatusType RecordsCompany :: buyRecord(int c_id,int r_id)
{
    if( c_id < 0 || r_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    if( r_id >= different_records_num)
    {
        // or c_id does not exist
        return StatusType :: DOESNT_EXISTS;
    }

    return StatusType::SUCCESS;
}
StatusType RecordsCompany :: addPrize(int c_id1,int c_id2,double amount)
{
    if( c_id1 < 0 || c_id2 < c_id1 || amount <= 0)
    {
        return StatusType :: INVALID_INPUT;
    }
    return StatusType :: SUCCESS;
} 

Output_t<double> RecordsCompany :: getExpenses(int c_id)
{
    if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    // to add: c_id is not member
    {
        return StatusType :: DOESNT_EXISTS;
    }
    int expenses;

    return Output_t<double>(expenses);
}

StatusType RecordsCompany :: putOnTop(int r_id1,int r_id2)
{
    if( r_id1 < 0 || r_id2 < 0)
    {
        return StatusType :: INVALID_INPUT;
    }
    
    if( r_id1 > different_records_num || r_id2 > different_records_num)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    // if r_id1 or r_id2 already exit 
    {
        return StatusType :: FAILURE;
    }

    return StatusType :: SUCCESS;
}

StatusType RecordsCompany :: getPlace(int r_id,int *column,int *hight) // leesh heek katben hight :((( n3'yerha wla mmno3?
{
    if( !(column) || !(hight) || r_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    if( r_id >= different_records_num)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    return StatusType :: SUCCESS;
}
