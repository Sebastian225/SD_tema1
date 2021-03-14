#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;

unsigned long long llrand() {
    unsigned long long r = 0;


    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

void generateTests(int nrTests, const int *N, const int *MAX){
    srand((unsigned)time(nullptr));

    ofstream fout("E:\\cpp facultate\\Sortari\\teste.txt");
    fout<<nrTests<<'\n';
    for(int i = 0; i < nrTests; i++){
        fout<<N[i]<<" "<<MAX[i]<<" ";
        for(int j = 0; j < N[i]; j++){
            fout<<(llrand() % MAX[i]) + 1<<" ";
        }
        fout<<'\n';
    }
    //fout<<2;
    fout.close();
}

void bubbleSort(vector<long long int> &v, int n){

    for(long long int i = 0; i < n; i++){
        for(long long int j = 0; j < n - i - 1; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

void countSort(vector<long long int> &v, vector<int> &vf, int n, long long int max){
    for(int i = 0; i<=max; i++){
        vf.push_back(0);
    }

    for(int i = 0; i < n; i++){
        vf[v[i]]++;
        //cout<<v[i]<<" ";
    }

    int index = 0;

    for(int i = 0; i<=max; i++){
        while(vf[i]){
            v[index] = i;
            vf[i]--;
            index++;
        }
    }
}

long long int getMax(vector<long long int> &v){
    long long int max = 0;
    for(long long i : v){
        if(i > max){
            max = i;
        }
    }
    return max;
}

void radixSort(vector<long long int> &v, int exp){ //base = 2^exp
    vector<long long int> b[1 << exp];
    vector<long long int> copy;
    long long int maxBitGr = (log2(getMax(v))/exp)+1;

    for(long long i = 0; i < maxBitGr; i++){
        for(long long & j : v){
            long long y = (j & (((1 << exp) - 1) << i*exp)) >> i*exp;
            b[y].push_back(j);
        }
        for(auto & j : b){
            for(long long & k : j){
                copy.push_back(k);
            }
        }
        v.clear();
        for(long long & j : copy){
            v.push_back(j);
        }
        copy.clear();
        for(auto & j : b){
            j.clear();
        }
    }
}

void merge(vector<long long int> &v, vector<long long int> &v1, vector<long long int> &v2, long long int left){

    long long int i1=0,i2=0,k=left;
    while(i1 < v1.size() && i2 < v2.size()){
        if(v1[i1]<=v2[i2]){
            v[k] = v1[i1];
            i1++;
        }
        else{
            v[k] = v2[i2];
            i2++;
        }
        k++;
    }
    while(i1<v1.size()){
        v[k]=v1[i1];
        i1++;
        k++;
    }
    while(i2<v2.size()){
        v[k]=v2[i2];
        i2++;
        k++;
    }
}

void mergeSort(vector<long long int> &v, long long int left, long long int right){
    if(left<right){
        long long mid = (left + right) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);

        long long size1 = mid-left+1;
        long long size2 = right-mid;

        vector<long long> v1, v2;

        for(long long i = 0; i < size1; ++i){
            v1.push_back(v[left+i]);
        }
        for(long long i = 0; i < size2; ++i){
            v2.push_back(v[mid+1+i]);
        }

        merge(v, v1, v2, left);
    }
}

void quickSort(vector<long long int> &v, long long int left, long long int right){
    vector<long long int> lower, higher, equal;
    if(left < right){
        long long pivot = left;

        for(long long int i = left; i < right; i++) {
            if (v[i] < v[pivot]) {
                lower.push_back(v[i]);
            } else if (v[i] == v[pivot]) {
                equal.push_back(v[i]);
            } else {
                higher.push_back(v[i]);
            }
        }

        for(long long i = 0; i<lower.size();i++){
            v[left+i]=lower[i];
        }
        for(long long i = 0; i<equal.size();i++){
            v[left+lower.size()+i]=equal[i];
        }
        for(long long i = 0; i<higher.size();i++){
            v[left+lower.size()+equal.size()+i]=higher[i];
        }

        quickSort(v, left, left + lower.size());
        quickSort(v, left + lower.size() + equal.size(), right);
    }
}

int N[] = {1000, 1000, 1000, 10000, 10000, 100000, 1000000, 1000000, 100000000, 100000000};
int MAX[] = {100, 10000, 1000000, 100, 10000, 1000000, 100, 10000, 1000000, 100000000};
vector<long long int> numbers, backup;
vector<int> frecv;

int main() {
    generateTests(10, N, MAX);

    //cout<<numbers.max_size();
    ifstream fin("E:\\cpp facultate\\Sortari\\teste.txt");
    int NR_TESTE, N_TEST, MAX_TEST, nr;
    fin>>NR_TESTE;
    for(int t = 0; t < NR_TESTE; t++){
        fin>>N_TEST>>MAX_TEST;
        cout<<"Test "<<t + 1<<'\n'<<N_TEST<<" numere, pana in "<<MAX_TEST<<'\n';
        for(int i = 0; i < N_TEST; i++){
            fin>>nr;
            numbers.push_back(nr);
        }
        backup = numbers;

        cout<<"BUBBLE SORT: ";
        auto start = chrono::system_clock::now();
        bubbleSort(numbers, N_TEST);
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        cout<<elapsed_seconds.count() << "s ";
        if(is_sorted(numbers.begin(), numbers.end())){
            cout<<"sorted\n";
        }
        else{
            cout<<"not sorted\n";
        }
        backup = numbers;

        cout<<"COUNT SORT: ";
        start = chrono::system_clock::now();
        if(MAX_TEST > frecv.max_size() or INT32_MAX<N_TEST){
            cout<<"can't sort!";
        }
        else {
            countSort(numbers, frecv, N_TEST, MAX_TEST);
        }
        end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        cout<<elapsed_seconds.count() << "s ";
        if(is_sorted(numbers.begin(), numbers.end())){
            cout<<"sorted\n";
        }
        else{
            cout<<"not sorted\n";
        }
        backup = numbers;

        cout<<"RADIX SORT (baza 1024): ";
        start = chrono::system_clock::now();
        radixSort(numbers, 10);
        end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        cout<<elapsed_seconds.count() << "s ";
        if(is_sorted(numbers.begin(), numbers.end())){
            cout<<"sorted\n";
        }
        else{
            cout<<"not sorted\n";
        }
        backup = numbers;

        cout<<"RADIX SORT (baza 16): ";
        start = chrono::system_clock::now();
        radixSort(numbers, 4);
        end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        cout<<elapsed_seconds.count() << "s ";
        if(is_sorted(numbers.begin(), numbers.end())){
            cout<<"sorted\n";
        }
        else{
            cout<<"not sorted\n";
        }
        backup = numbers;

        cout<<"MERGE SORT: ";
        start = chrono::system_clock::now();
        mergeSort(numbers, 0, N_TEST+1);
        end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        cout<<elapsed_seconds.count() << "s ";
        if(is_sorted(numbers.begin(), numbers.end())){
            cout<<"sorted\n";
        }
        else{
            cout<<"not sorted\n";
        }
        backup = numbers;

        cout<<"QUICK SORT: ";
        start = chrono::system_clock::now();
        quickSort(numbers, 0, N_TEST+1);
        end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        cout<<elapsed_seconds.count() << "s ";
        if(is_sorted(numbers.begin(), numbers.end())){
            cout<<"sorted\n";
        }
        else{
            cout<<"not sorted\n";
        }
        backup = numbers;

        cout<<"C++ NATIVE SORT: ";
        start = chrono::system_clock::now();
        sort(numbers.begin(), numbers.end());
        end = chrono::system_clock::now();
        elapsed_seconds = end-start;
        cout<<elapsed_seconds.count() << "s ";
        if(is_sorted(numbers.begin(), numbers.end())){
            cout<<"sorted\n";
        }
        else{
            cout<<"not sorted\n";
        }
        backup = numbers;
    }

    fin.close();

    return 0;
}
