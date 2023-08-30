#include<iostream>
#include<string>
#include <fstream>
#include<string.h> 
#include <stdlib.h>
#include<ctime>
using namespace std;
int indeex=-1;
int doctorindex=-1;
bool found;
int size1;
struct doctors{
    string dID;
    char  drname[50];
    char specialty[50];
};
struct med{
    char illness[50];
    char pmedicine[50];
    int dose;
};
struct patient
{
string id;
int age;
char Pname[50];
med medicine;
};

void savedata(patient patientrecored)
{
	string line;
	string fileName="Input.txt";
  ofstream myfile (fileName.c_str(),std::ios::app);
  if (myfile.is_open())
  {
    myfile<<patientrecored.id <<endl;
    myfile<<patientrecored.Pname <<endl;
    myfile<<patientrecored.age <<endl;
    myfile<<patientrecored.medicine.illness<<endl;
    myfile<<patientrecored.medicine.pmedicine<<endl;
    myfile<<patientrecored.medicine.dose<<endl;

    cout<<"The information was saved Successfully  .. "<<endl;
    myfile.close();
  }
  else cout << "Unable to open file, the file does not exists"; 

}
 
 void adddrname(doctors dr[]){
 doctorindex++;
     cout << "Enter doctor name: ";
    cin >> dr[doctorindex].drname;
    cout << "Enter doctor ID number: ";
    cin >> dr[doctorindex].dID;
    cout << "Enter doctor specialty: ";
    cin >> dr[doctorindex].specialty;
    cout<<"**doctor has been added** ";
     
 }
 
void add(patient arr[])
{
    indeex++;
    cout <<"enter the informations:"<< endl;
    cout<<"Patient name:";
    cin>>arr[indeex].Pname;
    cout<<"patient ID number:";
    cin>>arr[indeex].id;
    cout<<"Age *only integer numbers please* :";
    cin>>arr[indeex].age;
    cout<<"Illness:";
    cin>>arr[indeex].medicine.illness;
    cout<<"Medicine:";
    cin>>arr[indeex].medicine.pmedicine;
    cout<<"how many doses you have taken? *only numbers allowed* : ";
    cin>>arr[indeex].medicine.dose;
    cout<<"**patient has been added**";
}
void delete_rec(patient patientrecored[], string id)
{
        found = false;
    for (int i = 0 ; i <= indeex; i++)
    {
        if(id == patientrecored[i].id)
		{
            for (int j = i ; j < indeex ; j++)
                patientrecored[i] = patientrecored[i + 1];
            indeex--;
            cout << "*patient has been deleted*\n";
            found = true;
            break;
        }
    }
    
    if (!found)
        cout << "patient was not found!\n";
    
}

void update_rec( patient pati_rec[], string ID )
{
found=false;
for (int i = 0 ; i <= indeex ; i++)
{
    if(ID == pati_rec[i].id)
    {
        cout << "Enter new patinet name: ";
        cin >> pati_rec[i].Pname;
        cout << "**Patient name updated** "<<endl;
        cout<<"Enter new age for patient:";
        cin>>pati_rec[i].age;
        cout<<" Enter new illness name: ";
        cin>>pati_rec[i].medicine.illness;
        cout<<"**Patient illness updated**"<<endl;
        cout<<" Enter new pmedicine: ";
        cin>>pati_rec[i].medicine.pmedicine;
        cout<<"**Patient medicine updated**"<<endl;
        cout<<" Enter how many dose?: ";
        cin>>pati_rec[i].medicine.dose;
        cout<<"*patient has been updated**";
        found=true ;
        break;
        
    }
}
if (!found)
cout << "Patinet is not found\n";
}
 

void search_doc(doctors doc[],string id){
    found=false;
        for (int i = 0 ; i <= doctorindex ; i++)
        {
            if(id == doc[i].dID)
            {
                cout<<"docter name :"<<doc[i].drname<<endl;
                cout<<"doctor  id :"<<doc[i].dID<<endl;
                cout<<"doctor specialty:"<<doc[i].specialty<<endl;
                found=true;
                break;
            }
        }
        if (!found)
        cout << "doctor not found\n";
    
    
    
    
}
void  search_patientonly(patient patientrecored[], string id){
    found=false;
        for (int i = 0 ; i <= indeex ; i++)
        {
            if(id == patientrecored[i].id)
            {
                found=true;
                break;
            }
        }        if (!found)
                   cout<<"paient isn't found ";
    if(found)
        cout<<"paient is found ";
}
void displayDOC( doctors doctor[]){
    for (int i = 0 ; i <= doctorindex ; i++)
    {
            cout<<" the docotr ["<<i+1<<"] name is :"<<doctor[i].drname<<endl <<" doctor ID is: "<<doctor[i].dID<<endl<<"doctor specialty: "<<doctor[i].specialty<<endl;}
        
            
    }
void displayPA( patient patient[]){
    for (int i=0; i<=indeex; i++){
       
       
            cout<<" patient ["<<i+1<<"] name is: "<<patient[i].Pname<<endl<<" patient id is: "<<patient[i].id<<endl<<"patient age is: "<<patient[i].age<<endl<<"patient medicine name: "<<patient[i].medicine.pmedicine<<endl<<"patient illness: "<<patient[i].medicine.illness<<endl<<"patient dose: "<<patient[i].medicine.dose<<endl;}
        
    }
    
          
void search_patient_withcout(patient patientrecored[], string id){
    found=false;
        for (int i = 0 ; i <= indeex ; i++)
        {
            if(id == patientrecored[i].id)
            {
                cout<<"patient name :"<<patientrecored[i].Pname<<endl;
                cout<<"patient age  :"<<patientrecored[i].age<<endl;
                cout<<"patient illness:"<<patientrecored[i].medicine.illness<<endl;
                cout<<"patient medicine:"<<patientrecored[i].medicine.pmedicine<<endl;
                cout<<"patient dose :"<<patientrecored[i].medicine.dose<<endl;
                found=true;
                break;
            }
        }
        if (!found)
        cout << "patient not found!\n";
}
void sort(patient patientrecored[])
{
	bool ordered=false;
	for(int i=0;i<indeex && ordered == false;i++){
		ordered=true;
		patient pTemp;
		for(int j = 0;j<indeex;j++)
		    if(patientrecored[j].age>patientrecored[j+1].age){
		    	ordered=false;
		    	pTemp=patientrecored[j];
		    	patientrecored[j]=patientrecored[j+1];
		    	patientrecored[j+1]=pTemp;
			}
	}
	cout<<"\n patients after sorting by age : \n";
    displayPA(patientrecored);
}
void showFile(patient patentrec[]){ 
    string line;
    int a=0;
    ifstream inputFile;
    inputFile.open("input.txt", ios:: in );
    if( inputFile.is_open()){
        while(getline (inputFile, line)){
            strcpy(patentrec[a].Pname, line.c_str());
            getline(inputFile, line);
            patentrec[a].id= line;
            getline(inputFile, line);
            patentrec[a].age= atof(line.c_str());
            getline(inputFile, line);
            strcpy(patentrec[a].medicine.illness, line.c_str());
            getline(inputFile, line);
            strcpy(patentrec[a].medicine.pmedicine, line.c_str());
            getline(inputFile, line);
            patentrec[a].medicine.dose = atoi(line.c_str());
            getline(inputFile, line);
            
        }
        inputFile.close();
    }
    else
        cout<<" couldn't open file ";
    
}
void writeToOutputFile(string & fileName,patient patientrecored[])
{
	string line;
	cout<<"Enter output File Name:"<<endl;
	cin>>fileName;
    fileName=fileName+".txt";
  ofstream myfile (fileName.c_str());
  if (myfile.is_open())
  {
  	for(int i=0; i<sizeof(patientrecored); i++){
  		if(patientrecored[i].id!=""){
    myfile<<patientrecored[i].Pname <<endl;
    myfile<<patientrecored[i].id <<endl;
    myfile<<patientrecored[i].age <<endl;
    myfile<<patientrecored[i].medicine.illness<<endl;
    myfile<<patientrecored[i].medicine.pmedicine<<endl;
    myfile<<patientrecored[i].medicine.dose<<endl;
myfile<<"------------------------------------------"<<endl;
}
}
    myfile << "Finish Writing.\n";
    myfile.close();
  }
  else cout << "Unable to open file";


}


int main(){
    int size,size2,chocie;
    string pat_id;
    string doc_id;
    string fileName;
    cout<<"enter how many patients do you have: ";
    cin>>size;
    cout<<"enter how many doctors do you have : ";
    cin>>size2;
    patient patientarray[size];
    doctors doctoresarray[size2];
   showFile(patientarray);

    do{
        cout<<"\nChoose the operation: \n"
        << "\t1.Add patient records \n"
        << "\t2.Add doctor records \n"
        << "\t3.Delete patient records \n"
        << "\t4.Update patient records \n"
        << "\t5.Display doctors records \n"
        << "\t6.Display patient records \n"
        << "\t7.Search if the patient exists or not  \n"
        << "\t8.Search patient records \n"
        << "\t9.Sort patient records \n"
        << "\t10.write to the output file \n"
        << "\t0.Exit \n"
        << "\tEnter your choice: ";
        cin>>chocie;
       // cout<<endl;
        switch (chocie) {
            case 1:
                if(indeex<size -1)
                    add(patientarray);
                else
                    cout<<"the hospital is full you can't add anymore!";
                break;
            case 2:
                if(doctorindex<size2-1)
                    adddrname(doctoresarray);
                else
                    cout<<"the hospital is full you can't add anymore! \n";
                break;
            case 3:
                if(indeex>=0){
                    cout<<"enter patient id to delete: ";
                    cin>>pat_id;
                    delete_rec(patientarray, pat_id);
                }
                else
                    cout<<"there is no patients to delete \n";
                break;
            case 4:
                if(indeex>=0){
                    
                    cout<<" enter patient ID to update: ";
                    cin>> pat_id;
                    update_rec(patientarray, pat_id);
                }
                else
                    cout<<"this patient does not exist! \n";
                break;
            case 5:
                if(doctorindex>=0){
                   
                     displayDOC(doctoresarray);
                    
                }
                
                else
                    cout<<"there is no doctors! \n";
                break;
            case 6:
                if(indeex>=0)
                    displayPA( patientarray);
                else
                    cout<<"there is no patients! \n";
                break;
            case 7:
                if(indeex>=0){
                    cout<<" enter pateint ID ";
                    cin>>pat_id;
                    search_patientonly(patientarray, pat_id);
                    
                }
                else
                    cout<<"this patient does not exist! \n";
                break;
            case 8:
                if(indeex>=0){
                    cout<<" enter pateint ID ";
                    cin>>pat_id;
                    search_patient_withcout(patientarray, pat_id);
                    
                }
                else
                    cout<<"this patient does not exist! \n";
                break;
            case 9:
            	if(indeex>=1)
            	{
            		sort(patientarray);
				}
                else if(indeex>=-1)
                {
                	cout<<"there is only one patient \n";
				}
				else
				   cout<<"there is no patients to sort!\n";
				break;
            case 10:
                   writeToOutputFile(fileName,patientarray);
                break;
            default:
            	if(chocie!=0){
				
            	cout<<"wrong input"; }
                break;
        }
    
        
    }while(chocie !=0);
cout<<"The program has ended"<<endl;
    
    cout<<"Satistical report"<<endl;
    ofstream output;
    output.open("report.txt",ios::out);

    if(output.is_open()){
    	cout<<"Satistical report is open"<<endl;
    
    	output<<"Number of patients "<<size<<endl;
    	output<<"Number of doctors "<<size2<<endl;
    	time_t ttime=time(0);
        char* dt=ctime(&ttime);
    	output<<"Date and time for the last update: "<<dt<<endl;
    	output.close();
	}
	else
	cout<<"Not open";
    
    
     
    return 0;
}

