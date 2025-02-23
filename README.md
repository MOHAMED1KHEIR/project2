سأقوم بتحسين ملف `README.md` بإضافة تنسيقات إضافية مثل الخطوط العريضة، القوائم المنقطة بشكل أفضل، الجداول، والفواصل لجعل الملف أكثر وضوحًا وجاذبية بصريًا.

---

# README.md

## **Hospital Management System**

**This project** is a **Hospital Management System** developed in **C++** that leverages advanced data structures such as *Doubly Linked Lists*, *Circular Doubly Linked Lists*, and *Circular Linked Lists* to manage hospital-related data, including patients, doctors, and surgeries. The system provides two primary interfaces: one for **doctors** and another for **patients**, each with tailored functionalities.

---

## **Project Overview**

The system automates hospital operations by offering:

- **Doctor Interface**: Enables doctors to:
  - Add or delete patients.
  - Manage surgeries (add/delete).
  - View patient and surgery details.
  - Calculate surgery costs based on disease severity.
- **Patient Interface**: Allows patients to:
  - View the list of doctors.
  - View all patients or those with surgeries.
  - Check priority scores based on patient condition.

### **Data Structures Used**
| Data Structure            | Purpose                                      |
|---------------------------|----------------------------------------------|
| `DoublyLinkedList`        | Manages patient data (doctor's perspective)  |
| `CircularDoublyLinkedList`| Manages patient data (patient's perspective) & doctor list |
| `CircularLinkedList`      | Stores evaluation data (counts and costs)    |

---

## **Structs Analysis**

### 1. **`HastaNode`**
- **Description**: Represents a patient node in the list.
- **Fields**:
  - `HastaId`: Patient ID
  - `AmeliyatId`: Surgery ID (-1 if no surgery)
  - `old`: Patient age
  - `hastalik_derecesi`: Disease severity
  - `name`: Patient name
  - `hastaTuru`: Disease type/diagnosis
  - `baslangit_zaman`: Surgery start time
  - `bitis_zamani`: Surgery end time
  - `next`, `prev`: Pointers to next/previous nodes

### 2. **`doctorNode`**
- **Description**: Represents a doctor node.
- **Fields**:
  - `DName`: Doctor's name
  - `next`, `prev`: Pointers to next/previous nodes

### 3. **`degerlendirData`**
- **Description**: Stores evaluation data.
- **Fields**:
  - `AmeliyetUcreti`: Total surgery cost
  - `hastalarSayasi`: Patient count
  - `AmeliyatSayisi`: Surgery count
  - `next`: Pointer to next node

### 4. **`hastaVE_ameliyatVE_ucretSayisi`**
- **Description**: Tracks counters.
- **Fields**:
  - `hastalarCnt`: Patient count
  - `AmeliyatCnt`: Surgery count
  - `AmeliyatucretiCnt`: Total surgery cost

---

## **Classes Analysis**

### 1. **`DoublyLinkedList`**
- **Description**: Manages patient data for doctors using a doubly linked list.
- **Key Methods**:
  - **`addHastaNode()`**: Adds a patient, calculates cost (`hastalik_derecesi * 1500`), updates counters.
  - **`IdGoreHastaSil()`**: Deletes a patient by ID, adjusts pointers.
  - **`HastaDeteylerYaz()`**: Prints all patient details.
  - **`AmeliyatEkle()`**: Adds surgery details to a patient by ID.
  - **`Ameliyatsil()`**: Deletes a surgery by ID.
  - **`AmeliyatDetaylarınıGetir()`**: Shows surgery details for patients.
  - **`IDye_göre_ameliyat_ücretini_hesapla()`**: Calculates surgery cost.
  - **`degerlendirmaData1()`**: Returns counter data.
  - **Destructor**: Frees memory.

### 2. **`CircularDoublyLinkedList`**
- **Description**: Manages patient data and doctor list for patients using a circular doubly linked list.
- **Key Methods**:
  - **`doctorlarYaz()`**: Displays a list of 5 predefined doctors.
  - **`addNode()`**: Adds patient data (used for data transfer).
  - **`TumHastalarYazdir()`**: Displays all patients.
  - **`AmeliyatHastalariniYazdir()`**: Shows patients with surgeries.
  - **`TumHastalarınOncelikPuanlarYazdır()`**: Displays priority scores (severity * 10).
  - **Destructor**: Frees memory.

### 3. **`CircularLinkedList`**
- **Description**: Stores evaluation data in a circular singly linked list.
- **Key Methods**:
  - **`addNode(DoublyLinkedList op)`**: Adds evaluation data from `DoublyLinkedList`.
  - **`degerlendermedisplay()`**: Displays formatted evaluation stats.

---

## **External Functions**

- **`ReadHastaData()`**: Reads and returns patient data from user input.
- **`ReadAmeliyatData()`**: Reads and returns surgery data (start/end times).
- **`readtheNum(string message)`**: Prompts user for a number and returns it.
- **`transferData(DoublyLinkedList& dll, CircularDoublyLinkedList& CircularDll)`**: Transfers patient data between lists.
- **`BirinciOtomasyonGiriS()`**: Main entry menu (doctor, patient, exit, evaluation).
- **`DoctorEkrani()`**: Displays doctor options menu.
- **`loginDoctor()`**: Verifies doctor login (3 attempts).
- **`HastaEkrani()`**: Displays patient options menu.
- **`DoctorsecimYAP(enum doktur Doctor_secimi, DoublyLinkedList &op)`**: Executes doctor's choice.
- **`HastasecimYAP(enum hasta Hasta_secimi, CircularDoublyLinkedList& op)`**: Executes patient's choice.
- **`HstanaSestemi()`**: Runs the system based on user selection.

---

## **Main Function**
- **Purpose**: Initializes objects (`opDOCTOR`, `opHASTA`, `opdegerlendir`) and starts the system with `HstanaSestemi`.
