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
    
}

StatusType RecordsCompany :: makeMember(int c_id)
{
    if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }
    //if c_id does not exit 
    {
        return StatusType :: DOESNT_EXISTS;
    }
    
    return StatusType :: SUCCESS;
} 

Output_t<bool> RecordsCompany ::isMember(int c_id)
{

}

StatusType RecordsCompany :: buyRecord(int c_id,int r_id)
{
    return StatusType::SUCCESS;
}
StatusType RecordsCompany :: addPrize(int c_id1,int c_id2,double amount)
{

    return StatusType::SUCCESS;
} 

Output_t<double> RecordsCompany :: getExpenses(int c_id)
{

}

StatusType RecordsCompany :: putOnTop(int r_id1,int r_id2)
{
    return StatusType::SUCCESS;
}

StatusType RecordsCompany :: getPlace(int r_id,int *column,int *hight)
{
    return StatusType::SUCCESS;
}
