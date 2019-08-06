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
	// ��x���뵽������
	if (CurrentSize == MaxSize)
		throw NoMem();

	// ΪxѰ�Ҳ���λ��
	int i = ++CurrentSize;
	while (i != 1 && x > heap[i / 2]){
		// ���ܹ���x����heap[i]
		heap[i] = heap[i / 2];	// ��Ԫ������
		i /= 2;	// ���򸸽ڵ�
	}

	heap[i] = x;
	return *this;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x){
	// �����Ԫ�ط���x�����Ӷ���ɾ�����Ԫ��
	if (CurrentSize == 0)
		throw OutOfBounds();

	x = heap[1];	// ���Ԫ��

	// �ع���
	T y = heap[CurrentSize--];	// ���һ��Ԫ��

	// �Ӹ���ʼ��ΪyѰ�Һ��ʵ�λ��
	int i = 1, ci = 2;
	while (ci <= CurrentSize){
		// heap[ci]Ӧ��i�ϴ�ĺ���
		if (ci < CurrentSize && heap[ci] < heap[ci + 1])
			ci++;

		// �ж��Ƿ��ܽ�y����heap[i]
		if (y >= heap[ci])
			break;

		// ����
		heap[i] = heap[ci];
		// ����һ��
		i = ci;
		ci *= 2;
	}
	heap[i] = y;

	return *this;
}

template<class T>
void MaxHeap<T>::Initialize(T a[], int size, int ArraySize){
	// �����ѳ�ʼ��Ϊa
	delete[] heap;
	heap = new T[size + 1];
	for (int s = 1; s <= size; s++){
		heap[s] = a[s - 1];
	}
	CurrentSize = size;
	MaxSize = ArraySize;

	//����һ������
	for (int i = CurrentSize / 2; i >= 1; i--){
		T y = heap[i];

		// Ѱ�ҷ���y��λ��
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