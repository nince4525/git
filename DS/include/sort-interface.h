#pragma once

#include "record-sort.h"

//insertion
extern void InsSort(RecordType r[], int length);
extern void BinSort (RecordType r[], int length);
extern void ShellSort(RecordType r[], int length);

//swap
extern void BubbleSort(RecordType r[], int length);
extern void QuickSort(RecordType r[], int length);

//selection
extern void SelectSort(RecordType r[], int length);
extern void HeapSort(RecordType r[], int length);

//merging
extern void MergeSort(RecordType r[], int length);
extern void MergeSort2(RecordType r[], int length);

//distribution
extern void RadixSort(RecordType r[], int length);