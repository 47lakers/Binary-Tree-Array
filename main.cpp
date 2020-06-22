//
//  main.cpp
//  Binary Tree Array
//
//  Created by Ira Xavier Porchia on 5/31/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 10;
int lastUsedIndex;

int _arr[MAX];

void create(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
    cout << "Created an array full of 0s." << endl << endl;
}

bool isFull(int arr[], int size){
    if(arr[size - 1] != 0){
        return true;
    }
    return false;
}

void insert(int arr[], int size, int value){
    if(isFull(arr, size)){
        cout << "Array is full. Cannot insert." << endl << endl;
    }
    int i = 1;
    while(arr[i] != 0){
        i++;
    }
    arr[i] = value;
    cout << "Inserted: " <<  value << endl << endl;
}

void levelOrder(int arr[], int size){
    for(int i = 1; i < size; i++){
        if(arr[i] == 0){
            i++;
        }else{
            cout << arr[i] << " ";
        }
    }
    cout << endl << endl;
}

void preOrder(int one){
    if(one > MAX){
        return;
    }
    if(_arr[one] != 0){
        cout << _arr[one] << " ";
    }
    preOrder(one * 2);
    preOrder(one * 2 + 1);
}

void inOrder(int one){
    if(one > MAX){
        return;
    }
    preOrder(one * 2);
    if(_arr[one] != 0){
        cout << _arr[one] << " ";
    }
    preOrder(one * 2 + 1);
}

void postOrder(int one){
    if(one > MAX){
        return;
    }
    preOrder(one * 2);
    preOrder(one * 2 + 1);
    if(_arr[one] != 0){
        cout << _arr[one] << " ";
    }
}

void search(int value){
    for(int i = 0; i < MAX; i++){
        if(value == _arr[i]){
            cout << "Found value at index: " << i << endl << endl;
            return;
        }
    }
    cout << "Value not found." << endl << endl;
}

int main(int argc, const char * argv[]) {
    create(_arr, MAX);
    insert(_arr, MAX, 10);
    insert(_arr, MAX, 20);
    insert(_arr, MAX, 30);
    insert(_arr, MAX, 40);
    insert(_arr, MAX, 50);
    insert(_arr, MAX, 60);
    levelOrder(_arr, MAX);
    preOrder(1);
    cout << endl << endl;
    inOrder(1);
    cout << endl << endl;
    postOrder(1);
    cout << endl << endl;
    search(10);
    search(500);
    search(50);
    return 0;
}
