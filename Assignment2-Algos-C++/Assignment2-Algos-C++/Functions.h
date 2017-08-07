#pragma once
#include <array>
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void SelectFile();
void ReadFile(string aFileName);
void MinHeapify(int i, int n);
void MaxHeapify(int i, int n);
void HeapSort(bool aOption);
void BuildHeap(bool aOption);
void PrintHeap();