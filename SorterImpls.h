#include <vector>

using namespace std;

//Karim Oumghar
//Lab 4 - CSS 342 - February 27, 2015

void BubbleSort(vector<int> &items, int start, int end);
void InsertSort(vector<int> &items, int start, int end);
void Swap(vector<int> &items, int &x, int &y);
void QuickSort(vector<int> &items, int start, int end);
void MergeSort(vector<int> &items, int start, int end);
void Merge(vector<int> &items, int start, int mid, int end);
void IterativeMergeSort(vector<int> &items, int start, int end);
void ItMerge(vector<int> &items, int start, int mid, int end, vector<int> &temp);

void BubbleSort(vector<int> &items, int start, int end)
{
	int temp;
	for(int x = start; x < end + 1; x++)
	{
		for(int y = start; y < end; y++)
		{
			if(items[y] > items[y + 1])
			{
				temp = items[y + 1];
				items[y + 1] = items[y];
				items[y] = temp;
			}
		}
	}
}
void InsertSort(vector<int> &items, int start, int end)
{
	int temp;
	for(int x = start; x < end + 1; x++)
	{
		temp = items[x];
		int j = x;
		while(j > 0 && items[j - 1] > temp)
		{
			items[j] = items[j - 1];
			j--;
		}
		items[j] = temp;
	}
}
void MergeSort(vector<int> &items, int start, int end)
{
	if(start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(items, start, mid);
		MergeSort(items, mid + 1, end);
		Merge(items, start, mid, end);
	}
}
void Merge(vector<int> &items, int start, int mid, int end)
{
	vector<int> temp(items.size());
	int first1 = start;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = end;

	int index = first1;
	while(first1 <= last1 && first2 <= last2)
	{
		if(items[first1] <= items[first2])
		{
			temp[index] = items[first1];
			first1++;
		}
		else
		{
			temp[index] = items[first2];
			first2++;
		}
		index++;
	}
	while(first1 <= last1)
	{
		temp[index] = items[first1];
		first1++;
		index++;
	}
	while(first2 <= last2)
	{
		temp[index] = items[first2];
		first2++;
		index++;
	}
	for(index = start; index <= end; index++)
	{
		items[index] = temp[index];
	}
}
void IterativeMergeSort(vector<int> &items, int start, int end)
{
	vector<int> temp(items.size());
	int left, middle, right;
	for(int outer = 1; outer < end; outer *= 2)
	{
		for(int inner = 0; inner < end; inner = inner + (outer * 2))
		{
			left = inner;
			middle = (inner + outer) - 1;
			right = (inner +(outer * 2)) - 1;
			ItMerge(items, left, middle, right, temp);
		}
	}
}
void ItMerge(vector<int> &items, int start, int mid, int end, vector<int> &temp)
{
	if(mid >= items.size())
	{
		mid = items.size() - 1;
	}
	if(end >= items.size())
	{
		end = items.size() - 1;
	}
	int first1 = start;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = end;

	int index = first1;
	while(first1 <= last1 && first2 <= last2)
	{
		if(items[first1] <= items[first2])
		{
			temp[index] = items[first1];
			first1++;
		}
		else
		{
			temp[index] = items[first2];
			first2++;
		}
		index++;
	}
	while(first1 <= last1)
	{
		temp[index] = items[first1];
		first1++;
		index++;
	}
	while(first2 <= last2)
	{
		temp[index] = items[first2];
		first2++;
		index++;
	}
	for(index = start; index <= end; index++)
	{
		items[index] = temp[index];
	}
}
void QuickSort(vector<int> &items, int start, int end)
{
	if(items.size() < 5)
	{
		InsertSort(items, start, end);
	}
	else
	{
		int pivot = items[(start+(end-start)/2)];
		int left = start;
		int right = end;
		while(left <= right)
		{
			while(items[left] < pivot)
			{
				left++;
			}
			while(items[right] > pivot)
			{
				right--;
			}
			if(left <= right)
			{
				Swap(items, left, right);
				left++;
				right--;
			}
		}
		if(start < right)
		{
			QuickSort(items, start, left - 1);
		}
		if(end > left)
		{
			QuickSort(items, right + 1, end);
		}
    }
 
}
void Swap(vector<int> &items, int &x, int &y)
{
	int temp = items[x];
	items[x] = items[y];
	items[y] = temp;
}
