#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class Start
{

//______________________________Global Variables___________________________	
	protected:
		
		int choice;
		string time , path , DisplayData;
		string dataHolder[5];
//____________________________End Global Variables__________________________
	
	public:
		Start()
		{
			//-------------------------------------Banner-------------------------------------------------
			cout <<"------------------------------------------------------------------------------"<<endl;
			cout <<"------------------------------------------------------------------------------"<<endl;
			cout <<"<<<<<<<<<<<<<<<<<<<<<<<<--Pharmacy MANAGEMENT SYSTEM-->>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
			cout <<"------------------------------------------------------------------------------"<<endl;
			cout <<"------------------------------------------------------------------------------"<<endl;
		}//end of constructor	


//-------------------------------------------Display Section-------------------------------------------------
		
		int mainDisplayPannel()
		{
			cout <<endl<<endl;
			cout <<"Please make a choice from the following given options."<<endl<<endl;
			cout <<"1 Customer Controls"<<endl<<"2 Stock operations"<<endl<<"3 to exit"<<endl<<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<"\n";	
			return choice;
		}//end of mainDisplayPanel Function
			
//-----------------------------------------End Display Section-----------------------------------------------
	
/********************************************************************************************************************************************/	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----------------Global Methods-------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/********************************************************************************************************************************************/



		//---------------------Delete Method----------------------
	
	void removeData(string deleteName)
	{
		
		if(remove(deleteName.c_str()) == 0)
		{				
			cout << "\nRecord Deleted Successfully !";
			Sleep(2000);
			system("cls");
		}//end of status chacking
		
		else
		{
			cout << "ERROR !! File is either broken or Not existing";
			system("pause");
		}
	}//end of removeData Function	
	
	
	//------------------------------display Function--------------------------------------
	void displayData(string itemName)
	{
		path = itemName;
		try
		{
			ifstream item(path.c_str() , ios::app);
			if(!item.is_open() || item.bad())
			{
				throw "Got no record against this query";
				system("pause");
			}//end of if
			cout <<"\n\n";
			while(getline(item , DisplayData))
			{
				cout << DisplayData <<endl;
			}//end of while
		}//end of try
		
		catch(const char * ch)
		{
			cout << ch;
		}//end of catch
	
		
	}//end of displayCustomer Function	
	
	//--------------------------end of display Function-----------------------------------
	
	
/********************************************************************************************************************************************/	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----------------End of Global Methods-------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/********************************************************************************************************************************************/	
		
};//end of Start Class



/*=========================================================================================================
=================================================Customer Section==========================================
===========================================================================================================
*/
	
class Customer : public Start{
	

	
	public:
		
	//-------------------------------------------Stock Display Section-------------------------------------------------
		
		int customerDisplayPannel()
		{
			cout <<endl<<endl;
			cout <<"Please make a choice from the following given options."<<endl<<endl;
			cout <<"1 New Entery"<<endl<<"2 Display Customer Data"<<endl<<"3 Delete records"<<endl<<"4 exit to Main"<<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<"\n";	
			return choice;
		}//end of customerDisplayPanel Function
			
	//-----------------------------------------End Stock Display Section-----------------------------------------------
		
	
		//----------------------------add new Customer---------------------------		
		
	void getCustomerData()
	{
			
		cout << "Enter Customer Name , Medicine , Catagory , Quantity and Price " <<endl;
		cout << "Medicine Customer Name : ";
		cin >> dataHolder[0];
		cout << "\nMedicine Name : ";
		cin >> dataHolder[1];
		cout << "\nCatagory(Tablet or Capsule) : ";
		cin >> dataHolder[2];
		cout << "\nQuantity : ";
		cin >> dataHolder[3];
		cout << "\nPrice : ";
		cin >> dataHolder[4];
	}//end of getData Function
	
	
	void saveCustomerData()
	{
		SYSTEMTIME time;
		GetLocalTime(&time);
		
		path = "Customers/"+ dataHolder[0] + ".txt"; 
		ofstream data;
		try
		{
			
			data.open(path.c_str() , ios::app);
			if(!data.is_open() || data.bad())
			{
				throw "ERROR ! Unable to open the file";
				system("pause");
			}//end of if(failure in openning file)
			
			data << "Customer Name : " + dataHolder[0] << "\nMedicine Name : " +  dataHolder[1] + "\nMedicine Catagory : " + dataHolder[2];
			data << "\n";
			data  << "Quantity : " + dataHolder[3] << "\nPrice : " + dataHolder[4];
			data << "\n";
			data << "Data :  "  << time.wDay << "/" << time.wMonth << "/" << time.wYear;
			
			cout << "\nRecord Added Successfully!"<<endl;
			data.close();
			Sleep(2000);
			 
		}//end of try
		
		catch(const char * ch)
		{
			cout << ch;
		}//end of catch
	}//end of saveData Function
	
	//----------------------end of adding new Customer------------------------------
	
	
	
};//end of Customer Class

/*=========================================================================================================
===============================================End Customer Section========================================
===========================================================================================================
*/

//---------------------------------------------------------------------------------------------------------------------------------------------------


/*=========================================================================================================
=================================================Stock Section=============================================
===========================================================================================================
*/

class Stock : public Start{
		
	
	public:
		
		//-------------------------------------------Stock Display Section-------------------------------------------------
		
		int stockDisplayPannel()
		{
			cout <<endl<<endl;
			cout <<"Please make a choice from the following given options."<<endl<<endl;
			cout <<"1 Add New Medicine"<<endl<<"2 Delete Medicine"<<endl<<"3 to Dipslay Medicine Records"<<endl<<"4 exit to Main"<<endl<<endl;
			cout <<"choice : ";
			cin >> choice;
			cout <<"\n";	
			return choice;
		}//end of stockDisplayPanel Function
			
		//-----------------------------------------End Stock Display Section-----------------------------------------------
		
		
		
	//----------------------------add new Medicine---------------------------		
		
	void getStockData()
	{
		cout << "Enter Medicine Name , Company , Catagory , Weightage and Price " <<endl;
		cout << "Medicine Name : ";
		cin >> dataHolder[0];
		cout << "\nCompany Name : ";
		cin >> dataHolder[1];
		cout << "\nCatagory(Tablet or Capsule) : ";
		cin >> dataHolder[2];
		cout << "\nWeightage : ";
		cin >> dataHolder[3];
		cout << "\nPrice : ";
		cin >> dataHolder[4];
	}//end of getData Function
	
	
	void saveStockData()
	{
		
		path = "Medicine/"+ dataHolder[0] + ".txt"; 
		ofstream data;
		try
		{
			//data.open("Medicine/brufin.txt" , ios::app);
			data.open(path.c_str() , ios::app);
			if(!data.is_open() || data.bad())
			{
				throw "ERROR ! Unable to open the file";
				system("pause");
			}//end of if(failure in openning file)
			
			data << "Medicine Name : " + dataHolder[0] << "\nCompany Name : " +  dataHolder[1] + "\nMedicine Catagory : " + dataHolder[2];
			data << "\n";
			data  << "Weightage : " + dataHolder[3] << "\nPrice : " + dataHolder[4];
			
			cout << "\nRecord Added Successfully!"<<endl;
			data.close();
			Sleep(2000);
			system("cls"); 
		}//end of try
		
		catch(const char * ch)
		{
			cout << ch;
		}//end of catch
	}//end of saveData Function;
	//----------------------end of adding new medicine------------------------------
	
	

};//end of Stock Class


/*=========================================================================================================
===============================================End of Stock Section========================================
===========================================================================================================
*/	



int main() 
{
	int choice;
	Start s;
	Customer cstmr;
	tag:
	system("cls");
	Stock stk;
	choice = s.mainDisplayPannel();
	
	if( choice == 1)
	{
		customerTag:
		system("cls");	
		Start s;	
		choice = cstmr.customerDisplayPannel();
		if(choice == 1)
		{
			cstmr.getCustomerData();
			cstmr.saveCustomerData();
			system("cls");
			goto customerTag;
		}//end od inner if(add Customer)
		
		else if(choice == 2)
		{
			string tmpCustomer;
			cout << "Enter The Name of Customer"<<endl;
			cout << "Input : ";
			cin >> tmpCustomer;
			tmpCustomer = "Customers/" + tmpCustomer + ".txt";
			cstmr.displayData(tmpCustomer);
			system("pause");
			system("cls");
			goto customerTag;
			
		}//end of display customer
		else if(choice == 3)
		{
			string tmpDel;
			cout << "Enter The Name of Customer to Delete";
			cout << "\n Customer Name : ";
			cin >> tmpDel;
			tmpDel = "Customers/" + tmpDel + ".txt";
			s.removeData(tmpDel);
			goto customerTag;
		}//end of else if(delete customer)
		else if(choice == 4)
		{
			goto tag;
		}//end of else if(exit to main)
		
		else
		{
			cout << "ERROR !!! Invalid Option Selected !";
		}
	}//end of if(customer)
	
	
	else if( choice == 2)
	{
		stockTag:
		system("cls");	
		Start s;
		choice = stk.stockDisplayPannel();
		if(choice == 1)
		{
			stk.getStockData();
			stk.saveStockData();
			goto stockTag;	
		}//end of inner if(add)
		else if(choice == 2)
		{
			string tmpDel;
			cout << "Enter The Name of Medicine to Delete";
			cout << "\n Medicine Name : ";
			cin >> tmpDel;
			tmpDel = "Medicine/" + tmpDel + ".txt";
			s.removeData(tmpDel);
			goto stockTag;
			
		}//end of inner if(delete)
		else if(choice == 3)
		{
			string tmpMedicine;
			cout << "Enter The Name of Medicine"<<endl;
			cout << "Input : ";
			cin >> tmpMedicine;
			tmpMedicine = "Medicine/" + tmpMedicine + ".txt";
			cstmr.displayData(tmpMedicine);
			system("pause");
			system("cls");
			goto stockTag;
			
		}//end of 
		else if(choice == 4)
		{
			goto tag;
		}//end of else if(exit to main)
		else
		{
			cout << "ERROR !!! Invalid Option Selected !";
			goto stockTag;
		}//end of else
		
	}//end of stock choice
	else if( choice == 3)
	{
		cout << "-----------: Good By :) :------------  "<<endl;
		Sleep(2000);
		exit(0);
	}//end of exit choice
	else
	{
		cout << "\nERROR !!! Invalid Choice Made !!!"<<endl;
		system("pause");
		goto tag;
	}
	return 0;
}
