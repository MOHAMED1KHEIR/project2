#include <iostream>
#include <string>
#include <cstdlib>  //  exit
#include <iomanip>
using namespace std;
      enum Arayüz_seçenekleri { doktur = 1, hasta = 2, cikis = 3, degerlenderme };
      enum doktur {
	     Hasta_Ekle=1, ID_bilgisi_kullanarak_hasta_sil, Hasta_detayları_getir, Ameliyat_ekle, Ameliyat_sil,
	     Ameliyat_detaylarını_getir, IDye_göre_ameliyat_ücretini_hesapla, Ana_menüye_dön, Çıkış
       };
      enum hasta{
	  Hastane_doktorlarını_yazdır=1, Tüm_hastaları_yazdır=2, 
   	  Ameliyat_hastalarını_yazdır=3, Tüm_hastaların_öncelik_puanlarını_yazdır=4, Ana_menüye_dönH=5, ÇıkışH=6
      };
      short readtheNum(string message) {
	   short num;
	   cout << message;
	   cin >> num;
	   return num;
       }
      struct HastaNode
  {
	      short HastaId=-1;
		  short AmeliyatId = -1;
	      short old=0;
		  short hastalik_derecesi=0;
	      string name="";
	      string hastaTuru="";
		  string baslangit_zaman="";
		  string bitis_zamani="";
		  HastaNode* next=NULL;
		  HastaNode* prev=NULL;
		
  };
	  struct doctorNode {
		  string DName;
		  doctorNode* next = NULL;
		  doctorNode* prev = NULL;

	  };
	  struct degerlendirData
	  {
		 
		  int AmeliyetUcreti = 0;
		  int hastalarSayasi = 0;
		  int AmeliyetSayisi = 0;
		  degerlendirData* next=NULL;
	  };
	  struct hastaVE_ameliyetVE_ucretSayisi
	  {
		  int hastalarCnt = 0;
		  int AmeliyetCnt = 0;
		  int AmeliyetucretiCnt = 0;

		
	  };
      HastaNode ReadHastaData()
  {
	  HastaNode data;
	  cout << "hasta ID'si giriniz\n";
	  cin >> data.HastaId;
	  cout << "hasta adi giriniz\n";
	 // getline(cin, data.name);
	  cin >> data.name;
	  cout << "hasta yas giriniz\n";
	  cin >> data.old;
	  cout << "hastanin hastalik derecesi giriniz \n";
	  cin >> data.hastalik_derecesi;
      cout << "hasta icin koydugnuz tahsisi giriniz\n";
	  cin >> data.hastaTuru;
	  return data;
  }
      HastaNode ReadAmeliyatData()
  {
	  HastaNode data;
	  cout << "baslangit_zaman giriniz\n";
	  cin >> data.baslangit_zaman;
	  cout << "hasta ID'bitis_zamani giriniz\n";
	  cin >> data.bitis_zamani;
	  return data;
  }
      //class DoublyLinkedList sınıfı  çift yönlü bağlı liste yapısında
      class DoublyLinkedList
      {
		 
		  hastaVE_ameliyetVE_ucretSayisi cnt; //counter
       public:
	  HastaNode* head;

	  DoublyLinkedList() : head(NULL) {}
	  //1
	  void addHastaNode()
	  {
		  HastaNode data = ReadHastaData();
		  HastaNode* newNode = new HastaNode();
		  newNode->HastaId = data.HastaId;
		  newNode->hastalik_derecesi = data.hastalik_derecesi;
		  newNode->hastaTuru = data.hastaTuru;
		  newNode->name = data.name;
		  newNode->old = data.old;
		  newNode->next = NULL;
		  newNode->prev = NULL;
		  cnt.AmeliyetucretiCnt += (data.hastalik_derecesi * 1500);
		  if (head == NULL)
		  {
			  head = newNode;
			  cnt.hastalarCnt++;
		  }
		  else if (head->next == NULL)
		  {
			  head->next = newNode;
			  newNode->prev = head;
			  cnt.hastalarCnt++;
		  }
		  else
		  {
			  HastaNode* temp = head;
			  while (temp->next != NULL)
			  {
				  temp = temp->next;
			  }
			  temp->next = newNode;
			  newNode->prev = temp;
			  cnt.hastalarCnt++;
		  }
		  cout << "Hasta eklendi!\n";
	  }
	  //2
	  void IdGoreHastaSil()
	  {
		//  HastaNode* temp = head;
		  short HastaID = readtheNum("silemek istediginiz hasta IDsini giriniz");
		  if (head == NULL)
		  {
			  cout << " hastanade hasta yok";
		  }
		  else if (head->next == NULL && head->HastaId == HastaID)
		  {
			 
			  delete head;
			  head = NULL;
			  cout << HastaID << "->" << "  hasta silindi\n";
		  }
		  else
		  {

			  if (head->HastaId==HastaID)
			  {
				  HastaNode* temp1 = head->next;
				  temp1->prev = head;
				  delete head;
				  temp1->prev = NULL;
				  head = temp1;
				  cout << HastaID << "->" << "  hasta silindi\n";
			  }
			  else
			  {
				  HastaNode* temp = head;
			  while (temp->next != NULL && temp->next->HastaId != HastaID)
			  {
				  temp = temp->next;
			  }
			  if (temp->HastaId != HastaID && temp->next == NULL)
			  {
				  cout << "Aradiniz hasta bulunmadi\n";
			  }
			  else if (temp->next->HastaId == HastaID && temp->next->next == NULL)
			  {
				  HastaNode* sil = temp->next;
				  delete sil;
				  temp->next = NULL;
				  cout << HastaID << "->" << "  hasta silindi\n";
			  }
			  else
			  {
				  HastaNode* temp2 = temp->next->next;
				  HastaNode* sil = temp->next;
				  delete sil;
				  temp->next = temp2;
				  temp2->prev = temp;
				  cout << HastaID << "->" << "  hasta silindi\n";

			  }
			  }
		  }

	  }
	  //3
	  void HastaDeteylerYaz()
	  {
		  if (head == NULL)
		  {
			  cout << " hastanade hasta yok\n";

		  }
		  else
		  {
			  //Hasta ID: 1 Hasta ad soyad: zeynepmutlu hasta yasi: 25 hast. derecesi: 4 hast. teshis: grip
			  HastaNode* temp = head;
			  while (temp != NULL)
			  {
				  cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "hast. derecesi: " << temp->hastalik_derecesi << " hast. teshis: " << temp->hastaTuru << endl;
				  temp = temp->next;
			  }
		  }
	  }
	  //4 
	  void AmeliyatEkle()
	  {
		  short AmeliyatId = readtheNum("Eklemek istediginiz ameliyatin IDsini giriniz :: ");
		  HastaNode dataTarih = ReadAmeliyatData();
		  if (head == NULL)
		  {
			  cout << " hastanade hasta yok";
		  }
		  else if (head->next == NULL && head->HastaId == AmeliyatId)
		  {
			  head->baslangit_zaman = dataTarih.baslangit_zaman;
			  head->bitis_zamani = dataTarih.bitis_zamani;
			  head->AmeliyatId = AmeliyatId;
			  cnt.AmeliyetCnt++;
		  }

		  else
		  {
			  if (head->next != NULL && head->HastaId == AmeliyatId)
			  {
				  head->baslangit_zaman = dataTarih.baslangit_zaman;
				  head->bitis_zamani = dataTarih.bitis_zamani;
				  head->AmeliyatId = AmeliyatId;
				  cnt.AmeliyetCnt++;
			  }
			  else
			  {
				  HastaNode* temp = head;
				  while (temp->next != NULL && temp->next->HastaId != AmeliyatId)
				  {
					  temp = temp->next;
				  }
				  if (temp->HastaId != AmeliyatId && temp->next == NULL)
				  {
					  cout << "Aradiniz hasta bulunmadi\n";
				  }
				  else if (temp->next->HastaId == AmeliyatId && temp->next->next == NULL)
				  {
					  HastaNode* add = temp->next;
					  add->baslangit_zaman = dataTarih.baslangit_zaman;
					  add->bitis_zamani = dataTarih.bitis_zamani;
					  add->AmeliyatId = AmeliyatId;
					  cnt.AmeliyetCnt++;
				  }
				  else
				  {
					  HastaNode* add = temp->next;
					  add->baslangit_zaman = dataTarih.baslangit_zaman;
					  add->bitis_zamani = dataTarih.bitis_zamani;
					  add->AmeliyatId = AmeliyatId;
					  cnt.AmeliyetCnt++;

				  }
			  }
			  
		  }
	  }
	  //5
	  void Ameliyatsil()
	  {
		  short ameliyetID = readtheNum("silemek istediginiz Ameliyet IDsini giriniz  :: ");
		  if (head == NULL)
		  {
			  cout << " amelyet hasta yok";
		  }
		  else if (head->next == NULL && head->AmeliyatId == ameliyetID)
		  {
			  delete head;
			  head = NULL;
		  }
		  else
		  {
			  HastaNode* temp = head;
			  while (temp->next != NULL && temp->next->AmeliyatId != ameliyetID)
			  {
				  temp = temp->next;
			  }
			  if (temp->HastaId != ameliyetID && temp->next == NULL)
			  {
				  cout << "Aradiniz ameliyet bulunmadi\n";
			  }
			  else if (temp->next->AmeliyatId == ameliyetID && temp->next->next == NULL)
			  {
				  HastaNode* sil = temp->next;
				  delete sil;
				  temp->next = NULL;
			  }
			  else
			  {
				  HastaNode* temp2 = temp->next->next;
				  HastaNode* sil = temp->next;
				  delete sil;
				  temp->next = temp2;
				  temp2->prev = temp;

			  }
		  }
	  }
	  //6
	  void AmeliyatDetaylarınıGetir()
	  {
		  if (head == nullptr) {
			  cout << "Hastanede hasta yok\n";
			  return;
		  }

		  HastaNode* temp = head;
		  bool found = false;
		  while (temp != nullptr) {
			  if (temp->AmeliyatId > 0) {
				  cout << "Hasta ID: " << temp->HastaId << ", Ad Soyad: " << temp->name << ", Hasta Yaşı: " << temp->old << ", Hastalık Derecesi: " << temp->hastalik_derecesi << ", Hastalık Türü: " << temp->hastaTuru << ", Ameliyat Baslangıc Zamani: " << temp->baslangit_zaman << ", Ameliyat Bitis Zamani: " << temp->bitis_zamani << endl;
				  found = true;
			  }
			  temp = temp->next;
		  }

		  if (!found) {
			  cout << "Ameliyat için uygun hasta bulunamadı\n";
		  }
		  //if (head == NULL)
		  //{
			 // cout << " hastanade hasta yok\n";
		  //}
		  //else
		  //{
			 // HastaNode* temp = head;
			 // if (temp->next != NULL && temp->AmeliyatId > 0)
			 // {
				//  cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "hast. derecesi: " << temp->hastalik_derecesi << " hast. teshis: " << temp->hastaTuru << " Ameliyet baslangit_zaman " << temp->baslangit_zaman << " Ameliyet bitis_zaman " << temp->bitis_zamani << endl;
			 // }
			 //
				//  while (temp->next != NULL && temp->next->AmeliyatId <= 0)
				//  {
				//	  temp = temp->next;
				//  }
				//  if (temp->AmeliyatId <= 0 && temp->next == NULL)
				//  {
				//	  cout << " ameliyet biti\n";
				//  }
				//  else
				//  {
				//	//  HastaNode* temp = head;
				//	  while (temp != NULL)
				//	  {
				//		  if (temp->AmeliyatId > 0)
				//		  {
				//			  cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "hast. derecesi: " << temp->hastalik_derecesi << " hast. teshis: " << temp->hastaTuru << " Ameliyet baslangit_zaman " << temp->baslangit_zaman << " Ameliyet bitis_zaman " << temp->bitis_zamani << endl;
				//			  temp = temp->next;
				//		  }
				//	  }
				//  }
			 // 
			 //
		  //}
	  }
	  //7
	  int  IDye_göre_ameliyat_ücretini_hesapla()
	  {
		  short ameliyetID = readtheNum("hesaplamak  istediginiz hastanin Ameliyet ucreti IDsini giriniz  :: ");
		  if (head == NULL)
		  {
			  cout << " amelyet hasta yok";
		  }
		  else if (head->next == NULL && head->AmeliyatId == ameliyetID)
		  {
			  return head->hastalik_derecesi * 1500;
		  }
		  else
		  {
			  HastaNode* temp = head;
			  while (temp->next != NULL && temp->next->AmeliyatId != ameliyetID)
			  {
				  temp = temp->next;
			  }
			  if (temp->AmeliyatId != ameliyetID && temp->next == NULL)
			  {
				  cout << "Aradiniz ameliyet bulunmadi\n";
			  }
			  else if (temp->next->AmeliyatId == ameliyetID && temp->next->next == NULL)
			  {
				  HastaNode* temp2 = temp->next;
				  return temp2->hastalik_derecesi * 1375;
			  }
			  else
			  {
				  HastaNode* temp2 = temp->next;
				  return temp2->hastalik_derecesi * 1375;
				 

			  }
		  }
	  }
	  ///
	  hastaVE_ameliyetVE_ucretSayisi degerlendirmaData1()
	  {
		  return cnt;
	  }
	  ~DoublyLinkedList() {
		  HastaNode* current = head;
		  while (current != nullptr) {
			  HastaNode* temp = current;
			  current = current->next;
			  delete temp;
		  }
		  head  = nullptr;
	  }
  };
       //class  CircularDoublyLinkedList sınıfı    çift yönlü dairesel bağlı liste yapısında 
	  class CircularDoublyLinkedList
	  {
	  public:
		  HastaNode* head;
		  CircularDoublyLinkedList() : head(nullptr) {}
		  //1
		  void doctorlarYaz()
		  {
			  string doctorName[5] = { "ahmed oglu","numan","mehmet","melis","furkan" };
			  doctorNode* headD = NULL;
			  //CircularDoublyLinkedList ye doktorlar names aktirma
			  for (int i = 0; i < 5; i++)
			  {
				  struct doctorNode* newNode = new doctorNode();
				  newNode->DName = doctorName[i];
				  if (headD == NULL)
				  {
					  headD = newNode;
					  headD->next = headD;
					  headD->prev = headD;


				  }
				  else if (headD->next == headD)
				  {
					  headD->next = newNode;
					  newNode->prev = headD;
					  headD->prev = newNode;
					  newNode->next = headD;
				  }
				  else
				  {
					  doctorNode* temp = headD;
					  while (temp->next != headD)
					  {
						  temp = temp->next;
					  }
					  temp->next = newNode;
					  newNode->prev = temp;
					  newNode->next = headD;
					  headD->prev = newNode;
				  }

			  }
			  doctorNode* temp2 = headD;
			  short cnt = 1;

			  //CircularDoublyLinkedList den doktorlar names yazdir
			  while (temp2->next != headD)
			  {
				  cout << cnt << ". doctur name is  :" << temp2->DName << endl;
				  temp2 = temp2->next;
				  cnt++;
			  }
			  cout << cnt << ". doctur name is  :" << temp2->DName << endl;

		  }
		  //	DoublyLinkedList dan data CircularDoublyLinkedList ye aktirmak
		  void addNode(short HastaId, short AmeliyatId, short old, short hastalik_derecesi, string name, string hastaTuru, string baslangit_zaman, string bitis_zamani)
		  {
			  HastaNode* newNode = new HastaNode();
			  newNode->HastaId = HastaId;
			  newNode->AmeliyatId = AmeliyatId;
			  newNode->old = old;
			  newNode->hastalik_derecesi = hastalik_derecesi;
			  newNode->name = name;
			  newNode->hastaTuru = hastaTuru;
			  newNode->baslangit_zaman = baslangit_zaman;
			  newNode->bitis_zamani = bitis_zamani;
			  if (head == NULL)
			  {
				  head = newNode;
				  head->next = head;
				  head->prev = head;


			  }
			  else if (head->next == head)
			  {
				  head->next = newNode;
				  newNode->prev = head;
				  head->prev = newNode;
				  newNode->next = head;
			  }
			  else
			  {
				  HastaNode* temp = head;
				  while (temp->next != head)
				  {
					  temp = temp->next;
				  }
				  temp->next = newNode;
				  newNode->prev = temp;
				  newNode->next = head;
				  head->prev = newNode;
			  }

		  }
		  //2
		  void TumHastalarYazdir()
		  {
			  HastaNode* temp = head;

			  if (head == NULL)
			  {
				  cout << " hastanade hasta yok\n";

			  }

			  else if (temp->next == head)
			  {

				  cout << ".hasta  :" << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "hast. derecesi: " << temp->hastalik_derecesi << " hast. teshis: " << temp->hastaTuru << endl;

			  }
			  else
			  {

				  short cnt = 1;
				  while (temp->next != head)
				  {
					  cout << cnt << ".hasta  :" << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "hast. derecesi: " << temp->hastalik_derecesi << " hast. teshis: " << temp->hastaTuru << endl;
					  temp = temp->next;
					  cnt++;
				  }
				  cout << cnt << ".hasta  :" << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "hast. derecesi: " << temp->hastalik_derecesi << " hast. teshis: " << temp->hastaTuru << endl;

			  }


		  }
		  //3
		  void AmeliyatHastalariniYazdir()
		  {
			  if (head == nullptr) {
				  cout << "Hastanede hasta yok\n";
				  return;
			  }

			  HastaNode* temp = head;
			  bool found = false;
			  do {
				  if (temp->AmeliyatId > 0) {
					  cout << "Hasta ID: " << temp->HastaId << ", Ad Soyad: " << temp->name << ", Hasta Yaşı: " << temp->old << ", Hastalık Derecesi: " << temp->hastalik_derecesi << ", Hastalık Türü: " << temp->hastaTuru << ", Ameliyat Başlangıç Zamani: " << temp->baslangit_zaman << ", Ameliyat Bitiş Zamani: " << temp->bitis_zamani << endl;
					  found = true;
				  }
				  temp = temp->next;
			  } while (temp != head);  

			  if (!found) {
				  cout << "Ameliyat için uygun hasta bulunamadı\n";
			  }
		  }

		/*	if (head == NULL)
			{
				cout << " hastanade hasta yok\n";

			}
			else
			{
				HastaNode* temp = head;
				while (temp->next != head && temp->next->AmeliyatId <= 0)
				{
					temp = temp->next;
				}
				if (temp->AmeliyatId <= 0 && temp->next == head)
				{
					cout << " ameliyet bulunmadi\n";
				}
				else
				{
					
					HastaNode* temp = head;
					while (temp != head)
					{
						if (temp->AmeliyatId > 0)
						{
							cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "hast. derecesi: " << temp->hastalik_derecesi << " hast. teshis: " << temp->hastaTuru << " Ameliyet baslangit_zaman " << temp->baslangit_zaman << " Ameliyet bitis_zaman " << temp->bitis_zamani << endl;
							temp = temp->next;
						}

					}
				}


			}*/
	    
		//4
		void TumHastalarınOncelikPuanlarYazdır()
		{
			
			if (head == nullptr) {
				cout << "Hastanede hasta yok\n";
				return;
			}

			HastaNode* temp = head;
			bool found = false;
			do {
				if (temp->AmeliyatId > 0) {
					cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "HESAPLANAN ONCELIK DEGERI  " << temp->hastalik_derecesi * 10 << endl;
					found = true;
				}
				temp = temp->next;
			} while (temp != head);

			if (!found) {
				cout << "Ameliyat için uygun hasta bulunamadı\n";
			}
			/*
			HastaNode* temp = head;
			if (head == NULL)
			{
				cout << " hastanade hasta yok\n";
			}
			while (temp->next!=head)
			{
				cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "HESAPLANAN ONCELIK DEGERI  " << temp->hastalik_derecesi * 10 << endl;
				temp = temp->next;
			}
			cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "HESAPLANAN ONCELIK DEGERI  " << temp->hastalik_derecesi * 10 << endl;*/
			//else if (temp->next == head)
			//{
			//	cout  << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "HESAPLANAN ONCELIK DEGERI  " <<temp->hastalik_derecesi*10 << endl;
			//}
			//else
			//{
			//	short cnt = 1;
			//	while (temp->next != head)
			//	{
			//		cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "HESAPLANAN ONCELIK DEGERI  " << temp->hastalik_derecesi * 10 << endl;
			//		temp = temp->next;
			//		cnt++;
			//	}
			//	cout << "Hasta ID: " << temp->HastaId << "ad soyad: " << temp->name << "hasta yasi: " << temp->old << "HESAPLANAN ONCELIK DEGERI  " << temp->hastalik_derecesi * 10 << endl;
			//}

		}

	  ~CircularDoublyLinkedList() {
		  if (!head) return;

		  HastaNode* current = head;
		  do {
			  HastaNode* next = current->next;
			  delete current;
			  current = next;
		  } while (current != head);

		  head = nullptr;
	  }
      };	
	  //class  CircularyLinkedList sınıfı     
	  //dairesel tek yönlü bağlı liste
	  class CircularLinkedList
	  {
	  private:
		  degerlendirData* head;
	  public:
		  CircularLinkedList() : head(nullptr) {}  
		  void addNode(DoublyLinkedList op)
		  {
			  hastaVE_ameliyetVE_ucretSayisi	x = op.degerlendirmaData1();
			  struct degerlendirData* nnode = new degerlendirData();
			  nnode->AmeliyetSayisi = x.AmeliyetCnt;
			  nnode->AmeliyetUcreti = x.AmeliyetucretiCnt;
			  nnode->hastalarSayasi = x.hastalarCnt;
			  if (head == NULL) {
				  nnode->next = nnode;
				  head = nnode;
			  }
			  else if (head->next == head) {
				  head->next = nnode;
				  nnode->next = head;
			  }
			  else {
				  degerlendirData* iter = head;
				  while (iter->next != head) {
					  iter = iter->next;
				  }
				  iter->next = nnode;
				  nnode->next = head;
			  }
		  }

		  void degerlendermedisplay()
		  {
			  if (head == nullptr) 
			  { 
				  cout << "The list is empty" << endl;
				  
				  return;
			  }

			  degerlendirData* temp = head;
			  do {
				  cout << setw(17) << " hastalar Sayasi |" << setw(5) << temp->hastalarSayasi << endl;
				  cout << setw(17) << " Ameliyet Sayisi |" << setw(5) << temp->AmeliyetSayisi << endl;
				  cout << setw(17) << " Ameliyet Ucreti |" << setw(5) << temp->AmeliyetUcreti << endl;
				  temp = temp->next;
			  } while (temp != head);
			  cout << endl;
		  }

	  };
	  void transferData(DoublyLinkedList& dll, CircularDoublyLinkedList& CircularDll)
	  {
		      HastaNode* current = dll.head;
		      while (current != nullptr) 
			  {
			 CircularDll.addNode(current->HastaId, current->AmeliyatId, current->old, current->hastalik_derecesi, current->name, current->hastaTuru, current->baslangit_zaman, current->bitis_zamani);
			  current = current->next;
			  }
	  }
	  enum  Arayüz_seçenekleri  BirinciOtomasyonGiriS()
	  {
		  Arayüz_seçenekleri secimNO=doktur;
		  cout << "hastane Otomasyon uygulamasina hosgaldinin\n";
		  short theNum = readtheNum("doctor girisi icin 1'e yaz :\nhasta girisi icin 2'e yaz:\ncikis icin 3'e yaz:\ndegerlenderme icin 4'e yaz: ->");
		  if (theNum == 1)
		  {
			  secimNO = doktur;
		  }
		  else if (theNum == 2)
		  {
			  secimNO = hasta;
		  }
		  else if (secimNO == 3)
		  {
			 secimNO = cikis;
		  }
		  else
		  {
			  secimNO = degerlenderme;
		  }
		  return secimNO;

	  }
	  enum doktur DoctorEkrani()
	  {
		  enum doktur Doctor_secimi1 = Çıkış;
		  cout << "1-Hasta_Ekle\n2-ID_bilgisi_kullanarak_hasta_sil\n3-Hasta_detayları_getir\n4-Ameliyat_ekle\n5-Ameliyat_sil\n6-Ameliyat_detaylarını_getir\n7-IDye_göre_ameliyat_ücretini_hesapla\n8-Ana_menüye_dön\n9-cikis\n";
		  short Doctor_secimiNO = readtheNum("secim yapiniz {1-2-3-4-5-6-7-8-9] :\n ");
		  switch (Doctor_secimiNO) {
		  case 1:
			  Doctor_secimi1 = Hasta_Ekle;
			  break;
		  case 2:
			  Doctor_secimi1 = ID_bilgisi_kullanarak_hasta_sil;
			  break;
		  case 3:
			  Doctor_secimi1 = Hasta_detayları_getir;
			  break;
		  case 4:
			  Doctor_secimi1 = Ameliyat_ekle;
			  break;
		  case 5:
			  Doctor_secimi1 = Ameliyat_sil;
			  break;
		  case 6:
			  Doctor_secimi1 = Ameliyat_detaylarını_getir;
			  break;
		  case 7:
			  Doctor_secimi1 = IDye_göre_ameliyat_ücretini_hesapla;
			  break;
		  case 8:
			  Doctor_secimi1 = Ana_menüye_dön;
			  break;
		  case 9:
			  Doctor_secimi1 = Çıkış;
			  break;
		  default:
			  cout << "Geçersiz seçim, lütfen tekrar deneyin.\n";
			  break;
		  }
		  return Doctor_secimi1;

	  }
	  bool loginDoctor()
	  {
		  short cnt = 3;
		  do {
			  string username, password;
			  cout << "Enter username: ";
			  cin >> username;
			  cout << "\nEnter password: ";
			  cin >> password;
			  if (username != "MOHAMED" || password != "123")
			  {
				  cnt--;
				  if (cnt == 0)
				  {
					  cout << "Uzgunum, 3 denemeden sonra giremezsin\n";

					  return false;
				  }
				  cout << "username or password is error\n";
			  }
			  else

				  return true;

		  } while (cnt != 0);
		  return 1;
	  }
	  enum hasta HastaEkrani()
	  {
		  enum hasta hasta_secimi1 = Hastane_doktorlarını_yazdır;
		  cout << "1-Hastane_doktorlarını_yazdır\n2-Tüm_hastaları_yazdır\n3-Ameliyat_hastalarını_yazdır\n4-Tüm_hastaların_öncelik_puanlarını_yazdır\n5-Ana_menüye_dön\n6-Çıkış\n";
		  short Doctor_secimiNO = readtheNum("secim yapiniz {1-2-3-4-5-6] :\n ");
		  switch (Doctor_secimiNO) {
		  case 1:
			  hasta_secimi1 = Hastane_doktorlarını_yazdır;
			  break;
		  case 2:
			  hasta_secimi1 = Tüm_hastaları_yazdır;
			  break;
		  case 3:
			  hasta_secimi1 = Ameliyat_hastalarını_yazdır;
			  break;
		  case 4:
			  hasta_secimi1 = Tüm_hastaların_öncelik_puanlarını_yazdır;
			  break;
		  case 5:
			  hasta_secimi1 = Ana_menüye_dönH;
			  break;
		  case 6:
			  hasta_secimi1 = ÇıkışH;
			  break;

		  default:
			  cout << "Geçersiz seçim, lütfen tekrar deneyin.\n";
			  break;
		  }
		  return hasta_secimi1;

	  }
	  void DoctorsecimYAP(enum doktur Doctor_secimi, DoublyLinkedList &op)
	  { 
		  switch (Doctor_secimi) 
		  {
		  case Hasta_Ekle:
			   op.addHastaNode();
			   break;
		  case  ID_bilgisi_kullanarak_hasta_sil:
			  op.IdGoreHastaSil();
			  break;
		  case Hasta_detayları_getir:
			  op.HastaDeteylerYaz();
			  break;
		  case Ameliyat_ekle:
			  op.AmeliyatEkle();
			  break;
		  case Ameliyat_sil:
			  op.Ameliyatsil();
			  break;
		  case Ameliyat_detaylarını_getir:
			  op.AmeliyatDetaylarınıGetir();
			  break;
		  case IDye_göre_ameliyat_ücretini_hesapla:
			cout<<"ameliyat_ücretini " << op.IDye_göre_ameliyat_ücretini_hesapla() << endl;
			  break;
		    // case Ana_menüye_dön:
			//  
			//  break;
		  case Çıkış:
			  std::cout << "Closing the console..." << std::endl;
			  exit(0); 
			  break;
		  }
	  }
	  void HastasecimYAP(enum hasta Hasta_secimi, CircularDoublyLinkedList& op)
	  {
		  switch (Hasta_secimi)
		  {
		  case Hastane_doktorlarını_yazdır:
			  op.doctorlarYaz();
			  break;
		  case  Tüm_hastaları_yazdır:
			  op.TumHastalarYazdir();
			  break;
		  case Ameliyat_hastalarını_yazdır:
			  op.AmeliyatHastalariniYazdir();
			  break;
		  case Tüm_hastaların_öncelik_puanlarını_yazdır:
			  op.TumHastalarınOncelikPuanlarYazdır();
			  break;
		  case Ana_menüye_dönH:
			
			  break;
		  case ÇıkışH:
			  cout << "Closing the console..." << std::endl;
			  exit(0);
			  break;
	
		  }
	  }
	  void HstanaSestemi(Arayüz_seçenekleri secim, DoublyLinkedList opDOCTOR, CircularDoublyLinkedList opHASTA, CircularLinkedList opdegerlendir)
	  {
		  if (secim == doktur)
		  {
			  bool VeriDogruMu = loginDoctor();
			  enum doktur Doctor_secimi;
			  if (VeriDogruMu == true)
			  {
				  while (true)
				  {
                    Doctor_secimi = DoctorEkrani();
				   if (Doctor_secimi == Ana_menüye_dön)
				   {
					   transferData(opDOCTOR, opHASTA);
					   HstanaSestemi(BirinciOtomasyonGiriS(), opDOCTOR, opHASTA, opdegerlendir);
				   }
				   DoctorsecimYAP(Doctor_secimi, opDOCTOR);
				  }   
			  }
		  }
		  else if (secim == hasta)
		  {
			  enum hasta hasta_secimi;
			  while (true)
			  {
			  hasta_secimi = HastaEkrani();
			  if (hasta_secimi == Ana_menüye_dönH)
			  {
				 /* transferData(opDOCTOR, opHASTA);*/
				  HstanaSestemi(BirinciOtomasyonGiriS(), opDOCTOR, opHASTA, opdegerlendir);
			  }
			  HastasecimYAP(hasta_secimi, opHASTA);
			  }
			
		  }
		  else if(secim == cikis)
		  {
			  std::cout << "Closing the console..." << std::endl;
			  exit(0);
			 
		  }
		  
		  else if (secim == degerlenderme)
		  {
			  opdegerlendir.addNode( opDOCTOR);
			  opdegerlendir.degerlendermedisplay();
		  }
	  }
int main()
{
	DoublyLinkedList opDOCTOR;
	CircularDoublyLinkedList opHASTA;
	CircularLinkedList opdegerlendir;
	HstanaSestemi(BirinciOtomasyonGiriS(), opDOCTOR, opHASTA, opdegerlendir);
}


