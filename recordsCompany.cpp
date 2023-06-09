#include "recordsCompany.h"

RecordsCompany :: RecordsCompany() = default;

RecordsCompany :: ~RecordsCompany()
{
   

    club_members_tree.treeClear(); //deletes only nodes
    customers.deleteHash(); //deletes all customers
    
     // ymkn lazim n3ml helper destructor ym7a el array and records 3shan nst3mlo b new month?
    // bnf3 hek bs 3shan mykonsh she5bol code
    for(int i=0;i<different_records_num;i++)
    {
        invertedNode* curNode = recordNodesArr[i];
        Record* curRecord = curNode->getRecord();
        delete curRecord;
        delete curNode;
    }
    delete[] recordNodesArr;
}

StatusType RecordsCompany :: newMonth(int *records_stocks,int number_of_records)
{
    if( number_of_records < 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    //should delete previous recordNodes? i think yes

    for(int i=0;i<different_records_num;i++)
    {
        invertedNode* curNode = recordNodesArr[i];
        Record* curRecord = curNode->getRecord();
        delete curRecord;
        delete curNode;
    }

    delete[] recordNodesArr;

    try
    {
        recordNodesArr = new invertedNode*[number_of_records];

        for(int i=0; i < number_of_records; i++)
        {
            Record* record = new Record(i,records_stocks[i]);
            recordNodesArr[i] = new invertedNode(record);
            invertedNode* tempNode = recordNodesArr[i];
            record->setRecordNode(tempNode);
        }
    }
    catch(const std::exception& e)
    {
        return StatusType::ALLOCATION_ERROR;
    }

    club_members_tree.inOrder(ResetClubMembers());

    different_records_num = number_of_records;

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

    // ymkn konna mn2dr kol el astor belfunction l7d hon b RecordsCompany :: isMember(int c_id)
    // l2no same returned values
    try
    {
        club_members_tree.insert(customer_ptr);
    }
    catch(const std::exception& e)
    {
        return StatusType::ALLOCATION_ERROR;
    }
    
    customer_ptr->makeMember();

    // we should update undeserved_prize here
    //adding undeserved prize:
    double undeservedPrize = club_members_tree.calcExtra(customer_ptr);
    customer_ptr->setUndeservedPrize(undeservedPrize);
    
    return StatusType :: SUCCESS;
} 

Output_t<bool> RecordsCompany :: isMember(int c_id)
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

StatusType RecordsCompany :: addPrize(int c_id1,int c_id2,double amount)
{
    if( c_id1 < 0 || c_id2 < c_id1 || amount <= 0)
    {
        return StatusType :: INVALID_INPUT;
    }

    //interval ids
    int id1=0 , id2=0; 
    
    AVLNode* customer = club_members_tree.find_by_id(c_id1);
    //if c_id1 exists in tree
    if(customer)
    {
        id1 = c_id1;
    }
    else
    {
        AVLNode* customerSuccessor = club_members_tree.findSuccessor(c_id1);
        id1 = customerSuccessor->data->getCustomerID();
    }
    id2 = club_members_tree.findPredecessor(c_id2)->data->getCustomerID();
    //////
    club_members_tree.addExtra(id2, amount);
    club_members_tree.addExtra(id1, -amount);

    //addPrize is complete, i just need to check mkre ktse later.
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
    double prizeAmount = club_members_tree.calcExtra(customer_ptr);
    double undeservedPrize = customer_ptr->getUndeservedPrize();

    //check
    double expenses = customer_ptr->getExpenses() - prizeAmount + undeservedPrize;

    return Output_t<double>(expenses);
}


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

    invertedNode* first_record = recordNodesArr[r_id1];
    invertedNode* sec_record = recordNodesArr[r_id2];

    invertedNode* first_parent = first_record->findRoot();
    invertedNode* sec_parent = sec_record->findRoot();

    if(first_parent == sec_parent)
    {
        return StatusType :: FAILURE;
    }

    int first_size = first_parent->getTotalNodes();
    int sec_size = sec_parent->getTotalNodes();

    invertedNode* captain;
	invertedNode* exCaptain;

    int captain_new_height;
    int exCaptain_new_height;

    if(first_size > sec_size)
    {
        captain = first_parent;
        exCaptain = sec_parent;
        
        captain->setMinHeightID(exCaptain->getMinHeightID());

        captain_new_height = exCaptain->getTotalRecords() + captain->getHeight();
        exCaptain_new_height = exCaptain->getHeight() - captain_new_height;

    }
    else
    {
        captain = sec_parent;
        exCaptain = first_parent;

        captain_new_height = captain->getHeight();
        exCaptain_new_height = exCaptain->getHeight() + captain->getTotalRecords() - captain_new_height;
    }

    exCaptain->setParent(captain);
    captain->setTotalNodes(captain->getTotalNodes() + exCaptain->getTotalNodes());
    captain->setTotalRecords(captain->getTotalRecords() + exCaptain->getTotalRecords());


    captain->setHeight(captain_new_height);
    exCaptain->setHeight(exCaptain_new_height);

    return StatusType :: SUCCESS;
}

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
    invertedNode* record_node = recordNodesArr[r_id];
    invertedNode* root = record_node->findRoot();

    *column = root->getColumn();
    *height = root->getHeight() + record_node->getHeight();


    return StatusType :: SUCCESS;
}
