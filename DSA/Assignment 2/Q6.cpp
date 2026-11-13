#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    string department;
    double cgpa;
    string award;
    int ogIdx;

    Student() {
        id = 0;
        name = "";
        department = "";
        cgpa = 0.0;
        award = "None";
        ogIdx = 0;
    }

    Student(int i, string n, string d, double c, int idx) {
        id = i;
        name = n;
        department = d;
        cgpa = c;
        award = "None";
        ogIdx = idx;
    }
};

void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student* L = new Student[n1];
    Student* R = new Student[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].cgpa > R[j].cgpa || (L[i].cgpa == R[j].cgpa && L[i].ogIdx < R[j].ogIdx)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void assignAwards(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i].cgpa >= 3.8) {
            arr[i].award = "Rector's List";
        } else if (arr[i].cgpa >= 3.5) {
            arr[i].award = "Dean's List";
        } else {
            arr[i].award = "None";
        }
    }
}

int main() {
    const int numStudents = 30;
    Student students[numStudents] = {
        Student(101, "Ali Khan", "CS", 3.92, 0),
        Student(102, "Ayesha Ahmed", "SE", 3.55, 1),
        Student(103, "Bilal Raza", "EE", 3.85, 2),
        Student(104, "Fatima Noor", "CS", 3.92, 3),
        Student(105, "Hassan Ali", "AI", 3.10, 4),
        Student(106, "Zainab Malik", "CS", 3.75, 5),
        Student(107, "Usman Tariq", "SE", 3.40, 6),
        Student(108, "Sana Ejaz", "CY", 3.88, 7),
        Student(109, "Hamza Farooq", "EE", 2.90, 8),
        Student(110, "Amina Sheikh", "AI", 3.65, 9),
        Student(111, "Saad Qureshi", "CS", 3.55, 10),
        Student(112, "Mahnoor Butt", "SE", 3.95, 11),
        Student(113, "Danyal Shah", "CY", 3.20, 12),
        Student(114, "Zohra Baig", "EE", 3.70, 13),
        Student(115, "Omar Farooq", "CS", 3.81, 14),
        Student(116, "Khadija Bibi", "AI", 3.33, 15),
        Student(117, "Talha Munir", "SE", 3.95, 16),
        Student(118, "Rimsha Kanwal", "CY", 3.50, 17),
        Student(119, "Ahsan Iqbal", "EE", 2.80, 18),
        Student(120, "Hira Mani", "CS", 3.60, 19),
        Student(121, "Waleed Khan", "AI", 3.00, 20),
        Student(122, "Rabia Basri", "SE", 3.85, 21),
        Student(123, "Fahad Mustafa", "CY", 3.45, 22),
        Student(124, "Mehwish Hayat", "EE", 3.78, 23),
        Student(125, "Imran Riaz", "CS", 3.15, 24),
        Student(126, "Sadia Imam", "AI", 3.90, 25),
        Student(127, "Kamran Akmal", "SE", 2.50, 26),
        Student(128, "Nida Yasir", "CY", 3.52, 27),
        Student(129, "Junaid Jamshed", "EE", 3.88, 28),
        Student(130, "Bushra Ansari", "CS", 3.68, 29)
    };

    mergeSort(students, 0, numStudents - 1);
    assignAwards(students, numStudents);

    cout << "ID \t Name \t\t\t Dept \t CGPA \t Award" << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << students[i].id << "\t " 
             << students[i].name << "\t\t " 
             << students[i].department << "\t " 
             << students[i].cgpa << "\t " 
             << students[i].award << endl;
    }

    return 0;
}
