#ifndef CSTACK_H_
#define CSTACK_H_
#include<queue>
using std::queue;

template <typename T>
class CStack{
public:
	CStack(){}
	~CStack(){}

	void append(const T& data);
	T remove();
	bool empty(){
		return q1.empty() && q2.empty();
	}
private:
	queue<T> q1;
	queue<T> q2;
};

template<typename T>
void CStack<T>::append(const T& data){
	// ������ѡ�ǿյĶ��У����������ж��յ�ʱ��Ĭ�ϲ������1
	if (q1.empty()){
		q2.push(data);
	}
	else{
		q1.push(data);
	}
}

template<typename T>
T CStack<T>::remove(){
	// ɾ��Ԫ�ص�ʱ�򣬽��ǿյĶ��е�����Ԫ�أ����˶�βԪ���⣬�����뵽�յĶ�����
	T res;
	if (q1.empty()){
		while (q2.size() > 1){
			T& data = q2.front();
			q2.pop();
			q1.push(data);
		}
		res = q2.front();
		q2.pop();
	}
	else{
		while (q1.size() > 1){
			T& data = q1.front();
			q1.pop();
			q2.push(data);
		}
		res = q1.front();
		q1.pop();
	}
	return res;
}

#endif