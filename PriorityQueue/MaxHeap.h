#ifndef MAXHEAP_H_
#define MAXHEAP_H_
#include<iostream>

template<class T>
class MaxHeap{
private:
	int CurrentSize, MaxSize;
	T* heap;
public:
	MaxHeap(int MaxHeapSize = 10);
	~MaxHeap(){ delete[] heap; }
	int Size() const{ return CurrentSize; }
	T Max(){
		if (CurrentSize == 0)
			throw OutOfBounds();
		return heap[1];
	}
	MaxHeap<T>& Insert(const T& x);
	MaxHeap<T>& DeleteMax(T& x);
	void Initialize(T a[], int size, int ArraySize);
	void Output(std::ostream&);
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize){
	MaxSize = MaxHeapSize;
	heap = new T[MaxSize + 1];
	CurrentSize = 0;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x){
	// 将x插入到最大堆中
	if (CurrentSize == MaxSize)
		throw NoMem();

	// 为x寻找插入位置
	int i = ++CurrentSize;
	while (i != 1 && x > heap[i / 2]){
		// 不能够将x放入heap[i]
		heap[i] = heap[i / 2];	// 将元素下移
		i /= 2;	// 移向父节点
	}

	heap[i] = x;
	return *this;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x){
	// 将最大元素放入x，并从堆中删除最大元素
	if (CurrentSize == 0)
		throw OutOfBounds();

	x = heap[1];	// 最大元素

	// 重构堆
	T y = heap[CurrentSize--];	// 最后一个元素

	// 从根开始，为y寻找合适的位置
	int i = 1, ci = 2;
	while (ci <= CurrentSize){
		// heap[ci]应是i较大的孩子
		if (ci < CurrentSize && heap[ci] < heap[ci + 1])
			ci++;

		// 判断是否能将y放入heap[i]
		if (y >= heap[ci])
			break;

		// 不能
		heap[i] = heap[ci];
		// 下移一层
		i = ci;
		ci *= 2;
	}
	heap[i] = y;

	return *this;
}

template<class T>
void MaxHeap<T>::Initialize(T a[], int size, int ArraySize){
	// 把最大堆初始化为a
	delete[] heap;
	heap = new T[size + 1];
	for (int s = 1; s <= size; s++){
		heap[s] = a[s - 1];
	}
	CurrentSize = size;
	MaxSize = ArraySize;

	//产生一个最大堆
	for (int i = CurrentSize / 2; i >= 1; i--){
		T y = heap[i];

		// 寻找放置y的位置
		int c = 2 * i;
		while (c <= CurrentSize){
			if (c < CurrentSize&&heap[c] < heap[c + 1])
				c++;

			if (y >= heap[c])
				break;

			heap[c / 2] = heap[c];
			c *= 2;
		}
		heap[c / 2] = y;
	}
}

template<class T>
void MaxHeap<T>::Output(std::ostream& out){
	if (CurrentSize == 0){
		out << "MaxHeap is empty\n";
		return;
	}
	for (int i = 1; i <= CurrentSize; i++){
		out << i << ": " << heap[i];
		if (i != CurrentSize)
			out << ", ";
	}
	out << "\n";
}

template<class T>
std::ostream& operator<<(std::ostream& out, MaxHeap<T>& h){
	h.Output(out);
	return out;
}
#endif