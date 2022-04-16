#include <iostream>
using namespace std;

void fmahasiswa (string *nama, string *nim, int *jml_mhs){
	for (int i=0; i<*jml_mhs; i++){
		cout<<"--------------------------------------------------";
		cout<<endl;
		cout<<"Masukkan Nama mahasiswa "<<i+1<<" = "; cin.ignore(); getline(cin, *(nama+i));
		cout<<"Masukkan NIM mahasiswa "<<i+1<<" = "; cin>>*(nim+i);	
		cout<<"--------------------------------------------------";
		cout<< endl;	
	}
}

void fipk (float *jml, int jml_mat, int ke){
	float ipk;
	string hasilipk;
	ipk=(*(jml+ke)/jml_mat/100)*4;
	if(ipk>=3.51){
		cout<<"Mendapat nilai IPK = "<<ipk<<endl;
		cout <<"+==========+"<<endl;
		cout <<"||CUMLAUDE||"<<endl;
		cout <<"+==========+"<<endl;
	}else if(ipk<= 3.5 && ipk >= 2.76){
		cout<<"Mendapat nilai IPK = "<<ipk<<endl;
		cout <<"+==================+"<<endl;
		cout <<"||SANGAT MEMUASKAN||"<<endl;
		cout <<"+==================+"<<endl;
	}else{
		cout<<"Mendapat nilai IPK = "<<ipk<<endl;
		cout <<"+===========+"<<endl;
		cout <<"||MEMUASKAN||"<<endl;
		cout <<"+===========+"<<endl;
	}
	
}

int main(){
	
	int jum_mhs, jum_mat;
	
	cout<<endl;
	cout<<"Mahasiswa yang akan diinputkan = "; cin>>jum_mhs;
	cout<<"Jumlah matkul per mahasiswa = "; cin>>jum_mat;
	cout<<endl<<endl;
	
	float jum[jum_mhs], tmp = 0;
	int nilai[25], nil_urt[jum_mhs][25], i;
	string nama[jum_mhs], nim[jum_mhs];
	fmahasiswa (nama, nim, &jum_mhs);
	
	for (i=0; i<jum_mhs; i++){
		cout<<endl;
		cout<<"+------------------+"<<endl;
		cout<<"|NILAI MAHASISWA -"<<i+1<<"|"<<endl;
		cout<<"+------------------+"<<endl;
		cout<<endl;
		for (int j=0; j<jum_mat; j++){
			cout<<"Masukkan nilai matkul ke-"<<j+1<<" = ";cin>>nilai[j];
		}
		
		int pilihan;
		cout<<"\n==============================";
		cout<<"\nMetode sorting nilai ascending\n1. Bubble Sorting\n2. Selection Sorting\n3. Insertion Sorting\n";
		cout<<"Pilih metode sorting = "; cin>>pilihan;
		cout<<"==============================";
		
		if(pilihan == 1){
			for( int k=0; k<jum_mat; k++){
				for(int l=0; l<jum_mat; l++){
					if(nilai[l]>nilai[l+1]){
						tmp = nilai[l];
						nilai[l] = nilai[l+1];
						nilai[l+1] = tmp;
					}
				}
				nil_urt[i][k]= nilai[k];
			}
		}
		else if(pilihan == 2){
			for(int m=0; m<jum_mat; m++){
				int  tukar = m;
				for(int n=i+1; n<jum_mat; n++){
					if(nilai[n] < nilai[tukar]){
						tukar = n;
					}
				}
				tmp = nilai[tukar];
				nilai[tukar] = nilai[m];
				nilai[m] = tmp;
				nil_urt[i][m] = nilai[m];
			}
		}
		else{
			for(int o=0; o<jum_mat; o++){
				tmp = nilai[o];
				int p=o-1;
				while(nilai[p] > tmp && p >= 0){
					nilai[p+1] = nilai[p];
					p--;
				}
				nilai[p+1] = tmp;
				nil_urt[i][p] = nilai[p];
			}
		}
		
		
		for (int m=0; m<jum_mat; m++){	
			jum[i]=jum[i]+nilai[m];
		}
	}
	
	
	cout << endl << endl;
    for (int i=0; i<jum_mhs; i++){
		cout<<endl;
		cout<<"+===============+"<<endl;
    	cout<<"|MAHASISWA ke- "<<i+1<<"|"<<endl;
		cout<<"+===============+"<<endl<<endl;
    	cout<<"~~>"<<nama[i];
    	cout<<" ("<<nim[i]<<")<~~"<<endl;
		cout<<"Nilai terendah -> tertinggi"<<endl;
		
    	for( int j=0; j<jum_mat; j++){
    		cout<<"ke- "<<j+1<<" : "<<nil_urt[i][j]<<endl;
		}
		
		cout<<endl;
    	cout<<"Dengan nilai total = "<<jum[i]<<endl;
		fipk (jum, jum_mat, i);
		cout<<endl;
	}
}
