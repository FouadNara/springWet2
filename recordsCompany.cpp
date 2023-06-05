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

    //should delete previous recordNodes?

    try
    {
        recordNodesArr = new invertedNode*[number_of_records];

        for(int i=0;i<number_of_records;i++)
        {
            Record* record = new Record(i);
            recordNodesArr[i] = new invertedNode(record);
            invertedNode* tempNode = recordNodesArr[i];
            record->setRecordNode(tempNode);
        }
    }
    catch(const std::exception& e)
    {
        return StatusType::ALLOCATION_ERROR;
    }

    return StatusType :: SUCCESS;
}

StatusType RecordsCompany :: addCostumer(int c_id,int phone)
{
    if(c_id < 0 || phone < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    Customer* customer_ptr = customers.search(c_id); 
    if(customer_ptr)
    {
        return StatusType :: ALREADY_EXISTS;
    }

    Customer* CustomerToAdd;
    try
    {
        CustomerToAdd = new Customer(c_id, phone);
        customers.insert(c_id, CustomerToAdd);
    }
    catch(const std::exception& e)
    {
        return StatusType::ALLOCATION_ERROR;
    }
    
    return StatusType::SUCCESS;
}

Output_t<int> RecordsCompany :: getPhone(int c_id)
{
    if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }
    
    Customer* customer_ptr = customers.search(c_id); 
    if(!customer_ptr)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    int phone_number = customer_ptr->getPhoneNumber();

    return Output_t<int>(phone_number);
}

StatusType RecordsCompany :: makeMember(int c_id)
{
    if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    Customer* customer_ptr = customers.search(c_id); 

    if(!customer_ptr)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    if(customer_ptr->isMember())
    {
        return StatusType::ALREADY_EXISTS;
    }

    try
    {
        club_members_tree.insert(customer_ptr);
    }
    catch(const std::exception& e)
    {
        return StatusType::ALLOCATION_ERROR;
    }
    
    customer_ptr->makeMember();
    return StatusType :: SUCCESS;
} 

Output_t<bool> RecordsCompany ::isMember(int c_id)
{
   if( c_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    Customer* customer_ptr = customers.search(c_id); 

    if(!customer_ptr)
    {
        return StatusType :: DOESNT_EXISTS;
    }
    bool is_member = customer_ptr->isMember();

    return Output_t<bool>(is_member);
}
 

//TODO
StatusType RecordsCompany :: buyRecord(int c_id,int r_id)
{
    if( c_id < 0 || r_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    Customer* customer = customers.search(c_id);

    if((!customer) || r_id >= different_records_num)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    Record* record = recordNodesArr[r_id]->getRecord();
    if(customer->isMember())
    {
        int prevBuyers = record->getNumBuyers(); 
        customer->addMonthlyExpenses(100 + prevBuyers);
    }
    record->buy();

    return StatusType::SUCCESS;
}

//TODO
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
    Customer* customer_ptr = customers.search(c_id); 

    //customer doesn't exist
    if(!customer_ptr)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    //customer is not club member
    if(!customer_ptr->isMember())
    {
        return StatusType :: DOESNT_EXISTS;
    }

    //todo: function to calculate expenses (from AVLtree)
    int expenses;

    return Output_t<double>(expenses);
}

//TODO
StatusType RecordsCompany :: putOnTop(int r_id1,int r_id2)
{
    if( r_id1 < 0 || r_id2 < 0)
    {
        return StatusType :: INVALID_INPUT;
    }
    
    if( r_id1 >= different_records_num || r_id2 >= different_records_num)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    // if r_id1 and r_id2 same group
    {
        return StatusType :: FAILURE;
    }

    return StatusType :: SUCCESS;
}

//TODO
StatusType RecordsCompany :: getPlace(int r_id,int *column,int *height)
{
    if( !(column) || !(height) || r_id < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    if( r_id >= different_records_num)
    {
        return StatusType :: DOESNT_EXISTS;
    }

    return StatusType :: SUCCESS;
}
